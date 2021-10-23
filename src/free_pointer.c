/*
** Saverio976, 2021
** EatSleepCode
** File description:
** free functions called by eat_sleep_code_interface.c
*/

#include <SFML/Graphics.h>
#include "struct_context.h"
#include <stdlib.h>
#include <stddef.h>

void free_pointer_bg(sfTexture *t, sfSprite *s)
{
    sfSprite_destroy(s);
    sfTexture_destroy(t);
}

void free_pointer_ctx(context_t *ctx)
{
    sfFont_destroy(ctx->font);
    sfText_destroy(ctx->text);
    for (int i = 0; ctx->text_file[i] != NULL; i++)
        free(ctx->text_file[i]);
    free(ctx->text_file);
    sfRenderWindow_destroy(ctx->window);
    free(ctx);
}
