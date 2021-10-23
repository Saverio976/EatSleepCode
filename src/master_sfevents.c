/*
** Saverio976, 2021
** EatSleepCode
** File description:
** iterr on a poll event from eat_sleep_code()
*/

#include <SFML/Graphics.h>
#include <stddef.h>
#include "struct_context.h"
#include "eatsleepcode.h"
#include "struct_eventfunc.h"

const evtfunc_t EVTFUNC[] = {{sfEvtClosed, &event_close},
                                {sfEvtMouseWheelScrolled, &event_mouse_scroll},
                                {sfEvtKeyPressed, &event_key_pressed},
                                {sfEvtTextEntered, &event_text_entered},
                                {sfEvtKeyPressed, NULL}};

static void iterr_for_event(context_t *ctx, sfEvent *event)
{
    int is_swap_modif = 0;
    int is_end = 0;

    for (int i = 0; (is_end == 0) && EVTFUNC[i].fptr != NULL; i++)
        if (event->type == EVTFUNC[i].type)
            is_end = EVTFUNC[i].fptr(ctx, event, &is_swap_modif);
    if (is_swap_modif)
        save_swap_modif(ctx);
}

void master_event_window(context_t *ctx, sfEvent *event)
{
    while (sfRenderWindow_pollEvent(ctx->window, event))
        iterr_for_event(ctx, event);
}
