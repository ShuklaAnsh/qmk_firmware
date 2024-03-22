#include QMK_KEYBOARD_H
#include <keebmk1.h>

#ifdef BONGO_ENABLE
#    include "bongo.h"
#endif

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_QWERTY] = {ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN), ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [_LOWER]  = {ENCODER_CCW_CW(RGB_HUD, RGB_HUI), ENCODER_CCW_CW(RGB_SAD, RGB_SAI)},
    [_RAISE]  = {ENCODER_CCW_CW(RGB_VAD, RGB_VAI), ENCODER_CCW_CW(RGB_SPD, RGB_SPI)},
};
#endif

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_left()) {
        return OLED_ROTATION_270;
    }
    return OLED_ROTATION_180;
}

static void render_status(void) {
    // Host Keyboard Layer Status
    oled_write_ln_P(PSTR("-----"), false);

    switch (get_highest_layer(layer_state)) {
        case LAYER_BASE:
            oled_write_P(PSTR("BASE\n"), false);
            break;
        case LAYER_LEFT_FN:
            oled_write_P(PSTR("LEFN\n"), false);
            break;
        case LAYER_RIGHT_FN:
            oled_write_P(PSTR("RIFN\n"), false);
            break;
        case LAYER_COMBINED_FN:
            oled_write_P(PSTR("COMB\n"), false);
            break;
        case LAYER_ENC_LEFT:
            oled_write_P(PSTR("ENCL\n"), false);
            break;
        case LAYER_ENC_RIGHT:
            oled_write_P(PSTR("ENCR\n"), false);
            break;
        case LAYER_DEBUG:
            oled_write_P(PSTR("DEBUG\n"), false);
            break;
        default:
            // Or use the write_ln shortcut over adding '\n' to the end of your string
            oled_write_ln_P(PSTR("???"), false);
    }

    oled_write_ln_P(PSTR(
        is_keyboard_left() ? "LEFT" : "RIGHT"
    ), false);

    // Host Keyboard LED Status
    led_t led_state = host_keyboard_led_state();
    oled_write_P(led_state.num_lock ? PSTR("NUM ") : PSTR("    "), false);
    oled_write_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);
    oled_write_P(led_state.scroll_lock ? PSTR("SCR ") : PSTR("    "), false);
}

bool oled_task_user(void) {
    if (is_keyboard_left()) {
        render_status(); // Renders the current keyboard state (layer, lock, caps, scroll, etc)
    } else {
        return true;
    }

    return false;
}

bool oled_task_kb(void) {
    if (!oled_task_user()) {
        return false;
    }
    if (!is_keyboard_left()) {
        // if (!oled_task_needs_to_repaint()) {
        //     return false;
        // }
        oled_clear();
        draw_bongo();
    }
    return false;
}

#endif

// #ifdef RGB_MATRIX_ENABLE

// void suspend_power_down_kb(void) {
//     rgb_matrix_set_suspend_state(true);
//     suspend_power_down_user();
// }

// void suspend_wakeup_init_kb(void) {
//     rgb_matrix_set_suspend_state(false);
//     suspend_wakeup_init_user();
// }
// #endif


// LED Layout
// Columns
// 0   1   2   3   4    5   6   7   8   9

// Physical (Center: 112)
// 0  24  49  74  99    124 149 174 199 224
//                                              Rows    Physical (Center: 32)
// 4   3   2   1   0     26  27  28  29  30        0           0
// 5   6   7   8   9     35  34  33  31  31        1          12
// 14  13  12  11  10    36  37  38  39  40        2          25
// 15  16  17  18  19    45  44  43  42  41        3          38
// 25  24  23  20            46  49  50  51        4          51
//             22  21    47  48                    5          64

led_config_t g_led_config = { {
// Key Matrix to LED Index
  // Left Hand
  { 4, 3, 2, 1, 0},
  { 5, 6, 7, 8, 9 },
  { 14, 13, 12, 11, 10 },
  { 15, 16, 17, 18, 19 },
  { 25, 24, 23, 20, NO_LED },
  { NO_LED, NO_LED, NO_LED, 22, 21 },
  // Right Hand
  { 26, 27, 28, 29, 30},
  { 35, 34, 33, 32, 31 },
  { 36, 37, 38, 39, 40 },
  { 45, 44, 43, 42, 41 },
  { NO_LED, 46, 49, 50, 51 },
  { 47, 48, NO_LED, NO_LED, NO_LED },
}, {
  // LED Index to Physical Position
  // Left Hand
{ 0, 0} , { 0, 12} , { 0, 25} , { 0, 38} , { 0, 51} ,
{ 24, 0} , { 24, 12} , { 24, 25} , { 24, 38} , { 24, 51} ,
{ 49, 0} , { 49, 12} , { 49, 25} , { 49, 38} , { 49, 51} ,
{ 74, 0} , { 74, 12} , { 74, 25} , { 74, 38} , { 74, 51} , { 74, 64} ,
{ 99, 0} , { 99, 12} , { 99, 25} , { 99, 38} , { 99, 64} ,
// Right
{ 124, 0} , { 124, 12} , { 124, 25} , { 124, 38} , { 124, 64} ,
{ 149, 0} , { 149, 12} , { 149, 25} , { 149, 38} , { 149, 51} , { 149, 64} ,
{ 174, 0} , { 174, 12} , { 174, 25} , { 174, 38} , { 174, 51} ,
{ 199, 0} , { 199, 12} , { 199, 25} , { 199, 38} , { 199, 51} ,
{ 224, 0} , { 224, 12} , { 224, 25} , { 224, 38} , { 224, 51} ,
}, {
  // LED Index to Flag
  4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4
} };

// bool led_update_kb(led_t led_state) {
//     bool res = led_update_user(led_state);
//     if(res) {
//         // writePin sets the pin high for 1 and low for 0.
//         // In this example the pins are inverted, setting
//         // it low/0 turns it on, and high/1 turns the LED off.
//         // This behavior depends on whether the LED is between the pin
//         // and VCC or the pin and GND.
//         writePin(B2, !led_state.num_lock);
//         writePin(C6, !led_state.caps_lock);
//         writePin(B7, !led_state.scroll_lock);
//     }
//     return res;
// }
