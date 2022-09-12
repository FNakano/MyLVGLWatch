#ifndef NETWORKNOSCREEN_H

#define NETWORKNOSCREEN_H

#include "config.h"
#include <WiFi.h>
#include "time.h"
#include "driver/adc.h"   // adc functions. Needed to turn WiFi off.

#define WIFI_FAILED_TO_CONNECT 0
#define WIFI_CONNECTED 1

#define WIFI_NTP_CLOCK_SET 1
#define WIFI_NTP_FAILED 0

/**
 * Turn wifi off
 */
void wiFiOff ();

/**
 * Turn wifi on
 */
int wiFiOn ();


/**
 * Adjust clock using network time. Need Wifi turned on. 
 */
int setClockNTP();

/**
 * Get IP address. It can be used to connect a web browser to the watch.
 * @return IP address as a string eg. 192.168.0.100
 */
const char *getIP ();

#endif
