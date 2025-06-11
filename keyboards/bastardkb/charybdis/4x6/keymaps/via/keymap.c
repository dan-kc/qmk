#include QMK_KEYBOARD_H
#include "features/achordion.h"

#ifdef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE
#    include "timer.h"
#endif // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE

enum charybdis_keymap_layers { LAYER_BASE = 0, LAYER_NUMERAL, LAYER_NAVIGATION, LAYER_SYMBOLS, LAYER_SYSTEM, LAYER_SYMBOLS_2 };

// Base layer row mods
#define HRM_Z LGUI_T(KC_Z)
#define HRM_X LALT_T(KC_X)
#define HRM_C LCTL_T(KC_C)
#define HRM_D LSFT_T(KC_D)
#define HRM_H RSFT_T(KC_H)
#define HRM_COM RCTL_T(KC_COMM)
#define HRM_DOT RALT_T(KC_DOT)
#define HRM_ESC RGUI_T(KC_ESC)

// Thumb keys
#define ENT_SYM LT(LAYER_SYMBOLS, KC_ENT)
#define L_NUM MO(LAYER_NUMERAL)
#define L_NAV MO(LAYER_NAVIGATION)

// Misc
#define HASH LALT(KC_3)
#define POUND KC_HASH
#define CLN LSFT(KC_SCLN)

// enable auto sniping
#define CHARYBDIS_AUTO_SNIPING_ON_LAYER LAYER_NAVIGATION
#ifndef POINTING_DEVICE_ENABLE
#    define DRGSCRL KC_NO
#    define DPI_MOD KC_NO
#    define S_D_MOD KC_NO
#    define SNIPING KC_NO
#endif // !POINTING_DEVICE_ENABLE


#define _______________DEAD_HALF_ROW_______________ XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
#define _______________MOD_ROW_GACS_L______________ KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX
#define _______________MOD_ROW_GACS_R______________ XXXXXXX, KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LAYER_BASE] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX,    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,       KC_J,    KC_L,    KC_U,    KC_Y, KC_BSPC, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX,    KC_A,    KC_R,    KC_S,    KC_T,    KC_G,       KC_M,    KC_N,    KC_E,    KC_I,    KC_O, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX,   HRM_Z,   HRM_X,   HRM_C,   HRM_D,    KC_V,       KC_K,   HRM_H, HRM_COM, HRM_DOT, HRM_ESC, XXXXXXX,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                    L_NUM,   L_NAV, KC_LSFT,    ENT_SYM,  KC_SPC,
                                           XXXXXXX, XXXXXXX,    XXXXXXX
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),

  [LAYER_NUMERAL] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     KC_DEL,    KC_7,    KC_8,    KC_9, _______, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     KC_TAB,    KC_4,    KC_5,    KC_6, XXXXXXX, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,       KC_0,    KC_1,    KC_2,    KC_3, _______, XXXXXXX,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                  XXXXXXX, _______, _______,    _______, _______,
                                           XXXXXXX, XXXXXXX,    XXXXXXX
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),

  [LAYER_NAVIGATION] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     KC_INS, KC_HOME, KC_PGDN, KC_PGUP,  KC_END, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX, DRGSCRL, KC_BTN3, KC_BTN2, KC_BTN1, XXXXXXX,    XXXXXXX, KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,    XXXXXXX, KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI, XXXXXXX,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                  _______, XXXXXXX, _______,    _______, _______,
                                           XXXXXXX, XXXXXXX,    XXXXXXX
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),


  [LAYER_SYMBOLS] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, _______, _______, _______, _______, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX,  KC_DLR,   POUND, KC_AMPR, KC_ASTR, KC_CIRC,    KC_PLUS, KC_PERC, KC_QUOT,  KC_DQT,  KC_GRV, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX, KC_LCBR, KC_RCBR, KC_LPRN, KC_RPRN,   KC_AT,    KC_MINS,     CLN, KC_SCLN, KC_EXLM, KC_QUES, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX, KC_LABK, KC_RABK, KC_LBRC, KC_RBRC, KC_TILD,    KC_EQUAL,KC_UNDS, KC_SLSH, KC_PIPE, KC_BSLS, XXXXXXX,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                  _______, _______, _______,    XXXXXXX, _______,
                                           XXXXXXX, XXXXXXX,    XXXXXXX
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),

  [LAYER_SYSTEM] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX, KC_MUTE, KC_VOLD, KC_VOLU, XXXXXXX, XXXXXXX,    KC_PSCR,   KC_F7,   KC_F8,   KC_F9, _______, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX, KC_MSTP, KC_MPLY, KC_MNXT, XXXXXXX, XXXXXXX,    KC_PEQL,   KC_F4,   KC_F5,   KC_F6, XXXXXXX, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,    KC_PDOT,   KC_F1,   KC_F2,   KC_F3, _______, XXXXXXX,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                  XXXXXXX, _______, _______,    XXXXXXX, _______,
                                           XXXXXXX, XXXXXXX,    XXXXXXX
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),
};
// clang-format on

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    if (!process_achordion(keycode, record)) {
        return false;
    }

    return true;
}

bool is_thumb_or_combo(uint16_t keycode) {
    switch (keycode) {
        case L_NUM:
        case L_NAV:
        case KC_LSFT:
        case ENT_SYM:
        case KC_SPC:
            return true;
            break;
    }
    return false;
}

// Allow same hand cords for MOD keys + thumb
bool achordion_chord(uint16_t tap_hold_keycode, keyrecord_t* tap_hold_record, uint16_t other_keycode, keyrecord_t* other_record) {
    // Exceptionally consider the following chords as holds, even though they
    // are on the same hand in Colemak.
    switch (tap_hold_keycode) {
        // the following allows same hand modifiers and thumb keys e.g. cmd space
        case HRM_Z:
        case HRM_X:
        case HRM_C:
        case HRM_D:
        case HRM_H:
        case HRM_COM:
        case HRM_DOT:
        case HRM_ESC:
            if (is_thumb_or_combo(other_keycode)) {
                return true;
            }
            break;
    }
    // Otherwise, follow the opposite hands rule.
    return achordion_opposite_hands(tap_hold_record, other_record);
}

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t* record) {
    switch (keycode) {
        case L_NUM:
        case L_NAV:
        case ENT_SYM:
        case KC_SPC:
            return true;
        default:
            // Do not select the hold action when another key is pressed.
            return false;
    }
}

uint16_t achordion_timeout(uint16_t tap_hold_keycode) {
    switch (tap_hold_keycode) {
        case L_NUM:
        case L_NAV:
        case ENT_SYM:
        case KC_SPC:
            return 0; // Bypass Achordion for these keys.
    }
    return 800;
}

#ifdef POINTING_DEVICE_ENABLE
#    ifdef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE
report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    if (abs(mouse_report.x) > CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD || abs(mouse_report.y) > CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD) {
        if (auto_pointer_layer_timer == 0) {
            layer_on(LAYER_POINTER);
#        ifdef RGB_MATRIX_ENABLE
            rgb_matrix_mode_noeeprom(RGB_MATRIX_NONE);
            rgb_matrix_sethsv_noeeprom(HSV_GREEN);
#        endif // RGB_MATRIX_ENABLE
        }
        auto_pointer_layer_timer = timer_read();
    }
    return mouse_report;
}

void matrix_scan_user(void) {
    if (auto_pointer_layer_timer != 0 && TIMER_DIFF_16(timer_read(), auto_pointer_layer_timer) >= CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS) {
        auto_pointer_layer_timer = 0;
        layer_off(LAYER_POINTER);
#        ifdef RGB_MATRIX_ENABLE
        rgb_matrix_mode_noeeprom(RGB_MATRIX_DEFAULT_MODE);
#        endif // RGB_MATRIX_ENABLE
    }
}
#    endif // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE

#    ifdef CHARYBDIS_AUTO_SNIPING_ON_LAYER
layer_state_t layer_state_set_user(layer_state_t state) {
    state = update_tri_layer_state(state, LAYER_NUMERAL, LAYER_SYMBOLS, LAYER_SYSTEM);
    charybdis_set_pointer_sniping_enabled(layer_state_cmp(state, CHARYBDIS_AUTO_SNIPING_ON_LAYER));
    return state;
}
#    endif // CHARYBDIS_AUTO_SNIPING_ON_LAYER
#endif     // POINTING_DEVICE_ENABLE

#ifdef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE
static uint16_t auto_pointer_layer_timer = 0;

#    ifndef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS
#        define CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS 1000
#    endif // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS

#    ifndef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD
#        define CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD 8
#    endif // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD
#endif     // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE

