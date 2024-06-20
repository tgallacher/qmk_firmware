#include QMK_KEYBOARD_H

enum layer_number {
  _QWERTY = 0,
  _LOWER,
  _RAISE,
  _ADJUST,  // unused
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | BSPC |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LCTRL |LWR A |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |    J |    K |    L |    ; |  '   |
 * |------+------+------+------+------+------|  C-b  |    |   \   |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |SHIFT |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |  ALT | /Super  /       \Space \  |   ENT   |      | RAISE|
 *                   |      |      |      |/       /         \      \ |         |      |      |
 *                   `----------------------------'           '------''-----------------------'
 */

 [_QWERTY] = LAYOUT(
  KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINUS,
  KC_LCTL,  LT(_LOWER, KC_A), KC_S, KC_D, KC_F, KC_G,      KC_H,    KC_J,          KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, LCTL(KC_B),              KC_BSLS,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_LSFT,
                         XXXXXXX, XXXXXXX, KC_LALT, KC_LGUI,                  KC_SPACE,  KC_ENT, XXXXXXX, MO(_RAISE)
),
/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |TRANS |TRANS |TRANS |TRANS |TRANS |TRANS |                    | PREV | PLAY | NEXT |VOLDW | MUTE |VOLUP|
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |TRANS |TRANS |TRANS |TRANS |TRANS |TRANS |                    |   (  |  )   |      |      |   [  |  ]   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |TRANS |TRANS |TRANS |TRANS |TRANS |TRANS |-------.    ,-------|LEFT  | DOWN |  UP  | RIGHT|   :  |  \|  |
 * |------+------+------+------+------+------|       |    |   +   |------+------+------+------+------+------|
 * |      |LShift|      |      |      |      |-------|    |-------|      |      |      |      |      |  `~  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |TRANS |TRANS |TRANS | /TRANS  /       \   =   \  |      |      |      |
 *                   |      |      |      |/       /         \       \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_LOWER] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                              KC_MRWD, KC_MPLY, KC_MFFD, KC_KB_VOLUME_DOWN, KC_KB_MUTE, KC_KB_VOLUME_UP,
  _______, _______, _______, _______, _______, _______,                              KC_LPRN, KC_RPRN, _______, _______, KC_LBRC, KC_RBRC,
  _______, _______, _______, _______, _______, _______,                              KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_COLN, KC_BSLS,
  _______, KC_LSFT, _______, _______, _______, _______, _______,            KC_PLUS, _______, _______, _______, _______, _______, KC_GRV,
                             _______, _______, _______, _______,            KC_EQL, _______, _______, _______
),
/* RAISE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |                    |      |      |      |      |      |     |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  F7  |  F8  |  F9  | F10  | F11  | F12  |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |      |      |      |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|DT_PRNT|DT_UP|DT_DOWN|      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |TRANS |TRANS |TRANS | /TRANS  /       \TRANS \  |TRANS |TRANS |TRANS |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_RAISE] = LAYOUT(
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                                KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                               XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                              XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,            XXXXXXX, DT_PRNT, DT_UP,   DT_DOWN, XXXXXXX, XXXXXXX, XXXXXXX,
                             _______, _______, _______, _______,            _______, _______, _______, _______
)
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
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

const char *read_mode_icon(bool swap);
void set_timelog(void);
const char *read_timelog(void);

bool oled_task_user(void) {
  if (is_keyboard_master()) {
    // If you want to change the display of OLED, you need to change here
    oled_write_ln(read_mode_icon(keymap_config.swap_lalt_lgui), false); // apple, win, alt?
    oled_write_ln(read_layer_state(), false); // current keyboard layer
    // oled_write_ln(read_keylog(), false);
    oled_write_ln(read_keylogs(), false); // show keystrokes
    // oled_write_ln(read_timelog(), false);
  } else {
    oled_write(read_logo(), false);
    // oled_write_ln(read_mode_icon(keymap_config.swap_lalt_lgui), false); // apple, win, alt?
    // oled_write_ln(read_keylogs(), false); // show keystrokes
  }
    return false;
}
#endif // OLED_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
#ifdef OLED_ENABLE
    set_keylog(keycode, record); // record keystroke
    // set_timelog();
#endif
  }
  return true;
}
