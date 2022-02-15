/*
** EPITECH PROJECT, 2022
** ESP
** File description:
** destroy window
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "esp.h"

void destroy_window(window_t *window)
{
    sfSprite_destroy(window->bg_sprite);
    sfTexture_destroy(window->bg_texture);
    sfText_destroy(window->text);
    sfFont_destroy(window->font);
    sfRenderWindow_destroy(window->win);
    file_edit_t_destroy(window->curr_file);
    free(window);
}
