#include QMK_KEYBOARD_H

enum charybdis_keymap_layers {
    LAYER_BASE = 0,
    LAYER_NUMERAL,
    LAYER_NAVIGATION,
    LAYER_SYMBOLS,
    LAYER_MEDIA
};

// Layer access
#define SYM MO(LAYER_SYMBOLS)
#define NUM MO(LAYER_NUMERAL)
#define NAV MO(LAYER_NAVIGATION)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [LAYER_BASE] = LAYOUT(
  // ╭──────────────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────────────╮
         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,           XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ├──────────────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────────────┤
         KC_LALT,    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,             KC_J,    KC_L,    KC_U,    KC_Y, KC_BSPC,  KC_RALT,
  // ├──────────────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────────────┤
         KC_LCTL,    KC_A,    KC_R,    KC_S,    KC_T,    KC_G,             KC_M,    KC_N,    KC_E,    KC_I,    KC_O,  KC_RCTL,
  // ├──────────────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────────────┤
         KC_LGUI,    KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,             KC_K,    KC_H, KC_COMM,  KC_DOT,  KC_ENT,  KC_RGUI,
  // ╰──────────────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────────────╯
                                   NUM,    NAV, KC_LSFT,         SYM,  KC_SPC,
                                   XXXXXXX, XXXXXXX,              XXXXXXX
  //                      ╰────────────────────────────────────────╯ ╰─────────────────────╯
  ),

  [LAYER_NUMERAL] = LAYOUT(
  // ╭──────────────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────────────╮
         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,           XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ├──────────────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────────────┤
         KC_LALT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,             XXXXXXX,    KC_7,    KC_8,    KC_9, _______,  KC_RALT,
  // ├──────────────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────────────┤
         KC_LCTL, XXXXXXX,  KC_DEL,  KC_TAB,  KC_ESC, XXXXXXX,             KC_LSFT,    KC_4,    KC_5,    KC_6, XXXXXXX,  KC_RCTL,
  // ├──────────────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────────────┤
         KC_LGUI, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                KC_0,    KC_1,    KC_2,    KC_3, _______,  KC_RGUI,
  // ╰──────────────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────────────╯
                               XXXXXXX, _______, _______,      _______, _______,
                               XXXXXXX, XXXXXXX,                 XXXXXXX
  ),

  [LAYER_NAVIGATION] = LAYOUT(
  // ╭──────────────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────────────╮
         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,           XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ├──────────────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────────────┤
         KC_LALT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,             KC_INS, KC_HOME, KC_PGDN, KC_PGUP,  KC_END,  KC_RALT,
  // ├──────────────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────────────┤
         KC_LCTL, DRGSCRL, KC_BTN3, KC_BTN2, KC_BTN1, XXXXXXX,             KC_LSFT, KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, KC_RCTL,
  // ├──────────────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────────────┤
         KC_LGUI, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,             XXXXXXX, KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI, KC_RGUI,
  // ╰──────────────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────────────╯
                               _______, XXXXXXX, _______,      _______, _______,
                               XXXXXXX, XXXXXXX,                XXXXXXX
  ),

  [LAYER_SYMBOLS] = LAYOUT(
  // ╭──────────────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────────────╮
         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,           XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ├──────────────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────────────┤
         KC_LALT,  KC_DLR, KC_HASH, KC_AMPR, KC_ASTR, KC_CIRC,             KC_PLUS, KC_PERC, KC_QUOT, KC_DQT,  KC_GRV,  KC_RALT,
  // ├──────────────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────────────┤
         KC_LCTL, KC_LCBR, KC_RCBR, KC_LPRN, KC_RPRN,   KC_AT,             KC_MINS, KC_COLN, KC_SCLN, KC_EXLM, KC_QUES, KC_RCTL,
  // ├──────────────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────────────┤
         KC_LGUI, KC_LABK, KC_RABK, KC_LBRC, KC_RBRC,  KC_TILD,              KC_EQL, KC_UNDS, KC_SLSH, KC_PIPE, KC_BSLS, KC_RGUI,
  // ╰──────────────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────────────╯
                               _______, _______, _______,     XXXXXXX, _______,
                               XXXXXXX, XXXXXXX,               XXXXXXX
  ),

  [LAYER_MEDIA] = LAYOUT(
  // ╭──────────────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────────────╮
         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,           XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ├──────────────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────────────┤
         KC_LALT, KC_MUTE, KC_VOLD, KC_VOLU, XXXXXXX, XXXXXXX,             KC_PSCR,   KC_F7,   KC_F8,   KC_F9, _______,  KC_RALT,
  // ├──────────────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────────────┤
         KC_LCTL, KC_MSTP, KC_MPLY, KC_MNXT, XXXXXXX, XXXXXXX,             KC_PEQL,   KC_F4,   KC_F5,   KC_F6, XXXXXXX,  KC_RCTL,
  // ├──────────────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────────────┤
         KC_LGUI, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,             KC_PDOT,   KC_F1,   KC_F2,   KC_F3, _______,  KC_RGUI,
  // ╰──────────────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────────────╯
                               XXXXXXX, _______, _______,     XXXXXXX, _______,
                               XXXXXXX, XXXXXXX,               XXXXXXX
  ),
};
// clang-format on

layer_state_t layer_state_set_user(layer_state_t state) {
    state = update_tri_layer_state(state,
                                   LAYER_NUMERAL,
                                   LAYER_SYMBOLS,
                                   LAYER_MEDIA);
    return state;
}
