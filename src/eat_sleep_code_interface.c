/*
** Saverio976, 2021
** EatSleepCode
** File description:
** the function that take the graphics
*/

#include <SFML/Graphics.h>
#include <stddef.h>
#include "constant.h"
#include "struct_context.h"
void render_code(context_t *, char *);
void master_event_window(context_t *, sfEvent *);
void free_pointer_bg(sfTexture *, sfSprite *);
void free_pointer_ctx(context_t *);

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
    context_t ctx = {.scroll_y = 0};
    sfTexture *background_texture;
    sfSprite *background;
    sfEvent event;

    ctx.window = create_window(1920, 1080, "EatSleepCode");
    if (!ctx.window)
        return (84);
    background = create_background(BG_PATH, &background_texture);
    if (!background)
        return (84);
    ctx.font = sfFont_createFromFile(FONT_PATH);
    if (!ctx.font)
        return (84);
    ctx.text = sfText_create();
    if (!ctx.text)
        return (84);
    while (sfRenderWindow_isOpen(ctx.window)) {
        master_event_window(&ctx, &event);
        sfRenderWindow_drawSprite(ctx.window, background, NULL);
        render_code(&ctx, path);
        sfRenderWindow_display(ctx.window);
    }
    free_pointer_ctx(&ctx);
    free_pointer_bg(background_texture, background);
    return (0);
}
