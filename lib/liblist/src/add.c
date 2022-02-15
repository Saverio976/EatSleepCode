/*
** EPITECH PROJECT, 2022
** LIBLIST
** File description:
** add elem
*/

#include <stdlib.h>
#include "my_list.h"

list_t *list_t_create(void *data, void (*destroy)(void *data))
{
    list_t *new;

    new = malloc(sizeof(list_t));
    if (new == NULL) {
        return (NULL);
    }
    new->destroy = destroy;
    new->data = data;
    new->last = new;
    new->next = new;
    return (new);
}

list_t *list_t_add_data(list_t *list, void *data, void (*destroy)(void *data))
{
    list_t *new;

    new = list_t_create(data, destroy);
    if (new == NULL) {
        return (NULL);
    }
    if (list == NULL) {
        return (new);
    }
    new->last = list->last;
    new->next = list;
    list->last->next = new;
    list->last = new;
    return (list);
}

list_t *list_t_add_elem(list_t *list, list_t *elem)
{
    if (elem == NULL) {
        return (list);
    }
    if (list == NULL) {
        return (elem);
    }
    elem->last = list->last;
    elem->next = list;
    list->last->next = elem;
    list->last = elem;
    return (list);
}
