/*
** Saverio976, 2021
** EatSleepCode
** File description:
** eat_sleep_code called by main()
*/

int eat_sleep_code_interface(char *);

int eat_sleep_code(int ac, char **av)
{
    int result_code = 0;

    //result_code = check_args(ac, av);
    if (result_code == 84)
        return (84);
    if (ac < 2)
        result_code = eat_sleep_code_interface("");
    else
        result_code = eat_sleep_code_interface(av[1]);
    return (result_code);
}
