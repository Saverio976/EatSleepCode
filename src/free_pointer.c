/*
** Saverio976, 2021
** EatSleepCode
** File description:
** free functions called by eat_sleep_code_interface.c
*/

#include <SFML/Graphics.h>
#include "struct_context.h"

void free_pointer_bg(sfTexture *t, sfSprite *s)
{
    sfSprite_destroy(s);
    sfTexture_destroy(t);
}

void free_pointer_ctx(context_t *ctx)
{
    sfFont_destroy(ctx->font);
    sfText_destroy(ctx->text);
    sfRenderWindow_destroy(ctx->window);
    free(ctx);
}
