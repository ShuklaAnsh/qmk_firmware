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
        LCTL_T(KC_A)  , LALT_T(KC_R)  , LGUI_T(KC_S)  , LSFT_T(KC_T)  , KC_G  ,
        LSFT_T(KC_Z)  , KC_X  , KC_C  , KC_D  , KC_V  ,
                    LCTL_T(KC_LEFT_CTRL)  , LALT_T(KC_LEFT_ALT)  ,
                                                         KC_ENTER , LT(LEFT_FN, KC_SPACE), LT(ENC_LEFT, KC_MUTE),
                                                                        LEFT_FN, KC_LEFT_GUI ,
        // RIGHT
                                                                                                        KC_6       , KC_7  , KC_8    ,  KC_9    ,  KC_0    ,
                                                                                                        KC_J       , KC_L  , KC_U    ,  KC_Y    ,  KC_SEMICOLON    ,
                                                                                                        KC_M       , RSFT_T(KC_N)  , RGUI_T(KC_E)    ,  RALT_T(KC_I)    ,  RCTL_T(KC_O),
                                                                                                        KC_K       , KC_H , KC_COMM ,  KC_DOT  ,  RSFT_T(KC_SLSH) ,
                                            LT(ENC_RIGHT, KC_MUTE) , LT(RIGHT_FN, KC_SPACE), KC_ENTER  ,  RALT_T(KC_RIGHT_ALT)    ,  RCTL_T(KC_RIGHT_CTRL) ,
                                            KC_RIGHT_GUI, RIGHT_FN
    ),

    [LAYER_QWERTY] = LAYOUT_5x5_4(
        // LEFT
        _______  , _______  , _______  , _______  , _______  ,
        KC_Q  , KC_W  , KC_E  , KC_R  , KC_T  ,
        LCTL_T(KC_A)  , LALT_T(KC_S)  , LGUI_T(KC_D)  , LSFT_T(KC_F)  , KC_G  ,
        LSFT_T(KC_Z)  , KC_X  , KC_C  , KC_V  , KC_B  ,
                    _______  , _______  ,
                                                         _______ , _______, _______,
                                                                        _______, _______ ,
        // RIGHT
                                                                                                        _______       , _______  , _______    ,  _______    ,  _______    ,
                                                                                                        KC_Y       , KC_U  , KC_I    ,  KC_O    ,  KC_P    ,
                                                                                                        KC_H       , RSFT_T(KC_J)  , RGUI_T(KC_K)    ,  RALT_T(KC_L)    ,  RCTL_T(KC_SEMICOLON),
                                                                                                        KC_N       , KC_M , _______ ,  _______  ,  _______ ,
                                            _______, _______, _______  ,  _______   ,  _______,
                                            _______, _______
    ),

    [LAYER_LEFT_FN] = LAYOUT_5x5_4(
        // LEFT
        KC_ESC  , _______  , _______  , _______  , _______  ,
        KC_TAB  , _______  , _______  , _______  , _______  ,
        KC_CAPS  , _______  , _______  , _______ , _______  ,
        _______  , _______  , _______  , _______  , _______  ,
                    _______  , _______  ,
                                                        _______ , _______ ,  _______,
                                                                        _______ , _______ ,
        // RIGHT
                                                                                                        _______    , _______  , KC_MINUS  ,  KC_EQUAL  ,  KC_DELETE ,
                                                                                                        _______    , _______    , KC_UP    ,  _______    ,  KC_PGUP ,
                                                                                                        _______    , KC_LEFT    , KC_DOWN    ,  KC_RIGHT    ,  KC_PGDN ,
                                                                                                        _______    , _______    , _______    ,  _______    ,  KC_END ,
                                                                                          _______ , COMBINED_FN    , _______ ,  _______  ,  _______  ,
                                                                                          _______ , _______
    ),


    [LAYER_RIGHT_FN] = LAYOUT_5x5_4(
        // LEFT
        KC_GRAVE  , _______  , _______  , _______  , _______  ,
        _______  , _______  , _______  , _______  , _______  ,
        _______  , _______  , _______  , _______  , _______  ,
        _______  , _______  , _______  , _______  , _______  ,
                    _______  , _______  ,
                                                        _______ , COMBINED_FN , _______ ,
                                                                     _______ , _______ ,
        // RIGHT
                                                                                                        _______    , _______  , KC_MINUS  ,  KC_EQUAL  ,  KC_BACKSPACE  ,
                                                                                                        _______    , _______    , KC_LEFT_BRACKET    ,  KC_RIGHT_BRACKET , KC_BACKSLASH ,
                                                                                                        _______    , _______    , _______    ,  _______    ,  KC_QUOTE ,
                                                                                                        _______    , _______    , _______    ,  _______    ,  _______ ,
                                                                                          _______ , _______    , _______ ,  _______  ,  _______  ,
                                                                                          _______ , _______
    ),

    [LAYER_COMBINED_FN] = LAYOUT_5x5_4(
        // LEFT
        KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  ,
        _______  , _______  , _______  , _______  , _______  ,
        _______  , _______  , _______  , _______  , _______ ,
        _______  , _______  , _______  , _______  , _______  ,
                    _______  , _______  ,
                                                        _______ , _______ , _______ ,
                                                                        _______ , _______ ,
        // RIGHT
                                                                                                        KC_F6    , KC_F7  , KC_F8  ,  KC_F9  ,  KC_F10  ,
                                                                                                        _______    , _______    , _______    ,  _______    ,  KC_F11 ,
                                                                                                        _______    , _______    , _______    ,  _______    ,  KC_F12 ,
                                                                                                        _______    , _______    , _______    ,  _______    ,  _______ ,
                                                                                          _______ , _______    , KC_NUM_LOCK ,  KC_MPRV  ,  _______  ,
                                                                                          _______ , _______
    ),

    [LAYER_ENC_LEFT] = LAYOUT_5x5_4(
        // LEFT
        _______  , _______  , _______  , _______  , _______  ,
        _______  , _______  , _______  , _______  , _______  ,
        _______  , _______  , _______  , _______  , _______  ,
        _______  , _______  , _______  , _______  , _______  ,
                    _______  , _______  ,
                                                        _______ , _______ , _______ ,
                                                                        _______ , OSL(LAYER_DEBUG) ,
        // RIGHT
                                                                                                        _______    , _______  , _______  ,  _______  ,  _______  ,
                                                                                                        _______    , _______    , _______    ,  _______    ,  _______ ,
                                                                                                        _______    , _______    , _______    ,  _______    ,  _______ ,
                                                                                                        _______    , _______    , _______    ,  _______    ,  _______ ,
                                                                                          TT(LAYER_DEBUG)  , _______    , _______ ,  _______  ,  _______  ,
                                                                                          _______ , _______
    ),

        [LAYER_ENC_RIGHT] = LAYOUT_5x5_4(
        // LEFT
        _______  , _______  , _______  , _______  , _______  ,
        _______  , _______  , _______  , _______  , _______  ,
        _______  , _______  , _______  , _______  , _______  ,
        _______  , _______  , _______  , _______  , _______  ,
                    _______  , _______  ,
                                                        _______ , _______ , TT(LAYER_DEBUG) ,
                                                                        _______ ,  _______ ,
        // RIGHT
                                                                                                        _______    , _______  , _______  ,  _______  ,  _______  ,
                                                                                                        _______    , _______    , _______    ,  _______    ,  _______ ,
                                                                                                        _______    , _______    , _______    ,  _______    ,  _______ ,
                                                                                                        _______    , _______    , _______    ,  _______    ,  _______ ,
                                                                                          _______ , _______    , _______ ,  _______  ,  _______  ,
                                                                                          OSL(LAYER_DEBUG) , _______
    ),


        [LAYER_DEBUG] = LAYOUT_5x5_4(
        // LEFT
        QK_BOOTLOADER  , QK_REBOOT  , QK_CLEAR_EEPROM , _______  , _______  ,
        QK_DEBUG_TOGGLE  , _______  , _______  , _______  , _______  ,
        _______  , _______  , _______  , _______  , _______  ,
        TT(LAYER_QWERTY), _______  , _______  , _______  , _______  ,
                    _______  , _______  ,
                                                        _______ , _______ , TT(LAYER_BASE) ,
                                                                        _______ , TT(LAYER_BASE) ,
        // RIGHT
                                                                                                        _______    , _______  , QK_CLEAR_EEPROM  ,  QK_REBOOT  ,  QK_BOOTLOADER  ,
                                                                                                        _______    , _______    , _______    ,  _______    ,  QK_DEBUG_TOGGLE ,
                                                                                                        _______    , _______    , _______    ,  _______    ,  _______ ,
                                                                                                        _______    , _______    , _______    ,  _______    ,  TT(LAYER_QWERTY) ,
                                                                                          TT(LAYER_BASE) , _______    , _______ ,  _______  ,  _______  ,
                                                                                          TT(LAYER_BASE) , _______
    ),
};

bool rgb_matrix_indicators_user(void) {
    led_t state = host_keyboard_led_state();
    if(state.caps_lock) {
        HSV hsv = {200, 200, 180};
        RGB rgb = hsv_to_rgb(hsv);
        rgb_matrix_set_color(4, rgb.r, rgb.g, rgb.b);
    }

    return true;
}
