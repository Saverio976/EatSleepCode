/*
** EPITECH PROJECT, 2021
** Libmy
** File description:
** check if a file is readable (perms)
*/

#include <errno.h>
#include <unistd.h>
#include <fcntl.h>

int file_is_readable(char const *path)
{
    int fd = open(path, O_RDONLY);

    if (fd < 0 && errno == EACCES)
        return (0);
    close(fd);
    return (1);
}
