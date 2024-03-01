#include QMK_KEYBOARD_H
#include <keebmk1.h>

#ifdef BONGO_ENABLE
#    include "bongo.h"
#endif

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = {ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN), ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [1] = {ENCODER_CCW_CW(RGB_HUD, RGB_HUI), ENCODER_CCW_CW(RGB_SAD, RGB_SAI)},
    [2] = {ENCODER_CCW_CW(RGB_VAD, RGB_VAI), ENCODER_CCW_CW(RGB_SPD, RGB_SPI)},
};
#endif

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_90;
    }
    return OLED_ROTATION_180;
}

static void render_status(void) {
    // Host Keyboard Layer Status
    oled_write_ln_P(PSTR("-----"), false);

    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write_P(PSTR("ABC\n"), false);
            break;
        case _LOWER:
            oled_write_P(PSTR("LOW\n"), false);
            break;
        case _RAISE:
            oled_write_P(PSTR("RSE\n"), false);
            break;
        default:
            // Or use the write_ln shortcut over adding '\n' to the end of your string
            oled_write_ln_P(PSTR("???"), false);
    }

    oled_write_ln_P(PSTR("boop"), false);

    // Host Keyboard LED Status
    led_t led_state = host_keyboard_led_state();
    oled_write_P(led_state.num_lock ? PSTR("NUM ") : PSTR("    "), false);
    oled_write_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);
    oled_write_P(led_state.scroll_lock ? PSTR("SCR ") : PSTR("    "), false);
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
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
    if (!is_keyboard_master()) {
        // if (!oled_task_needs_to_repaint()) {
        //     return false;
        // }
        oled_clear();
        draw_bongo();
    }
    return false;
}

#endif

#ifdef RGB_MATRIX_ENABLE

void suspend_power_down_kb(void) {
    rgb_matrix_set_suspend_state(true);
    suspend_power_down_user();
}

void suspend_wakeup_init_kb(void) {
    rgb_matrix_set_suspend_state(false);
    suspend_wakeup_init_user();
}
#endif

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
