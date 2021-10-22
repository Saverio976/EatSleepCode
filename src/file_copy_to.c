/*
** Saverio976, 2021
** EatSleepCode
** File description:
** copy the content of a file to another
*/

#include "my.h"
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

int copy_file_to(char const *dest, char const *src)
{
    int fd_src = open_readonly(src);
    int fd_dest;
    mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
    char buffer[30000] = {0};
    int nbyte = 30000;

    if (fd_src < 0)
        return (-84);
    fd_dest = open(dest, O_WRONLY | O_CREAT | O_EXCL, mode);
    if (fd_dest < 0)
        return (-84);
    while (nbyte == 30000) {
        nbyte = read(fd_src, buffer, 30000);
        write(fd_dest, buffer, nbyte);
    }
    return (0);
}
