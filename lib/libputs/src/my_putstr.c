/*
** EPITECH PROJECT, 2021
** LIBMY
** File description:
** put str to stdout
*/

#include <unistd.h>
#include "my_strings.h"

/**
 * @brief write the \0 terminated str if str is not null
 *
 * @param str
 *
 * @return the number of char wrote
 */
int my_putstr(char const *str)
{
    int size = my_strlen(str);

    if (size == -1) {
        return (0);
    }
    return (write(1, str, size));
}
