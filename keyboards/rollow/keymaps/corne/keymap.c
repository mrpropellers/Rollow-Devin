#include QMK_KEYBOARD_H

enum rollow_layers {
    _BASE,
    _NUMBERS,
    _SYMBOLS,
    _MEDIA,
    _MODIFY
};

enum custom_keycodes {
    KC_BASE = SAFE_RANGE,
    KC_LOWER,
    KC_RAISE,
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
 /* BASE
 * .-----------------------------------------.                    .-----------------------------------------.
 * | ESC  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |                    |   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------.    .-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * '-----------------------------------------/       /     \      \-----------------------------------------'
 *                          | LALT |LOWER | / Enter /       \ Space\  |TT(RS)| RTCR |
 *                          |      |      |/       /         \      \ |      |      |
 *                          '-------------''------'           '------''-------------'
 *
 *   Encoder Mapping
 *   --------------------------
 *   Left Encoder: Up <-> Down
 *   Right Encoder: Left <-> Right
 */


[_BASE] = LAYOUT_split_3x6_3( \
  KC_LBRC,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  KC_RBRC, \
  LT(_NUMBERS, KC_TAB),   KC_A,   KC_S,    KC_D,    KC_F,    KC_G,       KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN,  KC_QUOT, \
  KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,                     KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  MO(_SYMBOLS), \
                            KC_LALT, KC_LCTRL, LT(_MODIFY, KC_ENT),      KC_SPC,  KC_BSPC, KC_DEL \
),

/*
[_BASE] = LAYOUT_split_3x5_3( \
  KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, \
  KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                     KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, \
  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,                     KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, \
                                  KC_LALT, KC_LOWER, KC_ENT,      KC_SPC,  KC_RAISE, KC_RCTRL \
),*/

  /* LOWER
 * .-----------------------------------------.                    .-----------------------------------------.
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   !  |   @  |   #  |   $  |   %  |                    |   ^  |   &  |   *  |   (  |   )  |   |  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Shift|  =   |  -   |  +   |   {  |   }  |-------.    .-------|   [  |   ]  |   ;  |   :  |   \  | Shift|
 * '-----------------------------------------/       /     \      \-----------------------------------------'
 *                          | LALT |LOWER | / Enter /       \ Space\  |RAISE | RCTR |
 *                          |      |      |/       /         \      \ |      |      |
 *                          '-------------''------'           '------''-------------'
 *
 *   Encoder Mapping
 *   --------------------------
 *   Left Encoder: PG_UP <-> PG_DN
 *   Right Encoder: -
 */

[_NUMBERS] = LAYOUT_split_3x6_3( \
  _______,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                          KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______, \
  _______, _______, _______,  _______, _______, _______,                      _______, _______, _______,  _______, _______, _______, \
  _______, _______, _______,  _______, _______, _______,                      _______, _______, _______,  _______, _______, _______, \
                                      _______, _______, _______,       _______, _______, _______ \
),

 /* RAISE
 * .-----------------------------------------.                    .-----------------------------------------.
 * | Esc  |      |      |      |      |      |                    |      |      |  Up  |      |      |BackSp|
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  | LAt  | LCtl |      |      |      |                    |      | Left | Down |Right |Delete|      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |Shift | Undo | Cut  | Copy |Paste |      |-------.    .-------|      |      |      |      |   _  |      |
 * '-----------------------------------------/       /     \      \-----------------------------------------'
 *                          | LALT |LOWER | / Enter /       \ Space\  |RAISE | RCTR |
 *                          |      |      |/       /         \      \ |      |      |
 *                          '------------''------'            '------''-------------'
 *
 *   Encoder Left: -
 *   Encoder Right: VOL_UP VOL_D
 */

[_SYMBOLS] = LAYOUT_split_3x6_3( \
  KC_GRV, _______, _______, _______,  _______, _______,                       _______, _______, _______,  _______, _______, KC_BSLS, \
  _______,  KC_EXLM, KC_AT,  KC_HASH, KC_DLR, KC_PERC,                      KC_EQL, KC_PLUS, _______,  _______, _______, _______, \
  _______, KC_CIRC, KC_AMPR,  KC_ASTR, KC_LPRN, KC_RPRN,                       KC_MINS, KC_UNDS, _______,  _______, _______, _______, \
                                      _______, _______, _______,       _______, _______, _______ \
),

[_MEDIA] = LAYOUT_split_3x6_3( \
  KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6,                                   KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11, KC_F12, \
  TO(_BASE), KC_MPRV, KC_VOLD,  KC_VOLU, KC_MNXT, XXXXXXX,                      KC_INS, KC_HOME, KC_PGUP,  XXXXXXX, XXXXXXX, _______, \
  _______, _______, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,                      KC_DEL, KC_END, KC_PGDN, XXXXXXX, XXXXXXX, TO(_BASE), \
                                      _______, _______, KC_MPLY,       KC_MUTE, _______, TO(_BASE) \
),

[_MODIFY] = LAYOUT_split_3x6_3( \
  LSFT(KC_LBRC), _______, _______,  _______, _______, KC_ESC,                 _______, _______, _______,  LSFT(KC_9), LSFT(KC_0), LSFT(KC_RBRC), \
  _______, LSFT(KC_A), _______,  _______, _______, _______,                      _______, KC_LEFT, KC_DOWN,  KC_UP, KC_RIGHT, _______, \
  _______, _______, _______,  _______, LSFT(KC_V), _______,                      _______, TO(_MEDIA), _______,  _______, _______, _______, \
                                      KC_LGUI, _______, _______,       _______, KC_DEL, _______ \
)
};

#ifdef OLED_ENABLE

/*
static void render_logo(void) {
    static const char PROGMEM qmk_logo[] = {
        0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
        0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
        0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0
    };

    oled_write_P(qmk_logo, false);
}
*/




static void print_status_narrow(void) {
    // Print current mode
    oled_write_P(PSTR("d.vok\n-----"), false);
    oled_write_P(PSTR("\n\n"), false);
    // oled_write_ln_P(PSTR("MODE"), false);
    // oled_write_ln_P(PSTR(""), false);
    // if (keymap_config.swap_lctl_lgui) {
    //     oled_write_ln_P(PSTR("MAC"), false);
    // } else {
    //     oled_write_ln_P(PSTR("WIN"), false);
    // }

    // switch (get_highest_layer(default_layer_state)) {
    //     case _BASE:
    //         oled_write_ln_P(PSTR("Base"), false);
    //         break;
    //     default:
    //         oled_write_P(PSTR("Undef"), false);
    // }
    oled_write_P(PSTR("\n\n"), false);
    // Print current layer
    oled_write_ln_P(PSTR("LAYER"), false);
    switch (get_highest_layer(layer_state)) {
        case _BASE:
            oled_write_P(PSTR("Base\n"), false);
            break;
        case _NUMBERS:
            oled_write_P(PSTR("Num\n"), false);
            break;
        case _SYMBOLS:
            oled_write_P(PSTR("Glyph\n"), false);
            break;
        case _MEDIA:
            oled_write_P(PSTR("Media\n"), false);
            break;
        case _MODIFY:
            oled_write_P(PSTR("Mod\n"), false);
            break;
//         case _RAISE:
//             oled_write_P(PSTR("Raise"), false);
//             break;
//         case _LOWER:
//             oled_write_P(PSTR("Lower"), false);
//             break;
        default:
            oled_write_ln_P(PSTR("????"), false);
    }
    //oled_write_P(PSTR("\n\n"), false);
    //led_t led_usb_state = host_keyboard_led_state();
    //oled_write_ln_P(PSTR("CPSLK"), led_usb_state.caps_lock);
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {

    // if (is_keyboard_master()) {
    //     return OLED_ROTATION_270;
    // }
    // return rotation;
    return OLED_ROTATION_270;
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        print_status_narrow();
    } else {
        print_status_narrow();
        //render_logo();
    }
    return false;
}

#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_BASE:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_BASE);
            }
            return false;
//         case KC_LOWER:
//             if (record->event.pressed) {
//                 layer_on(_LOWER);
//             } else {
//                 layer_off(_LOWER);
//             }
//             return false;
//         case KC_RAISE:
//             if (record->event.pressed) {
//                 layer_on(_RAISE);
//             } else {
//                 layer_off(_RAISE);
//             }
//             return false;
    }
    return true;
}

#ifdef ENCODER_ENABLE

bool encoder_update_user(uint8_t index, bool clockwise) {
            tap_code(KC_UP);
    if (index == 0) {
        if (clockwise) {
        } else {
            tap_code(KC_DOWN);
        }
    } else if (index == 1) {
        if (clockwise) {
            tap_code(KC_LEFT);
        } else {
            tap_code(KC_RIGHT);
        }
    }
    return true;
}

#endif
