#include QMK_KEYBOARD_H

enum charybdis_keymap_layers { LAYER_BASE = 0, LAYER_NUMERAL, LAYER_NAVIGATION, LAYER_SYMBOLS, LAYER_MEDIA };
#define CHARYBDIS_AUTO_SNIPING_ON_LAYER LAYER_NAVIGATION

#define SPC_NAV LT(LAYER_NAVIGATION, KC_SPC)
#define ENT_SYM LT(LAYER_SYMBOLS, KC_ENT)
// #define ESC_NUM LT(LAYER_NUMERAL, KC_ESC)
#define SYM MO(LAYER_SYMBOLS)
#define NUM MO(LAYER_NUMERAL)
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
       KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_J,    KC_L,    KC_U,    KC_Y, KC_ESC, \
       KC_A,    KC_R,    KC_S,    KC_T,    KC_G,    KC_M,  KC_N, KC_E,KC_I, KC_O,    \
       LGUI_T(KC_Z),LALT_T(KC_X),LCTL_T(KC_C),LSFT_T(KC_D),KC_V, KC_K,RSFT_T(KC_H), RCTL_T(KC_COMM),LALT_T(KC_SLSH), RGUI_T(KC_SLSH), \
                      NUM, SPC_NAV,KC_LSFT,ENT_SYM,KC_BSPC

#define _______________DEAD_HALF_ROW_______________ XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
#define ______________MOD_ROW_GACS_L______________ KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX
#define ______________MOD_ROW_GACS_R______________ XXXXXXX, KC_RSFT, KC_RCTL, KC_LALT, KC_RGUI

#define LAYOUT_LAYER_NUMERAL                                                                  \
    _______________DEAD_HALF_ROW_______________,   XXXXXXX,    KC_7,    KC_8,    KC_9, XXXXXXX,  \
    _______________DEAD_HALF_ROW_______________,   XXXXXXX,    KC_4,    KC_5,    KC_6, XXXXXXX, \
    ______________MOD_ROW_GACS_L______________,   KC_0,       KC_1,    KC_2,    KC_3, XXXXXXX, \
                      NUM, SPC_NAV,KC_LSFT,ENT_SYM,KC_BSPC


#define LAYOUT_LAYER_NAVIGATION                                                               \
    _______________DEAD_HALF_ROW_______________,   KC_INS, KC_HOME, KC_PGDN, KC_PGUP,  KC_END, \
    _______________DEAD_HALF_ROW_______________,   KC_CAPS, KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, \
    ______________MOD_ROW_GACS_L______________,   XXXXXXX, KC_BTN1, KC_BTN2, KC_BTN3, DRGSCRL, \
                      NUM, SPC_NAV,KC_LSFT,ENT_SYM,KC_BSPC

#define LAYOUT_LAYER_SYMBOLS                                                                  \
    KC_DLR, POUND, KC_AMPR, KC_ASTR, KC_CIRC,      KC_PERC, KC_PLUS, KC_GRV, KC_DQT, KC_QUOT, \
    KC_LCBR,  KC_RCBR, KC_LPRN, KC_RPRN, KC_AT,  KC_EQL, KC_MINS, KC_COLON, KC_EXLM, KC_PIPE,    \
    LGUI_T(KC_LABK), LALT_T(KC_RABK),  LCTL_T(KC_LBRC), LSFT_T(KC_RBRC), KC_TILD,  HASH, LSFT_T(KC_UNDS), LCTL_T(KC_SCLN), LALT_T(KC_SCLN), LGUI_T(KC_BSLS), \
                      NUM, SPC_NAV,KC_LSFT,ENT_SYM,KC_BSPC

#define LAYOUT_LAYER_MEDIA                                                                  \
     XXXXXXX, KC_MUTE, KC_VOLD, KC_VOLU, XXXXXXX, _______________DEAD_HALF_ROW_______________, \
     KC_MPRV,  KC_MSTP, KC_MPLY, KC_MNXT, XXXXXXX,_______________DEAD_HALF_ROW_______________, \
     QK_BOOT , EE_CLR, KC_BRTD, KC_BRTU , XXXXXXX,_______________DEAD_HALF_ROW_______________, \
                      NUM, SPC_NAV,KC_LSFT,ENT_SYM,KC_BSPC

#define LAYOUT_wrapper(...) LAYOUT_charybdis_3x5(__VA_ARGS__)
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LAYER_BASE] = LAYOUT_wrapper(LAYOUT_LAYER_BASE),
  [LAYER_NUMERAL] = LAYOUT_wrapper(LAYOUT_LAYER_NUMERAL),
  [LAYER_NAVIGATION] = LAYOUT_wrapper(LAYOUT_LAYER_NAVIGATION),
  [LAYER_SYMBOLS] = LAYOUT_wrapper(LAYOUT_LAYER_SYMBOLS),
  [LAYER_MEDIA] = LAYOUT_wrapper(LAYOUT_LAYER_MEDIA),
};
// clang-format on

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // FIX: dot was registering as ">"
        case LALT_T(KC_SLSH):
            ............
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_DOT);
                return false;
            }
            break;

        case LGUI_T(KC_LABK):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_LABK);
                return false;
            }
            break;
        case LALT_T(KC_RABK):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_RABK);
                return false;
            }
            break;
        case LCTL_T(KC_LBRC):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_LBRC);
                return false;
            }
            break;
        case LSFT_T(KC_RBRC):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_RBRC);
                return false;
            }
            break;

        case LSFT_T(KC_UNDS):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_UNDS);
                return false;
            }
            break;
        case LCTL_T(KC_SCLN):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_SCLN);
                return false;
            }
            break;
        case LALT_T(KC_SCLN):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_QUES);
                return false;
            }
            break;
        case LGUI_T(KC_BSLS):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_BSLS);
                return false;
            }
            break;
    }
    return true;
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

// RHS
const uint16_t PROGMEM L_U[] = {KC_L, KC_U, COMBO_END};
const uint16_t PROGMEM U_Y[] = {KC_U, KC_Y, COMBO_END};

// LHS
const uint16_t PROGMEM KC_X_C[] = {KC_X, KC_C, COMBO_END};

combo_t key_combos[] = {
    COMBO(L_U, KC_TAB),
    COMBO(U_Y, KC_DEL),
};
