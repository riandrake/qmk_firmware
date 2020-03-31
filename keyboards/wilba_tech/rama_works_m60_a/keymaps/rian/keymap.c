#include "keyboards/wilba_tech/rama_works_m60_a/rama_works_m60_a.h"
#include "keyboards/wilba_tech/wt_rgb_backlight_api.h"
#include "keyboards/wilba_tech/wt_rgb_backlight.h"

#include "rian_m60_header.h"

enum Layers
{
    DEFAULT,
    GAME,
    LOWER,
    UPPER,
    ADJUST,
    NUM_LAYERS
};

enum Keycodes
{
	KC_GAME = SAFE_RANGE,
};

#define KC_____ KC_TRNS
#define KC_RESV KC_TRNS
#define KC_XXXX KC_NO

#define KC_LOWR MO(LOWER)
#define KC_TABx LT(UPPER, KC_TAB)
#define KC_ALTx LALT_T(KC_LGUI)
#define KC_CTLx LCTL_T(KC_ESC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] =
{
[DEFAULT] = KC_LAYOUT_60_hhkb(
//+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+
	 GRV,    1,    2,    3,    4,    5,    6,    7,    8,    9,    0, MINS,  EQL,  DEL, BSPC,
//+-------+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+---------+
	  TABx,    Q,    W,    E,    R,    T,    Y,    U,    I,    O,    P, LBRC, RBRC,     BSLS,
//+---------+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-------------+
		CTLx,    A,    S,    D,    F,    G,    H,    J,    K,    L, SCLN, QUOT,          ENT,
//+------- ----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+----------+-----+
		   LSFT,    Z,    X,    C,    V,    B,    N,    M, COMM,  DOT, SLSH,      RSFT, RALT,
//+--------+-----+-------+-----------------------------------------+---------+-----+--------+
			 LOWR,   ALTx,                                      SPC,     RGUI, RCTL
//+--------+-----+-------+-----------------------------------------+---------+-----+--------+
),
[GAME] = KC_LAYOUT_60_hhkb(
//+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+
	 GRV,    1,    2,    3,    4,    5,    6,    7,    8,    9,    0, MINS,  EQL,  DEL, BSPC,
//+-------+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+---------+
	  TABx,    Q,    W,    E,    R,    T,    Y,    U,    I,    O,    P, LBRC, RBRC,     BSLS,
//+---------+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-------------+
		CTLx,    A,    S,    D,    F,    G,    H,    J,    K,    L, SCLN, QUOT,          ENT,
//+------- ----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+----------+-----+
		   LSFT,    Z,    X,    C,    V,    B,    N,    M, COMM,  DOT, SLSH,      RSFT, RALT,
//+--------+-----+-------+-----------------------------------------+---------+-----+--------+
			 LOWR,   LALT,                                      SPC,     RGUI, RCTL
//+--------+-----+-------+-----------------------------------------+---------+-----+--------+
),
[LOWER] = KC_LAYOUT_60_hhkb(
//+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+
    RESV,   F1,   F2,   F3,   F4,   F5,   F6,   F7,   F8,   F9,  F10,  F11,  F12, ____, ____,
//+-------+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+---------+
	  RESV, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____,     ____,
//+---------+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-------------+
		RESV, BTN2, BTN3, BTN1, WH_U, ____, MS_L, MS_D, MS_U, MS_R, ____, ____,         ____,
//+------- ----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+----------+-----+
		   RESV, ____, WH_D, ____, ____, ____, ____, ____, ____, ____, ____,      ____, ____,
//+--------+-----+-------+-----------------------------------------+---------+-----+--------+
			 RESV,   RESV,                                      ENT,     ____, ____
//+--------+-----+-------+-----------------------------------------+---------+-----+--------+
),
[UPPER] = KC_LAYOUT_60_hhkb(
//+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+
    RESV,   F1,   F2,   F3,   F4,   F5,   F6,   F7,   F8,   F9,  F10,  F11,  F12, ____, ____,
//+-------+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+---------+
	  RESV, VOLD, MUTE, VOLU, ____, ____, ____, ____, ____, ____, ____, ____, ____,     ____,
//+---------+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-------------+
		RESV, MPRV, MPLY, MNXT, ____,  APP, LEFT, DOWN,   UP, RGHT, ____, ____,         ____,
//+------- ----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+----------+-----+
		   RESV, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____,      ____, ____,
//+--------+-----+-------+-----------------------------------------+---------+-----+--------+
			 RESV,   RESV,                                      ENT,     ____, ____
//+--------+-----+-------+-----------------------------------------+---------+-----+--------+
),
[ADJUST] = KC_LAYOUT_60_hhkb(
//+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+
    RESV, PSCR, SLCK, PAUS, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____,
//+-------+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+---------+
	  RESV,  INS, HOME, PGUP, ____, ____, ____, ____, ____, ____, ____, ____, ____,     ____,
//+---------+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-------------+
		RESV,  DEL,  END, PGDN, ____, ____, ____, ____, ____, ____, ____, ____,         ____,
//+------- ----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+----------+-----+
		   RESV, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____,      ____, ____,
//+--------+-----+-------+-----------------------------------------+---------+-----+--------+
			 RESV,   RESV,                                     ____,     ____, GAME
//+--------+-----+-------+-----------------------------------------+---------+-----+--------+
)
};

struct Colour { uint8_t h, s, v; };
struct Colour get_colour(uint32_t layer)
{
	struct Colour out = RGB_BACKLIGHT_COLOR_1;

	switch(layer)
	{
	case DEFAULT:
		out.v = 0;
		break;
	case ADJUST:
		out.h = 40;
		out.v = 255;
		break;
	case LOWER:
		out.h = 190;
		out.v = 255;
		break;
	case UPPER:
		out.h = 128;
		out.v = 255;
		break;
	case GAME:
		out.h = 40;
		out.v = 255;
		break;
	}

	out.v = 0;

	return out;
}

void update_layer_colour(uint32_t layer)
{
	struct Colour c = get_colour(layer);
	uint8_t p1[] = {    id_color_1, c.h, c.s };
	uint8_t p2[] = { id_brightness, c.v      };
	backlight_config_set_value(p1);
	backlight_config_set_value(p2);
}

void matrix_init_user(void)
{
	update_layer_colour(DEFAULT);
};

uint32_t get_default_layer(void)
{
	return biton32(eeconfig_read_default_layer());
}

bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
    switch(keycode)
	{
	case KC_GAME:
	{
		if (record->event.pressed)
		{
			if(get_default_layer() == GAME)
			{
				set_single_persistent_default_layer(DEFAULT);
				update_layer_colour(DEFAULT);
			}
			else
			{
				set_single_persistent_default_layer(GAME);
				update_layer_colour(GAME);
			}
		}
		return false;
	}
	}
	return true;
}

uint32_t layer_state_set_user(uint32_t state)
{
	state = update_tri_layer_state(state, LOWER, UPPER, ADJUST);

	uint32_t layer = biton32(state);

	if(!layer)
		update_layer_colour(get_default_layer());
	else
		update_layer_colour(biton32(state));

    return state;
}
