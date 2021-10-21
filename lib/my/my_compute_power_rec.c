/*
** EPITECH PROJECT, 2021
** Libmy
** File description:
** compute the power of with recursiv
*/

int my_compute_power_rec(int nb, int p)
{
    int result = 0;

    if (p < 0)
        return (0);
    if (p == 0)
        return (1);
    result = my_compute_power_rec(nb, p - 1);
    return nb * result;
}
