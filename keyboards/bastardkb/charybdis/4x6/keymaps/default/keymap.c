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

  // Needs a shift on the LHS
  [LAYER_NUMERAL] = LAYOUT(
  // ╭──────────────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────────────╮
         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,           XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ├──────────────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────────────┤
         KC_LALT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,             XXXXXXX,    KC_7,    KC_8,    KC_9, _______,  KC_RALT,
  // ├──────────────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────────────┤
         KC_LCTL, XXXXXXX,  KC_DEL,  KC_TAB,  KC_ESC, XXXXXXX,             XXXXXXX,    KC_4,    KC_5,    KC_6, XXXXXXX,  KC_RCTL,
  // ├──────────────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────────────┤
         KC_LGUI, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                KC_0,    KC_1,    KC_2,    KC_3, _______,  KC_RGUI,
  // ╰──────────────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────────────╯
                               XXXXXXX, _______, _______,      _______, _______,
                               XXXXXXX, XXXXXXX,                 XXXXXXX
  ),


  // Needs a shift on the LHS
  [LAYER_NAVIGATION] = LAYOUT(
  // ╭──────────────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────────────╮
         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,           XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ├──────────────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────────────┤
         KC_LALT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,             KC_INS, KC_HOME, KC_PGDN, KC_PGUP,  KC_END,  KC_RALT,
  // ├──────────────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────────────┤
         KC_LCTL, DRGSCRL, KC_BTN3, KC_BTN2, KC_BTN1, XXXXXXX,             XXXXXXX, KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, KC_RCTL,
  // ├──────────────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────────────┤
         KC_LGUI, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,             KC_PSCR, XXXXXXX, XXXXXXX, XXXXXXX, _______, KC_RGUI,
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
};
// clang-format on
