/*
** EPITECH PROJECT, 2021
** Libmy
** File description:
** init a str with custom char on n char
*/

char *my_init_nstr(char *str, char c, int n)
{
    for (int i = 0; i < n; i++)
        str[i] = c;
    return (str);
}
