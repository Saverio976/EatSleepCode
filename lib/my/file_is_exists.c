/*
** EPITECH PROJECT, 2021
** Libmy
** File description:
** check if a file exists
*/

#include <errno.h>
#include <unistd.h>
#include <fcntl.h>

int file_is_exists(char const *path)
{
    int fd = open(path, O_RDONLY);

    if (fd < 0 && errno == ENOENT)
        return (0);
    close(fd);
    return (1);
}
