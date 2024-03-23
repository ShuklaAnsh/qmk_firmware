#pragma once

#define LAYER_BASE 0
#define LAYER_QWERTY 1
#define LAYER_LEFT_FN 2
#define LAYER_RIGHT_FN 3
#define LAYER_COMBINED_FN 4
#define LAYER_ENC_LEFT 5
#define LAYER_ENC_RIGHT 6
#define LAYER_DEBUG 7

#define BONGO_ENABLE

enum oled_modes {
  OLED_DEFAULT,
  OLED_OFF,
  OLED_BONGO,
  _NUM_OLED_MODES
};

// OLED Behavior
extern uint8_t oled_mode;
extern bool oled_repaint_requested;
extern bool oled_wakeup_requested;
extern uint32_t oled_sleep_timer;

void oled_request_wakeup(void);
void oled_request_repaint(void);
bool oled_task_needs_to_repaint(void);
