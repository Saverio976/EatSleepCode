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
    int cursor_x;
    int cursor_y;
    char **text_file;
    char const *path;
    char const *swap;
};
typedef struct context context_t;

#endif
