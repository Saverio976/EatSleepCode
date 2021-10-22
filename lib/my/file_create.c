/*
** EPITECH PROJECT, 2021
** Libmy
** File description:
** create a file with `-rw-r--r--`
*/

#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

int file_create(char const *path)
{
    mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
    int fd = open(path, O_RDONLY | O_CREAT, mode);

    if (fd < 0)
        return (-84);
    close(fd);
    return (0);
}
