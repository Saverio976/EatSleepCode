/*
** EPITECH PROJECT, 2022
** ESP
** File description:
** display to sfRenderWindow
*/

#include <SFML/Graphics.h>
#include "my_strings.h"
#include "esp.h"

static void print_line(char const *str, int y, sfText *text,
        sfRenderWindow *win)
{
    sfVector2f pos = {10, 10 + 20 * y};

    sfText_setPosition(text, pos);
    sfText_setString(text, str);
    sfText_setFillColor(text, sfWhite);
    sfRenderWindow_drawText(win, text, NULL);
}

int file_edit_t_display(file_edit_t *file, sfRenderWindow *win, sfText *text)
{
    int index_y = 0;
    list_t *cursor = NULL;
    char const *tmp = NULL;

    if (file->line_top == NULL) {
        return (0);
    }
    cursor = file->line_top;
    do {
        if ((unsigned int) my_strlen(cursor->data) < file->x) {
            tmp = (char *) cursor->data + file->x;
            print_line(tmp, index_y, text, win);
        }
        index_y++;
        cursor = cursor->next;
    } while (cursor != file->list_line);
    return (index_y);
}
