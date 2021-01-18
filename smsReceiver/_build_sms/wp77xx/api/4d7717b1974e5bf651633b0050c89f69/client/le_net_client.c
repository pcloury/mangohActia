/*
 * ====================== WARNING ======================
 *
 * THE CONTENTS OF THIS FILE HAVE BEEN AUTO-GENERATED.
 * DO NOT MODIFY IN ANY WAY.
 *
 * ====================== WARNING ======================
 */

#include "le_net_interface.h"
#include "le_net_messages.h"
#include "le_net_service.h"


//--------------------------------------------------------------------------------------------------
// Generic Client Types, Variables and Functions
//--------------------------------------------------------------------------------------------------


//--------------------------------------------------------------------------------------------------
/**
 * Client Thread Objects
 *
 * This object is used to contain thread specific data for each IPC client.
 */
//--------------------------------------------------------------------------------------------------
typedef struct
{
    le_msg_SessionRef_t sessionRef;     ///< Client Session Reference
    int                 clientCount;    ///< Number of clients sharing this thread
    le_net_DisconnectHandler_t disconnectHandler; ///< Disconnect handler for this thread
    void*               contextPtr;     ///< Context for disconnect handler
}
_ClientThreadData_t;

//--------------------------------------------------------------------------------------------------
/**
 * Static pool for client threads.
 */
//--------------------------------------------------------------------------------------------------
LE_MEM_DEFINE_STATIC_POOL(le_net_ClientThreadData,
                          LE_CDATA_COMPONENT_COUNT,
                          sizeof(_ClientThreadData_t));


//--------------------------------------------------------------------------------------------------
/**
 * The memory pool for client thread objects
 */
//--------------------------------------------------------------------------------------------------
static le_mem_PoolRef_t _ClientThreadDataPool;


//--------------------------------------------------------------------------------------------------
/**
 * Key under which the pointer to the Thread Object (_ClientThreadData_t) will be kept in
 * thread-local storage.  This allows a thread to quickly get a pointer to its own Thread Object.
 */
//--------------------------------------------------------------------------------------------------
static pthread_key_t _ThreadDataKey;


//--------------------------------------------------------------------------------------------------
/**
 * This global flag is shared by all client threads, and is used to indicate whether the common
 * data has been initialized.
 *
 * @warning Use InitMutex, defined below, to protect accesses to this data.
 */
//--------------------------------------------------------------------------------------------------
static bool CommonDataInitialized = false;


//--------------------------------------------------------------------------------------------------
/**
 * Mutex and associated macros for use with the above CommonDataInitialized.
 */
//--------------------------------------------------------------------------------------------------
extern le_mutex_Ref_t le_ifgen_InitMutexRef;

/// Locks the mutex.
#define LOCK_INIT    le_mutex_Lock(le_ifgen_InitMutexRef);

/// Unlocks the mutex.
#define UNLOCK_INIT  le_mutex_Unlock(le_ifgen_InitMutexRef);

//--------------------------------------------------------------------------------------------------
/**
 * Initialize thread specific data, and connect to the service for the current thread.
 *
 * @return
 *  - LE_OK if the client connected successfully to the service.
 *  - LE_UNAVAILABLE if the server is not currently offering the service to which the client is
 *    bound.
 *  - LE_NOT_PERMITTED if the client interface is not bound to any service (doesn't have a binding).
 *  - LE_COMM_ERROR if the Service Directory cannot be reached.
 */
//--------------------------------------------------------------------------------------------------
static le_result_t InitClientForThread
(
    bool isBlocking
)
{
    // Open a session.
    le_msg_SessionRef_t sessionRef;
    le_msg_ProtocolRef_t protocolRef;

    protocolRef = le_msg_GetProtocolRef(PROTOCOL_ID_STR, sizeof(_Message_t));
    sessionRef = le_msg_CreateSession(protocolRef, SERVICE_INSTANCE_NAME);
    le_result_t result = ifgen_le_net_OpenSession(sessionRef, isBlocking);
    if (result != LE_OK)
    {
        LE_DEBUG("Could not connect to '%s' service", SERVICE_INSTANCE_NAME);

        return result;
    }

    // Store the client sessionRef in thread-local storage, since each thread requires
    // its own sessionRef.
    _ClientThreadData_t* clientThreadPtr = le_mem_Alloc(_ClientThreadDataPool);
    memset(clientThreadPtr, 0, sizeof(_ClientThreadData_t));
    clientThreadPtr->sessionRef = sessionRef;
    if (pthread_setspecific(_ThreadDataKey, clientThreadPtr) != 0)
    {
        LE_FATAL("pthread_setspecific() failed!");
    }

    // This is the first client for the current thread
    clientThreadPtr->clientCount = 1;

    return LE_OK;
}


//--------------------------------------------------------------------------------------------------
/**
 * Get a pointer to the client thread data for the current thread.
 *
 * If the current thread does not have client data, then NULL is returned
 */
//--------------------------------------------------------------------------------------------------
static _ClientThreadData_t* GetClientThreadDataPtr
(
    void
)
{
    return pthread_getspecific(_ThreadDataKey);
}


//--------------------------------------------------------------------------------------------------
/**
 * Return the sessionRef for the current thread.
 *
 * If the current thread does not have a session ref, then this is a fatal error.
 */
//--------------------------------------------------------------------------------------------------
__attribute__((unused)) static le_msg_SessionRef_t GetCurrentSessionRef
(
    void
)
{
    if (ifgen_le_net_HasLocalBinding())
    {
        return NULL;
    }
    else
    {
        _ClientThreadData_t* clientThreadPtr = GetClientThreadDataPtr();

        // If the thread specific data is NULL, then the session ref has not been created.
        LE_FATAL_IF(clientThreadPtr==NULL,
                    "le_net_ConnectService() not called for current thread");

        return clientThreadPtr->sessionRef;
    }
}


//--------------------------------------------------------------------------------------------------
/**
 * Init data that is common across all threads.
 */
//--------------------------------------------------------------------------------------------------
static void InitCommonData(void)
{
    // Perform common initialization across all instances of this API.
    ifgen_le_net_InitCommonData();

    // Allocate the client thread pool
    _ClientThreadDataPool = le_mem_InitStaticPool(le_net_ClientThreadData,
                                                  LE_CDATA_COMPONENT_COUNT,
                                                  sizeof(_ClientThreadData_t));

    // Create the thread-local data key to be used to store a pointer to each thread object.
    LE_ASSERT(pthread_key_create(&_ThreadDataKey, NULL) == 0);
}


//--------------------------------------------------------------------------------------------------
/**
 * Connect to the service, using either blocking or non-blocking calls.
 *
 * This function implements the details of the public ConnectService functions.
 *
 * @return
 *  - LE_OK if the client connected successfully to the service.
 *  - LE_UNAVAILABLE if the server is not currently offering the service to which the client is
 *    bound.
 *  - LE_NOT_PERMITTED if the client interface is not bound to any service (doesn't have a binding).
 *  - LE_COMM_ERROR if the Service Directory cannot be reached.
 */
//--------------------------------------------------------------------------------------------------
static le_result_t DoConnectService
(
    bool isBlocking
)
{
    // If this is the first time the function is called, init the client common data.
    LOCK_INIT
    if ( ! CommonDataInitialized )
    {
        InitCommonData();
        CommonDataInitialized = true;
    }
    UNLOCK_INIT

    _ClientThreadData_t* clientThreadPtr = GetClientThreadDataPtr();

    // If the thread specific data is NULL, then there is no current client session.
    if (clientThreadPtr == NULL)
    {
        le_result_t result;

        result = InitClientForThread(isBlocking);
        if ( result != LE_OK )
        {
            // Note that the blocking call will always return LE_OK
            return result;
        }

        LE_DEBUG("======= Starting client for '%s' service ========", SERVICE_INSTANCE_NAME);
    }
    else
    {
        // Keep track of the number of clients for the current thread.  There is only one
        // connection per thread, and it is shared by all clients.
        clientThreadPtr->clientCount++;
        LE_DEBUG("======= Starting another client for '%s' service ========",
                 SERVICE_INSTANCE_NAME);
    }

    return LE_OK;
}


//--------------------------------------------------------------------------------------------------
/**
 *
 * Connect the current client thread to the service providing this API. Block until the service is
 * available.
 *
 * For each thread that wants to use this API, either ConnectService or TryConnectService must be
 * called before any other functions in this API.  Normally, ConnectService is automatically called
 * for the main thread, but not for any other thread. For details, see @ref apiFilesC_client.
 *
 * This function is created automatically.
 */
//--------------------------------------------------------------------------------------------------
void le_net_ConnectService
(
    void
)
{
    if (!ifgen_le_net_HasLocalBinding())
    {
        // Connect to the service; block until connected.
        DoConnectService(true);
    }
}

//--------------------------------------------------------------------------------------------------
/**
 *
 * Try to connect the current client thread to the service providing this API. Return with an error
 * if the service is not available.
 *
 * For each thread that wants to use this API, either ConnectService or TryConnectService must be
 * called before any other functions in this API.  Normally, ConnectService is automatically called
 * for the main thread, but not for any other thread. For details, see @ref apiFilesC_client.
 *
 * This function is created automatically.
 *
 * @return
 *  - LE_OK if the client connected successfully to the service.
 *  - LE_UNAVAILABLE if the server is not currently offering the service to which the client is
 *    bound.
 *  - LE_NOT_PERMITTED if the client interface is not bound to any service (doesn't have a binding).
 *  - LE_COMM_ERROR if the Service Directory cannot be reached.
 */
//--------------------------------------------------------------------------------------------------
le_result_t le_net_TryConnectService
(
    void
)
{
    if (ifgen_le_net_HasLocalBinding())
    {
        return LE_OK;
    }
    else
    {
        // Connect to the service; return with an error if not connected.
        return DoConnectService(false);
    }
}

//--------------------------------------------------------------------------------------------------
// Session close handler.
//
// Dispatches session close notifications to the registered client handler function (if any)
//--------------------------------------------------------------------------------------------------
static void SessionCloseHandler
(
    le_msg_SessionRef_t sessionRef,
    void *contextPtr
)
{
    _ClientThreadData_t* clientThreadPtr = contextPtr;

    le_msg_DeleteSession( clientThreadPtr->sessionRef );

    // Need to delete the thread specific data, since it is no longer valid.  If a new
    // client session is started, new thread specific data will be allocated.
    le_mem_Release(clientThreadPtr);
    if (pthread_setspecific(_ThreadDataKey, NULL) != 0)
    {
        LE_FATAL("pthread_setspecific() failed!");
    }

    LE_DEBUG("======= '%s' service spontaneously disconnected ========", SERVICE_INSTANCE_NAME);

    if (clientThreadPtr->disconnectHandler)
    {
        clientThreadPtr->disconnectHandler(clientThreadPtr->contextPtr);
    }

    LE_FATAL("Component for le_net disconnected\n");
}

//--------------------------------------------------------------------------------------------------
/**
 * Set handler called when server disconnection is detected.
 *
 * When a server connection is lost, call this handler then exit with LE_FATAL.  If a program wants
 * to continue without exiting, it should call longjmp() from inside the handler.
 */
//--------------------------------------------------------------------------------------------------
void le_net_SetServerDisconnectHandler
(
    le_net_DisconnectHandler_t disconnectHandler,
    void *contextPtr
)
{
    if (ifgen_le_net_HasLocalBinding())
    {
        // Local bindings don't disconnect
        return;
    }

    _ClientThreadData_t* clientThreadPtr = GetClientThreadDataPtr();

    if (NULL == clientThreadPtr)
    {
        LE_CRIT("Trying to set disconnect handler for non-existent client session for '%s' service",
                SERVICE_INSTANCE_NAME);
    }
    else
    {
        clientThreadPtr->disconnectHandler = disconnectHandler;
        clientThreadPtr->contextPtr = contextPtr;

        if (disconnectHandler)
        {
            le_msg_SetSessionCloseHandler(clientThreadPtr->sessionRef,
                                          SessionCloseHandler,
                                          clientThreadPtr);
        }
    }
}


//--------------------------------------------------------------------------------------------------
/**
 *
 * Disconnect the current client thread from the service providing this API.
 *
 * Normally, this function doesn't need to be called. After this function is called, there's no
 * longer a connection to the service, and the functions in this API can't be used. For details, see
 * @ref apiFilesC_client.
 *
 * This function is created automatically.
 */
//--------------------------------------------------------------------------------------------------
void le_net_DisconnectService
(
    void
)
{
    if (ifgen_le_net_HasLocalBinding())
    {
        // Cannot disconnect local bindings
        return;
    }

    _ClientThreadData_t* clientThreadPtr = GetClientThreadDataPtr();

    // If the thread specific data is NULL, then there is no current client session.
    if (clientThreadPtr == NULL)
    {
        LE_CRIT("Trying to stop non-existent client session for '%s' service",
                SERVICE_INSTANCE_NAME);
    }
    else
    {
        // This is the last client for this thread, so close the session.
        if ( clientThreadPtr->clientCount == 1 )
        {
            le_msg_DeleteSession( clientThreadPtr->sessionRef );

            // Need to delete the thread specific data, since it is no longer valid.  If a new
            // client session is started, new thread specific data will be allocated.
            le_mem_Release(clientThreadPtr);
            if (pthread_setspecific(_ThreadDataKey, NULL) != 0)
            {
                LE_FATAL("pthread_setspecific() failed!");
            }

            LE_DEBUG("======= Stopping client for '%s' service ========", SERVICE_INSTANCE_NAME);
        }
        else
        {
            // There is one less client sharing this thread's connection.
            clientThreadPtr->clientCount--;

            LE_DEBUG("======= Stopping another client for '%s' service ========",
                     SERVICE_INSTANCE_NAME);
        }
    }
}

//--------------------------------------------------------------------------------------------------
/**
 * Add or remove a route on the given channel according to the input flag in the last argument for
 * the given destination address its given subnet's mask prefix length.
 *
 * The channel reference in the first input argument identifies the network interface which a route
 * is to be added onto or removed from. Whether the operation is an add or a remove depends on the
 * isAdd boolean value of the last API input argument.
 *
 * The IP address and subnet input arguments specify the destination address and subnet for the
 * route. If it is a network route, the formats used for them are the same as used in the Linux
 * command "route add -net <ipAddr>/<prefixLength> dev <netInterface>". If the route is a
 * host route, the prefixLength input argument should be given as "" (i.e. a null string).
 *
 * @note The prefixLength parameter used to take a subnet mask (255.255.255.0) for IPv4 and prefix
 *       length for IPv6. Now it only takes prefix length, although compatibility code is present
 *       to make it compatible with previous API declaration. Providing a subnet mask is however
 *       deprecated and the compatibility code will be removed in a latter version.
 *
 * @return
 *      - LE_OK upon success, otherwise another le_result_t failure code
 */
//--------------------------------------------------------------------------------------------------
le_result_t le_net_ChangeRoute
(
    le_dcs_ChannelRef_t channelRef,
        ///< [IN] the channel onto which the route change is made
    const char* LE_NONNULL destAddr,
        ///< [IN] Destination IP address for the route
    const char* LE_NONNULL prefixLength,
        ///< [IN] Destination's subnet prefix length
    bool isAdd
        ///< [IN] the change is to add (true) or delete (false)
)
{
    return ifgen_le_net_ChangeRoute(
        GetCurrentSessionRef(),
        channelRef,
        destAddr,
        prefixLength,
        isAdd
    );
}

//--------------------------------------------------------------------------------------------------
/**
 * Set the default GW addr for the given data channel retrieved from its technology
 *
 * @return
 *      - LE_OK upon success, otherwise LE_FAULT
 */
//--------------------------------------------------------------------------------------------------
le_result_t le_net_SetDefaultGW
(
    le_dcs_ChannelRef_t channelRef
        ///< [IN] the channel on which interface its default GW
        ///< addr is to be set
)
{
    return ifgen_le_net_SetDefaultGW(
        GetCurrentSessionRef(),
        channelRef
    );
}

//--------------------------------------------------------------------------------------------------
/**
 * Get the default GW address for the given data channel.
 *
 * @note
 *      Accomodates dual-stack IPv4/IPv6 addresses. If the default GW address only is only IPv4 or
 *      IPv6, but not both, the unused field of "addr" will be nulled.
 *
 * @return
 *      - LE_OK upon success, otherwise LE_FAULT
 */
//--------------------------------------------------------------------------------------------------
le_result_t le_net_GetDefaultGW
(
    le_dcs_ChannelRef_t channelRef,
        ///< [IN] Channel to retrieve GW addresses
    le_net_DefaultGatewayAddresses_t * addrPtr
        ///< [OUT] Channel's Default GW addresses
)
{
    return ifgen_le_net_GetDefaultGW(
        GetCurrentSessionRef(),
        channelRef,
        addrPtr
    );
}

//--------------------------------------------------------------------------------------------------
/**
 * Backup the current default GW configs of the system, including both IPv4 and IPv6 as applicable.
 * For each client application using this API to back up this system setting, only one backup copy
 * is kept. When a client application makes a second call to this API, its first backup copy will
 * be overwritten by the newer.
 * Thus, le_net keeps one single backup copy per client application, and, thus, multiple backup
 * copies altogether.  They are kept in their LIFO (last-in-first-out) chronological order that
 * the sequence for client applications to call le_net_RestoreDefaltGW() should be in the exact
 * reverse order of their calling le_net_BackupDefaultGW() such that config backups and restorations
 * happen in the correct LIFO manner.
 */
//--------------------------------------------------------------------------------------------------
void le_net_BackupDefaultGW
(
    void
)
{
     ifgen_le_net_BackupDefaultGW(
        GetCurrentSessionRef()
    );
}

//--------------------------------------------------------------------------------------------------
/**
 * Restore the default GW configs of the system to the last backed up ones, including IPv4 and/or
 * IPv6 depending on whether this same client application has called le_net_SetDefaultGW() to
 * change the system's IPv4 and/or IPv6 configs or not. The le_net interface remembers it and
 * perform config restoration only as necessary when le_net_RestoreDefaultGW() is called. When
 * le_net_BackupDefaultGW() is called, both IPv4 and IPv6 default GW configs are archived when
 * present.
 * As le_net keeps one single backup copy per client application, and, thus, multiple backup
 * copies altogether, they are kept in their LIFO (last-in-first-out) chronological order that
 * the sequence for client applications to call le_net_RestoreDefaltGW() should be in the exact
 * reverse order of their calling le_net_BackupDefaultGW() such that config backups and restorations
 * happen in the correct LIFO manner.
 * If these applications do not follow this order, the le_net interface will first generate a
 * warning in the system log and then still go ahead to restore the configs as directed. These
 * applications hold the responsibility for the resulting routing configs on the device.
 */
//--------------------------------------------------------------------------------------------------
le_result_t le_net_RestoreDefaultGW
(
    void
)
{
    return ifgen_le_net_RestoreDefaultGW(
        GetCurrentSessionRef()
    );
}

//--------------------------------------------------------------------------------------------------
/**
 * Set the DNS addresses for the given data channel retrieved from its technology
 *
 * @return
 *      - LE_OK upon success, otherwise LE_FAULT
 */
//--------------------------------------------------------------------------------------------------
le_result_t le_net_SetDNS
(
    le_dcs_ChannelRef_t channelRef
        ///< [IN] the channel from which the DNS addresses retrieved
        ///< will be set into the system config
)
{
    return ifgen_le_net_SetDNS(
        GetCurrentSessionRef(),
        channelRef
    );
}

//--------------------------------------------------------------------------------------------------
/**
 * Get the DNS server addresses for the given data channel retrieved from its technology
 *
 * @note
 *      Can accomodate up to two dual-stack DNS server addresses. In the case that there are more
 *      than two server addresses, the first two addresses of each IP version will be returned. If
 *      there are fewer than two dual-stack addresses, or contain only one type of IPv4 or IPv6
 *      addresses, the unused portions of the passed structure will be nulled and returned.
 *
 * @return
 *      - LE_OK upon success, otherwise LE_FAULT
 */
//--------------------------------------------------------------------------------------------------
le_result_t le_net_GetDNS
(
    le_dcs_ChannelRef_t channelRef,
        ///< [IN] Channel to retrieve DNS server addresses
    le_net_DnsServerAddresses_t * addrPtr
        ///< [OUT] DNS server addresses
)
{
    return ifgen_le_net_GetDNS(
        GetCurrentSessionRef(),
        channelRef,
        addrPtr
    );
}

//--------------------------------------------------------------------------------------------------
/**
 * Remove the last added DNS addresses via the le_dcs_SetDNS API
 */
//--------------------------------------------------------------------------------------------------
void le_net_RestoreDNS
(
    void
)
{
     ifgen_le_net_RestoreDNS(
        GetCurrentSessionRef()
    );
}
