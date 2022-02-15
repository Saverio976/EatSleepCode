/*
** EPITECH PROJECT, 2022
** ESP
** File description:
** handle event
*/

#include <SFML/Graphics.h>

int handle_event(sfRenderWindow *window)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed) {
            sfRenderWindow_close(window);
        }
    }
    return (0);
}
