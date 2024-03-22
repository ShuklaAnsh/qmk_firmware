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

#define EE_HANDS

// #define OLED_TIMEOUT 0

#define KINETIC_SPEED

// disable Cherry MX Lock switch support
#undef LOCKING_SUPPORT_ENABLE
#undef LOCKING_RESYNC_ENABLE

// #define GRAVE_ESC_ALT_OVERRIDE	// Always send Escape if Alt is pressed
// #define GRAVE_ESC_CTRL_OVERRIDE	// Always send Escape if Control is pressed
// #define GRAVE_ESC_GUI_OVERRIDE	// Always send Escape if GUI is pressed
// #define GRAVE_ESC_SHIFT_OVERRIDE // Always send Escape if Shift is pressed

// https://docs.qmk.fm/#/feature_rgb_matrix?id=rgb-matrix-effects
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
#define RGB_MATRIX_SOLID_REACTIVE_GRADIENT_MODE

#define RGB_MATRIX_LED_COUNT 52

// Data Sync
#define SPLIT_TRANSPORT_MIRROR
#define SPLIT_LAYER_STATE_ENABLE
#define SPLIT_LED_STATE_ENABLE
#define SPLIT_MODS_ENABLE
#define SPLIT_WPM_ENABLE
#define SPLIT_OLED_ENABLE
#define SPLIT_ACTIVITY_ENABLE
// https://docs.qmk.fm/#/feature_pointing_device?id=split-keyboard-configuration
// #define SPLIT_POINTING_ENABLE



// RP2040 Defines
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET // Activates the double-tap behavior
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 200U // Timeout window in ms in which the double tap can occur.
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_LED GP25 // Specify a optional status led by GPIO number which blinks when entering the bootloader
// I2C driver
#define I2C_DRIVER I2CD1
#define I2C1_SDA_PIN GP2
#define I2C1_SCL_PIN GP3

// SPI driver
#define SPI_DRIVER SPID0
#define SPI_SCK_PIN	GP18
#define SPI_MISO_PIN GP20
#define SPI_MOSI_PIN GP19

// Serial driver
#define SERIAL_USART_DRIVER SIOD0
#define SERIAL_USART_TX_PIN	GP0
#define BOOTMAGIC_ROW_RIGHT 6
#define BOOTMAGIC_COLUMN_RIGHT 4
#define BOOTMAGIC_ROW 0
#define BOOTMAGIC_COLUMN 10
