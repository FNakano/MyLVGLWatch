/*
 * Compilation PASSED.
 * HOOKED TO FTPNOSCREEN
 * HOOKED TO DATETIMESCREEN
 * TOGGLE BUTTON OK
 * NOT TESTED
 * 2022-06-04
 * 2022-08-31 - TESTING
 * 2022-08-31 - TESTED OK
 * 2022-09-01 - Fixed association between toggle and WebServer state, 
 *              Moved webServerFSTestAndHandle() out of loop() function to LVGL event loop.
 * 2022-09-04 - Adjusted wifi.ip call to match my convention
 * 
 */

#include "DateTimeScreen.h"
#include "FSWebServerNoScreen.h" // reuse the screen to try out FSWebServer.
#include "HardwareAbstraction.h"
#include "NetworkNoScreen.h"
#include "Styles.h"

int recordEvent (const char *desc); // the only function from FSWebServerNoScreen I need in this file

static lv_obj_t *fscont=NULL;  /**< reference to the screen (container of graphical objects) */
static lv_obj_t *toggleLabel=NULL;         /**< reference to graphical object: label to show if wifi is turned on/off. */
static lv_obj_t *infoLabel = NULL;  /**< reference to graphical object: top bar - shows time and battery level. */
static lv_obj_t *statusLabel = NULL;  /**< reference to graphical object: label to show watch's IP address. */

static void lv_update_task(struct _lv_task_t *);

void updateScreenData3 () {
    char buf[64]; // buffer for the infolabel
    sprintf (buf, "%s      %3d%s", hourMinute(), batPercentage(), "%");
    lv_label_set_text(infoLabel, buf);  // display battery level.
    lv_label_set_text(statusLabel, getIP());  // display IP
}

lv_task_t *webserver_task=NULL;

static void lv_webserver_task(struct _lv_task_t *) {
/*  
 *   Surrounded updateScreenData3 call with lv_update_task to comply with 
 *   lvgl task callback prototype (https://docs.lvgl.io/latest/en/html/overview/task.html)
 */
  webServerFSTestAndHandle();
}


static void lv_update_task(struct _lv_task_t *) {
/*  
 *   Surrounded updateScreenData3 call with lv_update_task to comply with 
 *   lvgl task callback prototype (https://docs.lvgl.io/latest/en/html/overview/task.html)
 */
  updateScreenData3 ();
}

static void button_event_handler(lv_obj_t *obj, lv_event_t event)
/*
 * Handles touch (click) events on the button in this screen. 
*/
{
    if (event == LV_EVENT_CLICKED) {
      /* this event happens to toggle and std buttons. */
        //closeFTPandSPIFFSandWiFi(); // turn FTP server off if exits the screen
        if (webserver_task) {
          recordEvent ("Web server ; terminado");
          lv_task_del(webserver_task); // remove webserver from event loop.
          webserver_task=NULL;
        }
        closeWebServerandSPIFFSandWiFi();
        keepActive(false);
        updateScreenData3();
        Serial.printf("Exit Clicked\n"); 
        updateScreenData();
        displayWatchFace(); // não reconstrói, apenas mostra.
    }
}


static void toggle_event_handler(lv_obj_t *obj, lv_event_t event)
/*
 * Handles touch (click) events on the toggle button in this screen. 
*/
{
    if (event == LV_EVENT_VALUE_CHANGED) {
        Serial.printf("Toggled\n");
        switch (lv_btn_get_state(obj)) {
          case LV_BTN_STATE_CHECKED_RELEASED: // checked and released
            lv_label_set_text(toggleLabel, "Turn Server off");                 // set button 2 label text.
            // startFTP();
            startWebServerFS();
            setClockNTP();    // if there is wifi then adjust date and time.
            recordEvent ("Web server ; iniciado");
            webserver_task=lv_task_create(lv_webserver_task, 1, LV_TASK_PRIO_MID, NULL); // insert the callback function into the task/event loop
            keepActive(true);
            break;
          case LV_BTN_STATE_RELEASED: // unchecked and released
            if (webserver_task) {
              recordEvent ("Web server ; terminado");
              lv_task_del(webserver_task); // remove webserver from event loop.
              webserver_task=NULL;
            }
            lv_label_set_text(toggleLabel, "Turn Server on");                 // set button 2 label text.
            //closeFTPandSPIFFSandWiFi();
            closeWebServerandSPIFFSandWiFi();
            keepActive(false);
            break;
        }
        updateScreenData3();
    }
}

void createFSSInfoBar (lv_obj_t *cont) {
  /*
   * Unable to create other function with same name.
   * 
   */
    lv_obj_t *infoButton = lv_btn_create(cont, NULL); // create a button to put the label to display info inside it.
    lv_obj_set_event_cb(infoButton, NULL);            // will not respond to events. 
    infoLabel = lv_label_create(infoButton, NULL);                 // create a label inside the button and get a pointer to it.
    lv_label_set_align(infoLabel, LV_ALIGN_CENTER);

    lv_obj_add_style(infoButton, LV_OBJ_PART_MAIN, getInfoStyle());  // apply style to the button. label style is set by "inheritance"
    lv_obj_set_size(infoButton,240,30);
    lv_obj_align(infoButton, cont, LV_ALIGN_IN_TOP_LEFT, 0, 0);      // place the button relative to the display area
  
}

void createFSSStatusLabel (lv_obj_t *cont) {
    statusLabel = lv_label_create(cont, NULL);
    lv_obj_add_style(statusLabel, LV_OBJ_PART_MAIN, getInfoStyle());  // apply style to the label. label style is set by "inheritance"
    lv_label_set_text(statusLabel, "T-Watch");
    lv_obj_align(statusLabel, NULL, LV_ALIGN_CENTER, 0, 0);
  
}

void createFSSButtons (lv_obj_t *cont) {
  // button 1
    lv_obj_t *label;  // label - auxiliary pointer to some button's label.
    lv_obj_t *btn1 = lv_btn_create(cont, NULL);  // create button 1. Its parent is the container
    lv_obj_set_event_cb(btn1, button_event_handler);            // button 1 event handler
    lv_obj_add_style(btn1, LV_OBJ_PART_MAIN, getFSSButtonStyle());  // apply style to the label. label style is set by "inheritance"
    lv_obj_set_size(btn1,200,30);
    lv_obj_align(btn1, NULL, LV_ALIGN_CENTER, 0, -50);   // button 1 text alignment
    label = lv_label_create(btn1, NULL);                 // create a label inside button 1 and get a pointer to it.
    lv_label_set_text(label, "Exit screen");                  // set button 1 label text

  // button 2 (checkbutton)
    lv_obj_t *btn2 = lv_btn_create(cont, NULL);
    lv_obj_set_event_cb(btn2, toggle_event_handler); 
    lv_obj_add_style(btn2, LV_OBJ_PART_MAIN, getFSSButtonStyle());  // apply style to the label. label style is set by "inheritance"
    lv_obj_set_size(btn2,200,30);
    lv_obj_align(btn2, NULL, LV_ALIGN_CENTER, 0, 50);
    lv_btn_set_checkable(btn2, true);                    // button 2 is a checkbutton
    toggleLabel = lv_label_create(btn2, NULL);                 // create a label inside button 2 and get a pointer to it.
    lv_label_set_text(toggleLabel, "Turn Server on");                 // set button 2 label text.
}

void buildWatchFace3 () {
/*
 * Build a watch face (a screen) containing one button,
 * one label and one toggle.
 * Click on the button to display current time in the label.
 * Click on the toggle to change its state (color).
 * Events are also logged in the serial monitor.
 * Shows how to create and load screen and container objects
 * It seems slower than getting current screen and modifying it.
 * 
 * This watch face is quite different of DateTimeScreen.
 * This code creates a new screen, style widgets, place them,
 * insert the screen update function as a task in the LVGL event loop
 * and (finally) loads the screen on the display 
 * (LVGL lingo/parlance: display = physical display device;
 * screen = representation of the display in which widgets can be set;
 * it is possible to have many screens but only one is loaded onto
 * a display at a time.
 */
    if (fscont==NULL) {
      /* create objects*/
      fscont = lv_obj_create (NULL, NULL); // https://docs.lvgl.io/latest/en/html/widgets/obj.html#screens
      lv_obj_add_style(fscont, LV_OBJ_PART_MAIN, getBkgdStyle());  // apply style
  
  
      createFSSButtons(fscont);
      createFSSInfoBar(fscont);
      createFSSStatusLabel(fscont);
  
      lv_task_create(lv_update_task, 60000, LV_TASK_PRIO_LOWEST, NULL); // insert the callback function into the task/event loop
    }

    lv_scr_load(fscont); // load the screen onto the display.
}
