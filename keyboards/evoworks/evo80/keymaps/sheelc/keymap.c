#include QMK_KEYBOARD_H
#include "rdmctmzt_common.h"

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_tkl_ansi(
        KC_ESC,  KC_F1,    C(KC_C),  C(KC_V),     C(KC_F4),     C(KC_PGUP), C(KC_PGDN), C(KC_TAB), A(KC_GRV), KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_F13,   KC_PSCR,  KC_SCRL,  KC_PAUS,
        KC_GRV,  KC_1,     KC_2,     KC_3,        KC_4,         KC_5,     KC_6,      KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,  KC_INS,   KC_HOME,  KC_PGUP,
        KC_TAB,  KC_Q,     KC_W,     KC_E,        KC_R,         KC_T,     KC_Y,      KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,  KC_DEL,   KC_END,   KC_PGDN,
        CW_TOGG, CW_TOGG,  KC_A,     KC_S,        KC_D,         KC_F,     KC_G,      KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,  KC_K42,   KC_ENT,   KC_ENT,
        OSM(MOD_LSFT), KC_K45, KC_Z, KC_X,        KC_C,         KC_V,     KC_B,      KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,            OSM(MOD_RSFT), KC_UP,
        OSM(MOD_LCTL), OSM(MOD_LGUI), OSM(MOD_LCTL),                          KC_SPC,                                  OSM(MOD_RALT), OSM(MOD_RGUI), MO(2),    OSM(MOD_RCTL), KC_LEFT,  KC_DOWN,  KC_RGHT
    ),
    [1] = LAYOUT_tkl_ansi(
        KC_TRNS, KC_TRNS,  G(KC_C),  G(KC_V),     G(KC_W),      G(S(KC_LBRC)), G(S(KC_RBRC)), G(KC_TAB), G(KC_GRV), KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  G(C(KC_S)), G(C(KC_Q)),
        KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS,     KC_TRNS,      KC_TRNS,  KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  G(S(KC_A)),
        KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS,     KC_TRNS,      KC_TRNS,  KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
        KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS,     KC_TRNS,      KC_TRNS,  KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
        KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS,     KC_TRNS,      KC_TRNS,  KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,  KC_TRNS,
        OSM(MOD_LCTL), OSM(MOD_LALT), OSM(MOD_LGUI),                            KC_SPC,                                OSM(MOD_RGUI), OSM(MOD_RALT), MO(2),    OSM(MOD_RCTL), KC_TRNS,  KC_TRNS,  KC_TRNS
    ),
    [2] = LAYOUT_tkl_ansi(
        KC_ESC,  KC_F1,    KC_F2,    KC_F3,       KC_F4,        KC_F5,    KC_F6,     KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_F13,   KC_MUTE,  KC_TRNS,  KC_TRNS,
        MD_USB,  MD_BLE1,  MD_BLE2,  MD_BLE3,     MD_24G,       KC_5,     KC_6,      KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,  KC_MPLY,  KC_MSTP,  KC_VOLU,
        KC_TAB,  TG(1),    LOGO_MOD, LOGO_RMOD,   LOGO_HUI,     LOGO_HUD, LOGO_SAI,  LOGO_SAD, LOGO_VAI, LOGO_VAD, LOGO_SPI, LOGO_SPD, KC_RBRC,  KC_BSLS,  KC_MPRV,  KC_MNXT,  KC_VOLD,
        KC_CAPS, KC_CAPS,  KC_A,     KC_S,        QK_BAT,       KC_F,     KC_G,      KC_NO,    KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,  KC_K42,   KC_ENT,   KC_ENT,
        KC_LSFT, KC_K45,   RM_TOGG,  RM_NEXT,     RM_PREV,      RM_HUEU,  RM_HUED,   RM_SATU,  RM_SATD,  RM_VALU,  RM_VALD,  KC_SLSH,            KC_RSFT,  RM_SPDU,
        KC_LCTL, QK_WLO,   KC_LALT,                             KC_SPC,                                  KC_RALT,  KC_RGUI,  MO(3),    KC_RCTL,  KC_LEFT,  RM_SPDD,  KC_RGHT
    ),
    [3] = LAYOUT_tkl_ansi(
        KC_ESC,  KC_F1,    KC_F2,    KC_F3,       KC_F4,        KC_F5,    KC_F6,     KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_F13,   KC_MUTE,  KC_TRNS,  KC_TRNS,
        MD_USB,  MD_BLE1,  MD_BLE2,  MD_BLE3,     MD_24G,       KC_5,     KC_6,      KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,  KC_MPLY,  KC_MSTP,  KC_VOLU,
        KC_TAB,  LOGO_TOG, LOGO_MOD, LOGO_RMOD,   LOGO_HUI,     LOGO_HUD, LOGO_SAI,  LOGO_SAD, LOGO_VAI, LOGO_VAD, LOGO_SPI, LOGO_SPD, KC_RBRC,  KC_BSLS,  KC_MPRV,  KC_MNXT,  KC_VOLD,
        KC_CAPS, KC_CAPS,  KC_A,     KC_S,        QK_BAT,       KC_F,     KC_G,      KC_NO,    KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,  KC_K42,   KC_ENT,   KC_ENT,
        KC_LSFT, KC_K45,   RM_TOGG,  RM_NEXT,     RM_PREV,      RM_HUEU,  RM_HUED,   RM_SATU,  RM_SATD,  RM_VALU,  RM_VALD,  KC_SLSH,            KC_RSFT,  RM_SPDU,
        KC_LCTL, QK_WLO,   KC_LGUI,                             KC_SPC,                                  KC_RGUI,  KC_RALT,  KC_NO,    KC_RCTL,  KC_LEFT,  RM_SPDD,  KC_RGHT
    )
};
// clang-format on

void keyboard_post_init_user(void) {
#ifdef OFFICE_MODE
    // Default to Mac Mode
    layer_on(1);
    
    // Turn off general key backlight by setting it to solid black
    rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
    rgb_matrix_sethsv_noeeprom(0, 0, 0);
#endif
}

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    // If we are currently holding the Function key (Layer 2)
    if (get_highest_layer(layer_state) == 2) {
        // LED Index 35 is the 'Q' key on the Evo80 matrix
        if (layer_state_is(1)) {
            // Mac Mode is ON -> Red
            RGB_MATRIX_INDICATOR_SET_COLOR(35, 255, 0, 0);
        } else {
            // Linux Mode (Layer 1 OFF) -> Green
            RGB_MATRIX_INDICATOR_SET_COLOR(35, 0, 255, 0);
        }
    }
    
    // Return false to allow the base Evo80 Bluetooth/Battery indicators to run!
    return false;
}
