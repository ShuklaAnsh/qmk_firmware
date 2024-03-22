#include QMK_KEYBOARD_H
#include <keebmk1.h>

#define ENC_LEFT MO(LAYER_ENC_LEFT)
#define ENC_RIGHT MO(LAYER_ENC_RIGHT)
#define RIGHT_FN MO(LAYER_RIGHT_FN)
#define LEFT_FN MO(LAYER_LEFT_FN)
#define COMBINED_FN MO(LAYER_COMBINED_FN)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [LAYER_BASE] = LAYOUT_5x5_4(
        // LEFT
        KC_1  , KC_2  , KC_3  , KC_4  , KC_5  ,
        KC_Q  , KC_W  , KC_F  , KC_P  , KC_B  ,
        KC_A  , KC_R  , KC_S  , KC_T  , KC_G  ,
        LSFT_T(KC_Z)  , KC_X  , KC_C  , KC_D  , KC_V  ,
                    LCTL_T(KC_LEFT_CTRL)  , LALT_T(KC_LEFT_ALT)  ,
                                                        KC_SPACE , KC_ENTER , ENC_LEFT,
                                                                        LGUI_T(KC_LEFT_GUI) , LEFT_FN ,
        // RIGHT
                                                                                                        KC_6       , KC_7  , KC_8    ,  KC_9    ,  KC_0    ,
                                                                                                        KC_J       , KC_L  , KC_U    ,  KC_Y    ,  KC_SEMICOLON    ,
                                                                                                        KC_M       , KC_N  , KC_E    ,  KC_I    ,  KC_O ,
                                                                                                        KC_K       , KC_H , KC_COMM ,  KC_DOT  ,  KC_SLSH ,
                                                                                        ENC_RIGHT , KC_ENTER  , KC_SPACE    ,  RALT_T(KC_RIGHT_ALT)    ,  RSFT_T(KC_RIGHT_SHIFT) ,
                                                                                        RIGHT_FN   , KC_RIGHT_GUI
    ),

    [LAYER_LEFT_FN] = LAYOUT_5x5_4(
        // LEFT
        KC_GRAVE  , _______  , _______  , _______  , _______  ,
        _______  , _______  , _______  , _______  , _______  ,
        KC_HOME  , KC_PGUP  , KC_PGDN  , KC_END , _______  ,
        KC_LEFT_SHIFT  , _______  , _______  , _______  , _______  ,
                    _______  , _______  ,
                                                        _______ , _______ , COMBINED_FN ,
                                                                        _______ , KC_PSCR ,
        // RIGHT
                                                                                                        _______    , _______  , KC_MINUS  ,  KC_EQUAL  ,  KC_DELETE  ,
                                                                                                        _______    , _______    , _______    ,  _______    ,  KC_BACKSLASH ,
                                                                                                        _______    , _______    , _______    ,  _______    ,  _______ ,
                                                                                                        _______    , _______    , _______    ,  _______    ,  KC_RIGHT_SHIFT ,
                                                                                          _______ , _______    , KC_SPACE ,  KC_EQL  ,  KC_UNDS  ,
                                                                                          _______ , _______
    ),


    [LAYER_RIGHT_FN] = LAYOUT_5x5_4(
        // LEFT
        KC_ESC  , _______  , _______  , _______  , _______  ,
        KC_TAB  , _______  , _______  , _______  , _______  ,
        KC_CAPS  , _______  , _______  , _______  , _______  ,
        KC_LEFT_SHIFT  , _______  , _______  , _______  , _______  ,
                    _______  , _______  ,
                                                        _______ , _______ , _______ ,
                                                                        _______ , _______ ,
        // RIGHT
                                                                                                        _______    , _______  , _______  ,  _______  ,  KC_BACKSPACE  ,
                                                                                                        _______    , _______    , _______    ,  KC_LEFT_BRACKET    ,  KC_RIGHT_BRACKET ,
                                                                                                        _______    , _______    , _______    ,  _______    ,  KC_QUOTE ,
                                                                                                        _______    , _______    , _______    ,  _______    ,  KC_RIGHT_SHIFT ,
                                                                                          _______ , _______    , _______ ,  _______  ,  _______  ,
                                                                                          COMBINED_FN , _______
    ),

    [LAYER_COMBINED_FN] = LAYOUT_5x5_4(
        // LEFT
        KC_F10  , KC_F1  , KC_F2  , KC_F3  , KC_F4  ,
        _______  , _______  , _______  , _______  , _______  ,
        _______  , KC_LEFT  , KC_UP  , KC_DOWN  , KC_RGHT  ,
        KC_LEFT_SHIFT  , _______  , _______  , _______  , _______  ,
                    _______  , _______  ,
                                                        _______ , _______ , _______ ,
                                                                        _______ , _______ ,
        // RIGHT
                                                                                                        KC_F5    , KC_F6  , KC_F7  ,  KC_F8  ,  KC_F9  ,
                                                                                                        KC_RPRN    , KC_P7    , KC_P8    ,  KC_P9    ,  KC_F11 ,
                                                                                                        KC_RBRC    , KC_P4    , KC_P5    ,  KC_P6    ,  KC_F12 ,
                                                                                                        _______    , KC_P1    , KC_P2    ,  KC_P3    ,  KC_RIGHT_SHIFT ,
                                                                                          KC_MPLY , KC_EQL    , KC_NUM_LOCK ,  KC_MPRV  ,  _______  ,
                                                                                          KC_MPLY , _______
    ),
};
