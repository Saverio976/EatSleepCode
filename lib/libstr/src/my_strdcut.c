/*
** EPITECH PROJECT, 2022
** LIBSTR
** File description:
** cut dup n
*/

#include <stdlib.h>
#include "my_macro.h"
#include "my_strings.h"

char *my_strdcut(char const *src, int n)
{
    char *new = NULL;
    int size = n;

    new = malloc(sizeof(char) * (size + 1));
    if (new == NULL) {
        return (NULL);
    }
    for (int i = 0; i < size; i++) {
        new[i] = src[i];
    }
    new[size] = '\0';
    return (new);
}
