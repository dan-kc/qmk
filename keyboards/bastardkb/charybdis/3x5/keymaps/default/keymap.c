/**
 * Copyright 2021 Charly Delay <charly@codesink.dev> (@0xcharly)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H

enum charybdis_keymap_layers {
    LAYER_BASE = 0,
    LAYER_NUMERAL,
    LAYER_NAVIGATION,
    LAYER_SYMBOLS,
    LAYER_MEDIA
};

// Base layer row mods
#define HRM_Z LGUI_T(KC_Z)
#define HRM_X LALT_T(KC_X)
#define HRM_C LCTL_T(KC_C)
#define HRM_D LSFT_T(KC_D)
#define HRM_H RSFT_T(KC_H)
#define HRM_COM RCTL_T(KC_COMM)
#define HRM_DOT RALT_T(KC_DOT)
#define HRM_ENT RGUI_T(KC_ENT)

// Thumb keys
#define SYM MO(LAYER_SYMBOLS)
#define NUM_ESC LT(LAYER_NUMERAL, KC_ESC)
#define NAV_TAB LT(LAYER_NAVIGATION, KC_TAB)

// Misc
#define HASH LALT(KC_3)
#define POUND KC_HASH
#define CLN LSFT(KC_SCLN)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LAYER_BASE] = LAYOUT(
  // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
          KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,       KC_J,    KC_L,    KC_U,    KC_Y, KC_BSPC,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
          KC_A,    KC_R,    KC_S,    KC_T,    KC_G,       KC_M,    KC_N,    KC_E,    KC_I,    KC_O,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
         HRM_Z,   HRM_X,   HRM_C,   HRM_D,    KC_V,       KC_K,   HRM_H, HRM_COM, HRM_DOT, HRM_ENT,
  // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                         NUM_ESC, NAV_TAB, KC_LSFT,        SYM,  KC_SPC
  //                   ╰───────────────────────────╯ ╰──────────────────╯
  ),

  [LAYER_NUMERAL] = LAYOUT(
  // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     KC_DEL,    KC_7,    KC_8,    KC_9, _______,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX,    KC_4,    KC_5,    KC_6, XXXXXXX,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,       KC_0,    KC_1,    KC_2,    KC_3, _______,
  // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                         XXXXXXX, _______, _______,    _______,  _______
  //                   ╰───────────────────────────╯ ╰──────────────────╯
  ),

  [LAYER_NAVIGATION] = LAYOUT(
  // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     KC_INS, KC_HOME, KC_PGDN, KC_PGUP,  KC_END,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       DRGSCRL, KC_BTN3, KC_BTN2, KC_BTN1, XXXXXXX,    XXXXXXX, KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,    XXXXXXX, KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI,
  // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                         _______, XXXXXXX, _______,    _______, _______
  //                   ╰───────────────────────────╯ ╰──────────────────╯
  ),

  [LAYER_SYMBOLS] = LAYOUT(
  // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
        KC_DLR,   POUND, KC_AMPR, KC_ASTR, KC_CIRC,    KC_PLUS, KC_PERC,  KC_QUOT, KC_DQT,  KC_GRV,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       KC_LCBR, KC_RCBR, KC_LPRN, KC_RPRN,   KC_AT,    KC_MINS,     CLN, KC_SCLN, KC_EXLM, KC_QUES,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       KC_LABK, KC_RABK, KC_LBRC, KC_RBRC, KC_TILD,    KC_EQUAL,KC_UNDS, KC_SLSH, KC_PIPE, KC_BSLS,
  // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                         _______, _______, _______,    XXXXXXX, _______
  //                   ╰───────────────────────────╯ ╰──────────────────╯
  ),

  [LAYER_MEDIA] = LAYOUT(
  // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
       KC_MUTE, KC_VOLD, KC_VOLU, XXXXXXX, XXXXXXX,    KC_PSCR,   KC_F7,   KC_F8,   KC_F9, _______,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       KC_MSTP, KC_MPLY, KC_MNXT, XXXXXXX, XXXXXXX,    KC_PEQL,   KC_F4,   KC_F5,   KC_F6, XXXXXXX,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,    KC_PDOT,   KC_F1,   KC_F2,   KC_F3, _______,
  // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                         XXXXXXX, _______, _______,    XXXXXXX, _______
  //                   ╰───────────────────────────╯ ╰──────────────────╯
  ),
};
// clang-format on

const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM =
    LAYOUT(
        'L','L','L','L','L','R','R','R','R','R',
        'L','L','L','L','L','R','R','R','R','R',
        'L','L','L','L','L','R','R','R','R','R',
                     '*','*','*', '*','*'
    );
