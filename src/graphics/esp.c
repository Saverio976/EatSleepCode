/*
** EPITECH PROJECT, 2022
** ESP
** File description:
** window loop
*/

#include <SFML/Graphics.h>
#include "my_dico.h"
#include "esp.h"

int window_loop(window_t *window, __attribute__((unused)) dico_t *args)
{
    int ret_code = 0;

    while (ret_code == 0 && sfRenderWindow_isOpen(window->win)) {
        sfRenderWindow_clear(window->win, sfBlack);
        sfRenderWindow_drawSprite(window->win, window->bg_sprite, NULL);
        file_edit_t_display(window->curr_file, window->win, window->text);
        sfRenderWindow_display(window->win);
        ret_code = handle_event(window->win, window->curr_file);
    }
    return (ret_code);
}
