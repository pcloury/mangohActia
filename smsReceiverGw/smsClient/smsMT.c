 /**
  * Sample code for Mobile Terminated SMS messages.
  *
  * Copyright (C) Sierra Wireless Inc.
  *
  *
  *
  */

#include "legato.h"
#include "interfaces.h"
#include "smsSample.h"
#include <stdio.h>
#include <string.h>
#include<stdlib.h>

#define  MESSAGE_FEEDBACK "Message from %s received"

static le_sms_RxMessageHandlerRef_t RxHdlrRef;
static le_sms_FullStorageEventHandlerRef_t FullStorageHdlrRef;
static char delim[] = ",";
static char path[] = "/home/root/coordinates.txt";


int writeCoordinatesTxt(int id, int latitude, int longitude)
{
   FILE * fp;
   /* open the file for writing*/
   fp = fopen(path,"r");
   LE_INFO("file openned");
   char delim[] = ",";
   int nbreCaracMax = 500;
   char latitudeLine[500];
   char longitudeLine[500];
   LE_INFO("test1");
   //line 1 txt: latitude, format : 0,0,0,0,0,0,0,0,0
   fgets(latitudeLine, nbreCaracMax , fp);
   LE_INFO("test2");
   //line 2 txt: longitude, same
   fgets(longitudeLine, nbreCaracMax , fp);
   //LE_INFO("longitudeLine %s", longitudeLine);
   LE_INFO("test2");
   //coordinates arrays in int
   char latitudeArray[10][50];
   char longitudeArray[10][50];
    
    //
    strcpy(latitudeArray[0],strtok(latitudeLine,delim));

    for (int i =1; i<10; i++){
        strcpy(latitudeArray[i],strtok(NULL,delim));
    }

    char newLatitude[50];
    sprintf(newLatitude, "%d", latitude);
    strcpy(latitudeArray[id],newLatitude);


    char newLatitudeLine[500] = "";

    strcat(newLatitudeLine,latitudeArray[0]);
    for (int j = 1; j<10; j++)
    {
        strcat(newLatitudeLine,",");
        strcat(newLatitudeLine,latitudeArray[j]);
        
    }
    
    strcpy(longitudeArray[0],strtok(longitudeLine,delim));
    for (int k =1; k<10; k++){
        strcpy(longitudeArray[k],strtok(NULL,delim));
    }
    
    char newLongitude[50];
    sprintf(newLongitude, "%d", longitude);
    strcpy(longitudeArray[id],newLongitude);
    
    char newLongitudeLine[500] = "";
    strcat(newLongitudeLine,longitudeArray[0]);
    for (int l = 1; l<10; l++)
    {
        strcat(newLongitudeLine,",");
        strcat(newLongitudeLine,longitudeArray[l]);
        
    }

    printf("%s",newLatitudeLine);
    printf("%s",newLongitudeLine);
    rewind(fp);

    LE_INFO("test3");
    fprintf(fp,"%s",newLatitudeLine);
    fprintf(fp,"%s",newLongitudeLine);
    
    fclose (fp);
    return 0;
}

/**
 * Handler function for SMS message reception.
 *
 */
//---------------------
static void RxMessageHandler
(
    le_sms_MsgRef_t msgRef,
    void*            contextPtr
)
{
    le_result_t  res;
    char         tel[LE_MDMDEFS_PHONE_NUM_MAX_BYTES];
    char         timestamp[LE_SMS_TIMESTAMP_MAX_BYTES] = {0};
    char         text[LE_SMS_TEXT_MAX_BYTES] = {0};
    char         textReturn[LE_SMS_TEXT_MAX_BYTES] = {0};

    LE_INFO("A New SMS message is received with ref.%p", msgRef);

    if (le_sms_GetFormat(msgRef) == LE_SMS_FORMAT_TEXT)
    {
        res = le_sms_GetSenderTel(msgRef, tel, sizeof(tel));
        if(res != LE_OK)
        {
            LE_ERROR("le_sms_GetSenderTel has failed (res.%d)!", res);
        }
        else
        {
            LE_INFO("Message is received from %s.", tel);
        }

        res = le_sms_GetTimeStamp(msgRef, timestamp, sizeof(timestamp));
        if(res != LE_OK)
        {
            LE_ERROR("le_sms_GetTimeStamp has failed (res.%d)!", res);
        }
        else
        {
            LE_INFO("Message timestamp is %s.", timestamp);
        }

        res = le_sms_GetText(msgRef, text, sizeof(text));
        if(res != LE_OK)
        {
            LE_ERROR("le_sms_GetText has failed (res.%d)!", res);
        }
        else
        {
            LE_INFO("Message content: \"%s\"", text);
            char *id = strtok(text, delim);
            char *latitudeStr = strtok(NULL,delim);
            char *longitudeStr = strtok(NULL,delim);
            
	        LE_INFO("latitude %s",latitudeStr);
	        int latitude;
	        int longitude;
	    
	        sprintf(latitudeStr, "%d", latitude);
	        sprintf(longitudeStr,"%d", longitude);
            //LE_INFO("try to write coordinates on txt");
            //writeCoordinatesTxt(0,latitude,longitude);
            
        }

        snprintf(textReturn, sizeof(textReturn), MESSAGE_FEEDBACK, tel);

        // Return a message to sender with phone number include (see smsMO.c file)
        //res = smsmo_SendMessage(tel, textReturn);
        if (res != LE_OK)
        {
            LE_ERROR("SmsMoMessage has failed (res.%d)!", res);
        }
        else
        {
            LE_INFO("the message has been successfully sent.");
        }

        res = le_sms_DeleteFromStorage(msgRef);
        if(res != LE_OK)
        {
            LE_ERROR("le_sms_DeleteFromStorage has failed (res.%d)!", res);
        }
        else
        {
            LE_INFO("the message has been successfully deleted from storage.");
        }
    }
    else
    {
        LE_WARN("Warning! I read only Text messages!");
    }

    le_sms_Delete(msgRef);
}

//--------------------------------------------------------------------------------------------------
/**
 * Handler function for SMS storage full message indication.
 *
 */
//--------------------- -----------------------------------------------------------------------------
static void StorageMessageHandler
(
    le_sms_Storage_t  storage,
    void*            contextPtr
)
{
    LE_INFO("A Full storage SMS message is received. Type of full storage %d", storage);
}


//--------------------------------------------------------------------------------------------------
/**
 * This function installs an handler for message reception.
 *
 * @return LE_FAULT  The function failed.
 * @return LE_OK     The function succeed.
 */
//--------------------------------------------------------------------------------------------------
le_result_t smsmt_Receiver
(
    void
)
{
    RxHdlrRef = le_sms_AddRxMessageHandler(RxMessageHandler, NULL);
    if (!RxHdlrRef)
    {
        LE_ERROR("le_sms_AddRxMessageHandler has failed!");
        return LE_FAULT;
    }
    else
    {
        return LE_OK;
    }
}

//--------------------------------------------------------------------------------------------------
/**
 * This function installs an handler for storage message indication.
 *
 * @return LE_FAULT  The function failed.
 * @return LE_OK     The function succeed.
 */
//--------------------------------------------------------------------------------------------------
le_result_t smsmt_MonitorStorage
(
    void
)
{
    FullStorageHdlrRef = le_sms_AddFullStorageEventHandler(StorageMessageHandler, NULL);
    if (!FullStorageHdlrRef)
    {
        LE_ERROR("le_sms_AddFullStorageEventHandler has failed!");
        return LE_FAULT;
    }
    else
    {
        return LE_OK;
    }
}


//--------------------------------------------------------------------------------------------------
/**
 * This function remove the handler for message reception.
 *
 */
//--------------------------------------------------------------------------------------------------
void smsmt_HandlerRemover
(
    void
)
{
    le_sms_RemoveRxMessageHandler(RxHdlrRef);
}

//--------------------------------------------------------------------------------------------------
/**
 * This function remove the handler for storage message indication.
 *
 */
//--------------------------------------------------------------------------------------------------
void smsmt_StorageHandlerRemover
(
    void
)
{
    le_sms_RemoveFullStorageEventHandler(FullStorageHdlrRef);
}
