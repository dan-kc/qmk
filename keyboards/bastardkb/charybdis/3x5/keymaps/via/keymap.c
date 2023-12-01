#include QMK_KEYBOARD_H
#include "features/achordion.h"
bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    if (!process_achordion(keycode, record)) {
        return false;
    }
    return true;
}

void matrix_scan_user(void) {
    achordion_task();
}

enum charybdis_keymap_layers { LAYER_BASE = 0, LAYER_NUMERAL, LAYER_NAVIGATION, LAYER_SYMBOLS, LAYER_WEIRD, LAYER_MEDIA };

#define CHARYBDIS_AUTO_SNIPING_ON_LAYER LAYER_NAVIGATION

#define ESC_NUM LT(LAYER_NUMERAL, KC_ESC)
#define SPC_NAV LT(LAYER_NAVIGATION, KC_SPC)
#define TAB_SFT LSFT_T(KC_TAB)
#define ENT_SYM LT(LAYER_SYMBOLS, KC_ENT)
#define KC_BRTU LSFT(LALT(LGUI(KC_COMM)))
#define KC_BRTD LSFT(LALT(LGUI(KC_DOT)))
#define HASH LALT(KC_3)
#define POUND KC_HASH

#ifndef POINTING_DEVICE_ENABLE
#    define DRGSCRL KC_NO
#    define DPI_MOD KC_NO
#    define S_D_MOD KC_NO
#    define SNIPING KC_NO
#endif // !POINTING_DEVICE_ENABLE

// clang-format off
#define LAYOUT_LAYER_BASE                                                                     \
       KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_J,    KC_L,    KC_U,    KC_Y, KC_QUOT, \
       KC_A,    KC_R,    KC_S,    KC_T,    KC_G,    KC_M,    KC_N,    KC_E,    KC_I, KC_O,    \
       LGUI_T(KC_Z),LALT_T(KC_X),LCTL_T(KC_C),LSFT_T(KC_D),KC_V, KC_K,RSFT_T(KC_H), RCTL_T(KC_COMM),LALT_T(KC_DOT), RGUI_T(KC_SLSH), \
                      ESC_NUM, SPC_NAV,TAB_SFT,ENT_SYM,KC_BSPC

#define _______________DEAD_HALF_ROW_______________ XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
#define ______________MOD_ROW_GACS_L______________ KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX
#define ______________MOD_ROW_GACS_R______________ XXXXXXX, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI

#define LAYOUT_LAYER_NUMERAL                                                                  \
    _______________DEAD_HALF_ROW_______________,   XXXXXXX,    KC_7,    KC_8,    KC_9, XXXXXXX,  \
    _______________DEAD_HALF_ROW_______________,   XXXXXXX,    KC_4,    KC_5,    KC_6, XXXXXXX, \
    ______________MOD_ROW_GACS_L______________,   KC_0,       KC_1,    KC_2,    KC_3, XXXXXXX, \
                      ESC_NUM, SPC_NAV,TAB_SFT,ENT_SYM,KC_BSPC


#define LAYOUT_LAYER_NAVIGATION                                                               \
    _______________DEAD_HALF_ROW_______________,   KC_INS, KC_HOME, KC_PGDN, KC_PGUP,  KC_END, \
    _______________DEAD_HALF_ROW_______________,   KC_CAPS, KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, \
    ______________MOD_ROW_GACS_L______________,   XXXXXXX, KC_BTN1, KC_BTN2, KC_BTN3, DRGSCRL, \
                      ESC_NUM, SPC_NAV,TAB_SFT,ENT_SYM,KC_BSPC

#define LAYOUT_LAYER_SYMBOLS                                                                  \
    _______________DEAD_HALF_ROW_______________,   XXXXXXX, KC_PLUS, KC_GRV, KC_DQT, XXXXXXX, \
    KC_LCBR,  KC_RCBR, KC_LPRN, KC_RPRN, XXXXXXX,  KC_EQL, KC_MINS, KC_COLON, KC_EXLM, KC_PIPE,    \
    KC_LABK, KC_RABK,  KC_LBRC, KC_RBRC, XXXXXXX,  XXXXXXX, KC_UNDS, KC_SCLN, KC_QUES, KC_BSLS, \
                      ESC_NUM, SPC_NAV,TAB_SFT,ENT_SYM,KC_BSPC

#define LAYOUT_LAYER_MEDIA                                                                  \
     XXXXXXX, KC_MUTE, KC_VOLD, KC_VOLU, XXXXXXX, _______________DEAD_HALF_ROW_______________, \
     KC_MPRV,  KC_MSTP, KC_MPLY, KC_MNXT, XXXXXXX,_______________DEAD_HALF_ROW_______________, \
     QK_BOOT , EE_CLR, KC_BRTD, KC_BRTU , XXXXXXX,_______________DEAD_HALF_ROW_______________, \
                      ESC_NUM, SPC_NAV,TAB_SFT,ENT_SYM,KC_BSPC


#define LAYOUT_LAYER_WEIRD                                                               \
     XXXXXXX, XXXXXXX, XXXXXXX, KC_CIRC, XXXXXXX,_______________DEAD_HALF_ROW_______________, \
     KC_DLR,  KC_AT,   KC_ASTR, KC_AMPR, XXXXXXX, _______________DEAD_HALF_ROW_______________ , \
     POUND,   KC_TILD, KC_PERC, HASH, XXXXXXX, ______________MOD_ROW_GACS_R______________, \
                      ESC_NUM, SPC_NAV,TAB_SFT,ENT_SYM,KC_BSPC

#define LAYOUT_wrapper(...) LAYOUT_charybdis_3x5(__VA_ARGS__)
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LAYER_BASE] = LAYOUT_wrapper(LAYOUT_LAYER_BASE),
  [LAYER_NUMERAL] = LAYOUT_wrapper(LAYOUT_LAYER_NUMERAL),
  [LAYER_NAVIGATION] = LAYOUT_wrapper(LAYOUT_LAYER_NAVIGATION),
  [LAYER_SYMBOLS] = LAYOUT_wrapper(LAYOUT_LAYER_SYMBOLS),
  [LAYER_WEIRD] = LAYOUT_wrapper(LAYOUT_LAYER_WEIRD),
  [LAYER_MEDIA] = LAYOUT_wrapper(LAYOUT_LAYER_MEDIA),
};
// clang-format on

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
    state = update_tri_layer_state(state, LAYER_NUMERAL, LAYER_SYMBOLS, LAYER_WEIRD);
    state = update_tri_layer_state(state, LAYER_NAVIGATION, LAYER_SYMBOLS, LAYER_MEDIA);
    charybdis_set_pointer_sniping_enabled(layer_state_cmp(state, CHARYBDIS_AUTO_SNIPING_ON_LAYER));
    return state;
}
#    endif // CHARYBDIS_AUTO_SNIPING_ON_LAYER
#endif     // POINTING_DEVICE_ENABLE

#ifdef RGB_MATRIX_ENABLE
// Forward-declare this helper function since it is defined in
// rgb_matrix.c.
void rgb_matrix_update_pwm_buffers(void);
#endif

void shutdown_user(void) {
#ifdef RGBLIGHT_ENABLE
    rgblight_enable_noeeprom();
    rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
    rgblight_setrgb(RGB_RED);
#endif // RGBLIGHT_ENABLE
#ifdef RGB_MATRIX_ENABLE
    rgb_matrix_set_color_all(RGB_RED);
    rgb_matrix_update_pwm_buffers();
#endif // RGB_MATRIX_ENABLE
}

bool is_thumb(uint16_t keycode) {
    switch (keycode) {
        case ESC_NUM:
            return true;
            break;
        case SPC_NAV:
            return true;
            break;
        case ENT_SYM:
            return true;
            break;
        case TAB_SFT:
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
        case LGUI_T(KC_Z):
        case LALT_T(KC_X):
        case LCTL_T(KC_C):
        case LSFT_T(KC_D):
        case RGUI_T(KC_SLSH):
        case LALT_T(KC_DOT):
        case RCTL_T(KC_COMM):
        case RSFT_T(KC_H):
            if (is_thumb(other_keycode)) {
                return true;
            }
            break;
    }

    // Otherwise, follow the opposite hands rule.
    return achordion_opposite_hands(tap_hold_record, other_record);
}

uint16_t achordion_timeout(uint16_t tap_hold_keycode) {
    switch (tap_hold_keycode) {
        case ESC_NUM:
        case SPC_NAV:
        case ENT_SYM:
        case TAB_SFT:
            return 0; // Bypass Achordion for these keys.
    }

    return 500;
}
