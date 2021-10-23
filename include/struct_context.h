/*
** Saverio976, 2021
** EatSleepCode
** File description:
** Context window with font, window, text
*/

#ifndef CONTEXT_H_
    #define CONTEXT_H_

    #include <SFML/Graphics.h>

struct context {
    sfRenderWindow *window;
    sfFont *font;
    sfText *text;
    int scroll_y;
    int scroll_x;
    char **text_file;
    int cursor_x;
    int cursor_y;
};
typedef struct context context_t;

#endif
