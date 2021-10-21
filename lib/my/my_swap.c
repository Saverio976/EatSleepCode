/*
** EPITECH PROJECT, 2021
** Libmy
** File description:
** swap value of two number
*/

void my_swap(int *a, int *b)
{
    int tmp = *b;

    *b = *a;
    *a = tmp;
}
