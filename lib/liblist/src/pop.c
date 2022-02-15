/*
** EPITECH PROJECT, 2022
** LIBLIST
** File description:
** pop elem
*/

#include <stdlib.h>
#include "my_list.h"

void *list_t_pop_data(list_t *elem)
{
    void *tmp;

    if (elem == NULL) {
        return (NULL);
    }
    if (elem->last != NULL) {
        elem->last->next = elem->next;
    }
    if (elem->next != NULL) {
        elem->next->last = elem->last;
    }
    elem->last = NULL;
    elem->next = NULL;
    tmp = elem->data;
    free(elem);
    return (tmp);
}

list_t *list_t_pop_elem(list_t *elem)
{
    if (elem == NULL) {
        return (NULL);
    }
    if (elem->last != NULL) {
        elem->last->next = elem->next;
    }
    if (elem->next != NULL) {
        elem->next->last = elem->last;
    }
    elem->last = NULL;
    elem->next = NULL;
    return (elem);
}
