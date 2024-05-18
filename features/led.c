// Copyright 2024 Florent Linguenheld (@FLinguenheld)
// SPDX-License-Identifier: GPL-2.0-or-later

#include <stdint.h>
#include QMK_KEYBOARD_H

int cycles = 4;
int nb = 0;
char up = 0;
uint8_t h = 170;

void keyboard_post_init_user(void) {
    rgblight_sethsv(0, 255, 100);  // RED -> Error if still on
}

void housekeeping_task_user(void) {

    if (cycles > 0)
    {
        nb++;
        if (nb % 5 == 0)
        {
            if (up == 1 ) {
                h++;

                if (h >= 170)
                {
                    up = 0;
                    cycles--;
                }
            }
            else {
                h--;

                if (h <= 50)
                    up = 1;
            }
        }


        rgblight_sethsv(h, 255, 255);

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
                rgblight_sethsv(HSV_ORANGE);
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
