/*
** EPITECH PROJECT, 2022
** LIBMY
** File description:
** show word array with \n between
*/

#include <stddef.h>
#include "my_puts.h"

/**
 * @brief print each char * of the 2d array with a newline after each char *
 *
 * @param array
 */
void my_wordarray_showln(char *const *array)
{
    if (array == NULL) {
        return;
    }
    for (int i = 0; array[i] != NULL; i++) {
        my_putstr(array[i]);
        my_putchar('\n');
    }
}

/**
 * @brief print each char * of the 2d array
 *
 * @param array
 */
void my_wordarray_show(char *const *array)
{
    if (array == NULL) {
        return;
    }
    for (int i = 0; array[i] != NULL; i++) {
        my_putstr(array[i]);
    }
}
