/*
** EPITECH PROJECT, 2021
** Libmy
** File description:
** return the first prime sup or equal to nb
*/

int my_is_prime(int);

int my_find_prime_sup(int nb)
{
    int is_notfound = 1;
    int i;

    for (i = nb; is_notfound; i++)
        is_notfound = my_is_prime(i) == 0;
    if (i == nb)
        return nb;
    else
        return --i;
}
