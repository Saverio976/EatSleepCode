/*
** EPITECH PROJECT, 2021
** Libmy
** File description:
** put in a terminal only printable chars and hex of non
*/

int my_str_isprintable(char const *);
int my_strlen(char const *);
int my_putnbr_base(int, char const *);
void my_putchar(char const);

int my_showstr(char const *str)
{
    char tab[2] = {0};
    for (int i = 0; i < my_strlen(str); i++) {
        tab[0] = str[i];
        if (my_str_isprintable(tab))
            my_putchar(str[i]);
        else {
            my_putchar('\\');
            my_putnbr_base((int) str[i], "0123456789abcdef");
        }
    }
    return (0);
}
