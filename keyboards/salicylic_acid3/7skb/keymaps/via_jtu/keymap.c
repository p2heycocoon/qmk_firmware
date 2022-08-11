#include QMK_KEYBOARD_H
// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layer_number {
  _BASE = 0,
  _L1,
  _L2,
  _L3,
};

  // 以下追加


void proc_regist_keycode(keyrecord_t *record, bool lshift, bool rshift, bool is_clear_shift, uint16_t regist_keycode, bool is_shift){
  if (record->event.pressed) {
    if(is_clear_shift){
        if (lshift) unregister_code(KC_LSFT);
        if (rshift) unregister_code(KC_RSFT);
    }
    if(is_shift)register_code(KC_LSFT);
    register_code(regist_keycode);
    unregister_code(regist_keycode);
    if(is_shift)unregister_code(KC_LSFT);
    if(is_clear_shift){
        if (lshift) register_code(KC_LSFT);
        if (rshift) register_code(KC_RSFT);
    }
  }
}


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  static bool lshift = false;
  static bool rshift = false;
  lshift = keyboard_report->mods & MOD_BIT(KC_LSFT);
  rshift = keyboard_report->mods & MOD_BIT(KC_RSFT);

  switch (keycode) {
    case KC_2:
        if (lshift || rshift) {
            proc_regist_keycode(record, lshift, rshift, true, KC_LBRC, false);
        } else {
            proc_regist_keycode(record, lshift, rshift, false, KC_2, false);
        }
        return false;
    case KC_6:
        if (lshift || rshift) {
          proc_regist_keycode(record, lshift, rshift, true, KC_EQL, false);
        } else {
          proc_regist_keycode(record, lshift, rshift, false, KC_6, false);
        }
        return false;
    case KC_7:
        if (lshift || rshift) {
          proc_regist_keycode(record, lshift, rshift, true, KC_6, true);
        } else {
          proc_regist_keycode(record, lshift, rshift, false, KC_7, false);
        }
        return false;
    case KC_8:
        if (lshift || rshift) {
          proc_regist_keycode(record, lshift, rshift, true, KC_QUOT, true);
        } else {
          proc_regist_keycode(record, lshift, rshift, false, KC_8, false);
        }
        return false;
    case KC_9:
        if (lshift || rshift) {
          proc_regist_keycode(record, lshift, rshift, true, KC_8, true);
        } else {
          proc_regist_keycode(record, lshift, rshift, false, KC_9, false);
        }
        return false;
    case KC_0:
        if (lshift || rshift) {
          proc_regist_keycode(record, lshift, rshift, true, KC_9, true);
        } else {
          proc_regist_keycode(record, lshift, rshift, false, KC_0, false);
        }
        return false;
    case KC_MINS:
        if (lshift || rshift) {
          proc_regist_keycode(record, lshift, rshift, true, KC_INT1, true);
        } else {
          proc_regist_keycode(record, lshift, rshift, false, KC_MINS, false);
        }
        return false;
    case KC_EQL:
        if (lshift || rshift) {
          proc_regist_keycode(record, lshift, rshift, true, KC_SCLN, true);
        } else {
          proc_regist_keycode(record, lshift, rshift, false, KC_MINS, true);
        }
        return false;
    case KC_LBRC:
        if (lshift || rshift) {
          proc_regist_keycode(record, lshift, rshift, true, KC_RBRC, true);
        } else {
          proc_regist_keycode(record, lshift, rshift, false, KC_RBRC, false);
        }
        return false;
    case KC_RBRC:
        if (lshift || rshift) {
          proc_regist_keycode(record, lshift, rshift, true, KC_NUHS, true);
        } else {
          proc_regist_keycode(record, lshift, rshift, false, KC_NUHS, false);
        }
        return false;
    case KC_BSLS:
        if (lshift || rshift) {
          proc_regist_keycode(record, lshift, rshift, true, KC_INT3, true);
        } else {
          proc_regist_keycode(record, lshift, rshift, false, KC_INT1, false);
        }
        return false;
    case KC_SCLN:
        if (lshift || rshift) {
          proc_regist_keycode(record, lshift, rshift, true, KC_QUOT, false);
        } else {
          proc_regist_keycode(record, lshift, rshift, false, KC_SCLN, false);
        }
        return false;
    case KC_QUOT:
        if (lshift || rshift) {
          proc_regist_keycode(record, lshift, rshift, true, KC_2, true);
        } else {
          proc_regist_keycode(record, lshift, rshift, false, KC_7, true);
        }
        return false;
    case KC_GRV:
        if (lshift || rshift) {
          proc_regist_keycode(record, lshift, rshift, true, KC_EQL, true);
        } else {
          proc_regist_keycode(record, lshift, rshift, false, KC_LBRC, true);
        }
        return false;
    case KC_CAPS:
        proc_regist_keycode(record, lshift, rshift, false, KC_CAPS, true);
        return false;
    case KC_TILD:
        proc_regist_keycode(record, lshift, rshift, false, KC_EQL, true);
        return false;
    case KC_AT:
        proc_regist_keycode(record, lshift, rshift, false, KC_LBRC, false);
        return false;
    case KC_CIRC:
        proc_regist_keycode(record, lshift, rshift, false, KC_EQL, false);
        return false;
    case KC_AMPR:
        proc_regist_keycode(record, lshift, rshift, false, KC_6, true);
        return false;
    case KC_ASTR:
        proc_regist_keycode(record, lshift, rshift, false, KC_QUOT, true);
        return false;
    case KC_LPRN:
        proc_regist_keycode(record, lshift, rshift, false, KC_8, true);
        return false;
    case KC_RPRN:
        proc_regist_keycode(record, lshift, rshift, false, KC_9, true);
        return false;
    case KC_UNDS:
        proc_regist_keycode(record, lshift, rshift, false, KC_INT1, true);
        return false;
    case KC_PLUS:
        proc_regist_keycode(record, lshift, rshift, false, KC_SCLN, true);
        return false;
    case KC_LCBR:
        proc_regist_keycode(record, lshift, rshift, false, KC_LSFT, true);
        return false;
    case KC_RCBR:
        proc_regist_keycode(record, lshift, rshift, false, KC_NUHS, true);
        return false;
    case KC_PIPE:
        proc_regist_keycode(record, lshift, rshift, false, KC_INT3, true);
        return false;
    case KC_COLN:
        proc_regist_keycode(record, lshift, rshift, false, KC_QUOT, false);
        return false;
    case KC_DQUO:
        proc_regist_keycode(record, lshift, rshift, false, KC_2, true);
        return false;
  }
  return true;
}
  // 追加ここまで

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT(
  //,-----------------------------------------------------|   |--------------------------------------------------------------------------------.
       KC_ESC,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,        KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_MINS,  KC_EQL, KC_BSLS,  KC_GRV,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------+--------+--------|
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_LBRC, KC_RBRC,KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------+--------|
     KC_LCTRL,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,        KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,  KC_ENT,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,        KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_RSFT, MO(_L1),
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
               KC_LALT, KC_LGUI,  KC_SPC,  KC_SPC,               KC_SPC,  KC_SPC,          KC_RGUI, KC_RALT
          //`---------------------------------------------|   |--------------------------------------------'
  ),

  [_L1] = LAYOUT(
  //,-----------------------------------------------------|   |--------------------------------------------------------------------------------.
  TG(_L2),   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,       KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,  KC_INS,  KC_DEL,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,     _______, _______, KC_PSCR, KC_SLCK,KC_PAUSE,   KC_UP, _______, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,     _______, _______, KC_HOME, KC_PGUP, KC_LEFT,KC_RIGHT, _______,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,     _______, _______,  KC_END, KC_PGDN, KC_DOWN, _______, _______,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
               _______, _______, _______, _______,              _______, _______,          KC_STOP, _______
          //`---------------------------------------------|   |--------------------------------------------'
  ),

  [_L2] = LAYOUT( /* Base */
  //,-----------------------------------------------------|   |--------------------------------------------------------------------------------.
 TG(_L2), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   QK_BOOT,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     RGB_TOG, RGB_MOD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     RGB_VAD, RGB_VAI, RGB_HUD, RGB_HUI, RGB_SAD, RGB_SAI, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
               XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,              XXXXXXX, XXXXXXX,          KC_STOP, XXXXXXX
          //`---------------------------------------------|   |--------------------------------------------'
  ),

  [_L3] = LAYOUT( /* Base */
  //,-----------------------------------------------------|   |--------------------------------------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   QK_BOOT,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
               XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,              XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX
          //`---------------------------------------------|   |--------------------------------------------'
  )
};


//A description for expressing the layer position in LED mode.
layer_state_t layer_state_set_user(layer_state_t state) {
#ifdef RGBLIGHT_ENABLE
    switch (get_highest_layer(state)) {
    case _L1:
      rgblight_sethsv_at(HSV_BLUE, 0);
      break;
    case _L2:
      rgblight_sethsv_at(HSV_RED, 0);
      break;
    case _L3:
      rgblight_sethsv_at(HSV_PURPLE, 0);
      break;
    default: //  for any other layers, or the default layer
      rgblight_sethsv_at( 0, 0, 0, 0);
      break;
    }
    rgblight_set_effect_range( 1, 11);
#endif
return state;
}
