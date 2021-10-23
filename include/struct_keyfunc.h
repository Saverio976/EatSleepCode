/*
** Saverio976, 2021
** EatSleepCode
** File description:
** struct keyfunc
*/

#ifndef STRUCTKEYFUNC_H_
    #define STRUCTKEYFUNC_H_

    #include <SFML/Graphics.h>
    #include "struct_context.h"

struct keyfunc {
    sfKeyCode code;
    int (*fptr)(context_t *, int *, sfEvent *);
};
typedef struct keyfunc keyfunc_t;

int key_escape(context_t *, int *, sfEvent *);
int key_left(context_t *, int *, sfEvent *);
int key_right(context_t *, int *, sfEvent *);
int key_up(context_t *, int *, sfEvent *);
int key_down(context_t *, int *, sfEvent *);
int key_backspace(context_t *, int *, sfEvent *);
int key_delete(context_t *, int *, sfEvent *);

#endif
