/* Copyright 2024 Florent Linguenheld (@FLinguenheld)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "keycodes.h"


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {

           case UNICODE:
      if (record->event.pressed) {

        register_code(KC_LEFT_SHIFT);
        register_code(KC_LEFT_CTRL);
        register_code(KC_U);

        unregister_code(KC_U);
        unregister_code(KC_LEFT_SHIFT);
        unregister_code(KC_LEFT_CTRL);
        
      } else {
          
      }     break;
    }
    return true;
}


// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_BASE] = LAYOUT(
    //|---------------+--------+--------+--------+--------|       |---------+--------+--------+--------+--------|
        GUI_T(KC_ESC) ,  KC_C  ,  KC_O  ,  KC_P  ,  KC_V  ,         QK_LEAD ,  KC_M  ,  KC_D  ,  KC_Y  ,  KC_W  ,
    //|---------------+--------+--------+--------+--------|       |---------+--------+--------+--------+--------|
            KC_A      ,  KC_S  ,  KC_E  ,  KC_N  ,  KC_F  ,           KC_L  ,  KC_R  ,  KC_T  ,  KC_I  ,  KC_U  ,
    //|---------------+--------+--------+--------+--------|       |---------+--------+--------+--------+--------|
            KC_Z      ,  KC_X  ,  KC_Q  ,  KC_B  ,                             KC_H  ,  KC_G  ,  KC_J  ,  KC_K  ,
    //|---------------+--------+--------+--------|                          |--------+--------+--------+--------|
    //             |------------+-----------------+---------|   |--------+--------------+-------------|
                     MO(_MOUSE) , CTL_T(KC_SPACE) , KC_LALT ,     KC_ENT , MO(_NUMERIC) , MO(_ARROWS)
    //             |------------+-----------------+---------|   |--------+--------------+-------------|
    ),

    [_NUMERIC] = LAYOUT(
    //|---------+---------+---------+---------+---------|       |---------+--------+--------+--------+---------|
        _______ , XXXXXXX ,  US_OE  , US_PND  , XXXXXXX ,         XXXXXXX ,  KC_4  ,  KC_5  ,  KC_6  ,  KC_7   ,
    //|---------+---------+---------+---------+---------|       |---------+--------+--------+--------+---------|
         US_AE  , XXXXXXX , US_EURO , XXXXXXX , XXXXXXX ,         XXXXXXX ,  KC_0  ,  KC_1  ,  KC_2  ,  KC_3   ,
    //|---------+---------+---------+---------+---------|       |---------+--------+--------+--------+---------|
        XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,                             KC_BSPC,  KC_8  ,  KC_9  , KC_DEL  ,
    //|---------+---------+---------+---------|                           |--------+--------+--------+---------|
    //                |------------+------------+---------|   |---------+---------+---------|
                        UC(0x30C4) , UC(0x00A0) , UNICODE ,     XXXXXXX , XXXXXXX , XXXXXXX
    //                |------------+------------+---------|   |---------+---------+---------|
    ),

    [_FN] = LAYOUT(
    //|---------+---------+---------+---------+---------|       |---------+--------+---------+---------+----------|
        _______ , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,         XXXXXXX ,  KC_F7 ,  KC_F8  ,  KC_F9  ,  KC_F10  ,
    //|---------+---------+---------+---------+---------|       |---------+--------+---------+---------+----------|
        XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,         XXXXXXX ,  KC_F4 ,  KC_F5  ,  KC_F6  ,  KC_F11  ,
    //|---------+---------+---------+---------+---------|       |---------+--------+---------+---------+----------|
        XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,                              KC_F1 ,  KC_F2  ,  KC_F3  ,  KC_F12  ,
    //|---------+---------+---------+---------|                           |--------+---------+---------+----------|
    //                      |---------+---------+---------|   |---------+---------+---------|
                              XXXXXXX , _______ , _______ ,     XXXXXXX , XXXXXXX , XXXXXXX
    //                      |---------+---------+---------|   |---------+---------+---------|
    ),

    [_ARROWS] = LAYOUT(
    //|---------+---------+---------+---------+---------|       |---------+---------+--------------+------------+----------|
        _______ , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,         XXXXXXX , KC_HOME , KC_PAGE_DOWN , KC_PAGE_UP ,  KC_END  ,
    //|---------+---------+---------+---------+---------|       |---------+---------+--------------+------------+----------|
        XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,         XXXXXXX , KC_LEFT ,   KC_DOWN    ,   KC_UP    , KC_RIGHT ,
    //|---------+---------+---------+---------+---------|       |---------+---------+--------------+------------+----------|
        XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,                             KC_BSPC ,    KC_TAB    , S(KC_TAB)  ,  KC_DEL  ,
    //|---------+---------+---------+---------|                           |---------+--------------+------------+----------|
    //                      |---------+---------+---------|   |---------+---------+---------|
                              XXXXXXX , _______ , _______ ,     XXXXXXX , XXXXXXX , XXXXXXX
    //                      |---------+---------+---------|   |---------+---------+---------|
    ),

    [_MOUSE] = LAYOUT(
    //|---------------+-------------+---------------+----------------+---------|       |---------+--------------+--------------+--------------+---------|
        KC_MS_WH_LEFT , KC_MS_WH_UP , KC_MS_WH_DOWN , KC_MS_WH_RIGHT , XXXXXXX ,         XXXXXXX ,   XXXXXXX    ,   XXXXXXX    ,   XXXXXXX    , XXXXXXX ,
    //|---------------+-------------+---------------+----------------+---------|       |---------+--------------+--------------+--------------+---------|
          KC_MS_LEFT  ,  KC_MS_UP   ,  KC_MS_DOWN   ,  KC_MS_RIGHT   , XXXXXXX ,         XXXXXXX , KC_MS_ACCEL0 , KC_MS_ACCEL1 , KC_MS_ACCEL2 , XXXXXXX ,
    //|---------------+-------------+---------------+----------------+---------|       |---------+--------------+--------------+--------------+---------|
           KC_BSPC    ,   KC_TAB    ,  S(KC_TAB)    ,     KC_DEL     ,                               XXXXXXX    ,   XXXXXXX    ,   XXXXXXX    , XXXXXXX ,
    //|---------------+-------------+---------------+----------------|                           |--------------+--------------+--------------+---------|
    //                                             |---------+---------+---------|   |------------+------------+------------|
                                                     XXXXXXX , _______ , _______ ,     KC_MS_BTN1 , KC_MS_BTN3 , KC_MS_BTN2
    //                                             |---------+---------+---------|   |------------+------------+------------|
    ),

    [_ADJ] = LAYOUT(
    //|---------+---------+---------+---------+------------------|       |---------+---------+---------+-----------------+---------|
        XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,  KC_PRINT_SCREEN ,         XXXXXXX , XXXXXXX , XXXXXXX , KC_AUDIO_VOL_UP , XXXXXXX ,
    //|---------+---------+---------+---------+------------------|       |---------+---------+---------+-----------------+---------|
        XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,S(KC_PRINT_SCREEN),         XXXXXXX , XXXXXXX , XXXXXXX ,KC_AUDIO_VOL_DOWN, XXXXXXX ,
    //|---------+---------+---------+---------+------------------|       |---------+---------+---------+-----------------+---------|
        XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,                                      XXXXXXX , XXXXXXX ,  KC_AUDIO_MUTE  , XXXXXXX ,
    //|---------+---------+---------+---------|                                    |---------+---------+-----------------+---------|
    //                               |---------+---------+---------|   |---------+---------+------------------|
                                       XXXXXXX , _______ , _______ ,     XXXXXXX , XXXXXXX , XXXXXXX
    //                               |---------+---------+---------|   |---------+---------+------------------|
    ),
};
