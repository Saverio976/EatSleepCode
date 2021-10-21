/*
** EPITECH PROJECT, 2021
** task01
** File description:
** allocates memory and copies the string
*/

#include <stdlib.h>
#include <stddef.h>
int my_strlen(char const *);
int my_strcpy(char *, char const *);

char *my_strdup(char const *src)
{
    char *tab;

    if (src == NULL)
        return NULL;
    tab = malloc(sizeof(char) * my_strlen(src));
    my_strcpy(tab, src);
    return tab;
}
