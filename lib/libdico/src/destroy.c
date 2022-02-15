/*
** EPITECH PROJECT, 2022
** LIBLIST
** File description:
** destroy all linked list
*/

#include <stdlib.h>
#include "my_dico.h"

int dico_t_destroy(dico_t *dico)
{
    dico_t *tmp;
    dico_t *cursor;
    int nb = 0;

    if (dico == NULL) {
        return (0);
    }
    cursor = dico->next;
    for (; cursor != NULL && cursor != dico; nb++) {
        tmp = cursor->next;
        cursor->destroy(cursor->value);
        free(cursor);
        cursor = tmp;
    }
    cursor->destroy(cursor->value);
    free(cursor);
    return (nb + 1);
}
