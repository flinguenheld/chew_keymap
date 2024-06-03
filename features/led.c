// Copyright 2024 Florent Linguenheld (@FLinguenheld)
// SPDX-License-Identifier: GPL-2.0-or-later

#include <stdint.h>
#include QMK_KEYBOARD_H

int startup_led_cycles = 4;
int nb_qmk_cycles = 0;
char up_down = 0;
uint8_t h = 170;  // HSV value

void keyboard_post_init_user(void) {
    rgblight_sethsv(0, 255, 100);  // RED -> Error if still on
}

void housekeeping_task_user(void) {

    if (startup_led_cycles > 0)
    {
        nb_qmk_cycles++;
#ifdef SPLIT 
        if (nb_qmk_cycles % 5 == 0)
#else
        if (nb_qmk_cycles % 14 == 0)
#endif
        {
            if (up_down == 1 ) {
                h++;

                if (h >= 170)
                {
                    up_down = 0;
                    startup_led_cycles--;
                }
            }
            else {
                h--;

                if (h <= 50)
                    up_down = 1;
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
            rgblight_sethsv(HSV_TEAL);
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
            rgblight_sethsv(HSV_MAGENTA);
            active = true;
        }

        if (!active)
            rgblight_sethsv(HSV_OFF);
    }
}
