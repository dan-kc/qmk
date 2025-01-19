#include QMK_KEYBOARD_H
#include "features/achordion.h"

// Define layers
enum charybdis_keymap_layers { LAYER_BASE = 0, LAYER_NUMERAL, LAYER_NAVIGATION, LAYER_SYMBOLS, LAYER_MEDIA };

// Thumb keys
#define SPC_NAV LT(LAYER_NAVIGATION, KC_SPC)
#define ENT_SYM LT(LAYER_SYMBOLS, KC_ENT)
#define ESC_NUM LT(LAYER_NUMERAL, KC_ESC)

// Base layer row mods
#define HOME_Z LGUI_T(KC_Z)
#define HOME_X LALT_T(KC_X)
#define HOME_C LCTL_T(KC_C)
#define HOME_D LSFT_T(KC_D)
#define HOME_H RSFT_T(KC_H)
#define HOME_COMM RCTL_T(KC_COMM)
#define HOME_DOT RALT_T(KC_DOT)
#define HOME_SLSH RGUI_T(KC_SLSH)

// Symbols layer row mods
#define HOME_LABK LGUI_T(KC_LABK)
#define HOME_RABK LALT_T(KC_RABK)
#define HOME_LBRC LCTL_T(KC_LBRC)
#define HOME_RBRC LSFT_T(KC_RBRC)
#define HOME_UNDS RSFT_T(KC_UNDS)
#define HOME_SCLN RCTL_T(KC_SCLN)
#define HOME_QUES RALT_T(KC_QUES)
#define HOME_BSLS RGUI_T(KC_BSLS)

// Misc
#define HASH LALT(KC_3)
#define POUND KC_HASH

// enable auto sniping
#define CHARYBDIS_AUTO_SNIPING_ON_LAYER LAYER_NAVIGATION
#ifndef POINTING_DEVICE_ENABLE
#    define DRGSCRL KC_NO
#    define DPI_MOD KC_NO
#    define S_D_MOD KC_NO
#    define SNIPING KC_NO
#endif // !POINTING_DEVICE_ENABLE

#define _______________DEAD_HALF_ROW_______________ XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
#define ______________MOD_ROW_GACS_L______________ KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX
#define ______________MOD_ROW_GACS_R______________ XXXXXXX, KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI

// clang-format off
#define LAYOUT_LAYER_BASE                                                                     \
       KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_J,    KC_L,    KC_U,    KC_Y, KC_QUOT, \
       KC_A,    KC_R,    KC_S,    KC_T,    KC_G,    KC_M,  KC_N, KC_E,KC_I, KC_O,    \
       HOME_Z,HOME_X,HOME_C,HOME_D,KC_V,   KC_K ,   HOME_H, HOME_COMM ,HOME_DOT, HOME_SLSH, \
                      ESC_NUM, SPC_NAV,KC_LSFT,ENT_SYM,KC_BSPC

#define LAYOUT_LAYER_NUMERAL                                                                  \
    _______________DEAD_HALF_ROW_______________,   XXXXXXX,    KC_7,    KC_8,    KC_9, XXXXXXX,  \
    _______________DEAD_HALF_ROW_______________,   XXXXXXX,    KC_4,    KC_5,    KC_6, XXXXXXX, \
    ______________MOD_ROW_GACS_L______________,   KC_0,       KC_1,    KC_2,    KC_3, XXXXXXX, \
                      ESC_NUM, SPC_NAV,KC_LSFT,ENT_SYM,KC_BSPC


#define LAYOUT_LAYER_NAVIGATION                                                               \
    _______________DEAD_HALF_ROW_______________,   KC_INS, KC_HOME, KC_PGDN, KC_PGUP,  KC_END, \
    DRGSCRL, KC_BTN3, KC_BTN2, KC_BTN1, XXXXXXX,   KC_CAPS, KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, \
    ______________MOD_ROW_GACS_L______________,   ______________MOD_ROW_GACS_R______________, \
                      ESC_NUM, SPC_NAV,KC_LSFT,ENT_SYM,KC_BSPC

#define LAYOUT_LAYER_SYMBOLS                                                                  \
    KC_DLR, POUND, KC_AMPR, KC_ASTR, KC_CIRC,             KC_PERC, KC_PLUS, KC_GRV, KC_DQT, KC_QUOT, \
    KC_LCBR,  KC_RCBR, KC_LPRN, KC_RPRN, KC_AT,           KC_EQL, KC_MINS, KC_COLON, KC_EXLM, KC_PIPE,    \
    HOME_LABK, HOME_RABK,  HOME_LBRC, HOME_RBRC, KC_TILD,  HASH, HOME_UNDS, HOME_SCLN, HOME_QUES, HOME_BSLS, \
                             ESC_NUM, SPC_NAV,KC_LSFT,ENT_SYM,KC_BSPC

#define LAYOUT_LAYER_MEDIA                                                                  \
     XXXXXXX, KC_MUTE, KC_VOLD, KC_VOLU, XXXXXXX, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, \
     KC_MPRV,  KC_MSTP, KC_MPLY, KC_MNXT, XXXXXXX,KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, \
     QK_BOOT , EE_CLR, XXXXXXX, XXXXXXX , XXXXXXX,KC_F11, KC_F12, KC_F13, KC_F14, KC_F15, \
                      ESC_NUM, SPC_NAV,KC_LSFT,ENT_SYM,KC_BSPC

// Define layout
#define LAYOUT_wrapper(...) LAYOUT_charybdis_3x5(__VA_ARGS__)
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LAYER_BASE] = LAYOUT_wrapper(LAYOUT_LAYER_BASE),
  [LAYER_NUMERAL] = LAYOUT_wrapper(LAYOUT_LAYER_NUMERAL),
  [LAYER_NAVIGATION] = LAYOUT_wrapper(LAYOUT_LAYER_NAVIGATION),
  [LAYER_SYMBOLS] = LAYOUT_wrapper(LAYOUT_LAYER_SYMBOLS),
  [LAYER_MEDIA] = LAYOUT_wrapper(LAYOUT_LAYER_MEDIA),
};
// clang-format on

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    const bool is_tapped = record->tap.count && record->event.pressed;
    // tap.count is 0 if held, otherwise it is considered tapped
    switch (keycode) {
        // FIX: QMK does not allow some of these, so we need to override some behaviours
        // left side
        //   keyrecord_t record {
        //   keyevent_t event {
        //     keypos_t key {
        //       uint8_t col
        //       uint8_t row
        //     }
        //     bool     pressed (Down or up)
        //     uint16_t time
        //   }
        // }/
        // case KC_N:
        //                     process_altrep2(get_last_keycode(), get_last_mods());
        //
        //     if (record->event.pressed) {
        //         tap_code16(KC_N);
        //         return false;
        //     }
        //     return false;
        case HOME_LABK:
            if (is_tapped) {
                tap_code16(KC_LABK);
                return false;
            }
            break;
        case HOME_RABK:
            if (is_tapped) {
                tap_code16(KC_RABK);
                return false;
            }
            break;
        case HOME_LBRC:
            if (is_tapped) {
                tap_code16(KC_LBRC);
                return false;
            }
            break;
        case HOME_RBRC:
            if (is_tapped) {
                tap_code16(KC_RBRC);
                return false;
            }
            break;

        case HOME_UNDS:
            if (is_tapped) {
                tap_code16(KC_UNDS);
                return false;
            }
            break;
        case HOME_SCLN:
            if (is_tapped) {
                tap_code16(KC_SCLN);
                return false;
            }
            break;
        case HOME_QUES:
            if (is_tapped) {
                tap_code16(KC_QUES);
                return false;
            }
            break;
        case HOME_BSLS:
            if (is_tapped) {
                tap_code16(KC_BSLS);
                return false;
            }
            break;
    }

    if (!process_achordion(keycode, record)) {
        return false;
    }

    return true;
}

bool is_thumb_or_combo(uint16_t keycode) {
    switch (keycode) {
        case ESC_NUM:
        case SPC_NAV:
        case KC_LSFT:
        case ENT_SYM:
        case KC_BSPC:
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
        case HOME_Z:
        case HOME_X:
        case HOME_C:
        case HOME_D:
        case HOME_H:
        case HOME_COMM:
        case HOME_DOT:
        case HOME_SLSH:
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
        case ESC_NUM:
        case SPC_NAV:
        case ENT_SYM:
        case KC_BSPC:
            return true;
        default:
            // Do not select the hold action when another key is pressed.
            return false;
    }
}

uint16_t achordion_timeout(uint16_t tap_hold_keycode) {
    switch (tap_hold_keycode) {
        case ESC_NUM:
        case SPC_NAV:
        case KC_LSFT:
        case ENT_SYM:
        case KC_BSPC:
            return 0; // Bypass Achordion for these keys.
    }
    return 800;
}

// Pointing layer stuff
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
    achordion_task();
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
    state = update_tri_layer_state(state, LAYER_NUMERAL, LAYER_SYMBOLS, LAYER_MEDIA);
    // Setup tri layer
    charybdis_set_pointer_sniping_enabled(layer_state_cmp(state, CHARYBDIS_AUTO_SNIPING_ON_LAYER));
    return state;
}
#    endif // CHARYBDIS_AUTO_SNIPING_ON_LAYER
#endif     // POINTING_DEVICE_ENABLE

// Combos
const uint16_t PROGMEM L_U[] = {KC_L, KC_U, COMBO_END};
const uint16_t PROGMEM U_Y[] = {KC_U, KC_Y, COMBO_END};
const uint16_t PROGMEM W_F[] = {KC_W, KC_F, COMBO_END};

combo_t key_combos[] = {
    COMBO(L_U, KC_TAB),
    COMBO(U_Y, KC_DEL),
    COMBO(W_F, RGB_TOG),
};
