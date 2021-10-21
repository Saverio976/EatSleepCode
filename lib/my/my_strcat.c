/*
** EPITECH PROJECT, 2021
** Libmy
** File description:
** concatenetes two strings
*/

int my_strlen(char const *);

char *my_strcat(char *dest, char const *src)
{
    int i;
    int len = my_strlen(dest);

    for (i = 0; i < my_strlen(src); i++)
        dest[len + i] = src[i];
    dest[len + i] = '\0';
    return dest;
}
