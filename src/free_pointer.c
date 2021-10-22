/*
** Saverio976, 2021
** EatSleepCode
** File description:
** free functions called by eat_sleep_code_interface.c
*/

#include <SFML/Graphics.h>

void free_pointer_bg_w(sfTexture *t, sfSprite *s, sfRenderWindow *w)
{
    sfSprite_destroy(s);
    sfTexture_destroy(t);
    sfRenderWindow_destroy(w);
}

void free_pointer_tx_ft(sfFont *font, sfText *text)
{
    sfFont_destroy(font);
    sfText_destroy(text);
}
