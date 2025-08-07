#include <stdlib.h>
#include <string.h>

#include "keyboard.h"
#include "glfw3.h"
#include "../util.h"
#include "../render/window.h"


Keyboard_Input *keyboard_create() {
    Keyboard_Input *keyboard_input = malloc(sizeof(*keyboard_input));

    *keyboard_input = (Keyboard_Input) {
        .key_functions = calloc(SEAKEY_COUNT, sizeof(*keyboard_input->key_functions)),
    };

    return keyboard_input;
}

void keyboard_register_key(Keyboard_Input *keyboard_input, SEAKEY key, Key_Callback key_callback, void *context) {
    keyboard_input->key_functions[key] = (Key_Function) {
        .key_callback = key_callback,
        .context = context,
    };

    LOG_INFO("info (keyboard): Key %d registered", key);

    return;
}

void keyboard_deregister_key(Keyboard_Input *keyboard_input, SEAKEY key) {
    keyboard_input->key_functions[key] = (Key_Function) {
        .key_callback = NULL,
        .context = NULL,
    };

    LOG_INFO("info (keyboard): Key %d deregistered", key);

    return;
}

void keyboard_poll_keys(Keyboard_Input *keyboard_input, const Window_State *window_state) {
    for (int i = 0; i < SEAKEY_COUNT; i++) {
        int glfw_key = 0;
        if (i < 10) {
            glfw_key = i + GLFW_NUMKEY_OFFSET;
        } else {
            glfw_key = i - SEAKEY_ALPHA_OFFSET + GLFW_ALPHAKEY_OFSSET;
        }

        SEAKEY_STATE state = glfwGetKey(window_state->window, glfw_key);
        
        if (keyboard_input->key_functions[i].key_callback != NULL) {
            void *context = keyboard_input->key_functions[i].context;
            keyboard_input->key_functions[i].key_callback(state, context);
        }
    }

    return;
}

void keyboard_destroy(Keyboard_Input* keyboard_input) {
    free(keyboard_input->key_functions);
    free(keyboard_input);

    return;
}

