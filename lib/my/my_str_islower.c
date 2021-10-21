/*
** EPITECH PROJECT, 2021
** Libmy
** File description:
** check if a string contains only lower case
*/

int my_strlen(char const *);

int my_str_islower(char const *str)
{
    int ok = 1;
    int i = 0;

    for (; ok && i < my_strlen(str); i++) {
        if (!('a' <= str[i] && str[i] <= 'z'))
            ok = 0;
    }
    return ok;
}
