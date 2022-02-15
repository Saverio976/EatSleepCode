/*
** EPITECH PROJECT, 2021
** LIBFILE
** File description:
** return the nbyte of a file
*/

#include <sys/stat.h>

/**
 * @brief get size of the content of filepath (if stat can)
 *
 * @param path
 *
 * @return -1 if stat cant get size; the size else
 */
int fs_get_size(char const *path)
{
    struct stat info;
    int ret;

    ret = stat(path, &info);
    if (ret == -1)
        return (-1);
    return ((int) info.st_size);
}
