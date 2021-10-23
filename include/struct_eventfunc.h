/*
** EPITECH PROJECT, 2021
** EatSleepCode
** File description:
** struct eventfunc
*/

#ifndef STRUCTEVTFUNC_H_
    #define STRUCTEVTFUNC_H_

    #include <SFML/Graphics.h>
    #include "struct_context.h"

struct evtfunc {
    sfEventType type;
    int (*fptr)(context_t *, sfEvent *, int *);
};
typedef struct evtfunc evtfunc_t;

int event_close(context_t *, sfEvent *, int *);
int event_mouse_scroll(context_t *, sfEvent *, int *);
int event_text_entered(context_t *, sfEvent *, int *);
int event_key_pressed(context_t *, sfEvent *, int *);

#endif
