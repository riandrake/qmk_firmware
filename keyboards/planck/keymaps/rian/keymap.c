#include "planck.h"
#include "action_layer.h"
#include "include.h"

extern keymap_config_t keymap_config;

enum planck_layers
{
  _QWERTY,
  _LOWER,
  _UPPER,
  _MOUSE,
  _TAB,
};

#define KC_REST RESET
#define KC_LOWR MO(_LOWER)
#define KC_UPPR MO(_UPPER)
#define KC_TAB  LT(_TAB, KC_TAB)
#define KC_XESC LT(_MOUSE, KC_ESC)
#define KC_RESV KC_TRNS
#define KC_____ KC_TRNS
#define KC_XXXX KC_NO


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] =
{
  [_QWERTY] = LAYOUT(
    TAB , Q   , W   , E   , R   , T   , Y   , U   , I   , O   , P   , BSPC
  , XESC, A   , S   , D   , F   , G   , H   , J   , K   , L   , SCLN, EQL
  , LSFT, Z   , X   , C   , V   , B   , N   , M   , COMM, DOT , SLSH, ENT  
  , LCTL, LGUI, XXXX, XXXX, LALT, LOWR, SPC , UPPR, HYPR, XXXX, XXXX, XXXX),

  [_LOWER] = LAYOUT(
    TILD, EXLM, AT  , HASH, DLR , PERC, CIRC, AMPR, ASTR, LPRN, RPRN, ____
  , DEL , LCBR, RCBR, UNDS, QUOT, PIPE, LEFT, DOWN, UP  , RGHT, ____, ____
  , ____, ____, ____, ____, ____, ____, APP , ____, ____, ____, ____, ____
  , ____, ____, XXXX, XXXX, RESV, ____, ____, RESV, HYPR, XXXX, XXXX, XXXX ),

  [_UPPER] = LAYOUT(
    GRV , 1   , 2   , 3   , 4   , 5   , 6   , 7   , 8   , 9   , 0   , ____
  , ESC , LBRC, RBRC, MINS, DQT , BSLS, ____, ____, ____, ____, ____, ____
  , ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____
  , ____, ____, XXXX, XXXX, RESV, ____, ____, RESV, ____, XXXX, XXXX, XXXX ),

  [_TAB] = LAYOUT(
    RESV, F1  , F2  , F3  , F4  , F5  , F6  , F7  , F8  , F9  , F10 , F11
  , ESC , ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, F12
  , ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____
  , ____, ____, XXXX, XXXX, XXXX, ____, ____, XXXX, ____, XXXX, XXXX, XXXX ),

  [_MOUSE] = LAYOUT(
    TAB , MPRV, MPLY, MNXT, VOLD, VOLU, ____, ____, ____, ____, ____, REST
  , RESV, BTN2, BTN3, BTN1, WH_U, ____, MS_L, MS_D, MS_U, MS_R, ____, ____
  , ____, ____, ____, WH_D, ____, ____, ____, ____, ____, ____, ____, ____
  , ____, ____, XXXX, XXXX, XXXX, ____, ____, XXXX, ____, XXXX, XXXX, XXXX ),
};

uint32_t layer_state_set_user(uint32_t state)
{
  //state = update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
  return state;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
  return true;
}
