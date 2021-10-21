/*
** Saverio976, 2021
** EatSleepCode
** File description:
** utilities functions
*/

#include "my.h"

char *sanitize_string(char *str)
{
    char tab[2] = {0};

    for (int i = 0; str[i] != '\0'; i++) {
        tab[0] = str[i];
        if (!my_str_isprintable(tab))
            str[i] = '?';
    }
    return str;
}
