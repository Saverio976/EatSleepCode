/*
** EPITECH PROJECT, 2022
** ESP
** File description:
** motion in a file
*/

#include <SFML/Graphics.h>
#include "my_strings.h"
#include "esp.h"

int move_cursor_up(sfEvent *event, file_edit_t *file)
{
    if (event->type != sfEvtKeyPressed || event->key.code != sfKeyUp) {
        return (0);
    }
    if (file->y - 1 < 0) {
        return (0);
    }
    file->curr_line = file->curr_line->last;
    file->y -= 1;
    if (file->line_top->last == file->curr_line) {
        file->line_top = file->line_top->last;
        file->line_bot = file->line_bot->last;
    } else {
        file->global_y -= 1;
    }

    return (0);
}

int move_cursor_down(sfEvent *event, file_edit_t *file)
{
    if (event->type != sfEvtKeyPressed || event->key.code != sfKeyDown) {
        return (0);
    }
    if (file->y + 1 > file->nb_lines) {
        return (0);
    }
    file->curr_line = file->curr_line->next;
    file->y += 1;
    if (file->line_bot->next == file->curr_line) {
        file->line_bot = file->line_bot->next;
        file->line_top = file->line_top->next;
    } else {
        file->global_y += 1;
    }
    return (0);
}

int move_cursor_right(sfEvent *event, file_edit_t *file)
{
    int len = 0;

    if (event->type != sfEvtKeyPressed || event->key.code != sfKeyRight) {
        return (0);
    }
    len = my_strlen(file->curr_line->data);
    file->global_x += 1;
    if (file->global_x >= len) {
        file->global_x = len - 1;
    }
    return (0);
}

int move_cursor_left(sfEvent *event, file_edit_t *file)
{
    int len = 0;

    if (event->type != sfEvtKeyPressed || event->key.code != sfKeyLeft) {
        return (0);
    }
    len = my_strlen(file->curr_line->data);
    if (file->global_x >= len) {
        file->global_x = len - 1;
    }
    file->global_x -= 1;
    if (file->global_x < 0) {
        file->global_x = 0;
        return (0);
    }
    return (0);
}
