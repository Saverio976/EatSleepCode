/*
** Saverio976, 2021
** EatSleepCode
** File description:
** the main function
*/

#include "my.h"
int eat_sleep_code(int, char **);

int main(int ac, char **av)
{
    int result_code;
    file_is_writable("test.txt");
    result_code = eat_sleep_code(ac, av);
    return (result_code);
}
