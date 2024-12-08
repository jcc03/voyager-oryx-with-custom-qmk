#include QMK_KEYBOARD_H
#include "version.h"
#define MOON_LED_LEVEL LED_LEVEL
#define ML_SAFE_RANGE SAFE_RANGE

enum custom_keycodes {
  RGB_SLD = ML_SAFE_RANGE,
};



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_voyager(
    KC_EQUAL,       KC_1,           KC_2,           KC_3,           KC_4,           KC_5,                                           KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_MINUS,       
    KC_GRAVE,       KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,                                           KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_BSLS,        
    KC_NO,          MT(MOD_LGUI, KC_A),MT(MOD_LALT, KC_S),MT(MOD_LCTL, KC_D),MT(MOD_LSFT, KC_F),KC_G,                                           KC_H,           MT(MOD_RSFT, KC_J),MT(MOD_LCTL, KC_K),MT(MOD_LALT, KC_L),MT(MOD_RGUI, KC_SCLN),KC_QUOTE,       
    KC_NO,          KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,                                           KC_N,           KC_M,           KC_COMMA,       KC_DOT,         KC_SLASH,       TG(3),          
                                                    KC_BSPC,        KC_TAB,                                         KC_ENTER,       LT(1,KC_SPACE)
  ),
  [1] = LAYOUT_voyager(
    KC_LBRC,        KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,                                          KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,         
    KC_RBRC,        KC_NO,          KC_ESCAPE,      KC_PAGE_UP,     KC_PSCR,        KC_TRANSPARENT,                                 KC_NO,          KC_NO,          KC_UP,          KC_DELETE,      KC_NO,          KC_F12,         
    KC_LCBR,        KC_TRANSPARENT, MT(MOD_LALT, KC_HOME),MT(MOD_LCTL, KC_PGDN),MT(MOD_LSFT, KC_END),KC_TRANSPARENT,                                 KC_NO,          KC_LEFT,        KC_DOWN,        KC_RIGHT,       KC_NO,          KC_NO,          
    KC_RCBR,        KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [2] = LAYOUT_voyager(
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
    KC_NO,          KC_EXLM,        KC_AT,          KC_HASH,        KC_DLR,         KC_PERC,                                        KC_7,           KC_8,           KC_9,           KC_MINUS,       KC_SLASH,       KC_NO,          
    KC_NO,          KC_CIRC,        KC_AMPR,        KC_ASTR,        KC_LPRN,        KC_RPRN,                                        KC_4,           KC_5,           KC_6,           KC_PLUS,        KC_ASTR,        KC_NO,          
    KC_NO,          KC_ESCAPE,      KC_LBRC,        KC_RBRC,        KC_LCBR,        KC_RCBR,                                        KC_1,           KC_2,           KC_3,           KC_DOT,         KC_EQUAL,       KC_NO,          
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_0
  ),
  [3] = LAYOUT_voyager(
    KC_EQUAL,       KC_1,           KC_2,           KC_3,           KC_4,           KC_5,                                           KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_MINUS,       
    KC_TAB,         KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,                                           KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_BSLS,        
    KC_LEFT_SHIFT,  KC_A,           KC_S,           KC_D,           KC_F,           KC_G,                                           KC_H,           KC_J,           KC_K,           KC_L,           KC_SCLN,        KC_TRANSPARENT, 
    KC_LEFT_GUI,    KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,                                           KC_N,           KC_M,           KC_COMMA,       KC_DOT,         KC_SLASH,       KC_TRANSPARENT, 
                                                    KC_BSPC,        KC_LEFT_CTRL,                                   KC_ENTER,       KC_SPACE
  ),
};

const uint16_t PROGMEM combo0[] = { KC_F, KC_J, COMBO_END};
const uint16_t PROGMEM combo1[] = { MT(MOD_LSFT, KC_F), MT(MOD_RSFT, KC_J), COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    COMBO(combo0, LALT(KC_TAB)),
    COMBO(combo1, KC_CAPS),
};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_EQUAL:
            return TAPPING_TERM + 200;
        case MT(MOD_LGUI, KC_A):
            return TAPPING_TERM + 40;
        case MT(MOD_LALT, KC_S):
            return TAPPING_TERM + 20;
        case MT(MOD_LSFT, KC_F):
            return TAPPING_TERM -20;
        case KC_Z:
            return TAPPING_TERM + 200;
        case KC_MINUS:
            return TAPPING_TERM + 200;
        case KC_P:
            return TAPPING_TERM + 200;
        case MT(MOD_RSFT, KC_J):
            return TAPPING_TERM -20;
        case MT(MOD_LALT, KC_L):
            return TAPPING_TERM + 20;
        case MT(MOD_RGUI, KC_SCLN):
            return TAPPING_TERM + 40;
        case KC_SLASH:
            return TAPPING_TERM + 200;
        case MT(MOD_LALT, KC_HOME):
            return TAPPING_TERM + 20;
        case MT(MOD_LSFT, KC_END):
            return TAPPING_TERM -20;
        default:
            return TAPPING_TERM;
    }
}

extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
    [0] = { {0,209,255}, {17,231,255}, {216,209,255}, {0,209,255}, {57,207,200}, {132,209,255}, {34,209,255}, {34,209,255}, {34,209,255}, {180,209,255}, {161,209,255}, {18,209,255}, {102,255,255}, {27,255,255}, {69,209,255}, {34,209,255}, {236,150,255}, {57,207,200}, {180,209,255}, {43,255,255}, {146,209,255}, {69,209,255}, {18,209,255}, {146,209,255}, {18,209,255}, {161,209,255}, {236,150,255}, {57,207,200}, {201,209,255}, {18,209,255}, {57,207,200}, {132,209,255}, {69,209,255}, {18,209,255}, {34,209,255}, {69,209,255}, {18,209,255}, {34,209,255}, {146,209,255}, {57,207,200}, {57,207,200}, {180,209,255}, {57,207,200}, {0,209,255}, {34,209,255}, {180,209,255}, {201,209,255}, {161,209,255}, {109,209,255}, {34,209,255}, {0,209,255}, {201,209,255} },

    [1] = { {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255} },

    [2] = { {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {213,218,204}, {213,218,204}, {213,218,204}, {213,218,204}, {213,218,204}, {0,0,255}, {213,218,204}, {213,218,204}, {213,218,204}, {213,218,204}, {213,218,204}, {0,0,255}, {213,218,204}, {213,218,204}, {213,218,204}, {213,218,204}, {213,218,204}, {213,218,204}, {213,218,204}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {102,218,204}, {102,218,204}, {102,218,204}, {213,218,204}, {213,218,204}, {0,0,255}, {102,218,204}, {102,218,204}, {102,218,204}, {213,218,204}, {213,218,204}, {0,0,255}, {102,218,204}, {102,218,204}, {102,218,204}, {213,218,204}, {213,218,204}, {0,0,255}, {213,218,204}, {102,218,204} },

    [3] = { {236,150,255}, {236,150,255}, {236,150,255}, {236,150,255}, {236,150,255}, {236,150,255}, {236,150,255}, {236,150,255}, {236,150,255}, {236,150,255}, {236,150,255}, {236,150,255}, {236,150,255}, {236,150,255}, {236,150,255}, {236,150,255}, {236,150,255}, {236,150,255}, {236,150,255}, {236,150,255}, {236,150,255}, {236,150,255}, {236,150,255}, {236,150,255}, {236,150,255}, {236,150,255}, {236,150,255}, {236,150,255}, {236,150,255}, {236,150,255}, {236,150,255}, {236,150,255}, {236,150,255}, {236,150,255}, {236,150,255}, {236,150,255}, {236,150,255}, {236,150,255}, {236,150,255}, {236,150,255}, {236,150,255}, {236,150,255}, {236,150,255}, {236,150,255}, {236,150,255}, {236,150,255}, {236,150,255}, {236,150,255}, {236,150,255}, {236,150,255}, {236,150,255}, {236,150,255} },

};

void set_layer_color(int layer) {
  for (int i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
    HSV hsv = {
      .h = pgm_read_byte(&ledmap[layer][i][0]),
      .s = pgm_read_byte(&ledmap[layer][i][1]),
      .v = pgm_read_byte(&ledmap[layer][i][2]),
    };
    if (!hsv.h && !hsv.s && !hsv.v) {
        rgb_matrix_set_color( i, 0, 0, 0 );
    } else {
        RGB rgb = hsv_to_rgb( hsv );
        float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
        rgb_matrix_set_color( i, f * rgb.r, f * rgb.g, f * rgb.b );
    }
  }
}

bool rgb_matrix_indicators_user(void) {
  if (rawhid_state.rgb_control) {
      return false;
  }
  if (keyboard_config.disable_layer_led) { return false; }
  switch (biton32(layer_state)) {
    case 0:
      set_layer_color(0);
      break;
    case 1:
      set_layer_color(1);
      break;
    case 2:
      set_layer_color(2);
      break;
    case 3:
      set_layer_color(3);
      break;
   default:
    if (rgb_matrix_get_flags() == LED_FLAG_NONE)
      rgb_matrix_set_color_all(0, 0, 0);
    break;
  }
  return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {

    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
  }
  return true;
}



