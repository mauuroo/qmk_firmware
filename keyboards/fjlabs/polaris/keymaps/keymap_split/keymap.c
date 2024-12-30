/*
Copyright 2020 <me@fjlaboratories.com>
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.
This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.
You should have received a copy of the GNU General Public License
along with this program. If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

enum custom_keycodes {
    MACRO_DISCORD = SAFE_RANGE, // Macro para Discord
    MACRO_SPOTIFY,              // Macro para Spotify
    MACRO_ENV,                  //Macro para activar entorno virtual
    MACRO_MOVE_TO_MONITOR,       //Macro para mover ventana a otro monitor
    MACRO_FXSOUND,              //Macro para enfocar FXSound
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MACRO_DISCORD:
            if (record->event.pressed) {
                SEND_STRING(SS_DOWN(X_LALT) SS_TAP(X_SPACE) SS_UP(X_LALT) "discord" SS_DELAY(200) SS_TAP(X_ENTER));
            }
            break;
        case MACRO_SPOTIFY:
            if (record->event.pressed) {
                SEND_STRING(SS_DOWN(X_LALT) SS_TAP(X_SPACE) SS_UP(X_LALT) "spotify" SS_DELAY(200) SS_TAP(X_ENTER));
            }
            break;
        case MACRO_ENV:
            if (record->event.pressed) {
                SEND_STRING("env/scripts/activate" SS_DELAY(500) SS_TAP(X_ENTER));
            }
            break;
        case MACRO_MOVE_TO_MONITOR:
            if (record->event.pressed) {
                SEND_STRING(SS_DOWN(X_RGUI) SS_DOWN(X_LSFT) SS_TAP(X_RIGHT) SS_UP(X_RGUI) SS_UP(X_LSFT));
            }
            break;
        case MACRO_FXSOUND:
            if (record->event.pressed) {
                SEND_STRING(SS_DOWN(X_LALT) SS_TAP(X_SPACE) SS_UP(X_LALT) "FxSound" SS_DELAY(200) SS_TAP(X_ENTER));
            }
            break;
    }
    return true;
}

enum layers {
    _LAYER0,
    _LAYER1,
    _LAYER2,
    _LAYER3,
    _LAYER4
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_LAYER0] = LAYOUT_all( /* Base */
        KC_ESC,                 KC_1,    KC_2,    KC_3,            KC_4,              KC_5,            KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSLS, KC_DEL,
        KC_TAB,                 KC_Q,    KC_W,    KC_E,            KC_R,              KC_T,            KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSPC,
        LT(_LAYER2, KC_CAPS),   KC_A,    KC_S,    KC_D,            KC_F,              KC_G,            KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,
        KC_LSFT, KC_LSFT,       KC_Z,    KC_X,    KC_C,            KC_V,              KC_B,            KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT, KC_RGUI,
        KC_LCTL, _______,       KC_LALT,  LT(_LAYER1, KC_SPC),   LT(_LAYER1, KC_SPC), LT(_LAYER1, KC_SPC),      LT(_LAYER1, KC_SPC),                               KC_RALT, _______, _______
    ),
    [_LAYER1] = LAYOUT_all( /* Fn_space */
        KC_GRAVE,         KC_F1,  KC_F2,    KC_F3,           KC_F4,             KC_F5,          KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,   _______,  _______,
        _______,          _______, KC_UP,   _______,         _______,           _______,        _______, _______, KC_INS,  KC_DEL,  _______, _______, _______,  _______,
        _______,          KC_LEFT, KC_DOWN, KC_RIGHT,        KC_HOME,           _______,        _______, KC_END,  _______, _______, _______, _______,           _______,
        _______, _______, _______, _______, KC_VOLD,         KC_VOLU,           _______,        RALT(KC_N), _______, KC_MPRV, KC_MPLY, KC_MNXT,          _______,  _______,
        _______, _______, _______,          _______,         _______,           _______,        _______,                                     _______, _______,  _______
    ),
    [_LAYER2] = LAYOUT_all( /* Capslock Layer (for macros)*/
        C(KC_GRAVE),           _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        MACRO_MOVE_TO_MONITOR, MACRO_DISCORD, A(KC_F4), MACRO_ENV, _______, _______, _______, _______, _______, _______, KC_PSCR, _______, _______,          _______,
        _______,               _______, MACRO_SPOTIFY, _______, MACRO_FXSOUND, _______, _______, _______, _______, _______, _______, _______,                   _______,
        _______,               _______, _______, KC_CALC, _______, _______, _______, _______, _______, _______, _______, _______,          _______, QK_BOOT,
        _______,               _______, _______,          _______,          _______,          _______, _______,                            _______, _______, TG(_LAYER3)
  ),
    [_LAYER3] = LAYOUT_all( /* Layer without LT space for specific things*/
        KC_ESC,                 KC_1,    KC_2,    KC_3,            KC_4,             KC_5,            KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSLS, KC_DEL,
        KC_TAB,                 KC_Q,    KC_W,    KC_E,            KC_R,             KC_T,            KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSPC,
        LT(_LAYER2, KC_CAPS),   KC_A,    KC_S,    KC_D,            KC_F,             KC_G,            KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,
        KC_LSFT, KC_LSFT,       KC_Z,    KC_X,    KC_C,            KC_V,             KC_B,            KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT, KC_RGUI,
        KC_LCTL, _______,       KC_LALT,          KC_SPC,          KC_SPC,           KC_SPC,          KC_SPC,                                     KC_RALT,  _______, _______
    ),

};
