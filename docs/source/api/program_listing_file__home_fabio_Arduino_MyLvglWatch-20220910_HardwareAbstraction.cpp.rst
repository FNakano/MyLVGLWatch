
.. _program_listing_file__home_fabio_Arduino_MyLvglWatch-20220910_HardwareAbstraction.cpp:

Program Listing for File HardwareAbstraction.cpp
================================================

|exhale_lsh| :ref:`Return to documentation for file <file__home_fabio_Arduino_MyLvglWatch-20220910_HardwareAbstraction.cpp>` (``/home/fabio/Arduino/MyLvglWatch-20220910/HardwareAbstraction.cpp``)

.. |exhale_lsh| unicode:: U+021B0 .. UPWARDS ARROW WITH TIP LEFTWARDS

.. code-block:: cpp

   
   #include "HardwareAbstraction.h"
   // Deep sleep and wakeup functions.
   // WiFi power management is in NetworkNoScreen.ino file.
   
   static TTGOClass *ttgo = NULL;    // pointer to watch internals
   
   /* flags to manage sleep and wake up. */
   static bool irq=false;         // indicates that a hardware button interrupt occured
   static bool fKeepActive=false;  // indicates that some process is running so that the watch cannot deepSleep.
   
   void setupHardware() {
       ttgo = TTGOClass::getWatch();    // pointer to watch internals
       // backend setup
       Serial.begin(115200);
       ttgo = TTGOClass::getWatch();
       ttgo->begin();
   
       // PEK KEY hardware button interrupt handling to set date and time.
       pinMode(AXP202_INT, INPUT_PULLUP);
       attachInterrupt(AXP202_INT, [] {
           irq = true;
       }, FALLING);
       ttgo->power->enableIRQ(AXP202_PEK_SHORTPRESS_IRQ, true);
       ttgo->power->clearIRQ();
   
   //  start screen 
       ttgo->lvgl_begin();
   }
   
   /*
    *   setCpuFrequencyMhz(240); // maximum speed
    *   Above mentioned function is already defined elsewhere
    */
   
   void setDisplayBrightness(uint8_t b) {
       ttgo->bl->adjust(b);
   }
   
   void keepActive (bool newValue) {
     fKeepActive=newValue;
   }
   
   bool keepActive () {
     // Function (name) overload - C++ feature
     return fKeepActive;
   }
   
   void turnDisplayOn() {
     ttgo->openBL();
   }
   
   const char *hourMinute() {
     /*For immediate use - no buffering. */
     return ttgo->rtc->formatDateTime(PCF_TIMEFORMAT_HM);
   }
   
   const char *ymd(){
     return ttgo->rtc->formatDateTime(PCF_TIMEFORMAT_YYYY_MM_DD);
   }
   
   int8_t batPercentage() {
     return ttgo->power->getBattPercentage();
   }
   
   void turnDisplayOff() {
     ttgo->closeBL();
   }
   
   void isr () {
       if (irq) { // hardware button interrupt response
           irq=false; // clear flag
           /* */
           ttgo->power->readIRQ();  // get the IRQ source
           if (ttgo->power->isPEKShortPressIRQ()) { // hardware button short press
               // Clean power chip irq status
               ttgo->power->clearIRQ();
           }
       }
   }
   
   void tryDeepSleep() {
     if (fKeepActive) return;
     /*
      * Set wakeup through touchscreen and go deep sleep.
     */
     /*
      * Turn screen and other hardware off (except ESP32), 
      * set touchscreen as the only wakeup source,
      * set ESP32 to deep sleep.
     */
       // Set  touchscreen sleep
       ttgo->displaySleep();
   
       /*
       In TWatch2019/ Twatch2020V1, touch reset is not connected to ESP32,
       so it cannot be used. Set the touch to sleep,
       otherwise it will not be able to wake up.
       Only by turning off the power and powering on the touch again will the touch be working mode
       // ttgo->displayOff();
       */
   
       ttgo->powerOff();  // contains the same code below (??)
   
       //Set all channel power off (turn sensors and devices other than ESP32 off)
       ttgo->power->setPowerOutPut(AXP202_LDO3, false);
       ttgo->power->setPowerOutPut(AXP202_LDO4, false);
       ttgo->power->setPowerOutPut(AXP202_LDO2, false);
       ttgo->power->setPowerOutPut(AXP202_EXTEN, false);
       ttgo->power->setPowerOutPut(AXP202_DCDC2, false);
   
       // TOUCH SCREEN  Wakeup source
       esp_sleep_enable_ext1_wakeup(GPIO_SEL_38, ESP_EXT1_WAKEUP_ALL_LOW);
   
       // PEK KEY hardware button interrupt handling
       /* esp_sleep_enable_ext1_wakeup(GPIO_SEL_35, ESP_EXT1_WAKEUP_ALL_LOW);  // uncomment to wake watch up from hardware button press
       pinMode(AXP202_INT, INPUT_PULLUP);
       attachInterrupt(AXP202_INT, [] {
           irq = true;
       }, FALLING);
       ttgo->power->enableIRQ(AXP202_PEK_SHORTPRESS_IRQ, true); */
       ttgo->power->clearIRQ();
       // enable touch interrupt (maybe wake up ESP32 is the only possible action)
       pinMode(TOUCH_INT, INPUT);
       esp_deep_sleep_start();  // Put ESP32 to deep sleep
   }
