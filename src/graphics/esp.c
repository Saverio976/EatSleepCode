/*
** EPITECH PROJECT, 2022
** ESP
** File description:
** window loop
*/

#include <SFML/Graphics.h>
#include "my_dico.h"
#include "my_macro.h"
#include "my_strings.h"
#include "esp.h"

void draw_cursor(sfRenderWindow *win, file_edit_t *file,
        sfRectangleShape *rect, sfText *text)
{
    sfVector2f size = {file->charactr_size / 2, file->charactr_size};
    sfColor color = sfRed;
    sfVector2f pos = {0, OFFSET_CODE_Y + file->charactr_size * file->global_y};
    int index = 0;

    index = MIN(file->global_x, my_strlen(file->curr_line->data) - 1);
    sfText_setString(text, file->curr_line->data);
    pos.x = sfText_findCharacterPos(text, index).x;
    color.a = 100;
    sfRectangleShape_setFillColor(rect, color);
    sfRectangleShape_setSize(rect, size);
    sfRectangleShape_setPosition(rect, pos);
    sfRenderWindow_drawRectangleShape(win, rect, NULL);
}

int window_loop(window_t *window, __attribute__((unused)) dico_t *args)
{
    int ret_code = 0;
    sfRectangleShape *rect;

    rect = sfRectangleShape_create();
    while (ret_code == 0 && sfRenderWindow_isOpen(window->win)) {
        sfRenderWindow_clear(window->win, sfBlack);
        sfRenderWindow_drawSprite(window->win, window->bg_sprite, NULL);
        file_edit_t_display(window->curr_file, window->win, window->text);
        draw_cursor(window->win, window->curr_file, rect, window->text);
        sfRenderWindow_display(window->win);
        ret_code = handle_event(window->win, window->curr_file, window->modes);
    }
    sfRectangleShape_destroy(rect);
    return (ret_code);
}
