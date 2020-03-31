#include QMK_KEYBOARD_H
#include "rgblight.h"
#include "include.h"

enum Layers { _QWERT, _GAME, _LOWER, _UPPER, _FUNCT, _MOUSE };

#define KC_RESV _______
#define KC_____ _______
#define KC_XXXX KC_NO
#define KC_UPPR MO(_UPPER)
#define KC_LOWR MO(_LOWER)
#define KC_XESC LT(_MOUSE, KC_ESC)
#define KC_XTAB LT(_FUNCT, KC_TAB)
#define KC_FUNC MO(_FUNCT)
#define KC_GAME TG(_GAME)
#define KC_REST RESET
#define KC_RGB  RGB_TOG

#define KC_NXTD  LCTL(LGUI(KC_RGHT))
#define KC_LSTD  LCTL(LGUI(KC_LEFT))

#define RGB_CARBON 100,30,0
#define RGB_GAME  50,80,240

extern keymap_config_t keymap_config;
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] =
{
    [_QWERT] = LAYER(
        XTAB, Q   , W   , E   , R   , T   , Y   , U   , I   , O   , P   , BSPC,
        XESC, A   , S   , D   , F   , G   , H   , J   , K   , L   , SCLN, EQL ,
        LSFT, Z   , X   , C   , V   , B   , N   , M   , COMM, DOT , SLSH, ENT ,
        LCTL, LGUI, LALT,             LOWR, SPC ,             UPPR, HYPR, GAME  
    ),
    [_GAME] = LAYER(
         TAB, Q   , W   , E   , R   , T   , Y   , U   , I   , O   , P   , BSPC,
         ESC, A   , S   , D   , F   , G   , H   , J   , K   , L   , SCLN, EQL ,
        LSFT, Z   , X   , C   , V   , B   , N   , M   , COMM, DOT , SLSH, ENT ,
        LCTL, LGUI, LALT,             SPC , LOWR,             UPPR, HYPR, GAME  
    ),
    [_LOWER] = LAYER(
        TILD, EXLM, AT  , HASH, DLR , PERC, CIRC, AMPR, ASTR, LPRN, RPRN, ____,
		DEL , LCBR, RCBR, UNDS, QUOT, PIPE, LEFT, DOWN, UP  , RGHT, ____, ____,
        ____, ____, ____, ____, ____, ____, APP , ____, ____, ____, ____, ____,
        ____, ____, ____,             RESV, RESV,             RESV, ____, ____
    ),
    [_UPPER] = LAYER(
        GRV , 1   , 2   , 3   , 4   , 5   , 6   , 7   , 8   , 9   , 0   , ____,
		DEL , LBRC, RBRC, MINS, DQT , BSLS, LEFT, DOWN, UP  , RGHT, ____, ____,
        ____, ____, ____, ____, ____, ____, APP , ____, ____, ____, ____, ____,
        ____, ____, ____,             RESV, RESV,             RESV, ____, ____
    ),
    [_FUNCT] = LAYER(
        RESV, F1  , F2  , F3  , F4  , F5  , F6  , F7  , F8  , F9  , F10 , F11 ,
        ESC , ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, F12 ,
        ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____,
        ____, ____, ____,             XXXX, RESV,             XXXX, ____, ____
    ),
    [_MOUSE] = LAYER(
        MUTE, MPRV, MPLY, MNXT, ____, ____, ____, ____, ____, ____, ____, ____,
        RESV, BTN2, BTN3, BTN1, WH_U, VOLU, MS_L, MS_D, MS_U, MS_R, ____, RGB ,
        ____, ____, ____, WH_D, VOLD, ____, ____, ____, ____, ____, ____, ____,
        ____, ____, ____,             XXXX, RESV,             XXXX, ____, REST
    )
};

uint16_t get_tapping_term( uint16_t keycode )
{
    return 175;
}

void update_rgb( uint32_t state )
{
    switch( biton32( state ) ) 
    {
    case _QWERT:
        rgblight_setrgb( RGB_CARBON );
        break;
	case _GAME:
        rgblight_setrgb( RGB_GAME );
		break;
    default:
        rgblight_setrgb( RGB_PURPLE );
        break;
    }
}

uint32_t layer_state_set_user( uint32_t state )
{
	//state = update_tri_layer_state(state, _LOWER, _UPPER, _ADJST);
    update_rgb(state );
    return state;
}

void persistent_default_layer_set( uint16_t default_layer )
{
    eeconfig_update_default_layer( default_layer );
    default_layer_set( default_layer );
}

void keyboard_post_init_user()
{
    rgblight_enable_noeeprom();
    rgblight_setrgb( RGB_CARBON );
}

void suspend_power_down_user()
{
    rgblight_disable_noeeprom();
}

void suspend_wakeup_init_user()
{
    rgblight_enable_noeeprom();
}
