/*
** Saverio976, 2021
** EatSleepCode
** File description:
** the function that take the graphics
*/

#include <SFML/Graphics.h>
#include <stddef.h>
#include <stdlib.h>
#include "constant.h"
#include "struct_context.h"
#include "my.h"
#include "eatsleepcode.h"

sfRenderWindow *create_window(unsigned int w, unsigned int h, char const *t)
{
    sfVideoMode mode = {w, h, 32};
    sfRenderWindow *window;

    window = sfRenderWindow_create(mode, t, sfResize | sfClose, NULL);
    sfRenderWindow_setKeyRepeatEnabled(window, sfFalse);
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

context_t *create_context(unsigned int w, unsigned int h, char const *title,
                            char const *font_path)
{
    context_t *ctx = malloc(sizeof(context_t));
    
    ctx->scroll_y = 0;
    ctx->scroll_x = 0;
    ctx->cursor_y = 0;
    ctx->cursor_x = 0;
    ctx->window = create_window(w, h, title);
    if (!(ctx->window))
        return NULL;
    ctx->font = sfFont_createFromFile(font_path);
    if (!(ctx->font))
        return NULL;
    ctx->text = sfText_create();
    if (!(ctx->text))
        return NULL;
    return (ctx);
}

static void add_to_context(context_t *ctx, char const *swap, char const *path)
{
    ctx->path = path;
    ctx->swap = swap;
    ctx->text_file = read_text(swap);
}

static void init_screen_frame(sfRenderWindow *window, sfSprite *bg)
{
    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_drawSprite(window, bg, NULL);
}

int eat_sleep_code_interface(char const *swap, char const *path)
{
    context_t *ctx = create_context(1920, 1080, "EatSleepCode", FONT_PATH);
    sfTexture *background_texture;
    sfSprite *background;
    sfEvent event;

    if (!ctx)
        return (84);
    add_to_context(ctx, swap, path);
    if (!(ctx->text_file))
        return (84);
    background = create_background(BG_PATH, &background_texture);
    if (!background)
        return (84);
    while (sfRenderWindow_isOpen(ctx->window)) {
        master_event_window(ctx, &event);
        init_screen_frame(ctx->window, background);
        render_code(ctx);
        sfRenderWindow_display(ctx->window);
    }
    free_pointer_ctx(ctx);
    free_pointer_bg(background_texture, background);
    return (0);
}
