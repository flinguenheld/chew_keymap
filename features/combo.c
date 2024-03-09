// Copyright 2023 Florent Linguenheld (@FLinguenheld)
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
  LAYER_LEFT_HAND,

  /* -- */
  CAP_WORD,
  CAP_LOCK,

  /* French */
  A_GRAVE,
  E_GRAVE,
  U_GRAVE,
  C_CEDILLA,
  // FR_GRAVE,
  // FR_DIAERESIS,
  // FR_CIRCUMFLEX,

  /* -- */
  AMPERSAND,
  AT_SIGN,
  BACKSLASH,
  BACKSLASH_2,
  CIRCUMFLEX,
  COLON,
  DOLLAR,
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
  SLASH_2,
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

  /* Non qwerty */
  EURO,

  /* One hand special */
  CONTROL_RIGHT,
  CONTROL_SHIFT_RIGHT,

  ALT_LEFT,
  SHIFT_LEFT,
  CONTROL_SHIFT_LEFT,

  /* Just to replace the define in config.h */
  COMBO_LENGTH,
};
uint16_t COMBO_LEN = COMBO_LENGTH;

/* Sequences fo keys */
const uint16_t PROGMEM combo_leader[] = {LT(_MOUSE, KC_COMM), LT(_ARROWS, KC_DOT), COMBO_END};
const uint16_t PROGMEM combo_bootloader[] = {KC_K, KC_TAB, KC_Z, KC_BSPC, KC_V, KC_J, COMBO_END};

const uint16_t PROGMEM combo_adj[] = {CTL_T(KC_SPACE), LT(_NUMERIC, KC_ENT), COMBO_END};
const uint16_t PROGMEM combo_fn[] = {LT(_NUMERIC, KC_ENT), KC_N, COMBO_END};
const uint16_t PROGMEM combo_left_hand[] = {LT(_MOUSE, KC_COMM), GUI_T(KC_ESC), COMBO_END};

/* -- */
const uint16_t PROGMEM combo_cap_word[] = {LT(_NUMERIC, KC_ENT), KC_T, COMBO_END};
const uint16_t PROGMEM combo_cap_lock[] = {LT(_NUMERIC, KC_ENT), KC_C, COMBO_END};

/* -- */
const uint16_t PROGMEM combo_a_grave[] = {LT(_MOUSE, KC_COMM), KC_A, COMBO_END};
const uint16_t PROGMEM combo_e_grave[] = {LT(_MOUSE, KC_COMM), KC_E, COMBO_END};
const uint16_t PROGMEM combo_u_grave[] = {LT(_MOUSE, KC_COMM), KC_U, COMBO_END};
const uint16_t PROGMEM combo_c_cedilla[] = {LT(_ARROWS, KC_DOT), KC_C, COMBO_END};
// const uint16_t PROGMEM combo_fr_grave[] = {LT(_ARROWS, KC_DOT),  KC_G, COMBO_END};
// const uint16_t PROGMEM combo_fr_circumflex[] = {LT(_ARROWS, KC_DOT),  KC_F, COMBO_END};
// const uint16_t PROGMEM combo_fr_diaeresis[] = {LT(_ARROWS, KC_DOT),  KC_T, COMBO_END};

/* -- */
const uint16_t PROGMEM combo_ampersand[] = {KC_E, KC_U, COMBO_END};
const uint16_t PROGMEM combo_at_sign[] = {KC_D, KC_L, COMBO_END};
const uint16_t PROGMEM combo_backslash[] = {KC_P, KC_S, COMBO_END};
const uint16_t PROGMEM combo_backslash_2[] = {KC_B, KC_E, COMBO_END};
const uint16_t PROGMEM combo_circumflex[] = {KC_B, KC_O, COMBO_END};
const uint16_t PROGMEM combo_colon[] = {KC_C, KC_G, COMBO_END};
const uint16_t PROGMEM combo_dollar[] = {KC_O, KC_W, COMBO_END};
const uint16_t PROGMEM combo_equal[] = {KC_T, KC_H, COMBO_END};
const uint16_t PROGMEM combo_exclamation_mark[] = {KC_Q, KC_Y, COMBO_END};
const uint16_t PROGMEM combo_grave[] = {KC_T, KC_G, COMBO_END};
const uint16_t PROGMEM combo_hash[] = {KC_X, KC_U, COMBO_END};
const uint16_t PROGMEM combo_minus[] = {KC_T, KC_R, COMBO_END};
const uint16_t PROGMEM combo_percent[] = {KC_B, KC_U, COMBO_END};
const uint16_t PROGMEM combo_pipe[] = {KC_I, KC_E, COMBO_END};
const uint16_t PROGMEM combo_plus[] = {KC_T, KC_L, COMBO_END};
const uint16_t PROGMEM combo_question_mark[] = {KC_P, KC_D, COMBO_END};
const uint16_t PROGMEM combo_quote[] = {KC_T, KC_N, COMBO_END};
const uint16_t PROGMEM combo_quote_double[] = {KC_A, KC_U, COMBO_END};
const uint16_t PROGMEM combo_semicolon[] = {KC_G, KC_H, COMBO_END};
const uint16_t PROGMEM combo_slash[] = {KC_S, KC_L, COMBO_END};
const uint16_t PROGMEM combo_slash_2[] = {KC_E, KC_W, COMBO_END};
const uint16_t PROGMEM combo_star[] = {KC_S, KC_T, COMBO_END};
const uint16_t PROGMEM combo_tilde[] = {KC_I, KC_U, COMBO_END};
const uint16_t PROGMEM combo_underscore[] = {KC_S, KC_R, COMBO_END};

const uint16_t PROGMEM combo_angle_bracket_left[] = {KC_C, KC_S, COMBO_END};
const uint16_t PROGMEM combo_angle_bracket_right[] = {KC_S, KC_H, COMBO_END};
const uint16_t PROGMEM combo_angle_bracket_leftright[] = {KC_C, KC_H, COMBO_END};

const uint16_t PROGMEM combo_bracket_left[] = {KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM combo_bracket_right[] = {KC_O, KC_U, COMBO_END};
const uint16_t PROGMEM combo_bracket_leftright[] = {KC_B, KC_W, COMBO_END};

const uint16_t PROGMEM combo_curly_bracket_left[] = {KC_X, KC_E, COMBO_END};
const uint16_t PROGMEM combo_curly_bracket_right[] = {KC_E, KC_Y, COMBO_END};
const uint16_t PROGMEM combo_curly_bracket_leftright[] = {KC_X, KC_Y, COMBO_END};

const uint16_t PROGMEM combo_parenthesis_left[] = {KC_T, KC_D, COMBO_END};
const uint16_t PROGMEM combo_parenthesis_right[] = {KC_D, KC_R, COMBO_END};
const uint16_t PROGMEM combo_parenthesis_leftright[] = {KC_P, KC_L, COMBO_END};

/* Non qwerty */
const uint16_t PROGMEM combo_euro[] = {KC_X, KC_Q, COMBO_END};

/* One hand special */
const uint16_t PROGMEM combo_control_right[] = {LT(_NUMERIC, KC_ENT), KC_R, COMBO_END};
const uint16_t PROGMEM combo_control_shift_right[] = {LT(_NUMERIC, KC_ENT), KC_S, COMBO_END};

const uint16_t PROGMEM combo_alt_left[] = {CTL_T(KC_SPACE), KC_A, COMBO_END};
const uint16_t PROGMEM combo_shift_left[] = {CTL_T(KC_SPACE), US_EACU, COMBO_END};
const uint16_t PROGMEM combo_control_shift_left[] = {CTL_T(KC_SPACE), GUI_T(KC_ESC), COMBO_END};

/* Sequences fo keys */
combo_t key_combos[] = {
    [LEADER] = COMBO(combo_leader, QK_LEAD),
    [BOOTLOADER] = COMBO(combo_bootloader, QK_BOOTLOADER),

    [LAYER_ADJ] = COMBO(combo_adj, OSL(_ADJ)),
    [LAYER_FN] = COMBO(combo_fn, OSL(_FN)),
    [LAYER_LEFT_HAND] = COMBO(combo_left_hand, OSL(_LEFT_HAND)),

    /* -- */
    [CAP_WORD] = COMBO(combo_cap_word, QK_CAPS_WORD_TOGGLE),
    [CAP_LOCK] = COMBO(combo_cap_lock, KC_CAPS_LOCK),

    /* French */
    [A_GRAVE] = COMBO(combo_a_grave, CS_A_GRAVE),
    [E_GRAVE] = COMBO(combo_e_grave, CS_E_GRAVE),
    [U_GRAVE] = COMBO(combo_u_grave, CS_U_GRAVE),
    [C_CEDILLA] = COMBO(combo_c_cedilla, US_CCED),
    // [FR_GRAVE] = COMBO(combo_fr_grave, US_DGRV),
    // [FR_DIAERESIS] = COMBO(combo_fr_diaeresis, US_DIAE),
    // [FR_CIRCUMFLEX] = COMBO(combo_fr_circumflex, US_DCIR),

    /* -- */
    [AMPERSAND] = COMBO(combo_ampersand, KC_AMPERSAND),
    [AT_SIGN] = COMBO(combo_at_sign, KC_AT),
    [BACKSLASH] = COMBO(combo_backslash, KC_BACKSLASH),
    [BACKSLASH_2] = COMBO(combo_backslash_2, KC_BACKSLASH),
    [CIRCUMFLEX] = COMBO(combo_circumflex, KC_CIRCUMFLEX),
    [COLON] = COMBO(combo_colon, KC_COLON),
    [DOLLAR] = COMBO(combo_dollar, KC_DOLLAR),
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
    [SLASH_2] = COMBO(combo_slash_2, KC_SLASH),
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

    /* Non qwerty */
    [EURO] COMBO(combo_euro, US_EURO),

    /* One hand special */
    [CONTROL_RIGHT] = COMBO(combo_control_right, KC_RCTL),
    [CONTROL_SHIFT_RIGHT] = COMBO(combo_control_shift_right, C(S(XXXXXXX))),

    [ALT_LEFT] = COMBO(combo_alt_left, KC_LEFT_ALT),
    [SHIFT_LEFT] = COMBO(combo_shift_left, KC_LEFT_SHIFT),
    [CONTROL_SHIFT_LEFT] = COMBO(combo_control_shift_left, C(S(XXXXXXX))),
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
