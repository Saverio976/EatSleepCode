/*
** EPITECH PROJECT, 2022
** ESP
** File description:
** get file object
*/

#include <stdlib.h>
#include "my_fs.h"
#include "my_strings.h"
#include "esp.h"

static char *get_only_file(char const *pathfile)
{
    int i = 0;
    int is_found = 0;
    char *file = NULL;

    i = my_strlen(pathfile) - 1;
    if (i < 1) {
        return (NULL);
    }
    for (; i >= 0 && is_found == 0; i--) {
        if (pathfile[i] == '/') {
            is_found = 1;
        }
    }
    i++;
    if (my_strlen(pathfile + i) > 254 || my_strlen(pathfile + i) < 2) {
        return (NULL);
    }
    file = my_strdup(pathfile + i);
    return (file);
}

static list_t *get_filelines(char const *pathfile)
{
    list_t *lines = NULL;
    char *content = NULL;
    int size = 0;
    char *buf = NULL;
    int lastnewline = 0;

    size = fs_get_size(pathfile);
    if (size < 0) {
        return (NULL);
    }
    content = fs_get_content(pathfile);
    for (int i = 0; content != NULL && i < size; i++) {
        if (content[i] == '\n') {
            buf = my_strdcut(content + lastnewline, i - lastnewline);
            lastnewline = i + 1;
            lines = list_t_add_data(lines, buf, free);
        }
    }
    return (lines);
}

static file_edit_t *fill_filedit(file_edit_t *file, char const *pathfile,
        char *filename)
{
    file->pathfile = my_strdup(pathfile);
    my_strcpy(file->filename, filename);
    free(filename);
    file->list_line = get_filelines(pathfile);
    file->curr_line = file->list_line;
    file->line_top = file->list_line;
    file->x = 0;
    file->y = 0;
    file->nb_lines = list_t_len(file->list_line);
    file->charactr_size = 20;
    return (file);
}

file_edit_t *getfile(char const *pathfile)
{
    file_edit_t *file = NULL;
    char *filename = NULL;

    if (pathfile == NULL) {
        return (NULL);
    }
    filename = get_only_file(pathfile);
    if (filename == NULL) {
        return (NULL);
    }
    file = malloc(sizeof(file_edit_t));
    if (file == NULL) {
        free(filename);
        return (NULL);
    }
    file = fill_filedit(file, pathfile, filename);
    return (file);
}
