/*
** EPITECH PROJECT, 2021
** Libmy
** File description:
** compare two string
*/

int my_strlen(char const *);

int my_strcmp(char const *s1, char const *s2)
{
    int len_1 = my_strlen(s1);
    int len_2 = my_strlen(s2);
    int max = (len_1 < len_2) ? len_2 : len_1;
    char char_1;
    char char_2;
    int return_nb = 0;

    for (int i = 0; !return_nb && i < max; i++) {
        char_1 = (i < len_1) ? s1[i] : ' ';
        char_2 = (i < len_2) ? s2[i] : ' ';
        return_nb = char_1 - char_2;
    }
    return return_nb;
}
