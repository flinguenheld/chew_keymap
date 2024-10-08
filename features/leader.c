// Copyright 2024 Florent Linguenheld (@FLinguenheld)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "keycodes.h"
#include <stdlib.h>

void leader_end_user(void) {
  if (leader_sequence_two_keys(KC_M, KC_S)) {
    SEND_STRING("f@linguenheld.fr");
  } else if (leader_sequence_two_keys(KC_M, KC_A)) {
    SEND_STRING("florent@linguenheld.fr");
  } else if (leader_sequence_two_keys(KC_F, KC_L)) {
    SEND_STRING("flinguenheld");

  } else if (leader_sequence_three_keys(KC_D, KC_O, KC_T)) {
    SEND_STRING("https://github.com/flinguenheld/dotfiles");
  } else if (leader_sequence_three_keys(KC_H, KC_U, KC_B)) {
    SEND_STRING("https://github.com/flinguenheld/");
  } else if (leader_sequence_three_keys(KC_Q, KC_M, KC_K)) {
    SEND_STRING("$HOME/qmk_firmware/keyboards/chew/split/keymaps/chew_keymap");
  } else if (leader_sequence_three_keys(KC_Q, KC_M, KC_C)) {
    SEND_STRING("qmk compile && qmk flash");

  } else if (leader_sequence_three_keys(KC_T, KC_E, KC_S)) {
    SEND_STRING("test01234");
  } else if (leader_sequence_three_keys(KC_A, KC_D, KC_M)) {
    SEND_STRING("admin01234");

  } else if (leader_sequence_three_keys(KC_L, KC_O, KC_C)) {
    SEND_STRING("https://localhost:");

  } else if (leader_sequence_two_keys(KC_U, KC_S)) {
    SEND_STRING("setxkbmap us altgr-intl");
  } else if (leader_sequence_one_key(KC_C)) {
    SEND_STRING(" | wl-copy --trim-newline");

    /* ----- */
  } else if (leader_sequence_three_keys(KC_D, KC_E, KC_G)) {
    tap_code16(US_DEG); // °
  } else if (leader_sequence_three_keys(KC_D, KC_I, KC_A)) {
    tap_code16(US_OSTR); // ø
  } else if (leader_sequence_three_keys(KC_S, KC_E, KC_C)) {
    tap_code16(US_SECT); // §

    /* Copyright / Register */
  } else if (leader_sequence_three_keys(KC_C, KC_O, KC_P)) {
    tap_code16(US_COPY); // ©
  } else if (leader_sequence_three_keys(KC_R, KC_E, KC_G)) {
    tap_code16(US_REGD); // ®

    /* Currency */
  } else if (leader_sequence_three_keys(KC_E, KC_U, KC_R)) {
    tap_code16(US_EURO); // €
  } else if (leader_sequence_three_keys(KC_P, KC_O, KC_U)) {
    tap_code16(US_PND); // £
  } else if (leader_sequence_three_keys(KC_Y, KC_E, KC_N)) {
    tap_code16(US_YEN); // ¥
  } else if (leader_sequence_three_keys(KC_C, KC_E, KC_N)) {
    tap_code16(US_CENT); // ¢

    /* Fractions */
  } else if (leader_sequence_three_keys(KC_F, KC_C, KC_T)) {
    tap_code16(US_QRTR); // ¼
  } else if (leader_sequence_three_keys(KC_F, KC_C, KC_G)) {
    tap_code16(US_HALF); // ½
  } else if (leader_sequence_three_keys(KC_F, KC_H, KC_T)) {
    tap_code16(US_TQTR); // ¾

    /* Maths */
  } else if (leader_sequence_three_keys(KC_M, KC_U, KC_L)) {
    tap_code16(US_MUL); // ×
  } else if (leader_sequence_three_keys(KC_D, KC_I, KC_V)) {
    tap_code16(US_DIV); // ÷
  } else if (leader_sequence_two_keys(KC_P, KC_M)) {
    send_unicode_string("±");
  } else if (leader_sequence_three_keys(KC_I, KC_N, KC_E)) {
    send_unicode_string("≠");
  } else if (leader_sequence_three_keys(KC_A, KC_L, KC_M)) {
    send_unicode_string("≈");
  } else if (leader_sequence_three_keys(KC_S, KC_Q, KC_U)) {
    send_unicode_string("√");
  } else if (leader_sequence_three_keys(KC_I, KC_N, KC_F)) {
    send_unicode_string("∞");
  } else if (leader_sequence_two_keys(KC_LABK, KC_LABK)) {
    send_unicode_string("≤");
  } else if (leader_sequence_two_keys(KC_RABK, KC_RABK)) {
    send_unicode_string("≥");

    /* Greek */
  } else if (leader_sequence_three_keys(KC_B, KC_E, KC_T)) {
    tap_code16(US_SS); // ß
  } else if (leader_sequence_three_keys(KC_M, KC_I, KC_C)) {
    tap_code16(US_MICR); // µ
  } else if (leader_sequence_two_keys(KC_P, KC_I)) {
    send_unicode_string("π");
  } else if (leader_sequence_three_keys(KC_O, KC_M, KC_E)) {
    send_unicode_string("Ω");

    /* Icons */
  } else if (leader_sequence_three_keys(KC_L, KC_O, KC_V)) {
    send_unicode_string("♥");
  } else if (leader_sequence_three_keys(KC_F, KC_L, KC_A)) {
    send_unicode_string("⚡");
  } else if (leader_sequence_three_keys(KC_S, KC_T, KC_A)) {
    send_unicode_string("✶");
  } else if (leader_sequence_three_keys(KC_B, KC_U, KC_L)) {
    send_unicode_string("💡");
  } else if (leader_sequence_three_keys(KC_I, KC_N, KC_F)) {
    send_unicode_string("ℹ️");
  } else if (leader_sequence_three_keys(KC_G, KC_E, KC_A)) {
    send_unicode_string("⚙️");

  } else if (leader_sequence_one_key(KC_V)) {
    send_unicode_string("✓");
  } else if (leader_sequence_two_keys(KC_V, KC_B)) {
    send_unicode_string("✔");
  } else if (leader_sequence_two_keys(KC_V, KC_V)) {
    send_unicode_string("✅");

  } else if (leader_sequence_one_key(KC_X)) {
    send_unicode_string("✗");
  } else if (leader_sequence_two_keys(KC_X, KC_B)) {
    send_unicode_string("✘");

  } else if (leader_sequence_one_key(KC_QUESTION)) {
    send_unicode_string("❔");
  } else if (leader_sequence_one_key(KC_EXCLAIM)) {
    send_unicode_string("❗");
  } else if (leader_sequence_two_keys(KC_QUESTION, KC_QUESTION)) {
    send_unicode_string("❓");
  } else if (leader_sequence_two_keys(KC_EXCLAIM, KC_EXCLAIM)) {
    send_unicode_string("❕");

    /* Subscript / superscript */
  } else if (leader_sequence_two_keys(KC_U, KC_U)) {
    send_unicode_string("⁰");
  } else if (leader_sequence_two_keys(KC_D, KC_U)) {
    send_unicode_string("₀");
  } else if (leader_sequence_two_keys(KC_U, KC_H)) {
    tap_code16(US_SUP1); // ¹
  } else if (leader_sequence_two_keys(KC_D, KC_H)) {
    send_unicode_string("₁");
  } else if (leader_sequence_two_keys(KC_U, KC_G)) {
    tap_code16(US_SUP2); // ²
  } else if (leader_sequence_two_keys(KC_D, KC_G)) {
    send_unicode_string("₂");
  } else if (leader_sequence_two_keys(KC_U, KC_J)) {
    tap_code16(US_SUP3); // ³
  } else if (leader_sequence_two_keys(KC_D, KC_J)) {
    send_unicode_string("₃");
  } else if (leader_sequence_two_keys(KC_U, KC_R)) {
    send_unicode_string("⁴");
  } else if (leader_sequence_two_keys(KC_D, KC_R)) {
    send_unicode_string("₄");
  } else if (leader_sequence_two_keys(KC_U, KC_T)) {
    send_unicode_string("⁵");
  } else if (leader_sequence_two_keys(KC_D, KC_T)) {
    send_unicode_string("₅");
  } else if (leader_sequence_two_keys(KC_U, KC_I)) {
    send_unicode_string("⁶");
  } else if (leader_sequence_two_keys(KC_D, KC_I)) {
    send_unicode_string("₆");
  } else if (leader_sequence_two_keys(KC_U, KC_M)) {
    send_unicode_string("⁷");
  } else if (leader_sequence_two_keys(KC_D, KC_M)) {
    send_unicode_string("₇");
  } else if (leader_sequence_two_keys(KC_U, KC_D)) {
    send_unicode_string("⁸");
  } else if (leader_sequence_two_keys(KC_D, KC_D)) {
    send_unicode_string("₈");
  } else if (leader_sequence_two_keys(KC_U, KC_Y)) {
    send_unicode_string("⁹");
  } else if (leader_sequence_two_keys(KC_D, KC_Y)) {
    send_unicode_string("₉");
  };
}
