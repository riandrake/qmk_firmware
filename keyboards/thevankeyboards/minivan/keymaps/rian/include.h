#pragma once

#define LAYER( \
    x01, x02, x03, x04, x05, x06, x07, x08, x09, x10, x11, x12, \
    x13, x14, x15, x16, x17, x18, x19, x20, x21, x22, x23, x24, \
    x25, x26, x27, x28, x29, x30, x31, x32, x33, x34, x35, x36, \
    x37, x38, x39,           x40, x41,           x42, x43, x44 ) \
{ \
        { KC_##x01, KC_##x02, KC_##x03, KC_##x04, KC_##x05, KC_##x06, KC_##x07, KC_##x08, KC_##x09, KC_##x10, KC_##x11, KC_##x12, }, \
        { KC_##x13, KC_##x14, KC_##x15, KC_##x16, KC_##x17, KC_##x18, KC_##x19, KC_##x20, KC_##x21, KC_##x22, KC_##x23, KC_##x24, }, \
        { KC_##x25, KC_##x26, KC_##x27, KC_##x28, KC_##x29, KC_##x30, KC_##x31, KC_##x32, KC_##x33, KC_##x34, KC_##x35, KC_##x36, }, \
        { KC_##x37, KC_##x38, KC_##x39, KC_##x40, KC_NO   , KC_NO   , KC_NO   , KC_##x41, KC_##x42, KC_##x43, KC_NO   , KC_##x44  }  \
}
