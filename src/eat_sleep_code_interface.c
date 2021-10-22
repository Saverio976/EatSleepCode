/*
** Saverio976, 2021
** EatSleepCode
** File description:
** the function that take the graphics
*/

#include <SFML/Graphics.h>
#include <stddef.h>
#include "constant.h"
void render_code(sfRenderWindow *, sfFont *, sfText *, char *);
void master_event_window(sfRenderWindow *, sfEvent *);
void free_pointer_bg_w(sfTexture *, sfSprite *, sfRenderWindow *);
void free_pointer_tx_ft(sfFont *, sfText *);

sfRenderWindow *create_window(unsigned int w, unsigned int h, char const *t)
{
    sfVideoMode mode = {w, h, 32};
    sfRenderWindow *window;

    window = sfRenderWindow_create(mode, t, sfResize | sfClose, NULL);
    return (window);
}

sfSprite *create_background(char const *path, sfTexture **background_texture)
{
    sfSprite *background_sprite;

    *background_texture = sfTexture_createFromFile(path, NULL);
    if (!(*background_texture))
        return (NULL);
    background_sprite = sfSprite_create();
    sfSprite_setTexture(background_sprite, *background_texture, sfTrue);
    return (background_sprite);
}

int eat_sleep_code_interface(char *path)
{
    sfRenderWindow *window = create_window(1920, 1080, "EatSleepCode");
    sfTexture *background_texture;
    sfSprite *background;
    sfEvent event;
    sfFont *font;
    sfText *text;

    if (!window)
        return (84);
    background = create_background(BG_PATH, &background_texture);
    if (!background)
        return (84);
    font = sfFont_createFromFile(FONT_PATH);
    if (!font)
        return (84);
    text = sfText_create();
    if (!text)
        return (84);
    while (sfRenderWindow_isOpen(window)) {
        master_event_window(window, &event);
        sfRenderWindow_drawSprite(window, background, NULL);
        render_code(window, font, text, path);
        sfRenderWindow_display(window);
    }
    free_pointer_tx_ft(font, text);
    free_pointer_bg_w(background_texture, background, window);
    return (0);
}
