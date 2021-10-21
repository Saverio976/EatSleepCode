/*
** EPITECH PROJECT, 2021
** Libmy
** File description:
** put nbr in base (base) in the terminal
*/

int my_strlen(char const *);
char *my_revstr(char *);
int my_putstr(char const *);

int my_putnbr_base(int nbr, char const *base)
{
    char result[31] = {0};
    int i = 0;
    int len = my_strlen(base);

    if (len == 0)
        return (-84);
    while (nbr != 0) {
        result[i] = base[nbr % len];
        nbr = nbr / len;
        i++;
    }
    my_revstr(result);
    if (my_strlen(result) == 1) {
        result[1] = result[0];
        result[0] = '0';
    }
    my_putstr(result);
    return (0);
}
