/*
** EPITECH PROJECT, 2021
** Libmy
** File description:
** write n byte to dest$
*/

int my_strlen(char const *);

char *my_strncat(char *dest, char const *src, int nb)
{
    int i;
    int len = my_strlen(dest);

    for (i = 0; i < nb && src[i] != '\0'; i++)
        dest[len + i] = src[i];
    dest[len + i] = '\0';
    return dest;
}
