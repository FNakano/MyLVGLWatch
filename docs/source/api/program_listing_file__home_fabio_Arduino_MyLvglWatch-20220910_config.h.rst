
.. _program_listing_file__home_fabio_Arduino_MyLvglWatch-20220910_config.h:

Program Listing for File config.h
=================================

|exhale_lsh| :ref:`Return to documentation for file <file__home_fabio_Arduino_MyLvglWatch-20220910_config.h>` (``/home/fabio/Arduino/MyLvglWatch-20220910/config.h``)

.. |exhale_lsh| unicode:: U+021B0 .. UPWARDS ARROW WITH TIP LEFTWARDS

.. code-block:: cpp

   
   // => Hardware select
   // #define LILYGO_WATCH_2019_WITH_TOUCH     // To use T-Watch2019 with touchscreen, please uncomment this line
   // #define LILYGO_WATCH_2019_NO_TOUCH          // To use T-Watch2019 Not touchscreen , please uncomment this line
   // #define LILYGO_WATCH_2020_V1             //To use T-Watch2020, please uncomment this line
   // #define LILYGO_WATCH_2020_V2             //To use T-Watch2020 V2, please uncomment this line
   #define LILYGO_WATCH_2020_V3             //To use T-Watch2020 V3, please uncomment this line
   
   
   // NOT SUPPORT ...
   // NOT SUPPORT ...
   
   // => Function select
   #define LILYGO_WATCH_LVGL                   //To use LVGL, you need to enable the macro LVGL
   
   #include <LilyGoWatch.h>
