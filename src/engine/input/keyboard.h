#pragma once

#define SEAKEY_COUNT 36
#define SEAKEY_ALPHA_OFFSET 10
#define GLFW_NUMKEY_OFFSET 48
#define GLFW_ALPHAKEY_OFSSET 65

#include "../render/window.h"

typedef enum {
    SEAKEY_RELEASE,
    SEAKEY_PRESS,
} SEAKEY_STATE;

typedef enum {
    SEAKEY_0,
    SEAKEY_1,
    SEAKEY_2,
    SEAKEY_3,
    SEAKEY_4,
    SEAKEY_5,
    SEAKEY_6,
    SEAKEY_7,
    SEAKEY_8,
    SEAKEY_9,
    SEAKEY_A,
    SEAKEY_B,
    SEAKEY_C,
    SEAKEY_D,
    SEAKEY_E,
    SEAKEY_F,
    SEAKEY_G,
    SEAKEY_H,
    SEAKEY_I,
    SEAKEY_J,
    SEAKEY_K,
    SEAKEY_L,
    SEAKEY_M,
    SEAKEY_N,
    SEAKEY_O,
    SEAKEY_P,
    SEAKEY_Q,
    SEAKEY_R,
    SEAKEY_S,
    SEAKEY_T,
    SEAKEY_U,
    SEAKEY_V,
    SEAKEY_W,
    SEAKEY_X,
    SEAKEY_Y,
    SEAKEY_Z,
} SEAKEY;

typedef void (*Key_Callback)(SEAKEY_STATE state, void *context);

typedef struct {
    Key_Callback key_callback;
    void *context;
} Key_Function;

typedef struct {
    Key_Function *key_functions;
} Keyboard_Input;

Keyboard_Input *keyboard_create();
void keyboard_register_key(Keyboard_Input *keyboard_input, SEAKEY key, Key_Callback key_callback, void *context);
void keyboard_deregister_key(Keyboard_Input *keyboard_input, SEAKEY key);
void keyboard_poll_keys(Keyboard_Input *keyboard_input, const Window_State *window_state);
void keyboard_destroy(Keyboard_Input* keyboard_input);
