/*
** EPITECH PROJECT, 2021
** Libmy
** File description:
** put char in the terminal
*/

#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}
