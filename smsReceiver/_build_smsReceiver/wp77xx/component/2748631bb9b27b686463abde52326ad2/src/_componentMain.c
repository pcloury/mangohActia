/*
 * AUTO-GENERATED _componentMain.c for the smsClient component.

 * Don't bother hand-editing this file.
 */

#include "legato.h"

#ifdef __cplusplus
extern "C" {
#endif

extern const char* _smsClient_le_sms_ServiceInstanceName;
const char** le_sms_ServiceInstanceNamePtr = &_smsClient_le_sms_ServiceInstanceName;
void le_sms_ConnectService(void);
extern const char* _smsClient_le_dcs_ServiceInstanceName;
const char** le_dcs_ServiceInstanceNamePtr = &_smsClient_le_dcs_ServiceInstanceName;
void le_dcs_ConnectService(void);
extern const char* _smsClient_le_net_ServiceInstanceName;
const char** le_net_ServiceInstanceNamePtr = &_smsClient_le_net_ServiceInstanceName;
void le_net_ConnectService(void);
extern const char* _smsClient_le_gnss_ServiceInstanceName;
const char** le_gnss_ServiceInstanceNamePtr = &_smsClient_le_gnss_ServiceInstanceName;
void le_gnss_ConnectService(void);
// Component log session variables.
le_log_SessionRef_t smsClient_LogSession;
le_log_Level_t* smsClient_LogLevelFilterPtr;

// Declare component's COMPONENT_INIT_ONCE function,
// and provide default empty implementation.
__attribute__((weak))
COMPONENT_INIT_ONCE
{
}
// Component initialization function (COMPONENT_INIT).
COMPONENT_INIT;

// Library initialization function.
// Will be called by the dynamic linker loader when the library is loaded.
__attribute__((constructor)) void _smsClient_Init(void)
{
    LE_DEBUG("Initializing smsClient component library.");

    // Connect client-side IPC interfaces.
    le_sms_ConnectService();
    le_dcs_ConnectService();
    le_net_ConnectService();
    le_gnss_ConnectService();

    // Register the component with the Log Daemon.
    smsClient_LogSession = le_log_RegComponent("smsClient", &smsClient_LogLevelFilterPtr);

    // Queue the default component's COMPONENT_INIT_ONCE to Event Loop.
    le_event_QueueFunction(&COMPONENT_INIT_ONCE_NAME, NULL, NULL);

    // Queue the COMPONENT_INIT function to be called by the event loop
    le_event_QueueFunction(&COMPONENT_INIT_NAME, NULL, NULL);
}


#ifdef __cplusplus
}
#endif
