
.. _program_listing_file__home_fabio_Arduino_MyLvglWatch-20220910_DateTimeScreen.h:

Program Listing for File DateTimeScreen.h
=========================================

|exhale_lsh| :ref:`Return to documentation for file <file__home_fabio_Arduino_MyLvglWatch-20220910_DateTimeScreen.h>` (``/home/fabio/Arduino/MyLvglWatch-20220910/DateTimeScreen.h``)

.. |exhale_lsh| unicode:: U+021B0 .. UPWARDS ARROW WITH TIP LEFTWARDS

.. code-block:: cpp

   #ifndef DATETIMESCREEN_H
   
   #define DATETIMESCREEN_H
   
   #include "config.h" // choose watch version
   
   void updateScreenData ();
   
   void buildWatchFace ();
   
   void displayWatchFace();
   
   // not public
   
   static void infoEventHandler(lv_obj_t *obj, lv_event_t event);
   static void timeEventHandler(lv_obj_t *obj, lv_event_t event);
   static void rollerEventHandler(lv_obj_t *obj, lv_event_t event);
   static void leftButtonEventHandler(lv_obj_t *obj, lv_event_t event);
   static void rightButtonEventHandler(lv_obj_t *obj, lv_event_t event);
   static void createRoller(lv_obj_t *cont);
   static void createTimeButton (lv_obj_t *cont);
   static void createInfoBar (lv_obj_t *cont);
   static void createSideButtons (lv_obj_t *cont);
   #endif
