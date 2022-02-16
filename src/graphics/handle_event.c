/*
** EPITECH PROJECT, 2022
** ESP
** File description:
** handle event
*/

#include <SFML/Graphics.h>
#include "esp.h"

static int move_cursor_up(sfEvent *event, file_edit_t *file);
static int move_cursor_down(sfEvent *event, file_edit_t *file);
static int move_cursor_right(sfEvent *event, file_edit_t *file);
static int move_cursor_left(sfEvent *event, file_edit_t *file);

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

static int move_cursor_up(sfEvent *event, file_edit_t *file)
{
    if (event->type != sfEvtKeyPressed || event->key.code != sfKeyUp) {
        return (0);
    }
    if (file->y - 1 < 0) {
        return (0);
    }
    my_printf("up\n");
    file->curr_line = file->curr_line->last;
    file->y -= 1;
    if (file->line_top->last == file->curr_line) {
        file->line_top = file->line_top->last;
        file->line_bot = file->line_bot->last;
    }
    return (0);
}

static int move_cursor_down(sfEvent *event, file_edit_t *file)
{
    if (event->type != sfEvtKeyPressed || event->key.code != sfKeyDown) {
        return (0);
    }
    if (file->y + 1 > file->nb_lines) {
        return (0);
    }
    my_printf("down y : %d\n", file->y);
    file->curr_line = file->curr_line->next;
    file->y += 1;
    if (file->line_bot->next == file->curr_line) {
        file->line_bot = file->line_bot->next;
        file->line_top = file->line_top->next;
    }
    return (0);
}

static int move_cursor_right(sfEvent *event, file_edit_t *file)
{
    if (event->type != sfEvtKeyPressed || event->key.code != sfKeyRight) {
        return (0);
    }
    return (0);
}

static int move_cursor_left(sfEvent *event, file_edit_t *file)
{
    if (event->type != sfEvtKeyPressed || event->key.code != sfKeyLeft) {
        return (0);
    }
    return (0);
}

int handle_event(sfRenderWindow *window, file_edit_t *file)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed) {
            sfRenderWindow_close(window);
            continue;
        }
        for (int i = 0; KEYS[i] != sfKeyUnknown; i++) {
            FCNTS[i](&event, file);
        }
    }
    return (0);
}
