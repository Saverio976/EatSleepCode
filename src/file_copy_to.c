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
    return (link(src, dest));
}
