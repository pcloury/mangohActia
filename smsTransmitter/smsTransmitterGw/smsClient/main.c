 /**
  * Main functions to use the SMS sample codes.
  *
  * Copyright (C) Sierra Wireless Inc.
  *
  *
  *
  */

#include "legato.h"
#include "interfaces.h"
#include "smsSample.h"
#include "gnss.h"
#include "string.h"
#include "stdlib.h"


const char tel[] = "+33750820078";
const char tel2[] = "+33601364351";
const char gateway[] = "+7000023024202";
char* id = "0";

void loopSend(){
  le_result_t res;
  le_gnss_SampleRef_t positionSampleRef;
  le_result_t result;
  le_result_t res2;

  double  currentLat;
  double  currentLon;
  
	
  int32_t latitude;
  int32_t longitude;
  int32_t hAccuracy;

  int period = 0;

  while(1)
  {
    positionSampleRef = le_gnss_GetLastSampleRef();
    result = le_gnss_GetLocation(positionSampleRef, &latitude, &longitude, &hAccuracy);
    if (result != LE_OK)
    {
        LE_ERROR("Failed to get last registered location");
    }
    LE_INFO("latitude : %d", latitude);
    LE_INFO("longitude : %d", longitude);
    LE_INFO("precision : %d", hAccuracy);
    char latitudeString[50];
    char longitudeString[50];
    char messageToSend[50];

    currentLat = (double)latitude/1000000.0;
    currentLon = (double)longitude/1000000.0;

    //conversion coordinates from int to str
    sprintf(latitudeString, "%lf", currentLat);
    sprintf(longitudeString, "%lf", currentLon);


    //message to send creation. Format: MangohId,latitude,longitude
    
    strcat(messageToSend,id);
    strcat(messageToSend,",");
    strcat(messageToSend,latitudeString);
    strcat(messageToSend,",");
    strcat(messageToSend,longitudeString);
    

    //adapatation of the send frequency depending on the gnss precision

    if (hAccuracy <= 10) {
      period = 5;
      LE_INFO("Wait for 5 Sec");
      }
    
    else if (hAccuracy < 25 && hAccuracy > 10){
      period = 10;
      LE_INFO("Wait for 10 Sec");
    }
      
    else {
      period = 20;
      LE_INFO("Wait for 20 Sec");
    }


    res = smsmo_SendMessage(tel, messageToSend);
    res = smsmo_SendMessage(tel2, messageToSend);
    //res2 = smsmo_SendMessage(gateway, messageToSend);

    //reset messageToSend
    strcpy(messageToSend,"");

    sleep(period);
  }

}


//--------------------------------------------------------------------------------------------------
/**
 *  App init
 *
 */
//--------------------------------------------------------------------------------------------------
COMPONENT_INIT
{
    LE_INFO("Start SMS loop send");
    loopSend(10);
    
}
