#ifndef DATETIMESCREEN_H

#define DATETIMESCREEN_H

#include "config.h" // choose watch version

/**
 * Update data (text, values) displayed in graphical objects (e.g. time, date, battery level,...)
 */
void updateScreenData ();

/**
 * Create this watch face, place graphical objects in it, apply styles.
 */
void buildWatchFace ();

/**
 * Display the watch face. I.e. put it on the physical screen. 
 */
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
