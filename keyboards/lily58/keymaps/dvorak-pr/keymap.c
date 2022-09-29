#include QMK_KEYBOARD_H

enum layer_number {
  _DVORAK = 0,
  _FUNCTION,
  _ADJUST,
  _QWERTY
};

#define WIN_PRTSC LGUI(LSFT(KC_S))
#define MAC_PRTSC LGUI(LSFT(LCTL(KC_F4)))


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_DVORAK] = LAYOUT(
	KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, 
	KC_BSLS, KC_GRV, KC_QUOT, KC_COMM, KC_DOT, KC_P, KC_Y, KC_F, KC_G, KC_C, KC_R, KC_L, KC_EQL, 
	KC_TAB, KC_A, KC_O, KC_E, KC_U, KC_I, KC_D, KC_H, KC_T, KC_N, KC_S, KC_MINS, 
	LT(_FUNCTION,TO(_FUNCTION)), KC_SCLN, KC_Q, KC_J, KC_K, KC_X, KC_LBRC, KC_RBRC, KC_B, KC_M, KC_W, KC_V, KC_Z, KC_SLSH, 
	        KC_LCTL, KC_LALT, KC_BSPC, LSFT_T(KC_CAPS), RCTL_T(KC_ENT), KC_SPC, KC_APP, KC_LGUI
	),
	
	[_FUNCTION] = LAYOUT(
	KC_ESC, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,                                    KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, 
	LT(_ADJUST,TO(_ADJUST)), RGB_TOG, RGB_MOD, RGB_VAD, RGB_VAI, KC_F10,          KC_P7, KC_P8, KC_P9, KC_LPRN, KC_RPRN, KC_F12, 
	LT(_QWERTY, TO(_QWERTY)), KC_PGUP, KC_HOME, KC_UP, KC_END, WIN_PRTSC,                    KC_P4, KC_P5, KC_P6, KC_PAST, KC_PSLS, KC_PERC, 
	LT(_DVORAK,TO(_DVORAK)), KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, MAC_PRTSC,     KC_TRNS, KC_TRNS, KC_P1, KC_P2, KC_P3, KC_PPLS, 
	        KC_PMNS, KC_TRNS, KC_RCTL, KC_RALT, KC_DEL,                           KC_TRNS, KC_TRNS, KC_P0, KC_PDOT, KC_RGUI
	),

	[_ADJUST] = LAYOUT(
	KC_ESC,  KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,              KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
	TO(1),   BL_STEP, RGB_TOG, RGB_MOD,  RGB_HUI, RGB_SAI,              KC_VOLD, KC_VOLU, KC_COPY, KC_PSTE, KC_CUT,  KC_TRNS, 
	BL_TOGG, BL_INC,  BL_BRTG, RGB_RMOD, RGB_HUD, RGB_SAD,              KC_BRIU, KC_BTN1, KC_MS_U, KC_BTN2, KC_WH_U, KC_BTN3, 
	TO(0),   BL_DEC,  RGB_SPD, RGB_SPI,  RGB_VAD, RGB_VAI,              KC_HOME, KC_END,  KC_BRID, KC_MS_L, KC_MS_D, KC_MS_R, 
	         KC_WH_D, DB_TOGG, KC_TRNS, KC_TRNS,  KC_TRNS,              KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
	 ),
	/* QWERTY
	 * ,-----------------------------------------.                    ,-----------------------------------------.
	 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
	 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
	 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  -   |
	 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
	 * |LCTRL |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
	 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
	 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
	 * `-----------------------------------------/       /     \      \-----------------------------------------'
	 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
	 *                   |      |      |      |/       /         \      \ |      |      |      |
	 *                   `----------------------------'           '------''--------------------'
	 */
	[_QWERTY] = LAYOUT(
	KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_GRV,
	KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS,
	KC_LCTRL, KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                     KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
	KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_LBRC,  KC_RBRC,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_RSFT,
						KC_LALT, KC_LGUI, MO(_FUNCTION), KC_SPC, KC_ENT, MO(_ADJUST), KC_BSPC, KC_RGUI
	),
};



layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _FUNCTION, _ADJUST, _QWERTY);
}

//SSD1306 OLED update loop, make sure to enable OLED_ENABLE=yes in rules.mk
#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master())
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  return rotation;
}

// When you add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

bool oled_task_user(void) {
  if (is_keyboard_master()) {
    // If you want to change the display of OLED, you need to change here
    oled_write_ln(read_layer_state(), false);
    oled_write_ln(read_keylog(), false);
    oled_write_ln(read_keylogs(), false);
    //oled_write_ln(read_mode_icon(keymap_config.swap_lalt_lgui), false);
    //oled_write_ln(read_host_led_state(), false);
    //oled_write_ln(read_timelog(), false);
  } else {
    oled_write(read_logo(), false);
  }
    return false;
}
#endif // OLED_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
#ifdef OLED_ENABLE
    set_keylog(keycode, record);
#endif
    // set_timelog();
  }
  return true;
}
