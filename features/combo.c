// Copyright 2024 Florent Linguenheld (@FLinguenheld)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "keycodes.h"

/* How to :
        - Add an entry in the enum
        - Create a new sequence of keys
        - Link the enum to this sequence in the key_combos table

   For macros :
        - Same steps
        - And add the macro in the process_combo_event() function
*/

enum combos {
  LEADER,
  BOOTLOADER,

  LAYER_ADJ,
  LAYER_FN,

  /* -- */
  CAP_WORD,
  CAP_LOCK,

  /* French */
  DEAD_GRAVE,
  DEAD_CIRCUMFLEX,
  DEAD_DIAERESIS,

  E_ACUTE,
  C_CEDILLA,
  OE,
  AE,

  QU,

  EURO,

  FRENCH_QUOTE_LEFT,
  FRENCH_QUOTE_RIGHT,

  /* -- */
  AMPERSAND,
  AT_SIGN,
  BACKSLASH,
  BACKSLASH_2,
  CIRCUMFLEX,
  COLON,
  COMMA,
  DOLLAR,
  DOT,
  EQUAL,
  EXCLAMATION_MARK,
  GRAVE,
  HASH,
  MINUS,
  PERCENT,
  PIPE,
  PLUS,
  QUESTION_MARK,
  QUOTE,
  QUOTE_DOUBLE,
  SEMICOLON,
  SLASH,
  STAR,
  TILDE,
  UNDERSCORE,

  ANGLE_BRACKET_LEFT,
  ANGLE_BRACKET_RIGHT,
  ANGLE_BRACKET_LEFTRIGHT,

  BRACKET_LEFT,
  BRACKET_RIGHT,
  BRACKET_LEFTRIGHT,

  CURLY_BRACKET_LEFT,
  CURLY_BRACKET_RIGHT,
  CURLY_BRACKET_LEFTRIGHT,

  PARENTHESIS_LEFT,
  PARENTHESIS_RIGHT,
  PARENTHESIS_LEFTRIGHT,

  /* One hand special */
  SHIFT_LEFT,
  CTRL_SHIFT_LEFT,
  ALT_SHIFT_LEFT,
  BSP_LEFT,

  /* Just to replace the define in config.h */
  COMBO_LENGTH,
};
uint16_t COMBO_LEN = COMBO_LENGTH;

/* Sequences fo keys */
const uint16_t PROGMEM combo_leader[] = {MO(_NUMERIC), KC_L, COMBO_END};
const uint16_t PROGMEM combo_bootloader[] = {KC_BSPC, KC_L, KC_V, KC_F, COMBO_END};

const uint16_t PROGMEM combo_adj[] = {MO(_MOUSE), MO(_ARROWS), COMBO_END};
const uint16_t PROGMEM combo_fn[] = {MO(_NUMERIC), MO(_ARROWS), COMBO_END};

/* -- */
const uint16_t PROGMEM combo_cap_word[] = {MO(_NUMERIC), KC_U, COMBO_END};
const uint16_t PROGMEM combo_cap_lock[] = {MO(_ARROWS), KC_U, COMBO_END};

/* -- */
const uint16_t PROGMEM combo_dead_grave[] = {MO(_NUMERIC), KC_R, COMBO_END};
const uint16_t PROGMEM combo_dead_circumflex[] = {MO(_NUMERIC), KC_T, COMBO_END};
const uint16_t PROGMEM combo_dead_diaeresis[] = {MO(_NUMERIC), KC_I, COMBO_END};

const uint16_t PROGMEM combo_e_acute[] = {CTL_T(KC_SPACE), KC_E, COMBO_END};
const uint16_t PROGMEM combo_c_cedilla[] = {CTL_T(KC_SPACE), KC_C, COMBO_END};
const uint16_t PROGMEM combo_oe[] = {CTL_T(KC_SPACE), KC_O, COMBO_END};
const uint16_t PROGMEM combo_ae[] = {CTL_T(KC_SPACE), KC_A, COMBO_END};

const uint16_t PROGMEM combo_qu[] = {CTL_T(KC_SPACE), KC_Q, COMBO_END};

const uint16_t PROGMEM combo_euro[] = {KC_E, KC_P, COMBO_END};

const uint16_t PROGMEM combo_french_quote_left[] = {KC_A, KC_F, COMBO_END};
const uint16_t PROGMEM combo_french_quote_right[] = {KC_L, KC_U, COMBO_END};

/* -- */
const uint16_t PROGMEM combo_ampersand[] = {KC_O, KC_P, COMBO_END};
const uint16_t PROGMEM combo_at_sign[] = {KC_Q, KC_N, COMBO_END};
const uint16_t PROGMEM combo_backslash[] = {KC_M, KC_R, COMBO_END};
const uint16_t PROGMEM combo_backslash_2[] = {KC_C, KC_E, COMBO_END};
const uint16_t PROGMEM combo_circumflex[] = {KC_X, KC_Q, COMBO_END};
const uint16_t PROGMEM combo_colon[] = {KC_E, KC_N, COMBO_END};
const uint16_t PROGMEM combo_comma[] = {KC_T, KC_I, COMBO_END};
const uint16_t PROGMEM combo_dollar[] = {KC_Q, KC_B, COMBO_END};
const uint16_t PROGMEM combo_dot[] = {KC_R, KC_T, COMBO_END};
const uint16_t PROGMEM combo_equal[] = {KC_R, KC_J, COMBO_END};
const uint16_t PROGMEM combo_exclamation_mark[] = {KC_C, KC_O, COMBO_END};
const uint16_t PROGMEM combo_grave[] = {KC_R, KC_G, COMBO_END};
const uint16_t PROGMEM combo_hash[] = {KC_X, KC_N, COMBO_END};
const uint16_t PROGMEM combo_minus[] = {KC_R, KC_I, COMBO_END};
const uint16_t PROGMEM combo_percent[] = {KC_C, KC_N, COMBO_END};
const uint16_t PROGMEM combo_pipe[] = {KC_M, KC_D, COMBO_END};
const uint16_t PROGMEM combo_plus[] = {KC_R, KC_Y, COMBO_END};
const uint16_t PROGMEM combo_question_mark[] = {KC_G, KC_J, COMBO_END};
const uint16_t PROGMEM combo_quote[] = {KC_R, KC_U, COMBO_END};
const uint16_t PROGMEM combo_quote_double[] = {KC_A, KC_N, COMBO_END};
const uint16_t PROGMEM combo_semicolon[] = {KC_S, KC_E, COMBO_END};
const uint16_t PROGMEM combo_slash[] = {KC_T, KC_Y, COMBO_END};
const uint16_t PROGMEM combo_star[] = {KC_D, KC_Y, COMBO_END};
const uint16_t PROGMEM combo_tilde[] = {KC_S, KC_N, COMBO_END};
const uint16_t PROGMEM combo_underscore[] = {KC_H, KC_G, COMBO_END};

const uint16_t PROGMEM combo_angle_bracket_left[] = {KC_H, KC_T, COMBO_END};
const uint16_t PROGMEM combo_angle_bracket_right[] = {KC_T, KC_J, COMBO_END};
const uint16_t PROGMEM combo_angle_bracket_leftright[] = {KC_H, KC_J, COMBO_END};

const uint16_t PROGMEM combo_bracket_left[] = {KC_S, KC_O, COMBO_END};
const uint16_t PROGMEM combo_bracket_right[] = {KC_O, KC_N, COMBO_END};
const uint16_t PROGMEM combo_bracket_leftright[] = {KC_C, KC_P, COMBO_END};

const uint16_t PROGMEM combo_curly_bracket_left[] = {KC_X, KC_E, COMBO_END};
const uint16_t PROGMEM combo_curly_bracket_right[] = {KC_E, KC_B, COMBO_END};
const uint16_t PROGMEM combo_curly_bracket_leftright[] = {KC_X, KC_B, COMBO_END};

const uint16_t PROGMEM combo_parenthesis_left[] = {KC_R, KC_D, COMBO_END};
const uint16_t PROGMEM combo_parenthesis_right[] = {KC_D, KC_I, COMBO_END};
const uint16_t PROGMEM combo_parenthesis_leftright[] = {KC_M, KC_Y, COMBO_END};

/* One hand special */
const uint16_t PROGMEM combo_shift_left[] = {CTL_T(KC_SPACE), KC_LALT, COMBO_END};
const uint16_t PROGMEM combo_ctrl_shift_left[] = {CTL_T(KC_SPACE), GUI_T(KC_ESC), COMBO_END};
const uint16_t PROGMEM combo_alt_shift_left[] = {KC_LALT, GUI_T(KC_ESC), COMBO_END};
const uint16_t PROGMEM combo_bsp_left[] = {MO(_MOUSE), CTL_T(KC_SPACE), COMBO_END};

/* Sequences fo keys */
combo_t key_combos[] = {
    [LEADER] = COMBO(combo_leader, QK_LEAD),
    [BOOTLOADER] = COMBO(combo_bootloader, QK_BOOTLOADER),

    [LAYER_ADJ] = COMBO(combo_adj, OSL(_ADJ)),
    [LAYER_FN] = COMBO(combo_fn, OSL(_FN)),

    /* -- */
    [CAP_WORD] = COMBO(combo_cap_word, QK_CAPS_WORD_TOGGLE),
    [CAP_LOCK] = COMBO(combo_cap_lock, KC_CAPS_LOCK),

    /* French */
    [DEAD_GRAVE] = COMBO(combo_dead_grave, US_DGRV),
    [DEAD_CIRCUMFLEX] = COMBO(combo_dead_circumflex, US_DCIR),
    [DEAD_DIAERESIS] = COMBO(combo_dead_diaeresis, US_DIAE),

    [E_ACUTE] = COMBO(combo_e_acute, US_EACU),
    [C_CEDILLA] = COMBO(combo_c_cedilla, US_CCED),
    [OE] = COMBO(combo_oe, US_OE),
    [AE] = COMBO(combo_ae, US_AE),

    [QU] = COMBO(combo_qu, CS_QU),

    [EURO] COMBO(combo_euro, US_EURO),

    [FRENCH_QUOTE_LEFT] COMBO(combo_french_quote_left, US_LDAQ),
    [FRENCH_QUOTE_RIGHT] COMBO(combo_french_quote_right, US_RDAQ),

    /* -- */
    [AMPERSAND] = COMBO(combo_ampersand, KC_AMPERSAND),
    [AT_SIGN] = COMBO(combo_at_sign, KC_AT),
    [BACKSLASH] = COMBO(combo_backslash, KC_BACKSLASH),
    [BACKSLASH_2] = COMBO(combo_backslash_2, KC_BACKSLASH),
    [CIRCUMFLEX] = COMBO(combo_circumflex, KC_CIRCUMFLEX),
    [COLON] = COMBO(combo_colon, KC_COLON),
    [COMMA] = COMBO(combo_comma, KC_COMMA),
    [DOLLAR] = COMBO(combo_dollar, KC_DOLLAR),
    [DOT] = COMBO(combo_dot, KC_DOT),
    [EQUAL] = COMBO(combo_equal, KC_EQUAL),
    [EXCLAMATION_MARK] = COMBO(combo_exclamation_mark, KC_EXCLAIM),
    [GRAVE] = COMBO(combo_grave, KC_GRAVE),
    [HASH] = COMBO(combo_hash, KC_HASH),
    [MINUS] = COMBO(combo_minus, KC_MINUS),
    [PERCENT] = COMBO(combo_percent, KC_PERCENT),
    [PIPE] = COMBO(combo_pipe, KC_PIPE),
    [PLUS] = COMBO(combo_plus, KC_PLUS),
    [QUESTION_MARK] = COMBO(combo_question_mark, KC_QUESTION),
    [QUOTE] = COMBO(combo_quote, KC_QUOTE),
    [QUOTE_DOUBLE] = COMBO(combo_quote_double, KC_DOUBLE_QUOTE),
    [SEMICOLON] = COMBO(combo_semicolon, KC_SEMICOLON),
    [SLASH] = COMBO(combo_slash, KC_SLASH),
    [STAR] = COMBO(combo_star, KC_ASTERISK),
    [TILDE] = COMBO(combo_tilde, KC_TILDE),
    [UNDERSCORE] = COMBO(combo_underscore, KC_UNDERSCORE),

    [ANGLE_BRACKET_LEFT] = COMBO(combo_angle_bracket_left, KC_LEFT_ANGLE_BRACKET),
    [ANGLE_BRACKET_RIGHT] = COMBO(combo_angle_bracket_right, KC_RIGHT_ANGLE_BRACKET),
    [ANGLE_BRACKET_LEFTRIGHT] = COMBO_ACTION(combo_angle_bracket_leftright),

    [BRACKET_LEFT] = COMBO(combo_bracket_left, KC_LEFT_BRACKET),
    [BRACKET_RIGHT] = COMBO(combo_bracket_right, KC_RIGHT_BRACKET),
    [BRACKET_LEFTRIGHT] = COMBO_ACTION(combo_bracket_leftright),

    [CURLY_BRACKET_LEFT] = COMBO(combo_curly_bracket_left, KC_LEFT_CURLY_BRACE),
    [CURLY_BRACKET_RIGHT] = COMBO(combo_curly_bracket_right, KC_RIGHT_CURLY_BRACE),
    [CURLY_BRACKET_LEFTRIGHT] = COMBO_ACTION(combo_curly_bracket_leftright),

    [PARENTHESIS_LEFT] = COMBO(combo_parenthesis_left, KC_LEFT_PAREN),
    [PARENTHESIS_RIGHT] COMBO(combo_parenthesis_right, KC_RIGHT_PAREN),
    [PARENTHESIS_LEFTRIGHT] COMBO_ACTION(combo_parenthesis_leftright),

    /* One hand special */
    [SHIFT_LEFT] = COMBO(combo_shift_left, KC_LEFT_SHIFT),
    [CTRL_SHIFT_LEFT] = COMBO(combo_ctrl_shift_left, C(S(XXXXXXX))),
    [ALT_SHIFT_LEFT] = COMBO(combo_alt_shift_left, A(S(XXXXXXX))),
    [BSP_LEFT] = COMBO(combo_bsp_left, KC_BSPC),
};

/* Parenthesis left/right */
void process_combo_event(uint16_t combo_index, bool pressed) {
  switch (combo_index) {
  case ANGLE_BRACKET_LEFTRIGHT:
    if (pressed) {
      tap_code16(KC_LEFT_ANGLE_BRACKET);
      tap_code16(KC_RIGHT_ANGLE_BRACKET);
    }
    break;
  case BRACKET_LEFTRIGHT:
    if (pressed) {
      tap_code16(KC_LEFT_BRACKET);
      tap_code16(KC_RIGHT_BRACKET);
    }
    break;
  case CURLY_BRACKET_LEFTRIGHT:
    if (pressed) {
      tap_code16(KC_LEFT_CURLY_BRACE);
      tap_code16(KC_RIGHT_CURLY_BRACE);
    }
    break;
  case PARENTHESIS_LEFTRIGHT:
    if (pressed) {
      tap_code16(KC_LEFT_PAREN);
      tap_code16(KC_RIGHT_PAREN);
    }
    break;
  }
}
