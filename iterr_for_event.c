/*
** Saverio976, 2021
** EatSleepCode
** File description:
** iterr on a poll event from eat_sleep_code()
*/

#include <SFML/Graphics.h>

void iterr_for_event(sfRenderWindow *window, sfEvent *event)
{
    if (event->type == sfEvtClosed)
        sfRenderWindow_close(window);
}

void master_event_window(sfRenderWindow *window, sfEvent *event)
{
    while (sfRenderWindow_pollEvent(window, event)) {
        iterr_for_event(window, event);
    }
}
