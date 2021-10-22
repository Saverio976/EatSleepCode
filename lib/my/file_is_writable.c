/*
** EPITECH PROJECT, 2021
** Libmy
** File description:
** cehck if a file is writeable (perms)
*/

#include <errno.h>
#include <unistd.h>
#include <fcntl.h>

int file_is_writable(char const *path)
{
    int fd = open(path, O_WRONLY);

    if (fd < 0 && errno == EACCES)
        return (0);
    close(fd);
    return (1);
}
