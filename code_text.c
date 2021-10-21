/*
** Saverio976, 2021
** EatSleepCode
** File description:
** master read and write on text
*/

#include <SFML/Graphics.h>
#include "constant.h"
#include <stddef.h>
#include <stdlib.h>
char **read_text(char *);
char *sanitize_string(char *);

void update_text(sfRenderWindow *w, sfFont *font, sfText *text, char *path)
{
    sfVector2f position = {50, 30};
    char **text_char = read_text(path);

    for (int i = 0; text_char[i] != NULL; i++) {
        sfText_setString(text, sanitize_string(text_char[i]));
        sfText_setFont(text, font);
        sfText_setCharacterSize(text, 18);
        position.y += 20;
        sfText_setPosition(text, position);
        sfRenderWindow_drawText(w, text, NULL);
        free(text_char[i]);
    }
    free(text_char);
}

void render_code(sfRenderWindow *w, sfFont *font, sfText *text, char *path)
{
    update_text(w, font, text, path);
}
