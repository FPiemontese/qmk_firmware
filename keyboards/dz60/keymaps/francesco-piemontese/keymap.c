#include QMK_KEYBOARD_H

#define ______ KC_TRNS

/*
TODOs:
  - add a non-temporary layer switch key

MAYBEs:
  - add a numpad (would have to be in an additional layer)
*/

// Tap-dance declarations
enum {
  TD_HOME_PAGEUP,
  TD_END_PAGEDOWN,
};

// Tap-dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  // Tap once for Home, twice for Page Up
  [TD_HOME_PAGEUP] = ACTION_TAP_DANCE_DOUBLE(KC_HOME, KC_PGUP),
  // Tap once for End, twice for Page Down
  [TD_END_PAGEDOWN] = ACTION_TAP_DANCE_DOUBLE(KC_END, KC_PGDOWN),
};

// DZ60 layout 5, 1u right shift, arrow keys, 5 1u keys in the bottom row
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Qwerty
   * ,-----------------------------------------------------------------------------------------.
   * |ESC/~|  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  -  |  =  |   Bkspc   |
   * |-----------------------------------------------------------------------------------------+
   * | Tab    |  Q  |  W  |  E  |  R  |  T  |  Y  |  U  |  I  |  O  |  P  |  [  |  ]  |    \   |
   * |-----------------------------------------------------------------------------------------+
   * | Caps/FN |  A  |  S  |  D  |  F  |  G  |  H  |  J  |  K  |  L  |  ;  |  '  |    Enter    |
   * |-----------------------------------------------------------------------------------------+
   * | Shift     |  Z  |  X  |  C  |  V  |  B  |  N  |  M  |  ,  |  .  |  /  | RSh |  U  | DEL |
   * |-----------------------------------------------------------------------------------------+
   * | Ctrl |  Cmd  |  Alt  |              Space                | RAlt | FN  |  L  |  D  |  R  |
   * `-----------------------------------------------------------------------------------------'
   */

  LAYOUT_directional(
    KC_GESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, ______, KC_BSPC,
    KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS,
    LT(1, KC_CAPS), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT,
    KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_UP, KC_DEL,
    KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, KC_SPC, KC_SPC, KC_RALT, MO(1), KC_LEFT, KC_DOWN, KC_RIGHT
  ),

  /* FN Layer
   * ,-----------------------------------------------------------------------------------------.
   * |  `  |  F1 |  F2 |  F3 |  F4 |  F5 |  F6 |  F7 |  F8 |  F9 | F10 | F11 | F12 |           |
   * |-----------------------------------------------------------------------------------------+
   * |        |     |  ↑  |     |     |     |     |     |  ↑  |     |     |      |      | RESET|
   * |-----------------------------------------------------------------------------------------+
   * |         |  ←  |  ↓  |  →  |     |     |     |  ←  |  ↓  |  →  |     |  `  |             |
   * |-----------------------------------------------------------------------------------------+
   * |           |RGB T|RGB M|Hue ±|Sat ±|Val ±|     |     |     |     |STOP | ▶|| |VOL↑ |     |
   * |-----------------------------------------------------------------------------------------+
   * |      |       |       |                                   |     |      |TRCK←|VOL↓ |TRCK→|
   * `-----------------------------------------------------------------------------------------'
   */

  // RGB_HUD can be accessed by pressing Shift + RGB_HUI. The same applies for RGB_SAD and RGB_VAD
  LAYOUT_directional(
    KC_GRV, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, ______, ______,
    ______, ______, KC_UP, ______, ______, ______, ______, ______,  KC_UP, ______, ______, ______, ______, RESET,
    ______, KC_LEFT, KC_DOWN, KC_RIGHT, ______, ______, ______, KC_LEFT, KC_DOWN, KC_RIGHT, ______, KC_GRV, ______,
    ______, RGB_TOG, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, ______, ______, TD(TD_HOME_PAGEUP), TD(TD_END_PAGEDOWN), KC_MSTP, KC_MPLY, KC_VOLU, ______,
    KC_RCTL, ______, ______, ______, ______, ______, KC_MS_BTN2, ______, KC_MPRV, KC_VOLD, KC_MNXT
  ),

};
