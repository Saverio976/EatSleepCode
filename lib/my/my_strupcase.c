/*
** EPITECH PROJECT, 2021
** Libmy
** File description:
** up case all letter
*/

int my_strlen(char const *);

char *my_strupcase(char *str)
{
    for (int i = 0; i < my_strlen(str); i++)
        if ('a' <= str[i] && str[i] <= 'z')
            str[i] = str[i] - 32;
    return str;
}
