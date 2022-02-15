/*
** EPITECH PROJECT, 2022
** LIBLIST
** File description:
** remove elem from list
*/

#include <stdlib.h>
#include "my_list.h"

int list_t_rem(list_t *elem)
{
    if (elem == NULL) {
        return (0);
    }
    if (elem->last != NULL) {
        elem->last->next = elem->last;
    }
    if (elem->next != NULL) {
        elem->next->last = elem->last;
    }
    if (elem->destroy != NULL) {
        elem->destroy(elem->data);
    }
    elem->last = NULL;
    elem->next = NULL;
    free(elem);
    return (1);
}
