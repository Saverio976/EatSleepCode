/*
** Saverio976, 2021
** EatSleepCode
** File description:
** iterr event to found the rigth one
*/

#include <SFML/Graphics.h>
#include <stddef.h>
#include "struct_keyfunc.h"
#include "eatsleepcode.h"

static const keyfunc_t KEYFUNC[] = {{sfKeyEscape, &key_escape},
                                {sfKeyLeft, &key_left},
                                {sfKeyRight, &key_right},
                                {sfKeyUp, &key_up},
                                {sfKeyDown, &key_down},
                                {sfKeyBack, &key_backspace},
                                {sfKeyDelete, &key_delete},
                                {sfKeyEnter, &key_enter},
                                {sfKeyDown, NULL}};

int event_close(context_t *ctx, sfEvent *event, int *is_swap_modif)
{
    if (event->type != sfEvtClosed)
        return (0);
    sfRenderWindow_close(ctx->window);
    *is_swap_modif = 0;
    return (1);
}

int event_mouse_scroll(context_t *ctx, sfEvent *event, int *is_swap_modif)
{
    if (event->mouseWheelScroll.wheel == sfMouseVerticalWheel) {
        ctx->scroll_y += event->mouseWheelScroll.delta;
        if (ctx->scroll_y < 0)
            ctx->scroll_y = 0;
    } else {
        ctx->scroll_x += event->mouseWheelScroll.delta;
        if (ctx->scroll_x < 0)
            ctx->scroll_x = 0;
    }
    *is_swap_modif = 0;
    return (1);
}

int event_key_pressed(context_t *ctx, sfEvent *event, int *is_swap_modif)
{
    int is_end = 0;

    for (int i = 0; (is_end == 0) && KEYFUNC[i].fptr != NULL; i++)
        if (event->key.code == KEYFUNC[i].code)
            is_end = KEYFUNC[i].fptr(ctx, is_swap_modif, event);
    return is_end;
}

int event_text_entered(context_t *ctx, sfEvent *event, int *is_swap_modif)
{
    update_text_unicode(ctx, event->text.unicode);
    *is_swap_modif = 1;
    (ctx->cursor_x)++;
    return (1);
}
