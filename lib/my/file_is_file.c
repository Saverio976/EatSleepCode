/*
** EPITECH PROJECT, 2021
** Libmy
** File description:
** check if a file is a file
*/

#include <unistd.h>
#include <fcntl.h>

int file_is_file(char const *path)
{
    int fd = open(path, O_DIRECTORY);

    if (fd < 0)
        return (1);
    close(fd);
    return (0);
}
