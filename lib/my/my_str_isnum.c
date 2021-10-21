/*
** EPITECH PROJECT, 2021
** Libmy
** File description:
** check if a strin contains only digit
*/

int my_strlen(char const *);

int my_str_isnum(char const *str)
{
    int ok = 1;
    int i = 0;

    for (; ok && i < my_strlen(str); i++) {
        if ('0' <= str[i] && str[i] <= '9')
            ok = 1;
        else
            ok = 0;
    }
    return ok;
}
