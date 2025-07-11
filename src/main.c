#include <stdio.h>

#include "engine/render/window.h"
#include "engine/input/keyboard.h"
#include "engine/util.h"

void test_key_callback(SEAKEY_STATE state, void *context) {
    if (state == SEAKEY_PRESS) {
        Window_State *window_state = (Window_State*) context;
        window_set_close(window_state);
        LOG_INFO("key pressed");
    }
}

int main() {
    Window_State *window_state = window_create(800, 800, "Engine");
    Keyboard_Input *keyboard_input = keyboard_create();

    keyboard_register_key(keyboard_input, SEAKEY_A, test_key_callback, window_state);
    keyboard_deregister_key(keyboard_input, SEAKEY_A);

    while (!window_should_close(window_state)) {

        window_poll_swap(window_state);
        keyboard_poll_keys(keyboard_input, window_state);
    }


    keyboard_destroy(keyboard_input);
    window_destroy(window_state);

    return 0;
}


