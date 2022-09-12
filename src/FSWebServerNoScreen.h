#ifndef FSWEBSERVERNOSCREEN_H

#define FSWEBSERVERNOSCREEN_H

/** Turns file browsing/transfer on. */ 
void startWebServerFS();

/** Turns file browsint/transfer off. */
void closeWebServerandSPIFFSandWiFi();

/** Check if someone (usually through a web browser) requested some page 
 *  and responds to it. Example on how to use this function is in FSScreen.cpp
 *  
 *  Note for developers: this function should be added to LVGL event/task loop.
 *  @return true if the web server is on (can be used to avoid going to deep sleep).
 */
bool webServerFSTestAndHandle(void);
#endif
