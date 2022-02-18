/*
** EPITECH PROJECT, 2022
** ESP
** File description:
** handle event
*/

#include <SFML/Graphics.h>
#include "my_strings.h"
#include "esp.h"

static const sfKeyCode KEYS[] = {
    sfKeyUp,
    sfKeyDown,
    sfKeyRight,
    sfKeyLeft,
    sfKeyUnknown
};

static int (*FCNTS[])(sfEvent *, file_edit_t *) = {
    &move_cursor_up,
    &move_cursor_down,
    &move_cursor_right,
    &move_cursor_left,
    NULL
};

int handle_event(sfRenderWindow *window, file_edit_t *file,
        mode_context_t *mode)
{
    sfEvent event;

    while (sfRenderWindow_isOpen(window) &&
            sfRenderWindow_pollEvent(window, &event)) {
        for (int i = 0; KEYS[i] != sfKeyUnknown; i++) {
            FCNTS[i](&event, file);
        }
        if (event.type == sfEvtTextEntered) {

        }
        if (event.type == sfEvtClosed) {
            sfRenderWindow_close(window);
        }
    }
    return (0);
}
