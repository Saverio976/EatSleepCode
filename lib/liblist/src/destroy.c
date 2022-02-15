/*
** EPITECH PROJECT, 2022
** LIBLIST
** File description:
** destroy all linked list
*/

#include <stdlib.h>
#include "my_list.h"

int list_t_destroy(list_t *list)
{
    list_t *tmp;
    list_t *cursor;
    int nb = 0;

    if (list == NULL) {
        return (0);
    }
    cursor = list->next;
    for (; cursor != NULL && cursor != list; nb++) {
        tmp = cursor->next;
        cursor->destroy(cursor->data);
        free(cursor);
        cursor = tmp;
    }
    cursor->destroy(cursor->data);
    free(cursor);
    return (nb + 1);
}
