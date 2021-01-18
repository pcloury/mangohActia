/*
 * ====================== WARNING ======================
 *
 * THE CONTENTS OF THIS FILE HAVE BEEN AUTO-GENERATED.
 * DO NOT MODIFY IN ANY WAY.
 *
 * ====================== WARNING ======================
 */


#ifndef LE_SMS_MESSAGES_H_INCLUDE_GUARD
#define LE_SMS_MESSAGES_H_INCLUDE_GUARD


#include "le_sms_common.h"

#define _MAX_MSG_SIZE IFGEN_LE_SMS_MSG_SIZE

// Define the message type for communicating between client and server
typedef struct __attribute__((packed))
{
    uint32_t id;
    uint8_t buffer[_MAX_MSG_SIZE];
}
_Message_t;

#define _MSGID_le_sms_AddRxMessageHandler 0
#define _MSGID_le_sms_RemoveRxMessageHandler 1
#define _MSGID_le_sms_AddFullStorageEventHandler 2
#define _MSGID_le_sms_RemoveFullStorageEventHandler 3
#define _MSGID_le_sms_Create 4
#define _MSGID_le_sms_SetDestination 5
#define _MSGID_le_sms_SetText 6
#define _MSGID_le_sms_SetBinary 7
#define _MSGID_le_sms_SetUCS2 8
#define _MSGID_le_sms_SetPDU 9
#define _MSGID_le_sms_Send 10
#define _MSGID_le_sms_SendAsync 11
#define _MSGID_le_sms_Get3GPP2ErrorCode 12
#define _MSGID_le_sms_GetErrorCode 13
#define _MSGID_le_sms_GetPlatformSpecificErrorCode 14
#define _MSGID_le_sms_SendText 15
#define _MSGID_le_sms_SendPdu 16
#define _MSGID_le_sms_Delete 17
#define _MSGID_le_sms_GetFormat 18
#define _MSGID_le_sms_GetType 19
#define _MSGID_le_sms_GetCellBroadcastId 20
#define _MSGID_le_sms_GetCellBroadcastSerialNumber 21
#define _MSGID_le_sms_GetSenderTel 22
#define _MSGID_le_sms_GetTimeStamp 23
#define _MSGID_le_sms_GetUserdataLen 24
#define _MSGID_le_sms_GetText 25
#define _MSGID_le_sms_GetBinary 26
#define _MSGID_le_sms_GetUCS2 27
#define _MSGID_le_sms_GetPDU 28
#define _MSGID_le_sms_GetPDULen 29
#define _MSGID_le_sms_DeleteFromStorage 30
#define _MSGID_le_sms_CreateRxMsgList 31
#define _MSGID_le_sms_DeleteList 32
#define _MSGID_le_sms_GetFirst 33
#define _MSGID_le_sms_GetNext 34
#define _MSGID_le_sms_GetStatus 35
#define _MSGID_le_sms_MarkRead 36
#define _MSGID_le_sms_MarkUnread 37
#define _MSGID_le_sms_GetSmsCenterAddress 38
#define _MSGID_le_sms_SetSmsCenterAddress 39
#define _MSGID_le_sms_SetPreferredStorage 40
#define _MSGID_le_sms_GetPreferredStorage 41
#define _MSGID_le_sms_ActivateCellBroadcast 42
#define _MSGID_le_sms_DeactivateCellBroadcast 43
#define _MSGID_le_sms_ActivateCdmaCellBroadcast 44
#define _MSGID_le_sms_DeactivateCdmaCellBroadcast 45
#define _MSGID_le_sms_AddCellBroadcastIds 46
#define _MSGID_le_sms_RemoveCellBroadcastIds 47
#define _MSGID_le_sms_ClearCellBroadcastIds 48
#define _MSGID_le_sms_AddCdmaCellBroadcastServices 49
#define _MSGID_le_sms_RemoveCdmaCellBroadcastServices 50
#define _MSGID_le_sms_ClearCdmaCellBroadcastServices 51
#define _MSGID_le_sms_GetCount 52
#define _MSGID_le_sms_StartCount 53
#define _MSGID_le_sms_StopCount 54
#define _MSGID_le_sms_ResetCount 55
#define _MSGID_le_sms_EnableStatusReport 56
#define _MSGID_le_sms_DisableStatusReport 57
#define _MSGID_le_sms_IsStatusReportEnabled 58
#define _MSGID_le_sms_GetTpMr 59
#define _MSGID_le_sms_GetTpRa 60
#define _MSGID_le_sms_GetTpScTs 61
#define _MSGID_le_sms_GetTpDt 62
#define _MSGID_le_sms_GetTpSt 63


// Define type-safe pack/unpack functions for all enums, including included types

static inline bool le_sms_PackFormat
(
    uint8_t **bufferPtr,
    le_sms_Format_t value
)
{
    return le_pack_PackUint32(bufferPtr, (uint32_t)value);
}

static inline bool le_sms_UnpackFormat
(
    uint8_t **bufferPtr,
    le_sms_Format_t* valuePtr
)
{
    bool result;
    uint32_t value = 0;
    result = le_pack_UnpackUint32(bufferPtr, &value);
    if (result)
    {
        *valuePtr = (le_sms_Format_t)value;
    }
    return result;
}

static inline bool le_sms_PackType
(
    uint8_t **bufferPtr,
    le_sms_Type_t value
)
{
    return le_pack_PackUint32(bufferPtr, (uint32_t)value);
}

static inline bool le_sms_UnpackType
(
    uint8_t **bufferPtr,
    le_sms_Type_t* valuePtr
)
{
    bool result;
    uint32_t value = 0;
    result = le_pack_UnpackUint32(bufferPtr, &value);
    if (result)
    {
        *valuePtr = (le_sms_Type_t)value;
    }
    return result;
}

static inline bool le_sms_PackStatus
(
    uint8_t **bufferPtr,
    le_sms_Status_t value
)
{
    return le_pack_PackUint32(bufferPtr, (uint32_t)value);
}

static inline bool le_sms_UnpackStatus
(
    uint8_t **bufferPtr,
    le_sms_Status_t* valuePtr
)
{
    bool result;
    uint32_t value = 0;
    result = le_pack_UnpackUint32(bufferPtr, &value);
    if (result)
    {
        *valuePtr = (le_sms_Status_t)value;
    }
    return result;
}

static inline bool le_sms_PackLanguages
(
    uint8_t **bufferPtr,
    le_sms_Languages_t value
)
{
    return le_pack_PackUint32(bufferPtr, (uint32_t)value);
}

static inline bool le_sms_UnpackLanguages
(
    uint8_t **bufferPtr,
    le_sms_Languages_t* valuePtr
)
{
    bool result;
    uint32_t value = 0;
    result = le_pack_UnpackUint32(bufferPtr, &value);
    if (result)
    {
        *valuePtr = (le_sms_Languages_t)value;
    }
    return result;
}

static inline bool le_sms_PackCdmaServiceCat
(
    uint8_t **bufferPtr,
    le_sms_CdmaServiceCat_t value
)
{
    return le_pack_PackUint32(bufferPtr, (uint32_t)value);
}

static inline bool le_sms_UnpackCdmaServiceCat
(
    uint8_t **bufferPtr,
    le_sms_CdmaServiceCat_t* valuePtr
)
{
    bool result;
    uint32_t value = 0;
    result = le_pack_UnpackUint32(bufferPtr, &value);
    if (result)
    {
        *valuePtr = (le_sms_CdmaServiceCat_t)value;
    }
    return result;
}

static inline bool le_sms_PackStorage
(
    uint8_t **bufferPtr,
    le_sms_Storage_t value
)
{
    return le_pack_PackUint32(bufferPtr, (uint32_t)value);
}

static inline bool le_sms_UnpackStorage
(
    uint8_t **bufferPtr,
    le_sms_Storage_t* valuePtr
)
{
    bool result;
    uint32_t value = 0;
    result = le_pack_UnpackUint32(bufferPtr, &value);
    if (result)
    {
        *valuePtr = (le_sms_Storage_t)value;
    }
    return result;
}

static inline bool le_sms_PackErrorCode3GPP2
(
    uint8_t **bufferPtr,
    le_sms_ErrorCode3GPP2_t value
)
{
    return le_pack_PackUint32(bufferPtr, (uint32_t)value);
}

static inline bool le_sms_UnpackErrorCode3GPP2
(
    uint8_t **bufferPtr,
    le_sms_ErrorCode3GPP2_t* valuePtr
)
{
    bool result;
    uint32_t value = 0;
    result = le_pack_UnpackUint32(bufferPtr, &value);
    if (result)
    {
        *valuePtr = (le_sms_ErrorCode3GPP2_t)value;
    }
    return result;
}

static inline bool le_sms_PackErrorCode
(
    uint8_t **bufferPtr,
    le_sms_ErrorCode_t value
)
{
    return le_pack_PackUint32(bufferPtr, (uint32_t)value);
}

static inline bool le_sms_UnpackErrorCode
(
    uint8_t **bufferPtr,
    le_sms_ErrorCode_t* valuePtr
)
{
    bool result;
    uint32_t value = 0;
    result = le_pack_UnpackUint32(bufferPtr, &value);
    if (result)
    {
        *valuePtr = (le_sms_ErrorCode_t)value;
    }
    return result;
}

static inline bool le_mdmDefs_PackIpVersion
(
    uint8_t **bufferPtr,
    le_mdmDefs_IpVersion_t value
)
{
    return le_pack_PackUint32(bufferPtr, (uint32_t)value);
}

static inline bool le_mdmDefs_UnpackIpVersion
(
    uint8_t **bufferPtr,
    le_mdmDefs_IpVersion_t* valuePtr
)
{
    bool result;
    uint32_t value = 0;
    result = le_pack_UnpackUint32(bufferPtr, &value);
    if (result)
    {
        *valuePtr = (le_mdmDefs_IpVersion_t)value;
    }
    return result;
}

// Define pack/unpack functions for all structures, including included types


#endif // LE_SMS_MESSAGES_H_INCLUDE_GUARD
