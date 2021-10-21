/*
** EPITECH PROJECT, 2021
** Libmy
** File description:
** copy in dest the src
*/

int my_strlen(char const *);

char *my_strcpy(char *dest, char const *src)
{
    int i;
    int len = my_strlen(src);

    for (i = 0; i < len; i++)
        dest[i] = src[i];
    dest[i] = '\0';
    return dest;
}
