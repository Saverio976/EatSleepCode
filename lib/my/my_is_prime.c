/*
** EPITECH PROJECT, 2021
** Libmy
** File description:
** check if a number is prime
*/

int my_is_prime(int nb)
{
    int i;
    int is_ok = 1;

    if (nb <= 1)
        return (0);
    for (i = nb - 1; is_ok && i > 1; i--)
        if (nb % i == 0)
            is_ok = 0;
    if (is_ok)
        return (1);
    else
        return (0);
}
