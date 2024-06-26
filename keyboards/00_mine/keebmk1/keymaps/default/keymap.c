#include QMK_KEYBOARD_H
#include <keebmk1.h>

#define ENC_LEFT MO(LAYER_ENC_LEFT)
#define ENC_RIGHT MO(LAYER_ENC_RIGHT)
#define RIGHT_FN MO(LAYER_FN_RIGHT)
#define LEFT_FN MO(LAYER_FN_LEFT)
#define COMBINED_FN MO(LAYER_FN_COMBINED)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [LAYER_BASE] = LAYOUT_5x5_4(
        // LEFT
        KC_1  , KC_2  , KC_3  , KC_4  , KC_5  ,
        KC_Q  , KC_W  , KC_F  , KC_P  , KC_B  ,
        LCTL_T(KC_A)  , LALT_T(KC_R)  , LGUI_T(KC_S)  , LSFT_T(KC_T)  , KC_G  ,
        LSFT_T(KC_Z)  , KC_X  , KC_C  , KC_D  , KC_V  ,
                    LCTL_T(KC_LEFT_CTRL)  , LALT_T(KC_LEFT_ALT)  ,
                                                         KC_ENTER , LT(LEFT_FN, KC_SPACE), KC_MS_BTN3,
                                                                        LEFT_FN, KC_LEFT_GUI ,
        // RIGHT
                                                                                                        KC_6       , KC_7  , KC_8    ,  KC_9    ,  KC_0    ,
                                                                                                        KC_J       , KC_L  , KC_U    ,  KC_Y    ,  KC_QUOTE    ,
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

    [LAYER_FN_LEFT] = LAYOUT_5x5_4(
        // LEFT
        KC_ESC  , _______  , _______  , _______  , _______  ,
        KC_TAB  , _______  , _______  , _______  , _______  ,
        KC_CAPS  , _______  , _______  , _______ , _______  ,
        _______  , _______  , _______  , _______  , _______  ,
                    _______  , _______  ,
                                                        _______ , _______ ,  ENC_LEFT,
                                                                        _______ , _______ ,
        // RIGHT
                                                                                                        _______    , _______  , KC_MINUS  ,  KC_EQUAL  ,  KC_DELETE ,
                                                                                                        _______    , _______    , KC_UP    ,  _______    ,  KC_PGUP ,
                                                                                                        _______    , KC_LEFT    , KC_DOWN    ,  KC_RIGHT    ,  KC_PGDN ,
                                                                                                        _______    , _______    , _______    ,  _______    ,  KC_END ,
                                                                                          _______ , COMBINED_FN    , _______ ,  _______  ,  _______  ,
                                                                                          _______ , _______
    ),


    [LAYER_FN_RIGHT] = LAYOUT_5x5_4(
        // LEFT
        KC_GRAVE  , _______  , _______  , _______  , _______  ,
        KC_TAB  , KC_MS_BTN1  , KC_MS_UP  , KC_MS_BTN2  , KC_MS_ACCEL0  ,
        _______  , KC_MS_LEFT  , KC_MS_DOWN  , KC_MS_RIGHT  , KC_MS_ACCEL1  ,
        _______  , KC_MS_BTN3  , KC_MS_WH_LEFT  , KC_MS_WH_RIGHT  , KC_MS_ACCEL2  ,
                    _______  , _______  ,
                                                        _______ , COMBINED_FN , _______ ,
                                                                     _______ , _______ ,
        // RIGHT
                                                                                                        _______    , _______  , KC_MINUS  ,  KC_EQUAL  ,  KC_BACKSPACE  ,
                                                                                                        _______    , _______    , KC_LEFT_BRACKET    ,  KC_RIGHT_BRACKET , KC_BACKSLASH ,
                                                                                                        _______    , _______    , _______    ,  _______    ,  KC_SEMICOLON ,
                                                                                                        _______    , _______    , _______    ,  _______    ,  _______ ,
                                                                                          _______ , _______    , _______ ,  _______  ,  _______  ,
                                                                                          _______ , _______
    ),

    [LAYER_FN_COMBINED] = LAYOUT_5x5_4(
        // LEFT
        KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  ,
        KC_KP_SLASH  , KC_KP_7  , KC_KP_8  , KC_KP_9  , KC_KP_ASTERISK  ,
        KC_KP_MINUS  , LALT_T(KC_KP_4)  , LGUI_T(KC_KP_5)  , LSFT_T(KC_KP_6)  , KC_KP_PLUS ,
        KC_KP_EQUAL  ,  KC_KP_1  , KC_KP_2  , KC_KP_3  , _______  ,
                    _______  , KC_KP_0  ,
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
        QK_BOOTLOADER  , QK_REBOOT  , QK_CLEAR_EEPROM , _______  , RGB_TOG  ,
        QK_DEBUG_TOGGLE  , _______  , _______  , _______  , _______  ,
        _______  , _______  , _______  , _______  , _______  ,
        TT(LAYER_QWERTY), _______  , _______  , _______  , _______  ,
                    _______  , _______  ,
                                                        _______ , _______ , TT(LAYER_BASE) ,
                                                                        _______ , TT(LAYER_BASE) ,
        // RIGHT
                                                                                                        RGB_TOG    , _______  , QK_CLEAR_EEPROM  ,  QK_REBOOT  ,  QK_BOOTLOADER  ,
                                                                                                        _______    , _______    , _______    ,  _______    ,  QK_DEBUG_TOGGLE ,
                                                                                                        _______    , _______    , _______    ,  _______    ,  _______ ,
                                                                                                        _______    , _______    , _______    ,  _______    ,  TT(LAYER_QWERTY) ,
                                                                                          TT(LAYER_BASE) , _______    , _______ ,  _______  ,  _______  ,
                                                                                          TT(LAYER_BASE) , _______
    ),
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [LAYER_BASE] = {ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN), ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [LAYER_QWERTY]  = {ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN), ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [LAYER_FN_LEFT]  = {ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN), ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [LAYER_FN_RIGHT]  = {ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN), ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [LAYER_FN_COMBINED]  = {ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN), ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [LAYER_ENC_LEFT]  = {ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN), ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [LAYER_ENC_RIGHT]  = {ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN), ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [LAYER_DEBUG]  = {ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN), ENCODER_CCW_CW(KC_VOLD, KC_VOLU)}
};
#endif

bool rgb_matrix_indicators_user(void) {
    led_t state = host_keyboard_led_state();
    if(state.caps_lock || is_caps_word_on()) {
        HSV hsv = {200, 200, 180};
        RGB rgb = hsv_to_rgb(hsv);
        rgb_matrix_set_color(4, rgb.r, rgb.g, rgb.b);
    }

    return true;
}
