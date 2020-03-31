#include "iris.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _MOUSE 4
#define _ADJUST 16

enum custom_keycodes
{
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
};

#define KC_     KC_TRNS
#define _______ KC_TRNS
#define KC_XXXX KC_NO
#define KC_LOWR LOWER
#define KC_RASE RAISE
#define KC_RST  RESET
#define KC_BL_S BL_STEP
#define KC_DBUG DEBUG
#define KC_RTOG RGB_TOG
#define KC_RMOD RGB_MOD
#define KC_RHUI RGB_HUI
#define KC_RHUD RGB_HUD
#define KC_RSAI RGB_SAI
#define KC_RSAD RGB_SAD
#define KC_RVAI RGB_VAI
#define KC_RVAD RGB_VAD

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] =
{
  //============================================================================

  [_QWERTY] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
      TAB, 1  , 2  , 3  , 4  , 5  ,                6  , 7  , 8  , 9  , 0  ,BSPC,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
      ESC, Q  , W  , E  , R  , T  ,                Y  , U  , I  , O  , P  , EQL,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     LSFT, A  , S  , D  , F  , G  ,                H  , J  , K  , L  ,SCLN,QUOT,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
     LCTL, Z  , X  , C  , V  , B  ,LGUI,      ENT, N  , M  ,COMM,DOT ,SLSH,BSLS,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                       LALT,LOWR,MINS,          SPC,RASE,HYPR
  //                  `----+----+----'        `----+----+----'  
  ),

  //============================================================================

  [_LOWER] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     TILD,    ,    ,    ,    ,    ,                   ,    ,    ,    ,    ,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
      DEL,LCBR,RCBR,    ,    ,    ,                APP,    ,    ,LBRC,RBRC, F12,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,MPRV,MPLY,MNXT,WH_U,VOLU,               LEFT,DOWN, UP ,RGHT,    ,    ,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
         ,    ,    ,    ,WH_D,VOLD,         ,    ,    ,    ,    ,    ,    ,    ,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                           ,    ,    ,             ,    ,
  //                  `----+----+----'        `----+----+----'
  ),

  [_RAISE] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
      GRV, F1 , F2 , F3 , F4 , F5 ,                F6 , F7 , F8 , F9 , F10, F11,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,                   ,    ,    ,    ,PSCR, F12,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,BTN2,BTN3,BTN1,WH_U,VOLU,               MS_L,MS_D,MS_U,MS_R,    ,    ,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
         ,    ,    ,    ,WH_D,VOLD,         ,    ,    ,    ,    ,    ,    ,    ,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                           ,    ,    ,             ,    ,
  //                  `----+----+----'        `----+----+----'
  ),

  [_ADJUST] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
         ,    ,    ,    ,    ,    ,                   ,    ,    ,    ,    , RST,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,                   ,    ,    ,    ,    ,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,BTN2,BTN3,BTN1,WH_U,VOLU,               MS_L,MS_D,MS_U,MS_R,    ,    ,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
         ,    ,    ,    ,WH_D,VOLD,         ,    ,    ,    ,    ,    ,    ,    ,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                           ,    ,    ,             ,    ,
  //                  `----+----+----'        `----+----+----'
  ),

  //============================================================================
};

void persistent_default_layer_set( uint16_t default_layer )
{
  eeconfig_update_default_layer( default_layer );
  default_layer_set( default_layer );
}

bool process_record_user( uint16_t keycode, keyrecord_t* record )
{
  switch (keycode)
  {
    case QWERTY:
      if( record->event.pressed )
      {
        persistent_default_layer_set( 1UL << _QWERTY );
      }
      return false;
   case LOWER:
      if( record->event.pressed )
      {
        layer_on( _LOWER );
        update_tri_layer( _LOWER, _RAISE, _ADJUST );
      }
      else
      {
        layer_off( _LOWER );
        update_tri_layer( _LOWER, _RAISE, _ADJUST );
      }
      return false;
    case RAISE:
      if( record->event.pressed )
      {
        layer_on( _RAISE );
        update_tri_layer( _LOWER, _RAISE, _ADJUST );
      }
      else
      {
        layer_off( _RAISE );
        update_tri_layer( _LOWER, _RAISE, _ADJUST );
      }
      return false;
    case ADJUST:
      if( record->event.pressed )
      {
        layer_on( _ADJUST );
      }
      else
      {
        layer_off( _ADJUST );
      }
      return false;
  }
  return true;
}
