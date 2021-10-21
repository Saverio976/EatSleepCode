/*
** EPITECH PROJECT, 2021
** Libmy
** File description:
** reverse a string
*/

int my_strlen(char const *);

char *my_revstr(char *str)
{
    char tmp;
    int len = my_strlen(str) - 1;

    for (int i = 0; i <= len / 2; i++) {
        tmp = str[len - i];
        str[len - i] = str[i];
        str[i] = tmp;
    }
    return str;
}
