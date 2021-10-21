/*
** EPITECH PROJECT, 2021
** task04
** File description:
** take a string and do a string array
*/

#include <stddef.h>
#include <stdlib.h>
char *my_strdup(char const *);
int my_strlen(char const *);
char *my_strncpy(char *, char const *, int);

static int is_alpha(char c)
{
    if ((65 <= c && c <= 90) || (97 <= c && c <= 122))
        return (1);
    else if ('0' <= c && c <= '9')
        return (1);
    else
        return (0);
}

static int count_nb_word(char const *s)
{
    int result = 0;
    int in_word = (my_strlen(s) == 0) ? 0 : 1;;

    for (int i = 0; i < my_strlen(s); i++) {
        if (in_word && !is_alpha(s[i])) {
            in_word = 0;
            result++;
        } else if (!in_word) {
            in_word = 0;
        } else {
            in_word = 1;
        }
    }
    if (in_word)
        result++;
    return result;
}

static char *get_string_from(char const *str, int len)
{
    char *tab;

    tab = malloc(sizeof(char) * len);
    for (int i = 0; i < len; i++)
        tab[i] = str[i];
    tab[len] = '\0';
    return tab;
}

static int do_for_loop(char **result, char const *str, int *in_word, int *index)
{
    int len = 0;

    for (int i = 0; i < my_strlen(str); i++) {
        if (*in_word && !is_alpha(str[i])) {
            result[*index] = get_string_from(str + i - len, len);
            *in_word = 0;
            len = 0;
            (*index)++;
        } else if (!(*in_word) && !is_alpha(str[i])) {
            *in_word = 0;
            result[*index] = my_strdup("");
            (*index)++;
        } else {
            len++;
            *in_word = 1;
        }
    }
    return len;
}

char **my_str_to_word_array(char const *str)
{
    int len;
    int index = 0;
    int in_word;
    int nb_words;
    char **result;

    if (str == NULL)
        return NULL;
    nb_words = count_nb_word(str);
    result = malloc((sizeof(result) * nb_words) + 1);
    in_word = (my_strlen(str) == 0) ? 0 : 1;
    len = do_for_loop(result, str, &in_word, &index);
    if (in_word) {
        result[index] = get_string_from(str + my_strlen(str) - len, len);
        index++;
    }
    result[index] = NULL;
    return result;
}
