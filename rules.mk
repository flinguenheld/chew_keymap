LTO_ENABLE = yes

SRC += features/auto_shift.c
SRC += features/cap_word.c
INTROSPECTION_KEYMAP_C = features/combo.c # Replace SRC, see issue #21137
# SRC += features/combo.c # Replace SRC, see issue #21137
SRC += features/leader.c
SRC += features/led.c

MOUSEKEY_ENABLE = yes
AUTO_SHIFT_ENABLE = yes
AUTO_SHIFT_MODIFIERS = no
COMBO_ENABLE = yes
LEADER_ENABLE = yes
CAPS_WORD_ENABLE = yes
REPEAT_KEY_ENABLE = yes

UNICODE_ENABLE = yes
SEND_STRING_ENABLE = yes

RGBLIGHT_ENABLE = yes
WS2812_DRIVER = vendor
