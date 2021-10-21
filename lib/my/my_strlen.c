/*
** EPITECH PROJECT, 2021
** Libmy
** File description:
** return length of the string
*/

#include <stddef.h>

int my_strlen(char const *str)
{
    int i = 0;

    if (str == NULL)
        return (0);
    while (str[i])
        i++;
    return (i);
}
