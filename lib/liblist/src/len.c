/*
** EPITECH PROJECT, 2022
** LIBLIST
** File description:
** get len
*/

#include <stddef.h>
#include "my_list.h"

int list_t_len(list_t *list)
{
    list_t *cursor;
    int len = 0;

    if (list == NULL) {
        return (-1);
    }
    cursor = list;
    do {
        len++;
        cursor = cursor->next;
    } while (cursor != NULL && cursor != list);
    return (len);
}
