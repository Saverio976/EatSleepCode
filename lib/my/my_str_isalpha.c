/*
** EPITECH PROJECT, 2021
** Libmy
** File description:
** check if a string contains only alpha
*/

int my_strlen(char const *);

int my_str_isalpha(char const *str)
{
    int ok = 1;
    int i = 0;

    for (; ok && i < my_strlen(str); i++) {
        if ('a' <= str[i] && str[i] <= 'z')
            ok = 1;
        else if ('A' <= str[i] && str[i] <= 'Z')
            ok = 1;
        else
            ok = 0;
    }
    return ok;
}
