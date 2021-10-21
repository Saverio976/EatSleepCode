/*
** EPITECH PROJECT, 2021
** Libmy
** File description:
** copy src in dest with n char
*/

int my_strlen(char const *);

char *my_strncpy(char *dest, char const *src, int n)
{
    int i;
    int len = my_strlen(src);

    for (i = 0; i < n && i < len; i++)
        dest[i] = src[i];
    if (n > len)
        dest[i] = '\0';
    return dest;
}
