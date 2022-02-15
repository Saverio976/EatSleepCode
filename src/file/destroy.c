/*
** EPITECH PROJECT, 2022
** ESP
** File description:
** destroy file_edit
*/

#include <stdlib.h>
#include "my_list.h"
#include "esp.h"

void file_edit_t_destroy(file_edit_t *file)
{
    if (file->pathfile) {
        free(file->pathfile);
    }
    if (file->list_line) {
        list_t_destroy(file->list_line);
    }
    free(file);
}
