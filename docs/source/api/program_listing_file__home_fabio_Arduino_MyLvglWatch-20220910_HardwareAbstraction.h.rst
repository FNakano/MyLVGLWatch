
.. _program_listing_file__home_fabio_Arduino_MyLvglWatch-20220910_HardwareAbstraction.h:

Program Listing for File HardwareAbstraction.h
==============================================

|exhale_lsh| :ref:`Return to documentation for file <file__home_fabio_Arduino_MyLvglWatch-20220910_HardwareAbstraction.h>` (``/home/fabio/Arduino/MyLvglWatch-20220910/HardwareAbstraction.h``)

.. |exhale_lsh| unicode:: U+021B0 .. UPWARDS ARROW WITH TIP LEFTWARDS

.. code-block:: cpp

   #ifndef HARDWAREABSTRACTION_H
   
   #define HARDWAREABSTRACTION_H
   
   #include "config.h"
   
   void setupHardware();
   
   void setDisplayBrightness(uint8_t b);
   
   void turnDisplayOn();
   
   void turnDisplayOff();
   
   void keepActive(bool newValue);
   
   bool keepActive();
   
   const char *hourMinute();
   
   const char *ymd();
   
   int8_t batPercentage();
   
   void isr();
   
   void tryDeepSleep();
   
   #endif
