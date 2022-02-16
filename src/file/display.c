/*
** EPITECH PROJECT, 2022
** ESP
** File description:
** display to sfRenderWindow
*/

#include <SFML/Graphics.h>
#include "my_strings.h"
#include "esp.h"

static void print_line(char const *str, sfVector2f pos, sfText *text,
        sfRenderWindow *win)
{
    if (str == NULL || str[0] == '\0') {
        return;
    }
    sfText_setPosition(text, pos);
    sfText_setString(text, str);
    sfText_setFillColor(text, sfWhite);
    sfRenderWindow_drawText(win, text, NULL);
}

int file_edit_t_display(file_edit_t *file, sfRenderWindow *win, sfText *text)
{
    int index_y = 0;
    list_t *cursor = NULL;
    sfVector2f pos = {10, 10};

    if (file->line_top == NULL) {
        return (0);
    }
    sfText_setCharacterSize(text, file->charactr_size);
    cursor = file->line_top;
    do {
        if (my_strlen(cursor->data) > file->x) {
            print_line((char *) cursor->data + file->x, pos, text, win);
        }
        pos.y += file->charactr_size;
        index_y++;
        cursor = cursor->next;
    } while (cursor != file->list_line &&
            sfRenderWindow_getSize(win).y > pos.y);
    file->line_bot = cursor->last;
    return (index_y);
}
