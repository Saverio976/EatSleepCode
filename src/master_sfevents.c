/*
** Saverio976, 2021
** EatSleepCode
** File description:
** iterr on a poll event from eat_sleep_code()
*/

#include <SFML/Graphics.h>
#include "struct_context.h"

void iterr_for_event(context_t *ctx, sfEvent *event)
{
    if (event->type == sfEvtClosed)
        sfRenderWindow_close(ctx->window);
    else if (event->type == sfEvtMouseWheelScrolled)
        if (event->mouseWheelScroll.wheel == sfMouseVerticalWheel) {
            ctx->scroll_y += event->mouseWheelScroll.delta;
            if (ctx->scroll_y < 0)
                ctx->scroll_y = 0;
        }
}

void master_event_window(context_t *ctx, sfEvent *event)
{
    while (sfRenderWindow_pollEvent(ctx->window, event)) {
        iterr_for_event(ctx, event);
    }
}
