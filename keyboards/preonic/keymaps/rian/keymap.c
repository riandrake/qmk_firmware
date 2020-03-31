#include "preonic.h"
#include "action_layer.h"

extern keymap_config_t keymap_config;

enum planck_layers
{
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST,
};

#define LT_LOW  MO(_LOWER)
#define LT_RAIS MO(_RAISE)
#define RESERVD KC_TRNS

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] =
{
  [_QWERTY] = LAYOUT_ortho_5x12(                                                                   // DEFAULT
    KC_GRV , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_BSPC
  , KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   , KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_EQL
  , KC_ESC , KC_A   , KC_S   , KC_D   , KC_F   , KC_G   , KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOT
  , KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_HYPR 
  , KC_LCTL, KC_LGUI, KC_APP , KC_LALT, LT_LOW , KC_MINS, KC_SPC , LT_RAIS, KC_RALT, KC_BSLS, KC_RGUI, KC_ENT ),

  [_LOWER] = LAYOUT_ortho_5x12(                                                                      // LOWER
    KC_F12, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 
  , _______, KC_LCBR, KC_RCBR, _______, _______, _______, _______, _______, _______, KC_LBRC, KC_RBRC, _______
  , KC_DEL , _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, _______, _______
  , _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  , _______, _______, _______, _______, RESERVD, _______, _______, RESERVD, _______, _______, _______, _______ ),

  [_RAISE] = LAYOUT_ortho_5x12(                                                                      // RAISE
    KC_F12 , KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 
  , _______, KC_LCBR, KC_RCBR, _______, KC_WH_U, _______, _______, _______, _______, KC_LBRC, KC_RBRC, _______
  , _______, KC_BTN2, KC_BTN3, KC_BTN1, KC_WH_D, _______, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, _______, _______
  , _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  , _______, _______, _______, _______, RESERVD, _______, _______, RESERVD, _______, _______, _______, _______ ),

  [_ADJUST] = LAYOUT_ortho_5x12(                                                             // LOWER + RAISE
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RESET  
  , _______, _______, _______, _______, KC_VOLU, _______, _______, _______, _______, _______, _______, _______
  , _______, KC_MPRV, KC_MPLY, KC_MNXT, KC_VOLD, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END , _______, _______
  , _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  , _______, _______, _______, _______, RESERVD, _______, _______, RESERVD, _______, _______, _______, _______ ),
};

uint32_t layer_state_set_user(uint32_t state)
{
  state = update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
  return state;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
  return true;
}
