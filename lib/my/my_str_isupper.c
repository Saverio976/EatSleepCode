/*
** EPITECH PROJECT, 2021
** Libmy
** File description:
** check if a string contains only uppercase
*/

int my_strlen(char const *);

int my_str_isupper(char const *str)
{
    int ok = 1;
    int i = 0;

    for (; ok && i < my_strlen(str); i++) {
        if ('A' <= str[i] && str[i] <= 'Z')
            ok = 1;
        else
            ok = 0;
    }
    return ok;
}
