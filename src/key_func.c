/*
** Saverio976, 2021
** EatSleepCode
** File description:
** key func for keyfunc struct
*/

#include <SFML/Graphics.h>
#include "my.h"
#include "eatsleepcode.h"
#include "struct_context.h"

int key_escape(context_t *ctx, int *is_swap_modif, sfEvent *event)
{
    save_text_modif(ctx);
    sfRenderWindow_pollEvent(ctx->window, event);
    *is_swap_modif = 0;
    return (1);
}

int key_left(context_t *ctx, int *is_swap_modif, sfEvent *event)
{
    if (event->type != sfEvtKeyPressed)
        return (0);
    (ctx->cursor_x)--;
    if (ctx->cursor_x < 0)
        ctx->cursor_x = 0;
    *is_swap_modif = 0;
    return (1);
}

int key_right(context_t *ctx, int *is_swap_modif, sfEvent *event)
{
    int len = my_strlen(ctx->text_file[ctx->cursor_y]);

    if (event->type != sfEvtKeyPressed)
        return (0);
    (ctx->cursor_x)++;
    if (ctx->cursor_x > len)
        ctx->cursor_x = len;
    *is_swap_modif = 0;
    return (1);
}

int key_up(context_t *ctx, int *is_swap_modif, sfEvent *event)
{
    int len_x;

    if (event->type != sfEvtKeyPressed)
        return (0);
    (ctx->cursor_y)--;
    if (ctx->cursor_y < 0)
        ctx->cursor_y = 0;
    len_x = my_strlen(ctx->text_file[ctx->cursor_y]);
    if (ctx->cursor_x > len_x)
        ctx->cursor_x = len_x;
    *is_swap_modif = 0;
    return (1);
}

int key_down(context_t *ctx, int *is_swap_modif, sfEvent *event)
{
    int len_y = my_arraylen(ctx->text_file) - 1;
    int len_x;

    if (event->type != sfEvtKeyPressed)
        return (0);
    (ctx->cursor_y)++;
    if (ctx->cursor_y > len_y)
        ctx->cursor_y = len_y;
    len_x = my_strlen(ctx->text_file[ctx->cursor_y]);
    if (ctx->cursor_x > len_x)
        ctx->cursor_x = len_x;
    *is_swap_modif = 0;
    return (1);
}
