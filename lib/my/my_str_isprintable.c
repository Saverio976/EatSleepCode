/*
** EPITECH PROJECT, 2021
** Libmy
** File description:
** check if a string contains only printable chars
*/

int my_strlen(char const *);

int my_str_isprintable(char const *str)
{
    int ok = 1;

    for (int i = 0; ok && i < my_strlen(str); i++)
        if (!(' ' <= str[i] && str[i] <= '~'))
            ok = 0;
    return ok;
}
