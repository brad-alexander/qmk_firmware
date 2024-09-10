/* Copyright 2023 @ Keychron (https://www.keychron.com)
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
#include "keychron_common.h"
#include "keychron_ft_common.h"

enum layers{
    MAC_BASE,
    MAC_FN,
    WIN_BASE,
    WIN_FN,
};

enum {
    TD_ESC_CAPS,
    TD_RELOAD,
};

// uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
//     switch (keycode) {
//         case KC_ESC:
//             return 150;
//         case KC_R:
//             return 650;
//         default:
//             return TAPPING_TERM;
//     }
// }

// void dance_reload_each(tap_dance_state_t *state, void *user_data) {
//     switch (state->count) {
//         case 1:
//             register_code(KC_R);
//             break;
//     }
// }

// void dance_reload_reset(tap_dance_state_t *state, void *user_data) {
//     unregister_code(KC_R);
// }

// void dance_reload_finished(tap_dance_state_t *state, void *user_data) {
//     if (state->count > 1) {
//         register_code(KC_R);
//     }
// }

// void dance_reload_release(tap_dance_state_t *state, void *user_data) {
//     unregister_code(KC_R);
// }

// tap_dance_action_t tap_dance_actions[] = {
//     // Tap once for Escape, twice for Caps Lock
//     [TD_ESC_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_ESC, KC_CAPS),
//     [TD_RELOAD] = ACTION_TAP_DANCE_FN_ADVANCED_WITH_RELEASE(dance_reload_each, dance_reload_release, dance_reload_finished, dance_reload_reset),
// };

// const uint16_t PROGMEM shift_space[] = {KC_LEFT_SHIFT, KC_SPACE, COMBO_END};

// const key_override_t shift_space_override = ko_make_basic(MOD_MASK_SHIFT, KC_SPACE, SHIFTSPACE);
// const key_override_t *key_overrides[] = {
// 	&shift_space_override
// };

// const key_override_t shiftspace_override = ko_make_basic(MOD_MASK_SHIFT, KC_SPACE, SHIFTSPACE);

// const key_override_t **key_overrides = (const key_override_t *[]){
// 	&shiftspace_override,
// 	NULL // Null terminate the array of overrides!
// };


// combo_t key_combos[] = {
//     COMBO(shift_space, SHIFTSPACE),
// };

#define KEYMAP_R KC_R

// TD(TD_ESC_CAPS)
#define KEYMAP_ESC KC_ESC


// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [MAC_BASE] = LAYOUT_tkl_ansi(
        KEYMAP_ESC,KC_BRID, KC_BRIU,  KC_MICT,  KC_LAPA,  BL_DOWN,  BL_UP,    KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,    KC_SNAP,  KC_TRNS,  KC_PAUS,
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,     KC_BSPC,  KC_INS,   KC_HOME,  KC_PGUP,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KEYMAP_R, KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,    KC_BSLS,  KC_DEL,   KC_END,   KC_PGDN,
        KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,              KC_ENT,
        KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,              KC_RSFT,            KC_UP,
        KC_LCTL,  KC_LOPTN, KC_LCMMD,                               KC_SPC,                                 KC_RCMMD, MO(MAC_FN),KC_TRNS,   KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT),

    [MAC_FN] = LAYOUT_tkl_ansi(
        QK_BOOT,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,     KC_F12,   _______,  DB_TOGG,  BL_STEP,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,  _______,  _______,
        BL_TOGG,  BL_STEP,  BL_UP,    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,  _______,  _______,
        KC_OSSW,  _______,  BL_DOWN,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,              _______,
        _______,            _______,  _______,  _______,  _______,  _______,  NK_TOGG,  _______,  _______,  _______,  _______,              _______,            _______,
        _______,  _______,  _______,                                _______,                                _______,  _______,  _______,    _______,  _______,  _______,  _______),

    [WIN_BASE] = LAYOUT_tkl_ansi(
        KEYMAP_ESC,KC_F1,   KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,     KC_F12,   KC_PSCR,  KC_SCRL,  KC_PAUS,
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,     KC_BSPC,  KC_INS,   KC_HOME,  KC_PGUP,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KEYMAP_R, KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,    KC_BSLS,  KC_DEL,   KC_END,   KC_PGDN,
        KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,              KC_ENT,
        KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,              KC_RSFT,            KC_UP,
        KC_LCTL,  KC_LWIN,  KC_LALT,                                KC_SPC,                                 KC_RALT,  MO(WIN_FN), KC_APP,   KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT),

    [WIN_FN] = LAYOUT_tkl_ansi(
        QK_BOOT,  KC_BRID,  KC_BRIU,  KC_TASK,  KC_FLXP,  BL_DOWN,  BL_UP,    KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,    KC_VOLU,  _______,  DB_TOGG,  BL_STEP,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,  _______,  _______,
        BL_TOGG,  BL_STEP,  BL_UP,    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,  _______,  _______,
        KC_OSSW,  _______,  BL_DOWN,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,              _______,
        _______,            _______,  _______,  _______,  _______,  _______,  NK_TOGG,  _______,  _______,  _______,  _______,              _______,            _______,
        _______,  _______,  _______,                                _______,                                _______,  _______,  _______,    _______,  _______,  _______,  _______),
};

uint32_t reload_timer = 0;
uint8_t reload_state = 0;
bool should_reload = false;

bool between(uint32_t x, uint32_t a, uint32_t b) {
    return x >= a && x <= b;
}

void housekeeping_task_reload(void) {
    if (reload_timer == 0) {
        return;
    }
    int elapsed = timer_elapsed32(reload_timer);
    if ( elapsed > 1 && reload_state == 0) {
        register_code(KC_R);
        reload_state = 1;
    } else if (elapsed > 50 && reload_state == 1) {
        unregister_code(KC_R);
        reload_state = 2;
    } else if (elapsed > 825 && reload_state == 2 && should_reload) {
        register_code(KC_R);
        reload_state = 3;
    } else if (elapsed > 850 && reload_state == 3 && should_reload) {
        unregister_code(KC_R);
        reload_state = 0;
        reload_timer = 0;
        should_reload = false;
    } else if (elapsed > 900) {
        reload_state = 0;
        reload_timer = 0;
        should_reload = false;
    }
}

void housekeeping_task_user(void) {
    housekeeping_task_keychron();
    housekeeping_task_keychron_ft();
    housekeeping_task_reload();
}

bool a_pressed = false;
bool d_pressed = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    // case KC_UP_ARROW:
    //     if (!record->event.pressed) {
    //         unregister_code(KC_UP);
    //         unregister_code(KC_AUDIO_VOL_UP);
    //         return false;
    //     } else if (get_mods() & MOD_BIT(KC_RIGHT_CTRL)) {
    //         register_code(KC_AUDIO_VOL_UP);
    //         return false;
    //     }
    case KC_SPACE:
        if (get_mods() & MOD_BIT(KC_LEFT_SHIFT)) {
            if (record->event.pressed) {
                SEND_STRING(SS_DELAY(350) " ");
            }
            return false;
        }
        break;
    case KC_A:
        if (record->event.pressed) {
            a_pressed = true;
            if (d_pressed) {
                unregister_code(KC_D);
            }
        } else {
            if (d_pressed) {
                register_code(KC_D);
            }
            a_pressed = false;
        }
        break;
    case KC_R:
        if (!record->event.pressed) {
            return false;
        }
        if (reload_timer == 0) {
            reload_timer = timer_read32();
        } else {
            should_reload = true;
        }
        return false;
    case KC_D:
        if (record->event.pressed) {
            d_pressed = true;
            if (a_pressed) {
                unregister_code(KC_A);
            }
        } else {
            if (a_pressed) {
                register_code(KC_A);
            }
            d_pressed = false;
        }
        break;
    }
    if (!process_record_keychron(keycode, record)) {
        return false;
    }
    if (!process_record_keychron_ft(keycode, record)) {
        return false;
    }
    return true;
}

// void process_combo_event(uint16_t combo_index, bool pressed) {
//   switch(combo_index) {
//     case LEFT_RIGHT_COMBO:
//       if (pressed) {
//         unregister_code(KC_A);
//         register_code(KC_D);
//         register_code(KC_W);
//       }
//       break;
//     case RIGHT_LEFT_COMBO:
//       if (pressed) {
//         unregister_code(KC_D);
//         register_code(KC_A);
//         register_code(KC_S);
//       }
//       break;
//   }
// }
