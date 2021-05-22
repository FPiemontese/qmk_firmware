#include QMK_KEYBOARD_H

#define ______ KC_TRNS

/*

TODOs:
  - add pageUp pageDown end home
  - add a right click
  - add a non-temporary layer switch key
  - add an FN on the left
    - (DONE) maybe have CAPS lock act as itself when tapped and as FN when held down
  - remove unused RGB commands

MAYBEs:
  - add a numpad
  - move arrow keys to the left (FN + WASD?), have backspace and del on the right instead (removes
    need to move hand from arrow keys to backspace when navigating code)

*/


// DZ60 layout 5, 1u right shift, arrow keys, 5 1u keys in the bottom row
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Qwerty
   * ,-----------------------------------------------------------------------------------------.
   * | ` ~ |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  -  |  =  |   Bkspc   |
   * |-----------------------------------------------------------------------------------------+
   * | Tab    |  Q  |  W  |  E  |  R  |  T  |  Y  |  U  |  I  |  O  |  P  |  [  |  ]  |    \   |
   * |-----------------------------------------------------------------------------------------+
   * | Caps    |  A  |  S  |  D  |  F  |  G  |  H  |  J  |  K  |  L  |  ;  |  '  |    Enter    |
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
   * | Esc |  F1 |  F2 |  F3 |  F4 |  F5 |  F6 |  F7 |  F8 |  F9 | F10 | F11 | F12 |           |
   * |-----------------------------------------------------------------------------------------+
   * |        |RBB T|RGB M| Hue+| Hue-|     |     |     |  U  |     |     |      |      | RESET|
   * |-----------------------------------------------------------------------------------------+
   * |         | Sat+| Sat-| Val+| Val-|     |     |  L  |  D  |  R  |     |  `  |             |
   * |-----------------------------------------------------------------------------------------+
   * |           |     |     |     |     |     |     |     |     |     | STOP| ▶|| |VOL↑ |     |
   * |-----------------------------------------------------------------------------------------+
   * |      |       |       |                                   |     |      |TRCK←|VOL↓ |TRCK→|
   * `-----------------------------------------------------------------------------------------'
   */

  // RGB_HUD can be accessed by pressing Shift + RGB_HUI. The same applies for RGB_SAD and RGB_VAD
  LAYOUT_directional(
    KC_GRV, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10, KC_F11, KC_F12, ______, ______,
    ______, ______, KC_UP, ______, ______, ______, ______, ______,  KC_UP, ______, ______, ______, ______, RESET,
    ______, KC_LEFT, KC_DOWN, KC_RIGHT, ______, ______, ______, KC_LEFT, KC_DOWN, KC_RIGHT, ______, KC_GRV, ______,
    ______, RGB_TOG, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, ______, ______, ______, ______, KC_MSTP, KC_MPLY, KC_VOLU, ______,
    ______, ______, ______, ______, ______, ______, ______, ______, KC_MPRV, KC_VOLD, KC_MNXT
  ),

};
