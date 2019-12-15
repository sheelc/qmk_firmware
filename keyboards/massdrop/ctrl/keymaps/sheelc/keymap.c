#include QMK_KEYBOARD_H

enum ctrl_layers {
    _LIN_QWERTY = 0,
    _MAC_QWERTY,
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
    LIN_SW_APP,            //Linux Switch Apps
    LIN_SW_WIN,            //Linux Switch Windows
    LIN_PREV_TAB,          //Linux Prev Tab
    LIN_NEXT_TAB,          //Linux Next Tab
    LIN_CLOSE_WIN,         //Linux Close Window
    LIN_COPY,              //Linux Copy
    LIN_PASTE,             //Linux Paste
};

keymap_config_t keymap_config;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_LIN_QWERTY] = LAYOUT(
        KC_ESC,        KC_F1,         LIN_COPY,      LIN_PASTE,   LIN_CLOSE_WIN,   LIN_PREV_TAB,   LIN_NEXT_TAB,   LIN_SW_APP,   LIN_SW_WIN,   KC_F9,         KC_F10,   KC_F11,        KC_F12,             KC_PSCR, KC_SLCK, KC_PAUS, \
        KC_GRV,        KC_1,          KC_2,          KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,          KC_0,     KC_MINS,       KC_EQL,  KC_BSPC,   KC_INS,  KC_HOME, KC_PGUP, \
        KC_TAB,        KC_Q,          KC_W,          KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,          KC_P,     KC_LBRC,       KC_RBRC, KC_BSLS,   KC_DEL,  KC_END,  KC_PGDN, \
        KC_CAPS,       KC_A,          KC_S,          KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,          KC_SCLN,  KC_QUOT,       KC_ENT, \
        OSM(MOD_LSFT), KC_Z,          KC_X,          KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,        KC_SLSH,  OSM(MOD_RSFT),                              KC_UP, \
        OSM(MOD_LCTL), OSM(MOD_LGUI), OSM(MOD_LALT),                   KC_SPC,                             OSM(MOD_RALT), MO(_FNC), KC_APP,        OSM(MOD_RCTL),      KC_LEFT, KC_DOWN, KC_RGHT \
    ),
    [_MAC_QWERTY] = LAYOUT(
        KC_ESC,        KC_F1,         KC_F2,         KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,         KC_F10,   KC_F11,        KC_F12,             KC_PSCR, KC_SLCK, KC_PAUS, \
        KC_GRV,        KC_1,          KC_2,          KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,          KC_0,     KC_MINS,       KC_EQL,  KC_BSPC,   KC_INS,  KC_HOME, KC_PGUP, \
        KC_TAB,        KC_Q,          KC_W,          KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,          KC_P,     KC_LBRC,       KC_RBRC, KC_BSLS,   KC_DEL,  KC_END,  KC_PGDN, \
        KC_CAPS,       KC_A,          KC_S,          KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,          KC_SCLN,  KC_QUOT,       KC_ENT, \
        OSM(MOD_LSFT), KC_Z,          KC_X,          KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,        KC_SLSH,  OSM(MOD_RSFT),                              KC_UP, \
        OSM(MOD_LCTL), OSM(MOD_LGUI), OSM(MOD_LALT),                   KC_SPC,                             OSM(MOD_RALT), MO(_FNC), KC_APP,        OSM(MOD_RCTL),      KC_LEFT, KC_DOWN, KC_RGHT \
    ),
    [_FNC] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,            KC_MUTE, _______, _______, \
        _______, TG(_MAC_QWERTY), _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   KC_MPLY, KC_MSTP, KC_VOLU, \
        _______, RGB_SPD, RGB_VAI, RGB_SPI, RGB_HUI, RGB_SAI, _______, U_T_AUTO,U_T_AGCR,_______, _______, _______, _______, _______,   KC_MPRV, KC_MNXT, KC_VOLD, \
        _______, RGB_RMOD,RGB_VAD, RGB_MOD, RGB_HUD, RGB_SAD, _______, _______, _______, _______, _______, _______, _______, \
        _______, RGB_TOG, _______, _______, _______, MD_BOOT, NK_TOGG, _______, _______, _______, _______, _______,                              _______, \
        _______, _______, _______,                   _______,                            _______, _______, _______, _______,            _______, _______, _______ \
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

#define MODS_SHIFT  (get_mods() & MOD_BIT(KC_LSHIFT) || get_mods() & MOD_BIT(KC_RSHIFT))
#define MODS_CTRL  (get_mods() & MOD_BIT(KC_LCTL) || get_mods() & MOD_BIT(KC_RCTRL))
#define MODS_ALT  (get_mods() & MOD_BIT(KC_LALT) || get_mods() & MOD_BIT(KC_RALT))

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
        case LIN_SW_APP:
            if (record->event.pressed) {
                register_code(KC_LALT);
                tap_code(KC_TAB);
                unregister_code(KC_LALT);
            }
            break;
        case LIN_SW_WIN:
            if (record->event.pressed) {
                register_code(KC_LGUI);
                tap_code(KC_GRV);
                unregister_code(KC_LGUI);
            }
            break;
        case LIN_PREV_TAB:
            if (record->event.pressed) {
                register_code(KC_LALT);
                tap_code(KC_PGUP);
                unregister_code(KC_LALT);
            }
            break;
        case LIN_NEXT_TAB:
            if (record->event.pressed) {
                register_code(KC_LALT);
                tap_code(KC_PGDN);
                unregister_code(KC_LALT);
            }
            break;
        case LIN_CLOSE_WIN:
            if (record->event.pressed) {
                register_code(KC_LALT);
                tap_code(KC_F4);
                unregister_code(KC_LALT);
            }
            break;
        case LIN_COPY:
            if (record->event.pressed) {
                register_code(KC_LALT);
                tap_code(KC_C);
                unregister_code(KC_LALT);
            }
            break;
        case LIN_PASTE:
            if (record->event.pressed) {
                register_code(KC_LALT);
                tap_code(KC_V);
                unregister_code(KC_LALT);
            }
            break;
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

void oneshot_mods_changed_user(uint8_t mods) {
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
    } else {
        reset_random_color(76);
        reset_random_color(83);
    }

    if (mods & MOD_MASK_ALT) {
        rgb_matrix_set_color(78, RGB_RED); // LALT
        rgb_matrix_set_color(80, RGB_RED); // RALT
    } else {
        reset_random_color(78);
        reset_random_color(80);
    }

    if (mods & MOD_MASK_GUI) {
        rgb_matrix_set_color(77, RGB_RED); // GUI
    } else {
        reset_random_color(77);
    }
}

void rgb_matrix_indicators_user(void) {
    static bool clearedBoard = false;
    uint8_t layer = biton32(layer_state);

    switch (layer) {
    case _LIN_QWERTY:
    case _MAC_QWERTY:
        if (clearedBoard) {
            clearedBoard = false;
            for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
                reset_random_color(i);
            }
        }
        break;
    case _FNC:
        clearedBoard = true;
        bool mac_layer_on = layer_state_cmp(layer_state, _MAC_QWERTY);
        rgb_matrix_set_color_all(0, 0, 0);
        rgb_matrix_set_color(13, RGB_RED); // Mute
        if (mac_layer_on) {
            rgb_matrix_set_color(17, RGB_RED); // Number 1
        } else {
            rgb_matrix_set_color(17, RGB_GREEN);
        }

        rgb_matrix_set_color(30, RGB_GREEN); // Ins
        rgb_matrix_set_color(31, RGB_GREEN); // Home
        rgb_matrix_set_color(32, RGB_GREEN); // PageUp
        rgb_matrix_set_color(68, RGB_GOLD); // B
        return;
    }

    if ((get_oneshot_mods() & MOD_MASK_SHIFT) &&
        !has_oneshot_mods_timed_out()) {
        rgb_matrix_set_color(63, RGB_RED);
        rgb_matrix_set_color(74, RGB_RED);
    }

    if ((get_oneshot_mods() & MOD_MASK_CTRL) &&
        !has_oneshot_mods_timed_out()) {
        rgb_matrix_set_color(76, RGB_RED);
        rgb_matrix_set_color(83, RGB_RED);
    }

    if ((get_oneshot_mods() & MOD_MASK_ALT) &&
        !has_oneshot_mods_timed_out()) {
        rgb_matrix_set_color(78, RGB_RED);
        rgb_matrix_set_color(80, RGB_RED);
    }

    if ((get_oneshot_mods() & MOD_MASK_GUI) &&
        !has_oneshot_mods_timed_out()) {
        rgb_matrix_set_color(77, RGB_RED);
    }
}
