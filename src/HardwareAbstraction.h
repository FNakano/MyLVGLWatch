#ifndef HARDWAREABSTRACTION_H

#define HARDWAREABSTRACTION_H

#include "config.h"

/**
 * Initialize hardware for use. Call it in setup() function.
 */
void setupHardware();

/**
 * Set display brightness.
 * @param b brightness value from 0 to 255.
 */
void setDisplayBrightness(uint8_t b);

/**
 * Turn display on
 */
void turnDisplayOn();

/**
 * Turn display off
 */
void turnDisplayOff();

/**
 * Set the hardware to stay active (avoid entering deepsleep) or no (may enter deepsleep).
 * Deepsleep is a low-power mode: hardware is almost shut-off. It can be woken-up by 
 * touching the screen.
 * @param newValue true: stay active;
 *                 false: may enter deepsleep;
 */
void keepActive(bool newValue);

/**
 * Query if the hardware is set to stay active (avoid entering deepsleep) or no (may enter deepsleep).
 * Deepsleep is a low-power mode: hardware is almost shut-off. It can be woken-up by 
 * touching the screen.
 * @return true: stay active;
 *         false: may enter deepsleep;
 */
bool keepActive();

/**
 * Get current time. It is expected that new functions (eg. that return different formats) would be written in this file.
 * @return hour and minute as a string HH:MM
 */
const char *hourMinute();

/**
 * Get current date. It is expected that new functions (eg. that return different formats) would be written in this file.
 * @return year monty day in the month as a string YYYY-MM-DD
 */
const char *ymd();

/**
 * Get battery charge in percent.
 * @return number 0-100 percent
 */
int8_t batPercentage();

/**
 * Function executed when a hardware event occurs (ex. hardware button, touch screen, accelerometer, ...) 
 */
void isr();

/**
 * Check if hardware is set to stay active. If not, set the watch to wake-up on screen touch and (almost) shut off.
 */
void tryDeepSleep();

#endif
