/*
** EPITECH PROJECT, 2021
** task05
** File description:
** locate a substring
*/

static int my_strlen(char const *str)
{
    int i = 0;

    while (str[i])
        i++;
    return (i);
}

char *my_strstr(char *str, char const *to_find)
{
    int i;
    int j = 0;
    int occurence_find = 0;
    int len_str = my_strlen(str);
    int len_find = my_strlen(to_find);
    int len = len_str - len_find + 1;

    if (len_str < len_find)
        return (void *) 0;
    for (i = 0; !occurence_find && i < len; i++) {
        while (str[i + j] == to_find[j] && to_find[j] != '\0')
            j++;
        if (j == len_find)
            occurence_find = 1;
        j = 0;
    }
    if (occurence_find)
        return str + i - 1;
    else
        return (void *) 0;
}
