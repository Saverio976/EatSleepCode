/*
** EPITECH PROJECT, 2021
** Libmy
** File description:
** get len of an array null terminated
*/

#include <stddef.h>

int my_arraylen(char **array)
{
    int i = 0;

    for (; array[i] != NULL; i++);
    return (i);
}
