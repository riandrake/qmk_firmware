#include QMK_KEYBOARD_H
#include "bootloader.h"
#ifdef PROTOCOL_LUFA
  #include "lufa.h"
  #include "split_util.h"
#endif
#ifdef SSD1306OLED
  #include "ssd1306.h"
#endif

extern keymap_config_t keymap_config;

#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

extern uint8_t is_master;

enum Layers
{
	_QWERTY,
	_LOWER,
	_RAISE,
	_ADJUST,
};

enum custom_keycodes {
	QWERTY = SAFE_RANGE,
	LOWER,
	RAISE,
	ADJUST,
	FUNC
};

#define KC_____ KC_TRNS
#define KC_XXXX KC_NO
#define KC_LOWR LOWER
#define KC_RAIS RAISE
#define KC_FUNC FUNC
#define KC_RST  RESET

#define KC_SFTx SFT_T(KC_ESC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] =
{
  [_QWERTY] = LAYOUT_kc( \
  //,-----------------------------.            ,-----------------------------.
      TAB,   Q,   W,   E,   R,   T,                Y,   U,   I,   O,   P,BSPC,\
  //|----+----+----+----+----+----|            |----+----+----+----+----+----|
     SFTx,   A,   S,   D,   F,   G,                H,   J,   K,   L,SCLN, EQL,\
  //|----+----+----+----+----+----|            |----+----+----+----+----+----|
     LCTL,   Z,   X,   C,   V,   B,                N,   M,COMM, DOT,SLSH, ENT,\
  //|----+----+----+----+----+----+----|  |----+----+----+----+----+----+----|
                         LALT,LOWR, SPC,    RGUI,RAIS,HYPR\
                       //`-------------'  `--------------'
  ),

  [_LOWER] = LAYOUT_kc( \
  //,-----------------------------.            ,-----------------------------.
     TILD,EXLM,  AT,HASH, DLR,PERC,             CIRC,AMPR,ASTR,LPRN,RPRN,____,\
  //|----+----+----+----+----+----|            |----+----+----+----+----+----|
     ____,LCBR,RCBR,UNDS,QUOT,____,             LEFT,DOWN,  UP,RGHT,____,____,\
  //|----+----+----+----+----+----|            |----+----+----+----+----+----|
     ____,PIPE,____,____,____, DEL,              APP,____,____,____,____,____,\
  //|----+----+----+----+----+----+----|  |----+----+----+----+----+----+----|
                         ____,____,____,   ____,____,____\
                       //`-------------'  `--------------'
  ),

  [_RAISE] = LAYOUT_kc( \
  //,-----------------------------.            ,-----------------------------.
      GRV,   1,   2,   3,   4,   5,                6,   7,   8,   9,   0,____,\
  //|----+----+----+----+----+----|            |----+----+----+----+----+----|
     ____,LBRC,RBRC,MINS, DQT,____,             HOME,PGDN,PGUP, END,____,____,\
  //|----+----+----+----+----+----|            |----+----+----+----+----+----|
     ____,BSLS,____,____,____,____,             ____,____,____,____,____,____,\
  //|----+----+----+----+----+----+----|  |----+----+----+----+----+----+----|
                         ____,____,____,   ____,____,____\
                       //`-------------'  `--------------'
  ),

  [_ADJUST] = LAYOUT_kc( \
  //,-----------------------------.            ,-----------------------------.
      F12,  F1,  F2,  F3,  F4,  F5,               F6,  F7,  F8,  F9, F10, F11,\
  //|----+----+----+----+----+----|            |----+----+----+----+----+----|
     ____,BTN2,BTN3,BTN1,WH_U,VOLU,             MS_L,MS_D,MS_U,MS_R,____,____,
  //|----+----+----+----+----+----|            |----+----+----+----+----+----|
     ____,MPRV,MPLY,MNXT,WH_D,VOLD,              RST,____,____,____,____,____,\
  //|----+----+----+----+----+----+----|  |----+----+----+----+----+----+----|
                         ____,____,____,   ____,____,____\
                       //`-------------'  `--------------'
  )
};

uint16_t get_tapping_term( uint16_t keycode )
{
    return 175;
}

int RGB_current_mode;

void persistent_default_layer_set( uint16_t default_layer )
{
	eeconfig_update_default_layer( default_layer );
	default_layer_set( default_layer );
}

// Setting ADJUST layer RGB back to default
void update_tri_layer_RGB( uint8_t layer1, uint8_t layer2, uint8_t layer3 )
{
	if ( IS_LAYER_ON( layer1 ) && IS_LAYER_ON( layer2 ) )
		layer_on( layer3 );
	else
		layer_off( layer3 );
}

void matrix_init_user(void)
{
#ifdef RGBLIGHT_ENABLE
	RGB_current_mode = rgblight_config.mode;
#endif
	//SSD1306 OLED init, make sure to add #define SSD1306OLED in config.h
#ifdef SSD1306OLED
	iota_gfx_init( !has_usb() );   // turns on the display
#endif
}

//SSD1306 OLED update loop, make sure to add #define SSD1306OLED in config.h
#ifdef SSD1306OLED

// When add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

void matrix_scan_user(void)
{
	iota_gfx_task();
}

void matrix_render_user( struct CharacterMatrix *matrix )
{
	if( is_master )
	{
		// If you want to change the display of OLED, you need to change here
		matrix_write_ln( matrix, read_layer_state() );
		matrix_write_ln( matrix, read_keylog() );
		matrix_write_ln( matrix, read_keylogs() );
		//matrix_write_ln(matrix, read_mode_icon(keymap_config.swap_RGUI_LALT));
		//matrix_write_ln(matrix, read_host_led_state());
		//matrix_write_ln(matrix, read_timelog());
	}
	else
	{
		matrix_write( matrix, read_logo() );
	}
}

void matrix_update( struct CharacterMatrix *dest, const struct CharacterMatrix *source )
{
	if( memcmp( dest->display, source->display, sizeof( dest->display ) ) )
	{
		memcpy( dest->display, source->display, sizeof( dest->display ) );
		dest->dirty = true;
	}
}

void iota_gfx_task_user( void )
{
	struct CharacterMatrix matrix;
	matrix_clear( &matrix );
	matrix_render_user( &matrix );
	matrix_update( &display, &matrix );
}
#endif//SSD1306OLED

bool process_record_user( uint16_t keycode, keyrecord_t *record )
{
	if ( record->event.pressed )
	{
#ifdef SSD1306OLED
		set_keylog( keycode, record );
#endif
	// set_timelog();
	}

	switch ( keycode )
	{
	case QWERTY:
		if ( record->event.pressed )
			persistent_default_layer_set( 1UL << _QWERTY );
		return false;
	case LOWER:
		if ( record->event.pressed )
		{
			layer_on( _LOWER );
			update_tri_layer_RGB( _LOWER, _RAISE, _ADJUST );
		}
		else
		{
			layer_off( _LOWER );
			update_tri_layer_RGB( _LOWER, _RAISE, _ADJUST );
		}
		return false;
	case RAISE:
		if ( record->event.pressed )
		{
			layer_on( _RAISE );
			update_tri_layer_RGB( _LOWER, _RAISE, _ADJUST );
		}
		else
		{
			layer_off( _RAISE );
			update_tri_layer_RGB( _LOWER, _RAISE, _ADJUST );
		}
		return false;
	case ADJUST:
		if ( record->event.pressed )
			layer_on( _ADJUST );
		else
			layer_off( _ADJUST );
		return false;
	}
	return true;
}
