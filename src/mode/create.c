/*
** EPITECH PROJECT, 2022
** ESP
** File description:
** create mode_context_t
*/

#include <stdlib.h>
#include "my_puts.h"
#include "esp.h"

mode_context_t *mode_create(void)
{
    mode_context_t *mode = NULL;

    mode = malloc(sizeof(mode_context_t));
    if (mode == NULL) {
        my_printf("[EatSleepCode][error] mode_create bad malloc");
        return (NULL);
    }
    for (int i = 0; i < BUFF_INPUTS_SIZE; i++) {
        mode->inputs[i] = '\0';
    }
    mode->type = NORMAL;
    return (mode);
}
