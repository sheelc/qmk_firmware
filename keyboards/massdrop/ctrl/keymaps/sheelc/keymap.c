#include QMK_KEYBOARD_H

enum ctrl_layers {
    _LIN_QWERTY = 0,
    _MAC_QWERTY,
    _TAP,
    _FNC
};

enum ctrl_keycodes {
    U_T_AUTO = SAFE_RANGE, //USB Extra Port Toggle Auto Detect / Always Active
    U_T_AGCR,              //USB Toggle Automatic GCR control
    DBG_TOG,               //DEBUG Toggle On / Off
    DBG_MTRX,              //DEBUG Toggle Matrix Prints
    DBG_KBD,               //DEBUG Toggle Keyboard Prints
    DBG_MOU,               //DEBUG Toggle Mouse Prints
    MD_BOOT,               //Restart into bootloader after hold timeout
};

enum td_keycodes {
    TD_LPAR = 0,
    TD_RPAR,
    TD_MINS,
    TD_LBRC,
    TD_RBRC,
    TD_SCLN,
    TD_QUOT,
    TD_COMMA,
    TD_DOT,
    TD_SLSH
};

keymap_config_t keymap_config;

qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_LPAR] = ACTION_TAP_DANCE_DOUBLE(KC_9, S(KC_9)),
    [TD_RPAR] = ACTION_TAP_DANCE_DOUBLE(KC_0, S(KC_0)),
    [TD_MINS] = ACTION_TAP_DANCE_DOUBLE(KC_MINS, S(KC_MINS)),
    [TD_LBRC] = ACTION_TAP_DANCE_DOUBLE(KC_LBRC, S(KC_LBRC)),
    [TD_RBRC] = ACTION_TAP_DANCE_DOUBLE(KC_RBRC, S(KC_RBRC)),
    [TD_SCLN] = ACTION_TAP_DANCE_DOUBLE(KC_SCLN, S(KC_SCLN)),
    [TD_QUOT] = ACTION_TAP_DANCE_DOUBLE(KC_QUOT, S(KC_QUOT)),
    [TD_COMMA] = ACTION_TAP_DANCE_DOUBLE(KC_COMM, S(KC_COMM)),
    [TD_DOT] = ACTION_TAP_DANCE_DOUBLE(KC_DOT, S(KC_DOT)),
    [TD_SLSH] = ACTION_TAP_DANCE_DOUBLE(KC_SLSH, S(KC_SLSH)),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_LIN_QWERTY] = LAYOUT(
        KC_ESC,        KC_F1,         C(KC_C),       C(KC_V), C(KC_F4), C(KC_PGUP), C(KC_PGDN),   C(KC_TAB),   A(KC_GRV),   KC_F9,         KC_F10,   KC_F11,        KC_F12,             KC_PSCR, KC_SLCK, KC_PAUS, \
        KC_GRV,        KC_1,          KC_2,          KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,          KC_0,     KC_MINS,       KC_EQL,  KC_BSPC,   KC_INS,  KC_HOME, KC_PGUP, \
        KC_TAB,        KC_Q,          KC_W,          KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,          KC_P,     KC_LBRC,       KC_RBRC, KC_BSLS,   KC_DEL,  KC_END,  KC_PGDN, \
        KC_CAPS,       KC_A,          KC_S,          KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,          KC_SCLN,  KC_QUOT,       KC_ENT, \
        OSM(MOD_LSFT), KC_Z,          KC_X,          KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,        KC_SLSH,  OSM(MOD_RSFT),                              KC_UP, \
        OSM(MOD_LCTL), OSM(MOD_LALT), OSM(MOD_LCTL),                   KC_SPC,                             OSM(MOD_RCTL), MO(_FNC), KC_APP,        OSM(MOD_RCTL),      KC_LEFT, KC_DOWN, KC_RGHT \
    ),
    [_MAC_QWERTY] = LAYOUT(
        KC_ESC,        KC_F1,         G(KC_C),       G(KC_V),   G(KC_W),   G(S(KC_LBRC)),   G(S(KC_RBRC)),   G(KC_TAB),   G(KC_GRV),   KC_F9,         KC_F10,   KC_F11,        KC_F12,             KC_PSCR, KC_SLCK, KC_PAUS, \
        KC_GRV,        KC_1,          KC_2,          KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,          KC_0,     KC_MINS,       KC_EQL,  KC_BSPC,   KC_INS,  KC_HOME, KC_PGUP, \
        KC_TAB,        KC_Q,          KC_W,          KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,          KC_P,     KC_LBRC,       KC_RBRC, KC_BSLS,   KC_DEL,  KC_END,  KC_PGDN, \
        KC_CAPS,       KC_A,          KC_S,          KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,          KC_SCLN,  KC_QUOT,       KC_ENT, \
        OSM(MOD_LSFT), KC_Z,          KC_X,          KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,        KC_SLSH,  OSM(MOD_RSFT),                              KC_UP, \
        OSM(MOD_LCTL), OSM(MOD_LALT), OSM(MOD_LGUI),                   KC_SPC,                             OSM(MOD_RGUI), MO(_FNC), KC_APP,        OSM(MOD_RCTL),      KC_LEFT, KC_DOWN, KC_RGHT \
    ),
    [_TAP] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,            _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, TD(TD_LPAR), TD(TD_RPAR), TD(TD_MINS), _______, _______,   _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, TD(TD_LBRC), TD(TD_RBRC), _______,   _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, TD(TD_SCLN), TD(TD_QUOT), _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, TD(TD_COMMA), TD(TD_DOT), TD(TD_SLSH), _______,                              _______, \
        _______, _______, _______,                   _______,                            _______, _______, _______, _______,            _______, _______, _______ \
    ),
    [_FNC] = LAYOUT(
        _______, KC_F1,   KC_F2,   KC_F3,    KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,            KC_MUTE, _______, _______, \
        _______, TG(_MAC_QWERTY),  TG(_TAP), _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   KC_MPLY, KC_MSTP, KC_VOLU, \
        _______, RGB_SPD, RGB_VAI, RGB_SPI,  RGB_HUI, RGB_SAI, _______, U_T_AUTO,U_T_AGCR,_______, _______, _______, _______, _______,   KC_MPRV, KC_MNXT, KC_VOLD, \
        _______, RGB_RMOD,RGB_VAD, RGB_MOD,  RGB_HUD, RGB_SAD, _______, _______, _______, _______, _______, _______, _______, \
        _______, RGB_TOG, _______, _______,  _______, MD_BOOT, NK_TOGG, _______, _______, _______, _______, _______,                              _______, \
        _______, _______, _______,                    _______,                            _______, _______, _______, _______,            _______, _______, _______ \
    ),
    /*
    [X] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,            _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, NK_TOGG, _______, _______, _______, _______, _______,                              _______, \
        _______, _______, _______,                   _______,                            _______, _______, _______, _______,            _______, _______, _______ \
    ),
    */
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {
};

#define MODS_SHIFT  (get_mods() & MOD_MASK_SHIFT)
#define MODS_CTRL  (get_mods() & MOD_MASK_CTRL)
#define MODS_ALT  (get_mods() & MOD_MASK_ALT)

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static uint32_t key_timer;

    switch (keycode) {
        case U_T_AUTO:
            if (record->event.pressed && MODS_SHIFT && MODS_CTRL) {
                TOGGLE_FLAG_AND_PRINT(usb_extra_manual, "USB extra port manual mode");
            }
            return false;
        case U_T_AGCR:
            if (record->event.pressed && MODS_SHIFT && MODS_CTRL) {
                TOGGLE_FLAG_AND_PRINT(usb_gcr_auto, "USB GCR auto mode");
            }
            return false;
        case DBG_TOG:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_enable, "Debug mode");
            }
            return false;
        case DBG_MTRX:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_matrix, "Debug matrix");
            }
            return false;
        case DBG_KBD:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_keyboard, "Debug keyboard");
            }
            return false;
        case DBG_MOU:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_mouse, "Debug mouse");
            }
            return false;
        case MD_BOOT:
            if (record->event.pressed) {
                key_timer = timer_read32();
            } else {
                if (timer_elapsed32(key_timer) >= 500) {
                    reset_keyboard();
                }
            }
            return false;
        case RGB_TOG:
            if (record->event.pressed) {
              switch (rgb_matrix_get_flags()) {
                case LED_FLAG_ALL: {
                    rgb_matrix_set_flags(LED_FLAG_KEYLIGHT | LED_FLAG_MODIFIER);
                    rgb_matrix_set_color_all(0, 0, 0);
                  }
                  break;
                case LED_FLAG_KEYLIGHT | LED_FLAG_MODIFIER: {
                    rgb_matrix_set_flags(LED_FLAG_UNDERGLOW);
                    rgb_matrix_set_color_all(0, 0, 0);
                  }
                  break;
                case LED_FLAG_UNDERGLOW: {
                    rgb_matrix_set_flags(LED_FLAG_NONE);
                    rgb_matrix_disable_noeeprom();
                  }
                  break;
                default: {
                    rgb_matrix_set_flags(LED_FLAG_ALL);
                    rgb_matrix_enable_noeeprom();
                  }
                  break;
              }
            }
            return false;
        default:
            return true; //Process all other keycodes normally
    }

    return true;
}

void reset_random_color(int i) {
    HSV hsv = {rand() & 0xFF, rand() & 0xFF, rgb_matrix_config.hsv.v};
    RGB rgb = hsv_to_rgb(hsv);
    rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
}

bool keylights_enabled(void) {
    return !(rgb_matrix_get_flags() == LED_FLAG_NONE ||
             rgb_matrix_get_flags() == LED_FLAG_UNDERGLOW);
}

void oneshot_mods_changed_user(uint8_t mods) {
    if (g_suspend_state || !rgb_matrix_config.enable || !keylights_enabled()) {
        return;
    }

    bool mac_layer_on = layer_state_cmp(layer_state, _MAC_QWERTY);
    if (mods & MOD_MASK_SHIFT) {
        rgb_matrix_set_color(63, RGB_RED);
        rgb_matrix_set_color(74, RGB_RED);
    } else {
        reset_random_color(63); // LSHIFT
        reset_random_color(74); // RSHIFT
    }

    if (mods & MOD_MASK_CTRL) {
        rgb_matrix_set_color(76, RGB_RED); // LCTRL
        rgb_matrix_set_color(83, RGB_RED); // RCTRL
        if (!mac_layer_on) {
            rgb_matrix_set_color(78, RGB_RED); // LALT
            rgb_matrix_set_color(80, RGB_RED); // RALT
        }
    } else {
        reset_random_color(76);
        reset_random_color(83);
        if (!mac_layer_on) {
            reset_random_color(78);
            reset_random_color(80);
        }
    }

    if (mods & MOD_MASK_ALT) {
        rgb_matrix_set_color(77, RGB_RED); // GUI
    } else {
        reset_random_color(77);
    }

    if (mac_layer_on) {
        if (mods & MOD_MASK_GUI) {
            rgb_matrix_set_color(78, RGB_RED); // GUI
            rgb_matrix_set_color(80, RGB_RED); // GUI
        } else {
            reset_random_color(78);
            reset_random_color(80);
        }
    }
}

void reset_lights(void) {
    switch(rgb_matrix_get_flags()) {
    case LED_FLAG_NONE:
        break;
    case LED_FLAG_UNDERGLOW:
        for (int i = 0; i < UNDERGLOW_LIGHT_INDEX; i++) {
            rgb_matrix_set_color(i, 0, 0, 0);
        }
        for (int i = UNDERGLOW_LIGHT_INDEX; i < DRIVER_LED_TOTAL; i++) {
            reset_random_color(i);
        }
        break;
    case LED_FLAG_KEYLIGHT | LED_FLAG_MODIFIER:
        for (int i = 0; i < UNDERGLOW_LIGHT_INDEX; i++) {
            reset_random_color(i);
        }
        break;
    case LED_FLAG_ALL:
        for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
            reset_random_color(i);
        }
    }
}

void rgb_matrix_indicators_user(void) {
    if (g_suspend_state || !rgb_matrix_config.enable || rgb_matrix_get_flags() == LED_FLAG_NONE) {
        return;
    }

    static bool cleared_board = false;
    uint8_t layer = biton32(layer_state);
    bool mac_layer_on = layer_state_cmp(layer_state, _MAC_QWERTY);
    bool tap_layer_on = layer_state_cmp(layer_state, _TAP);

    switch (layer) {
    case _LIN_QWERTY:
    case _MAC_QWERTY:
    case _TAP:
        if (cleared_board) {
            cleared_board = false;
            reset_lights();
        }
        break;
    case _FNC:
        if (keylights_enabled()) {
            cleared_board = true;
            rgb_matrix_set_color_all(0, 0, 0);
            rgb_matrix_set_color(1, RGB_MAGENTA); // F1
            rgb_matrix_set_color(2, RGB_MAGENTA); // F2
            rgb_matrix_set_color(3, RGB_MAGENTA); // F3
            rgb_matrix_set_color(4, RGB_MAGENTA); // F4
            rgb_matrix_set_color(5, RGB_MAGENTA); // F5
            rgb_matrix_set_color(6, RGB_MAGENTA); // F6
            rgb_matrix_set_color(7, RGB_MAGENTA); // F7
            rgb_matrix_set_color(8, RGB_MAGENTA); // F8
            rgb_matrix_set_color(9, RGB_MAGENTA); // F9
            rgb_matrix_set_color(10, RGB_MAGENTA); // F10
            rgb_matrix_set_color(11, RGB_MAGENTA); // F11
            rgb_matrix_set_color(12, RGB_MAGENTA); // F12
            rgb_matrix_set_color(13, RGB_RED); // Mute
            if (mac_layer_on) {
                rgb_matrix_set_color(17, RGB_RED); // Number 1
            } else {
                rgb_matrix_set_color(17, RGB_GREEN);
            }

            if (tap_layer_on) {
                rgb_matrix_set_color(18, RGB_RED); // Number 2
            } else {
                rgb_matrix_set_color(18, RGB_GREEN);
            }

            rgb_matrix_set_color(30, RGB_GREEN); // Ins
            rgb_matrix_set_color(31, RGB_GREEN); // Home
            rgb_matrix_set_color(32, RGB_GREEN); // PageUp
            rgb_matrix_set_color(47, RGB_GREEN); // Del
            rgb_matrix_set_color(48, RGB_GREEN); // End
            rgb_matrix_set_color(49, RGB_GREEN); // PageDn
            rgb_matrix_set_color(51, RGB_PURPLE); // A
            rgb_matrix_set_color(64, RGB_PURPLE); // Z
            rgb_matrix_set_color(68, RGB_GOLD); // B
        }
        return;
    }

    if (keylights_enabled()) {
        if ((get_oneshot_mods() & MOD_MASK_SHIFT) &&
            !has_oneshot_mods_timed_out()) {
            rgb_matrix_set_color(63, RGB_RED);
            rgb_matrix_set_color(74, RGB_RED);
        }

        if ((get_oneshot_mods() & MOD_MASK_CTRL) &&
            !has_oneshot_mods_timed_out()) {
            rgb_matrix_set_color(76, RGB_RED);
            rgb_matrix_set_color(83, RGB_RED);
            if (!mac_layer_on) {
                rgb_matrix_set_color(78, RGB_RED);
                rgb_matrix_set_color(80, RGB_RED);
            }
        }

        if ((get_oneshot_mods() & MOD_MASK_ALT) &&
            !has_oneshot_mods_timed_out()) {
            rgb_matrix_set_color(77, RGB_RED);
        }

        if (mac_layer_on &&
            (get_oneshot_mods() & MOD_MASK_GUI) &&
            !has_oneshot_mods_timed_out()) {
            rgb_matrix_set_color(78, RGB_RED);
            rgb_matrix_set_color(80, RGB_RED);
        }
    }
}
