
.. _program_listing_file__home_fabio_Arduino_MyLvglWatch-20220910_DateTimeScreen.cpp:

Program Listing for File DateTimeScreen.cpp
===========================================

|exhale_lsh| :ref:`Return to documentation for file <file__home_fabio_Arduino_MyLvglWatch-20220910_DateTimeScreen.cpp>` (``/home/fabio/Arduino/MyLvglWatch-20220910/DateTimeScreen.cpp``)

.. |exhale_lsh| unicode:: U+021B0 .. UPWARDS ARROW WITH TIP LEFTWARDS

.. code-block:: cpp

   
   #include "DateTimeScreen.h"
   #include "WSScreen.h"
   #include "HardwareAbstraction.h"
   #include "Styles.h"
   
   int recordEvent (const char *desc); // the only function from FSWebServerNoScreen I need in this file
   
   
   /* after buildWatchFace() execution, is a pointer 
    * to the LVGL label that displays time. 
    * file scope variables.
    */
   static lv_obj_t *cont = NULL;       
   static lv_obj_t *timeLabel = NULL;  
   static lv_obj_t *infoLabel = NULL;  
   static lv_obj_t *leftLabel = NULL;  
   static lv_obj_t *rightLabel = NULL;  
   static int8_t curLev=0; 
   //#if !defined(DOXYGEN_SHOULD_SKIP_THIS)
   
   /* SCREEN DATA UPDATER */
   void updateScreenData () {
   
   #if 1
       lv_label_set_text(timeLabel, hourMinute());  // display time without seconds
       char buf[64]; // buffer for the infolabel
       sprintf (buf, "%s  %3d%s", ymd(), batPercentage(), "%");
       lv_label_set_text(infoLabel, buf);  // display info
       recordEvent ("Ver Hora ; atomico");
   #else
       // test strings - to isolate from hardware abstraction
       lv_label_set_text(timeLabel, "22:22");  // display time without seconds
       lv_label_set_text(infoLabel, "2022-09-01  70%");  // display info
   #endif
   
   }
   
   /* EVENT HANDLERS*/
   
   static void infoEventHandler(lv_obj_t *obj, lv_event_t event)
   {
       if (event == LV_EVENT_SHORT_CLICKED) {
           buildWatchFace3();
           updateScreenData3();
           Serial.printf("Clicked on infobar.\n"); 
       }
   }
   
   static void timeEventHandler(lv_obj_t *obj, lv_event_t event)
   // event handler for the time button/label
   {
       TTGOClass *ttgo = TTGOClass::getWatch();    // pointer to watch internals
       if (event == LV_EVENT_SHORT_CLICKED) {
           recordEvent ("Increase Brightness ; atomico");
           curLev=(curLev>206)?255:curLev+50;
           setDisplayBrightness(curLev);
           updateScreenData();
       }
   }
   
   static void rollerEventHandler(lv_obj_t *obj, lv_event_t event)
   {
       if (event == LV_EVENT_SHORT_CLICKED) {
           Serial.printf(" Short clicked\n");
           char buf[64];
           lv_roller_get_selected_str(obj, buf, sizeof(buf));
           lv_label_set_text(infoLabel, strcat(buf, " ; iniciado"));  // display info
           recordEvent(buf);
       }
       /*There could be other events that should not trigger anything. */
   }
   
   static void leftButtonEventHandler(lv_obj_t *obj, lv_event_t event)
   {
       if (event == LV_EVENT_SHORT_CLICKED) {
           char buf[]="Rodar ; iniciado";
           recordEvent(buf);
           lv_label_set_text(infoLabel, buf);  // display info
           Serial.printf("Clicked on left button.\n"); 
       }
   }
   
   static void rightButtonEventHandler(lv_obj_t *obj, lv_event_t event)
   {
       if (event == LV_EVENT_SHORT_CLICKED) {
           char buf[]="Esperar ; iniciado";
           recordEvent(buf);
           lv_label_set_text(infoLabel, buf);  // display info
           Serial.printf("Clicked on right button.\n"); 
       }
   }
   
   /* CREATE OBJECTS (button, roller, label, ...;
    * set event handler, set style and set position in the screen */
   
   LV_FONT_DECLARE(lv_font_montserrat_14);
   LV_FONT_DECLARE(lv_font_montserrat_28);
   
   static void createRoller(lv_obj_t *cont) {
       lv_obj_t *roller1 = lv_roller_create(cont, NULL);
       lv_roller_set_options(roller1,
                           "Caminhar\n"
                           // "Esperar\n" // right button
                           // "Rodar\n" // left button
                           "Oficina\n"
                           "Comer\n"
                           "Casa\n"
                           "Passear\n"
                           "Comprar\n"
                           "Exercitar\n"
                           "Descansar\n"
                           "Grupo",
                           LV_ROLLER_MODE_INIFINITE); // not nice if in NORMAL mode.
   
       lv_obj_add_style(roller1, LV_OBJ_PART_MAIN, getRollerStyle());  // apply style
       lv_roller_set_visible_row_count(roller1, 4);
       lv_obj_align(roller1, lv_scr_act(), LV_ALIGN_IN_BOTTOM_RIGHT, 0, 0); // https://docs.lvgl.io/latest/en/html/widgets/obj.html?highlight=alignment#alignment
       lv_obj_set_event_cb(roller1, rollerEventHandler);
   }
   
   static void createTimeButton (lv_obj_t *cont) {
       lv_obj_t *timeButton = lv_btn_create(cont, NULL); // create a button to put the label to display time inside it.
       lv_obj_set_event_cb(timeButton, timeEventHandler);            //  
       timeLabel = lv_label_create(timeButton, NULL);                 // create a label inside the button and get a pointer to it.
       lv_label_set_align(timeLabel, LV_ALIGN_CENTER);
   
       lv_obj_add_style(timeButton, LV_OBJ_PART_MAIN, getTimeStyle());  // apply style to the button. label style is set by "inheritance"
       lv_obj_set_size(timeButton,240,100);
       lv_obj_align(timeButton, cont, LV_ALIGN_CENTER, 0, -50);      // place the button relative to the display area
   }
   
   static void createInfoBar (lv_obj_t *cont) {
       lv_obj_t *infoButton = lv_btn_create(cont, NULL); // create a button to put the label to display info inside it.
       lv_obj_set_event_cb(infoButton, infoEventHandler);            //  
       infoLabel = lv_label_create(infoButton, NULL);                 // create a label inside the button and get a pointer to it.
       lv_label_set_align(infoLabel, LV_ALIGN_CENTER);
   
       lv_obj_add_style(infoButton, LV_OBJ_PART_MAIN, getInfoStyle());  // apply style to the button. label style is set by "inheritance"
       lv_obj_set_size(infoButton,240,30);
       lv_obj_align(infoButton, cont, LV_ALIGN_IN_TOP_LEFT, 0, 0);      // place the button relative to the display area
     
   }
   
   void createSideButtons (lv_obj_t *cont) {
       lv_obj_t *leftButton = lv_btn_create(cont, NULL); // create a button to put the label to display info inside it.
       lv_obj_set_event_cb(leftButton, leftButtonEventHandler);            //  
       leftLabel = lv_label_create(leftButton, NULL);                 // create a label inside the button and get a pointer to it.
       lv_label_set_align(leftLabel, LV_ALIGN_CENTER);
       lv_label_set_text(leftLabel, LV_SYMBOL_PLAY);  // fixed image
       lv_obj_add_style(leftButton, LV_OBJ_PART_MAIN, getSideButtonStyle());  // apply style to the button. label style is set by "inheritance"
   
       lv_obj_set_size(leftButton,40,120);
       lv_obj_align(leftButton, cont, LV_ALIGN_IN_BOTTOM_LEFT, 0, 0);      // place the button relative to the display area
       
       lv_obj_t *rightButton = lv_btn_create(cont, NULL); // create a button to put the label to display info inside it.
       lv_obj_set_event_cb(rightButton, rightButtonEventHandler);            //  
       rightLabel = lv_label_create(rightButton, NULL);                 // create a label inside the button and get a pointer to it.
       lv_label_set_align(rightLabel, LV_ALIGN_CENTER);
       lv_label_set_text(rightLabel, LV_SYMBOL_PAUSE);  // fixed image
   
       lv_obj_add_style(rightButton, LV_OBJ_PART_MAIN, getSideButtonStyle());  // apply style to the button. label style is set by "inheritance"
       lv_obj_set_size(rightButton,40,120);
       lv_obj_align(rightButton, cont, LV_ALIGN_IN_BOTTOM_LEFT, 0+45, 0);      // place the button relative to the display area
     
   }
   
   void buildWatchFace () {
   
       //lv_obj_t *cont = lv_scr_act(); // get a pointer to the current screen
       cont=lv_obj_create (NULL, NULL); // https://docs.lvgl.io/latest/en/html/widgets/obj.html#screens
       lv_obj_add_style(cont, LV_OBJ_PART_MAIN, getBkgdStyle());  // apply style
   
       createTimeButton(cont);
   
       /*info bar on the top of the screen*/
       createInfoBar(cont);
       /* activity roller */
       /* rola (para selecionar) e então clica!!! */
       createRoller(cont);
   
       /*buttons at the sides of the roller. */
       createSideButtons(cont);    
   }
   
   void displayWatchFace() {
       lv_scr_load(cont); // load the screen onto the display.
       if (curLev==0) curLev=10;
       setDisplayBrightness(curLev);
       setCpuFrequencyMhz(100); // need more than 10MHz to get fluid navigation on roller.
     
   }
   
   //#endif
