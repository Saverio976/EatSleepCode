/*
** EPITECH PROJECT, 2021
** Libmy
** File description:
** compute the square root
*/

int my_compute_power_rec(int, int);

int my_compute_square_root(int nb)
{
    int i = 1;
    int computed_root = my_compute_power_rec(i, 2);

    if (nb <= 0)
        return (0);
    while (computed_root != 0 && computed_root < nb) {
        i++;
        computed_root = my_compute_power_rec(i, 2);
    }
    if (my_compute_power_rec(i, 2) == nb)
        return i;
    else
        return (0);
}
