/*
** Saverio976, 2021
** EatSleepCode
** File description:
** read and return text from file
*/

#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>
#include "my.h"

static void add_to_counter(char c, int *counter)
{
    if (c == '\n')
        (*counter)++;
}

static int get_number_line(char const *path)
{
    int fd = open_readonly(path);
    int nbyte = 30000;
    int counter = 0;
    char buffer[30000];

    if (fd < 0)
        return (-84);
    while (nbyte == 30000) {
        nbyte = read(fd, buffer, 30000);
        for (int i = 0; i < nbyte; i++)
            add_to_counter(buffer[i], &counter);
    }
    close(fd);
    return (counter);
}

static void do_for_loop(char buffer[30000], int nbyte, char **tab)
{
    int len = 0;
    int index = 0;
    char *cursor = buffer;
    char *str;
    
    for (int i = 0; i < nbyte; i++) {
        if (buffer[i] != '\n')
            len++;
        else {
            str = malloc(sizeof(char) * (len + 1));
            my_strncpy(str, cursor, len);
            str[len] = '\0';
            tab[index] = str;
            index++;
            cursor = buffer + i + 1;
            len = 0;
        }
    }
    tab[index] = NULL;
}

char **read_text(char const *path)
{
    int size_y = get_number_line(path);
    int fd;
    int nbyte = 30000;
    char buffer[30000];
    char **tab;
    
    if (size_y < 0)
        return NULL;
    fd = open_readonly(path);
    if (fd < 0)
        return NULL;
    tab = malloc(sizeof(char *) * (size_y + 1));
    if (!tab)
        return NULL;
    while (nbyte == 30000) {
        nbyte = read(fd, buffer, 30000);
        do_for_loop(buffer, nbyte, tab);
    }
    close(fd);
    return (tab);
}
