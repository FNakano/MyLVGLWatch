
.. _program_listing_file__home_fabio_Arduino_MyLvglWatch-20220910_FSWebServerNoScreen.h:

Program Listing for File FSWebServerNoScreen.h
==============================================

|exhale_lsh| :ref:`Return to documentation for file <file__home_fabio_Arduino_MyLvglWatch-20220910_FSWebServerNoScreen.h>` (``/home/fabio/Arduino/MyLvglWatch-20220910/FSWebServerNoScreen.h``)

.. |exhale_lsh| unicode:: U+021B0 .. UPWARDS ARROW WITH TIP LEFTWARDS

.. code-block:: cpp

   #ifndef FSWEBSERVERNOSCREEN_H
   
   #define FSWEBSERVERNOSCREEN_H
   
   void startWebServerFS();
   
   void closeWebServerandSPIFFSandWiFi();
   
   bool webServerFSTestAndHandle(void);
   #endif
