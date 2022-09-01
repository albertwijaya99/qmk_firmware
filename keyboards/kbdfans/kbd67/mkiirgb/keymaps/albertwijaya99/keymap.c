#include QMK_KEYBOARD_H
#define _LAYER0 0
#define _LAYER1 1

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
		[_LAYER0] = LAYOUT_65_ansi_blocker( /* Base */
			KC_GESC,  KC_1,     KC_2,     KC_3,  KC_4,  KC_5,  KC_6,    KC_7,  KC_8,    KC_9,     KC_0,     KC_MINS,  KC_EQL,  KC_BSPC,   KC_HOME,
      KC_TAB,   KC_Q,     KC_W,     KC_E,  KC_R,  KC_T,  KC_Y,    KC_U,  KC_I,    KC_O,     KC_P,     KC_LBRC,  KC_RBRC, KC_BSLASH, KC_PGUP,
			KC_CAPS,  KC_A,     KC_S,     KC_D,  KC_F,  KC_G,  KC_H,    KC_J,  KC_K,    KC_L,     KC_SCLN,  KC_QUOT,           KC_ENT,    KC_PGDN,
      KC_LSFT,  KC_Z,     KC_X,     KC_C,  KC_V,  KC_B,  KC_N,    KC_M,  KC_COMM, KC_DOT,   KC_SLSH,  KC_RSFT,           KC_UP,     KC_END,
      KC_LCTL,  KC_LGUI,  KC_LALT,                KC_SPC,                KC_MPLY,           MO(1),    KC_LEFT,           KC_DOWN,   KC_RIGHT),
		[_LAYER1] = LAYOUT_65_ansi_blocker( /* FN */
			KC_GRV,   KC_F1,    KC_F2,   KC_F3,  KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,  KC_F12,  KC_DEL,   KC_TRNS,
      KC_TRNS,  RGB_TOG,  RGB_MOD, RGB_HUI,RGB_SAI, RGB_VAI, RGB_SPI, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,
			KC_TRNS,  KC_TRNS,  RGB_RMOD,RGB_HUD,RGB_SAD, RGB_VAD, RGB_SPD, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,          KC_TRNS,  KC_TRNS,
      KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS,KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,          KC_VOLU,  KC_TRNS,
      KC_TRNS,  KC_TRNS,  KC_TRNS,                  KC_TRNS,                   KC_TRNS,          KC_TRNS,  KC_MPRV,          KC_VOLD,  KC_MNXT),
};

enum combo_events {
  CLOSE,
  RENAME,
  RENAME2,
  CLEAR_LINE,
  BACKTICK,
  COMBO_LENGTH
};
uint16_t COMBO_LEN = COMBO_LENGTH;

const uint16_t PROGMEM c_close[] = {KC_LALT, KC_4, COMBO_END};
const uint16_t PROGMEM c_rename[] = {KC_LALT, KC_2, COMBO_END};
const uint16_t PROGMEM c_rename2[] = {KC_LSFT, KC_6, COMBO_END};
const uint16_t PROGMEM c_clear_line[] = {KC_LSFT, KC_BSPC, COMBO_END};
const uint16_t PROGMEM c_backtick[] = {KC_LCTL, KC_GESC, COMBO_END};

combo_t key_combos[] = {
	[CLOSE] = COMBO_ACTION(c_close),
	[RENAME] = COMBO_ACTION(c_rename),
	[RENAME2] = COMBO_ACTION(c_rename2),
	[CLEAR_LINE] = COMBO_ACTION(c_clear_line),
  [BACKTICK] = COMBO_ACTION(c_backtick)
};

void process_combo_event(uint16_t combo_index, bool pressed) {
  switch(combo_index) {
    case CLOSE:
      if (pressed) {
        tap_code16(LALT(KC_F4));
      }	
      break;
    case RENAME:
      if (pressed) {
        tap_code16(KC_F2);
      }	
      break;
    case RENAME2:
      if (pressed) {
        tap_code16(LSFT(KC_F6));
      }	
      break;
    case BSPC_LSFT_CLEAR:
      if (pressed) {
        tap_code16(KC_END);
        tap_code16(S(KC_HOME));
        tap_code16(KC_BSPC);
      }
      break;
    case BACKTICK:
      if (pressed) {
        tap_code16(KC_GRV);
      }
      break;
  }
}
