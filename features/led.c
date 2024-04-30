// Copyright 2024 Florent Linguenheld (@FLinguenheld)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

int nb = 0;

void keyboard_post_init_user(void) {
    rgblight_sethsv(HSV_GREEN);
}

void housekeeping_task_user(void) {

    if (nb < 15000) {
        nb++;
    } else {

        bool active = false;

        if (leader_sequence_active()) {
            rgblight_sethsv(HSV_BLUE);
            active = true;
        }

        if (is_caps_word_on()) {
            rgblight_sethsv(HSV_MAGENTA);
            active = true;
        }

        switch (get_highest_layer(layer_state)) {
            case _ADJ:;
                rgblight_sethsv(HSV_SPRINGGREEN);
                active = true;
            break;

            case _FN:;
                rgblight_sethsv(HSV_RED);
                active = true;
            break;
        }

        led_t led_state = host_keyboard_led_state();
        if (led_state.caps_lock) {
            rgblight_sethsv(HSV_AZURE);
            active = true;
        }

        if (!active)
            rgblight_sethsv(HSV_OFF);
    }
}
