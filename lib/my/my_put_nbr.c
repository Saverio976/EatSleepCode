/*
** EPITECH PROJECT, 2021
** Libmy
** File description:
** put a nbr in a terminal
*/

int my_putstr(char const *);
void my_putchar(char c);

static void print_last_range_number(void)
{
    char number[] = "-2147483648";

    my_putstr(number);
}

static int put_nbr_rec(int nb)
{
    int c = nb % 10;

    if (nb == 0)
        return (0);
    put_nbr_rec(nb / 10);
    my_putchar(c + 48);
    return (0);
}

int my_put_nbr(int nb)
{
    if (nb == -2147483648) {
        print_last_range_number();
        return (0);
    }
    if (nb == 0) {
        my_putchar('0');
        return (0);
    }
    if (nb < 0) {
        nb = nb * -1;
        my_putchar('-');
    }
    put_nbr_rec(nb);
    return (0);
}
