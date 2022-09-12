
.. _program_listing_file__home_fabio_Arduino_MyLvglWatch-20220910_NetworkNoScreen.h:

Program Listing for File NetworkNoScreen.h
==========================================

|exhale_lsh| :ref:`Return to documentation for file <file__home_fabio_Arduino_MyLvglWatch-20220910_NetworkNoScreen.h>` (``/home/fabio/Arduino/MyLvglWatch-20220910/NetworkNoScreen.h``)

.. |exhale_lsh| unicode:: U+021B0 .. UPWARDS ARROW WITH TIP LEFTWARDS

.. code-block:: cpp

   #ifndef NETWORKNOSCREEN_H
   
   #define NETWORKNOSCREEN_H
   
   #include "config.h"
   #include <WiFi.h>
   #include "time.h"
   #include "driver/adc.h"   // adc functions. Needed to turn WiFi off.
   
   #define WIFI_FAILED_TO_CONNECT 0
   #define WIFI_CONNECTED 1
   
   #define WIFI_NTP_CLOCK_SET 1
   #define WIFI_NTP_FAILED 0
   
   void wiFiOff ();
   
   int wiFiOn ();
   
   
   int setClockNTP();
   
   const char *getIP ();
   
   #endif
