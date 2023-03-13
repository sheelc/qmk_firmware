/* Copyright 2023 @ Keychron (https://www.keychron.com)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "led_matrix.h"

// clang-format off
enum layers{
  MAC_BASE,
  MAC_FN,
  LIN_BASE,
  LIN_FN,
  MOUSE,
};

enum ctrl_keycodes {
    MD_BOOT = SAFE_RANGE, //Restart into bootloader after hold timeout
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[MAC_BASE] = LAYOUT_ansi_84(
     KC_ESC,   TG(MOUSE), G(KC_C),  G(KC_V),  G(KC_W),  G(S(KC_LBRC)), G(S(KC_RBRC)), G(KC_TAB), G(KC_GRV), KC_F9,  KC_F10,   KC_F11,   KC_F12,   G(C(KC_S)),  KC_DEL,  G(C(KC_Q)),
     KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,            G(A(KC_A)),
     KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,            KC_PGDN,
     CW_TOGG,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,            KC_ENT,             KC_HOME,
     OSM(MOD_LSFT),            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,            OSM(MOD_RSFT),  KC_UP,    KC_END,
     OSM(MOD_LCTL),  OSM(MOD_LALT), OSM(MOD_LGUI),                               KC_SPC,                                 OSM(MOD_RGUI),MO(MAC_FN),OSM(MOD_RCTL),  KC_LEFT,  KC_DOWN,  KC_RGHT),

[MAC_FN] = LAYOUT_ansi_84(
     KC_TRNS,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_PSCR,  KC_DEL,   BL_STEP,
     KC_TRNS,  BT_HST1,  BT_HST2,  BT_HST3,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,
     BL_TOGG,  BL_STEP,  BL_INC,   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,
     KC_TRNS,  KC_TRNS,  BL_DEC,   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,            KC_TRNS,
     KC_TRNS,            KC_TRNS,  KC_TRNS,  KC_TRNS,  BAT_LVL,  MD_BOOT,  NK_TOGG,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,  KC_TRNS,  KC_TRNS,
     KC_TRNS,  KC_TRNS,  KC_TRNS,                                KC_TRNS,                                KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS),

[LIN_BASE] = LAYOUT_ansi_84(
     KC_ESC,   TG(MOUSE), C(KC_C),  C(KC_V), C(KC_F4), C(KC_PGUP), C(KC_PGDN),   C(KC_TAB), A(KC_GRV),   KC_F9,         KC_F10,   KC_F11,        KC_F12,     KC_SNAP,  KC_DEL,  G(KC_L),
     KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,            KC_PGUP,
     KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,            KC_PGDN,
     CW_TOGG,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,            KC_ENT,             KC_HOME,
     OSM(MOD_LSFT),            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,            OSM(MOD_RSFT),  KC_UP,    KC_END,
     OSM(MOD_LCTL),  OSM(MOD_LALT), OSM(MOD_LCTL),                               KC_SPC,                                 OSM(MOD_RCTL),MO(LIN_FN),OSM(MOD_RCTL),  KC_LEFT,  KC_DOWN,  KC_RGHT),

[LIN_FN] = LAYOUT_ansi_84(
     KC_TRNS,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_SNAP,  KC_DEL,   BL_STEP,
     KC_TRNS,  BT_HST1,  BT_HST2,  BT_HST3,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,
     BL_TOGG,  BL_STEP,  BL_INC,   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,
     KC_TRNS,  KC_TRNS,  BL_DEC,   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,            KC_TRNS,
     KC_TRNS,            KC_TRNS,  KC_TRNS,  KC_TRNS,  BAT_LVL,  MD_BOOT,  NK_TOGG,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,  KC_TRNS,  KC_TRNS,
     KC_TRNS,  KC_TRNS,  KC_TRNS,                                KC_TRNS,                                KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS),

[MOUSE] = LAYOUT_ansi_84(
     TG(MOUSE), KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_SNAP,  KC_DEL,   BL_STEP,
     XXXXXXX,   XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,  XXXXXXX,   XXXXXXX,            XXXXXXX,
     XXXXXXX,   XXXXXXX,     XXXXXXX,     XXXXXXX,     KC_BTN2,     XXXXXXX,     XXXXXXX,     KC_WH_U,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,
     XXXXXXX,  XXXXXXX,     XXXXXXX,     KC_WH_D,     KC_BTN1,     XXXXXXX,     KC_MS_L,     KC_MS_D,     KC_MS_U,     KC_MS_R,     XXXXXXX,  XXXXXXX,            XXXXXXX,             XXXXXXX,
     XXXXXXX,            XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,  XXXXXXX,   XXXXXXX,            XXXXXXX,  XXXXXXX,    XXXXXXX,
     XXXXXXX,  XXXXXXX, XXXXXXX,                               XXXXXXX,                                 XXXXXXX,XXXXXXX,XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX)
};

void keyboard_post_init_user(void) {
     led_matrix_disable();
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
     static uint32_t key_timer;

     switch (keycode) {
          case MD_BOOT:
               if (record->event.pressed) {
                    key_timer = timer_read32();
               } else {
                    if (timer_elapsed32(key_timer) >= 500) {
                         reset_keyboard();
                    }
               }
            return false;
     }

     return true;
}