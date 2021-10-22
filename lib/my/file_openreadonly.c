/*
** EPITECH PROJECT, 2021
** Libmy
** File description:
** abstract basic open file read only
*/

#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <stddef.h>
#include <unistd.h>
int my_strlen(char const *);

static char const *ERROR_MSGS[] = {": Is a directory\n",
                            ": Permission denied\n",
                            ": Not possible to read STREAMS file\n",
                            ": Loop between files link\n",
                            ": All file process's file descriptor are used\n",
                            ": Maximum number of file open\n",
                            ": File too large\n",
                            NULL};
static int const ERROR_SIGNL[] = {EISDIR,
                            EACCES,
                            EIO,
                            ELOOP,
                            EMFILE,
                            ENFILE,
                            EOVERFLOW,
                            0};

static int write_file_error(char *file, char const *msg)
{
    char space[] = ": ";
    char newline = '\n';

    write(2, file, my_strlen(file));
    write(2, space, my_strlen(space));
    write(2, msg, my_strlen(msg));
    write(2, &newline, 1);
    return (84);
}

static int itter_on_error(int err, char *file)
{
    int i = 0;

    while (ERROR_MSGS[i] != NULL && ERROR_SIGNL[i] != err)
        i++;
    if (err == ERROR_SIGNL[i])
        write_file_error(file, ERROR_MSGS[i]);
    return (-84);
}

int open_readonly(char *file)
{
    int fd;

    fd = open(file, O_DIRECTORY);
    if (fd != -1) {
        close(fd);
        write_file_error(file, ": Is a directory\n");
        return (-84);
    } else if (fd < 0 && errno == ENOENT) {
        write_file_error(file, ": No such file or directory\n");
        return (-84);
    }
    fd = open(file, O_RDONLY);
    if (fd >= 0)
        return fd;
    return itter_on_error(errno, file);
}
