/** @file Styles.cpp
 * user: Functions to define the style (colors, fonts, ...) of buttons, text and other graphical elements. 
 */
#include "config.h"

//LV_FONT_DECLARE(nbubuntubi80);
LV_FONT_DECLARE(nbubb80);
LV_FONT_DECLARE(lv_font_montserrat_28);
LV_FONT_DECLARE(lv_font_montserrat_22);

/*
 * > ... Style variables should be static, global or dynamically allocated. In other words they can not be local variables 
 * > in functions which are destroyed when the function exists ...
 * Fonte: https://docs.lvgl.io/latest/en/html/overview/style.html?highlight=theme#initialize-styles-and-set-get-properties
 */
 
static lv_style_t opaqueBackgroundStyle;
static lv_style_t timeStyle;
static lv_style_t infoStyle;
static lv_style_t rollerStyle;
static lv_style_t sideButtonStyle;
static lv_style_t fssButtonStyle;

/**
 * Create all styles. Call it in setup() function. 
 * developer: to create new styles, create a variable to store it, 
 * init it in this function and provide a getter function.
 */
void setupStyles () {

    /* Background style */
    lv_style_init(&opaqueBackgroundStyle);
    lv_style_set_border_width(&opaqueBackgroundStyle, LV_OBJ_PART_MAIN, 0);
    //lv_style_set_border_color(&opaqueBackgroundStyle, LV_OBJ_PART_MAIN, LV_COLOR_BLACK);
    //lv_style_set_border_opa(&opaqueBackgroundStyle, LV_OBJ_PART_MAIN, LV_OPA_100); // opaque
    lv_style_set_pad_top(&opaqueBackgroundStyle, LV_OBJ_PART_MAIN, 0);
    lv_style_set_pad_bottom(&opaqueBackgroundStyle, LV_OBJ_PART_MAIN, 0);
    lv_style_set_pad_left(&opaqueBackgroundStyle, LV_OBJ_PART_MAIN, 0);
    lv_style_set_pad_right(&opaqueBackgroundStyle, LV_OBJ_PART_MAIN, 0);
    lv_style_set_margin_top(&opaqueBackgroundStyle, LV_OBJ_PART_MAIN, 0);
    lv_style_set_margin_bottom(&opaqueBackgroundStyle, LV_OBJ_PART_MAIN, 0);
    lv_style_set_margin_left(&opaqueBackgroundStyle, LV_OBJ_PART_MAIN, 0);
    lv_style_set_margin_right(&opaqueBackgroundStyle, LV_OBJ_PART_MAIN, 0);
    lv_style_set_bg_color(&opaqueBackgroundStyle, LV_OBJ_PART_MAIN, LV_COLOR_BLACK);
    lv_style_set_bg_opa(&opaqueBackgroundStyle, LV_OBJ_PART_MAIN, LV_OPA_100); // opaque
    lv_style_set_text_color(&opaqueBackgroundStyle, LV_OBJ_PART_MAIN, LV_COLOR_WHITE);

    /*
     * timeStyle is the style of the button that displays time.
     */
    lv_style_init(&timeStyle);
    lv_style_copy(&timeStyle, &opaqueBackgroundStyle);
    // lv_style_set_text_font(&timeStyle, LV_STATE_DEFAULT, &nbubuntubi80); // https://lvgl.io/tools/fontconverter 0x20-0x46
    lv_style_set_text_font(&timeStyle, LV_STATE_DEFAULT, &nbubb80); // https://lvgl.io/tools/fontconverter 0x20-0x46

    /*
     * infoStyle is the style of the button at the top of the display.
     */
    lv_style_init(&infoStyle);
    lv_style_copy(&infoStyle, &opaqueBackgroundStyle);
    lv_style_set_text_font(&infoStyle, LV_STATE_DEFAULT, &lv_font_montserrat_28);

    /*
     * rollerStyle is the style of the rolling menu.
     */

    lv_style_init(&rollerStyle);
    lv_style_copy(&rollerStyle, &opaqueBackgroundStyle);
    /* OR-ING does not work
    lv_style_set_text_font(&rollerStyle, LV_ROLLER_PART_BG|LV_ROLLER_PART_SELECTED, &lv_font_montserrat_22);
    lv_style_set_text_line_space(&rollerStyle, LV_ROLLER_PART_BG|LV_ROLLER_PART_SELECTED, 0); // compact lines https://docs.lvgl.io/7.11/widgets/roller.html#parts-and-styles
    */
    lv_style_set_text_font(&rollerStyle, LV_ROLLER_PART_BG, &lv_font_montserrat_28);
    lv_style_set_text_line_space(&rollerStyle, LV_ROLLER_PART_BG, 0); // compact lines https://docs.lvgl.io/7.11/widgets/roller.html#parts-and-styles
    lv_style_set_text_font(&rollerStyle, LV_ROLLER_PART_SELECTED, &lv_font_montserrat_28);
    lv_style_set_text_line_space(&rollerStyle, LV_ROLLER_PART_SELECTED, 0); // compact lines https://docs.lvgl.io/7.11/widgets/roller.html#parts-and-styles
    // in version 7.7.2 selected item font is not set: https://forum.lvgl.io/t/how-to-change-the-roller-selected-text-font-size/2291/2

    /*
     * sideButtonStyle is the style of the buttons at the sides of the rolling menu.
     */
    lv_style_init(&sideButtonStyle);
    lv_style_copy(&sideButtonStyle, &opaqueBackgroundStyle);
    lv_style_set_text_font(&sideButtonStyle, LV_STATE_DEFAULT, &lv_font_montserrat_28);
    lv_style_set_bg_color(&sideButtonStyle, LV_OBJ_PART_MAIN, LV_COLOR_TEAL);

/*
 * fssButtonStyle is the style of the buttons in the FSScreen
 */
 
    lv_style_init(&fssButtonStyle);
    lv_style_copy(&fssButtonStyle, &opaqueBackgroundStyle);
    lv_style_set_bg_color(&fssButtonStyle, LV_STATE_PRESSED, LV_COLOR_WHITE);
    lv_style_set_text_font(&fssButtonStyle, LV_STATE_DEFAULT, &lv_font_montserrat_22);
    lv_style_set_border_width(&fssButtonStyle, LV_OBJ_PART_MAIN, 1);
    lv_style_set_border_color(&fssButtonStyle, LV_OBJ_PART_MAIN, LV_COLOR_WHITE);
}

/**
 * Get a style to use it in a graphical object. Usage examples in DateTimeScreen.cpp and WSScreen.cpp
 * The style is black opaque background, white text, default font (it is small, size 12 or 14)
 * applied to the screen background.
 */
lv_style_t *getBkgdStyle(){
  return &opaqueBackgroundStyle;
}

/**
 * Get a style to use it in a graphical object. Usage examples in DateTimeScreen.cpp
 * The style is black opaque background, white text, large font (80pt, numbers only)
 * applied to display time. 
 */
lv_style_t *getTimeStyle(){
  return &timeStyle;
}

/**
 * Get a style to use it in a graphical object. Usage examples in DateTimeScreen.cpp and WSScreen.cpp
 * The style is black opaque background, white text, medium font (28pt)
 * applied to the bar at the top of  the screen. 
 */
lv_style_t *getInfoStyle(){
  return &infoStyle;
}

/**
 * Get a style to use it in a graphical object. Usage examples in DateTimeScreen.cpp
 * The style is black opaque background, white text, blue selection background, medium font (28pt)
 * applied to the rolling menu to choose personal activity. 
 */
lv_style_t *getRollerStyle(){
  return &rollerStyle;
}

/**
 * Get a style to use it in a graphical object. Usage examples in DateTimeScreen.cpp
 * The style is blue opaque background, white text, medium font (28pt)
 * applied to the buttons beside the rolling menu. 
 */
lv_style_t *getSideButtonStyle(){
  return &sideButtonStyle;
}

/**
 * Get a style to use it in a graphical object. Usage example in WSScreen.cpp
 * The style is black opaque background, white text, medium font (28pt)
 * applied to the buttons to turn wifi on/off and exit WSScreen. 
 */
lv_style_t *getFSSButtonStyle(){
  return &fssButtonStyle;
}
