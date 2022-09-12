
.. _program_listing_file__home_fabio_Arduino_MyLvglWatch-20220910_Styles.h:

Program Listing for File Styles.h
=================================

|exhale_lsh| :ref:`Return to documentation for file <file__home_fabio_Arduino_MyLvglWatch-20220910_Styles.h>` (``/home/fabio/Arduino/MyLvglWatch-20220910/Styles.h``)

.. |exhale_lsh| unicode:: U+021B0 .. UPWARDS ARROW WITH TIP LEFTWARDS

.. code-block:: cpp

   #ifndef STYLES_H
   #define STYLES_H
   #include "config.h"
   
   void setupStyles ();
   lv_style_t *getBkgdStyle();
   lv_style_t *getTimeStyle();
   lv_style_t *getInfoStyle();
   lv_style_t *getRollerStyle();
   lv_style_t *getSideButtonStyle();
   lv_style_t *getFSSButtonStyle();
   #endif
