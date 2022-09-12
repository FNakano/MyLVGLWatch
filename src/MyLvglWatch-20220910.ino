/* @file MyLvglWatch-2022-09-10.ino
 *  This is the main file. As on most Arduino IDE projects, it is the entry point of the program and contains setup() and loop() functions.
 *  Based on MyLvglWatch-20220905-C.ino.
 */

#include "config.h" // choose watch version

#include "DateTimeScreen.h"
#include "HardwareAbstraction.h"
#include "Styles.h"

void setup()
{
    setupHardware();
    setupStyles();
    buildWatchFace();
    updateScreenData();
    displayWatchFace();
    turnDisplayOn();
}

void loop()
{
  /* Hardware interrupts and deepsleep are treated here. LVGL interrupts (events) are treated in
   * LGVL way (event callback/register/loop)  
  */
    uint32_t tInactive= lv_disp_get_inactive_time(NULL);
    if (tInactive>10000) tryDeepSleep(); // outside lv_event_handler to not interrupt UI operation
    isr();
    lv_task_handler();
}
