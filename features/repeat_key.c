// Copyright 2024 Florent Linguenheld (@FLinguenheld)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "keycodes.h"

bool remember_last_key_user(uint16_t keycode, keyrecord_t* record, uint8_t* remembered_mods) {
    switch (keycode) {
        case ALT_T(QK_REP):
            return false;
    }
    return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
       case ALT_T(QK_REP):
           if (record->tap.count) {
               process_repeat_key(QK_REPEAT_KEY, record);
               return false;
           }
       break;
    }
    return true;
}
