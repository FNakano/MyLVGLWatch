#ifndef WSSCREEN_H

#define WSSCREEN_H

#include "config.h"


/**
 * Create and display the watch face for file transfer, place graphical objects in it, apply styles.
 * 
 */
void buildWatchFace3();

/**
 * Update data (text, values) displayed in graphical objects (e.g. time, battery level, IP address,...)
 */
void updateScreenData3();

// not public
// static void event_handler... 

#endif
