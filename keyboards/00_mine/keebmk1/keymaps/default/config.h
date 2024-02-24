/*
Copyright 2012 Jun Wako <wakojun@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#define SPLIT_HAND_PIN F4

// #define ENCODERS_PAD_A { D4, D4 }
// #define ENCODERS_PAD_B { D5, D5 }

#define OLED_TIMEOUT 0

// The pin connected to the data pin of the LEDs
#define WS2812_DI_PIN D7
// // The number of LEDs connected
#define RGB_MATRIX_LED_COUNT 70

#define EE_HANDS

#define KINETIC_SPEED

// disable Cherry MX Lock switch support
#undef LOCKING_SUPPORT_ENABLE
#undef LOCKING_RESYNC_ENABLE

// up tp 8 layers
#define LAYER_STATE_8BIT // #define LAYER_STATE_16BIT

#define GRAVE_ESC_ALT_OVERRIDE	// Always send Escape if Alt is pressed
#define GRAVE_ESC_CTRL_OVERRIDE	// Always send Escape if Control is pressed
#define GRAVE_ESC_GUI_OVERRIDE	// Always send Escape if GUI is pressed
#define GRAVE_ESC_SHIFT_OVERRIDE // Always send Escape if Shift is pressed
