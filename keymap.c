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


// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_BASE] = LAYOUT_split_5_5_4_3(
    //|---------------+--------+--------+--------+-----------|       |--------+--------+--------+--------+--------|
        GUI_T(KC_ESC) ,  KC_B  ,  KC_O  ,  KC_W  ,  KC_BSPC  ,          KC_J  ,  KC_P  ,  KC_D  ,  KC_L  ,  KC_F  ,
    //|---------------+--------+--------+--------+-----------|       |--------+--------+--------+--------+--------|
            KC_A      ,  KC_I  ,  KC_E  ,  KC_U  ,   KC_Z    ,          KC_V  ,  KC_T  ,  KC_S  ,  KC_R  ,  KC_N  ,
    //|---------------+--------+--------+--------+-----------|       |--------+--------+--------+--------+--------|
            KC_K      ,  KC_X  ,  KC_Q  ,  KC_Y  ,                               KC_C  ,  KC_G  ,  KC_H  ,  KC_M  ,
    //|---------------+--------+--------+--------|                            |--------+--------+--------+--------|
    //          |------------+-----------------+---------------|   |--------+----------------------+----------------------!
                  MO(_MOUSE) , CTL_T(KC_SPACE) , ALT_T(QK_REP) ,     KC_ENT , LT(_NUMERIC, KC_DOT) , LT(_ARROWS, KC_COMM)
    //          |------------+-----------------+---------------|   |--------+----------------------+----------------------!
    ),

    [_NUMERIC] = LAYOUT_split_5_5_4_3(
    //|---------+---------+---------+---------+---------|       |---------+--------+--------+--------+---------|
        _______ , XXXXXXX , XXXXXXX , XXXXXXX , _______ ,         XXXXXXX ,  KC_7  ,  KC_8  ,  KC_9  , KC_DOT  ,
    //|---------+---------+---------+---------+---------|       |---------+--------+--------+--------+---------|
        XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,         XXXXXXX ,  KC_4  ,  KC_5  ,  KC_6  ,  KC_0   ,
    //|---------+---------+---------+---------+---------|       |---------+--------+--------+--------+---------|
        XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,                              KC_1  ,  KC_2  ,  KC_3  , KC_COMM ,
    //|---------+---------+---------+---------|                           |--------+--------+--------+---------|
    //                      |---------+---------+---------|   |---------+---------+---------!
                              XXXXXXX , XXXXXXX , UNICODE ,     XXXXXXX , XXXXXXX , XXXXXXX
    //                      |---------+---------+---------|   |---------+---------+---------!
    ),

    [_FN] = LAYOUT_split_5_5_4_3(
    //|---------+---------+---------+---------+---------|       |---------+--------+---------+---------+----------|
        _______ , XXXXXXX , XXXXXXX , XXXXXXX , _______ ,         XXXXXXX ,  KC_F7 ,  KC_F8  ,  KC_F9  ,  KC_F10  ,
    //|---------+---------+---------+---------+---------|       |---------+--------+---------+---------+----------|
        XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,         XXXXXXX ,  KC_F4 ,  KC_F5  ,  KC_F6  ,  KC_F11  ,
    //|---------+---------+---------+---------+---------|       |---------+--------+---------+---------+----------|
        XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,                              KC_F1 ,  KC_F2  ,  KC_F3  ,  KC_F12  ,
    //|---------+---------+---------+---------|                           |--------+---------+---------+----------|
    //                      |---------+---------+---------|   |---------+---------+---------!
                              XXXXXXX , _______ , _______ ,     XXXXXXX , XXXXXXX , XXXXXXX
    //                      |---------+---------+---------|   |---------+---------+---------!
    ),

    [_ARROWS] = LAYOUT_split_5_5_4_3(
    //|---------+---------+---------+---------+---------|       |---------+---------+--------------+------------+----------|
        _______ , XXXXXXX , XXXXXXX , XXXXXXX , _______ ,         XXXXXXX , KC_HOME , KC_PAGE_DOWN , KC_PAGE_UP ,  KC_END  ,
    //|---------+---------+---------+---------+---------|       |---------+---------+--------------+------------+----------|
        XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,         XXXXXXX , KC_LEFT ,   KC_DOWN    ,   KC_UP    , KC_RIGHT ,
    //|---------+---------+---------+---------+---------|       |---------+---------+--------------+------------+----------|
        XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,                             XXXXXXX ,   C(KC_D)    ,  C(KC_U)   , XXXXXXX  ,
    //|---------+---------+---------+---------|                           |---------+--------------+------------+----------|
    //                      |---------+---------+---------|   |---------+---------+---------!
                              XXXXXXX , _______ , _______ ,     XXXXXXX , XXXXXXX , XXXXXXX
    //                      |---------+---------+---------|   |---------+---------+---------!
    ),

    [_MOUSE] = LAYOUT_split_5_5_4_3(
    //|---------------+-------------+---------------+----------------+---------|       |---------+--------------+--------------+--------------+---------|
        KC_MS_WH_LEFT , KC_MS_WH_UP , KC_MS_WH_DOWN , KC_MS_WH_RIGHT , _______ ,         XXXXXXX ,   XXXXXXX    ,   XXXXXXX    ,   XXXXXXX    , XXXXXXX ,
    //|---------------+-------------+---------------+----------------+---------|       |---------+--------------+--------------+--------------+---------|
          KC_MS_LEFT  ,  KC_MS_UP   ,  KC_MS_DOWN   ,  KC_MS_RIGHT   , XXXXXXX ,         XXXXXXX , KC_MS_ACCEL0 , KC_MS_ACCEL1 , KC_MS_ACCEL2 , XXXXXXX ,
    //|---------------+-------------+---------------+----------------+---------|       |---------+--------------+--------------+--------------+---------|
          KC_MS_BTN1  ,   XXXXXXX   ,  KC_MS_BTN3   ,  KC_MS_BTN2    ,                               XXXXXXX    ,   XXXXXXX    ,   XXXXXXX    , XXXXXXX ,
    //|---------------+-------------+---------------+----------------|                           |--------------+--------------+--------------+---------|
    //                                             |---------+---------+---------|   |------------+------------+------------!
                                                     XXXXXXX , XXXXXXX , _______ ,     KC_MS_BTN1 , KC_MS_BTN2 , KC_MS_BTN3
    //                                             |---------+---------+---------|   |------------+------------+------------!
    ),

    [_ADJ] = LAYOUT_split_5_5_4_3(
    //|---------+---------+---------+---------+------------------|       |---------+---------+---------+-----------------+---------|
        XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,  KC_PRINT_SCREEN ,         XXXXXXX , XXXXXXX , XXXXXXX , KC_AUDIO_VOL_UP , XXXXXXX ,
    //|---------+---------+---------+---------+------------------|       |---------+---------+---------+-----------------+---------|
        XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,S(KC_PRINT_SCREEN),         XXXXXXX , XXXXXXX , XXXXXXX ,KC_AUDIO_VOL_DOWN, XXXXXXX ,
    //|---------+---------+---------+---------+------------------|       |---------+---------+---------+-----------------+---------|
        XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,                                      XXXXXXX , XXXXXXX ,  KC_AUDIO_MUTE  , XXXXXXX ,
    //|---------+---------+---------+---------|                                     |---------+---------+-----------------+---------|
    //                               |---------+---------+---------|   |---------+---------+------------------!
                                       XXXXXXX , _______ , _______ ,     XXXXXXX , XXXXXXX , XXXXXXX
    //                               |---------+---------+---------|   |---------+---------+------------------!
    ),

    [_LEFT_HAND] = LAYOUT_split_5_5_4_3(
    //|---------+---------+---------+---------+----------|       |---------+---------+---------+---------+---------|
        _______ , XXXXXXX , XXXXXXX , XXXXXXX , _______  ,         XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
    //|---------+---------+---------+---------+----------|       |---------+---------+---------+---------+---------|
        XXXXXXX , XXXXXXX , XXXXXXX , C(KC_Z) , KC_PASTE ,         XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
    //|---------+---------+---------+---------+----------|       |---------+---------+---------+---------+---------|
        XXXXXXX , KC_CUT  , XXXXXXX , KC_COPY ,                              XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
    //|---------+---------+---------+---------|                            |---------+---------+---------+---------|
    //                      |---------+---------+----------|   |---------+---------+---------!
                              XXXXXXX , XXXXXXX , KC_ENTER ,     XXXXXXX , XXXXXXX , XXXXXXX
    //                      |---------+---------+----------|   |---------+---------+---------!
    ),
};
