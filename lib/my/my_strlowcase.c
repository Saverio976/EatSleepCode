/*
** EPITECH PROJECT, 2021
** Libmy
** File description:
** lower case all letter
*/

int my_strlen(char const *);

char *my_strlowcase(char *str)
{
    for (int i = 0; i < my_strlen(str); i++)
        if ('A' <= str[i] && str[i] <= 'Z')
            str[i] = str[i] + 32;
    return str;
}
