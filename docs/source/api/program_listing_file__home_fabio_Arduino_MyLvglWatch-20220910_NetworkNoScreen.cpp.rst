
.. _program_listing_file__home_fabio_Arduino_MyLvglWatch-20220910_NetworkNoScreen.cpp:

Program Listing for File NetworkNoScreen.cpp
============================================

|exhale_lsh| :ref:`Return to documentation for file <file__home_fabio_Arduino_MyLvglWatch-20220910_NetworkNoScreen.cpp>` (``/home/fabio/Arduino/MyLvglWatch-20220910/NetworkNoScreen.cpp``)

.. |exhale_lsh| unicode:: U+021B0 .. UPWARDS ARROW WITH TIP LEFTWARDS

.. code-block:: cpp

   
   #include "NetworkNoScreen.h"
   /* WiFi settings change ssid and password 
    * according to your local setup.
    */
   static const char *ssid            = "NameOfNetworkTP";   
   static const char *password        = "0123456789";        
   /* NTP (Network Time Protocol) settings */
   static const char *ntpServer       = "pool.ntp.org";  
   static const long  gmtOffset_sec   = -3*3600;         
   static const int   daylightOffset_sec = 0;            
   static char ip[]="255.255.255.255"; 
   void wiFiOff () 
   /* Code do turn Wifi off.
    * based on: https://www.mischianti.org/2021/03/06/esp32-practical-power-saving-manage-wifi-and-cpu-1/
   */
   {
       WiFi.disconnect(true);
       WiFi.mode(WIFI_OFF);
       adc_power_off();
   }
   
   int wiFiOn () {
       int nWiFiProbe = 0;
       int MAX_WIFIPROBE = 20;
       // turn ESP32 WiFi on and connect to Access Point
       Serial.printf("Trying to connect to %s \n", ssid);
   
       adc_power_on();
       WiFi.mode(WIFI_STA);
       WiFi.begin(ssid, password);
       while (WiFi.status() != WL_CONNECTED) {
           delay(500);
           Serial.print(".");
           //tft->print(".");
           if (nWiFiProbe>MAX_WIFIPROBE) {
               wiFiOff();
               return WIFI_FAILED_TO_CONNECT;
           }
           nWiFiProbe++;
       }
       Serial.println(" CONNECTED");
       return WIFI_CONNECTED;
   }
   
   int setClockNTP() 
   /*
    * Turn radio (WiFi) on, connect to AP, requests
    * current time from NTP, store time into RTC, 
    * turn radio off.
    */
   {
       TTGOClass *ttgo = TTGOClass::getWatch();    // pointer to watch internals
       PCF8563_Class *rtc = ttgo->rtc;             // pointer to RTC (real-time clock) 
   
       if (wiFiOn()) {
         //init, get current time from NTP server and store it in ESP32 variable.
         configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
     
         struct tm timeinfo;
         if (!getLocalTime(&timeinfo)) {
             Serial.println("Failed to obtain time.");
             wiFiOff();
             return WIFI_NTP_FAILED;
         }
         Serial.println(&timeinfo, "%A, %B %d %Y %H:%M:%S");
         rtc->syncToRtc(); // write current time into watch RTC (PCF8563)
         return WIFI_NTP_CLOCK_SET;
       }
       wiFiOff();
       return WIFI_NTP_FAILED;
   }
   
   const char * getIP () {
     IPAddress ipToPrint = WiFi.localIP();
     sprintf(ip, "%u.%u.%u.%u", ipToPrint[0], ipToPrint[1], ipToPrint[2], ipToPrint[3]);
     return ip;
   }
