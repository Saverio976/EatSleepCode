/*
** EPITECH PROJECT, 2021
** Libmy
** File description:
** put a string in the terminal
*/

#include <unistd.h>
int my_strlen(char const *);

int my_putstr(char const *str)
{
    int res = write(1, str, my_strlen(str));

    return res;
}
