// Copyright 2024 Florent Linguenheld (@FLinguenheld)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "keycodes.h"

typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
} td_state_t;

static td_state_t td_state;
td_state_t cur_dance(tap_dance_state_t *state);

// Declare tapdance functions
// `finished` and `reset` functions for each tapdance keycode
void lt_mouse_stab_finished(tap_dance_state_t *state, void *user_data);
void lt_mouse_stab_reset(tap_dance_state_t *state, void *user_data);


// Determine the tapdance state to return
td_state_t cur_dance(tap_dance_state_t *state) {
    if (state->interrupted || !state->pressed) return TD_SINGLE_TAP;
    else return TD_SINGLE_HOLD;
}

// -------->
// Handle the possible states for each tapdance keycode defined:
void lt_mouse_stab_finished(tap_dance_state_t *state, void *user_data) {
    td_state = cur_dance(state);
    switch (td_state) {
        case TD_SINGLE_TAP:
            register_code16(S(KC_TAB));
            break;
        case TD_SINGLE_HOLD:
            layer_on(_MOUSE);
            break;
        default:
            break;
    }
}

void lt_mouse_stab_reset(tap_dance_state_t *state, void *user_data) {
    switch (td_state) {
        case TD_SINGLE_TAP:
            unregister_code16(S(KC_TAB));
            break;
        case TD_SINGLE_HOLD:
            layer_off(_MOUSE);
            break;
        default:
            break;
    }
}
// <--------

// Define `ACTION_TAP_DANCE_FN_ADVANCED()` for each tapdance keycode, passing in `finished` and `reset` functionsI
tap_dance_action_t tap_dance_actions[] = {
    [LT_MOUSE_STAB] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, lt_mouse_stab_finished, lt_mouse_stab_reset)
};
