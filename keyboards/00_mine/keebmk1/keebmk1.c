#include QMK_KEYBOARD_H
#include <keebmk1.h>
#ifdef BONGO_ENABLE
#    include "bongo.h"
#endif

#ifdef OLED_ENABLE

layer_state_t layer_state_set_kb(layer_state_t state) {
  oled_request_wakeup();
  return layer_state_set_user(state);
}

void matrix_init_kb(void) {
    oled_request_wakeup();
}

bool process_record_kb(uint16_t keycode, keyrecord_t *record) {
  oled_request_wakeup();
  return process_record_user(keycode, record);
}

bool encoder_update_kb(uint8_t index, bool clockwise) {
    oled_request_wakeup();
    return encoder_update_user(index, clockwise);
}

uint8_t oled_mode = OLED_DEFAULT;
bool oled_repaint_requested = false;
bool oled_wakeup_requested = false;
uint32_t oled_sleep_timer;

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
            oled_write_ln_P(PSTR("BASE"), false);
            break;
        case LAYER_FN_LEFT:
            oled_write_ln_P(PSTR("LEFN"), false);
            break;
        case LAYER_FN_RIGHT:
            oled_write_ln_P(PSTR("RIFN"), false);
            break;
        case LAYER_FN_COMBINED:
            oled_write_ln_P(PSTR("COMB"), false);
            break;
        case LAYER_ENC_LEFT:
            oled_write_ln_P(PSTR("ENCL"), false);
            break;
        case LAYER_ENC_RIGHT:
            oled_write_ln_P(PSTR("ENCR"), false);
            break;
        case LAYER_DEBUG:
            oled_write_ln_P(PSTR("DEBUG"), false);
            break;
        case LAYER_QWERTY:
            oled_write_ln_P(PSTR("QWERT"), false);
            break;
        default:
            oled_write_ln_P(PSTR("???"), false);
    }
    oled_write_ln_P(PSTR("\n-----"), false);


    // Host Keyboard LED Status
    led_t led_state = host_keyboard_led_state();
    oled_write_ln_P(led_state.num_lock ? PSTR("NUM ") : PSTR(""), false);
    oled_write_ln_P(led_state.caps_lock ? PSTR("CAP ") : PSTR(""), false);
    oled_write_ln_P(led_state.scroll_lock ? PSTR("SCR ") : PSTR(""), false);
}

bool oled_task_kb(void) {
    if (!oled_task_user()) {
        return false;
    }
    if (is_keyboard_left()) {
        render_status(); // Renders the current keyboard state (layer, lock, caps, scroll, etc)
    } else {
        if (!oled_task_needs_to_repaint()) {
            return false;
        }
        oled_clear();
        draw_bongo();
    }
    return false;
}

// Request a repaint of the OLED image without resetting the OLED sleep timer.
// Used for things like clock updates that should not keep the OLED turned on
// if there is no other activity.
void oled_request_repaint(void) {
    if (is_oled_on()) {
        oled_repaint_requested = true;
    }
}

// Request a repaint of the OLED image and reset the OLED sleep timer.
// Needs to be called after any activity that should keep the OLED turned on.
void oled_request_wakeup(void) {
    oled_wakeup_requested = true;
}

// Check whether oled_task_user() needs to repaint the OLED image.  This
// function should be called at the start of oled_task_user(); it also handles
// the OLED sleep timer and the OLED_OFF mode.
bool oled_task_needs_to_repaint(void) {
    // In the OLED_OFF mode the OLED is kept turned off; any wakeup requests
    // are ignored.
    if (oled_mode == OLED_OFF) {
        oled_wakeup_requested = false;
        oled_repaint_requested = false;
        oled_off();
        dprintf("OLED_OFF\n");
        return false;
    }

    // If OLED wakeup was requested, reset the sleep timer and do a repaint.
    if (oled_wakeup_requested) {
        oled_wakeup_requested = false;
        oled_repaint_requested = false;
        oled_sleep_timer = timer_read32() + OLED_TIMEOUT;
        oled_on();
        dprintf("oled_wakeup_requested\n");
        return true;
    }

    // If OLED repaint was requested, just do a repaint without touching the
    // sleep timer.
    if (oled_repaint_requested) {
        oled_repaint_requested = false;
        dprintf("oled_repaint_requested\n");
        return true;
    }

    // If the OLED is currently off, skip the repaint (which would turn the
    // OLED on if the image is changed in any way).
    if (!is_oled_on()) {
        dprintf("!is_oled_on\n");
        return false;
    }

    // If the sleep timer has expired while the OLED was on, turn the OLED off.
    if (timer_expired32(timer_read32(), oled_sleep_timer)) {
        dprintf("oled_off\n");
        oled_off();
        return false;
    }
    dprintf("oled_task_needs_to_repaint\n");
    // Always perform a repaint if the OLED is currently on.  (This can
    // potentially be optimized to avoid unneeded repaints if all possible
    // state changes are covered by oled_request_repaint() or
    // oled_request_wakeup(), but then any missed calls to these functions
    // would result in displaying a stale image.)
    return true;
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



