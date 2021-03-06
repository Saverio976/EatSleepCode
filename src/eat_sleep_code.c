/*
** Saverio976, 2021
** EatSleepCode
** File description:
** eat_sleep_code called by main()
*/

#include "my.h"
#include "eatsleepcode.h"

int eat_sleep_code(int ac, char **av)
{
    int result_code = 0;
    char swap[100];

    //result_code = check_args(ac, av);
    if (result_code == 84)
        return (84);
    if (ac < 2)
        result_code = eat_sleep_code_interface("README.md", "README.md");
    else {
        if (!file_is_file(av[1]))
            return write_file_error(av[1], ": Is not a file\n");
        my_strcpy(swap, av[1]);
        my_strcat(swap, ".esc.");
        if (file_is_exists(av[1]))
            copy_file_to(swap, av[1]);
        else
            file_create(swap);
        result_code = eat_sleep_code_interface(swap, av[1]);
    }
    return (result_code);
}
