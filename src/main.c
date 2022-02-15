/*
** EPITECH PROJECT, 2021
** EatSleepCode
** File description:
** the main entry point for the project
*/

#include "my_dico.h"
#include "my_puts.h"
#include "esp.h"

int main(int ac, char **av)
{
    dico_t *args = NULL;
    window_t *window = NULL;

    args = argparse(ac, av);
    if (args == NULL) {
        return (84);
    }
    my_printf("okici\n");
    window = create_window(args, 1920, 1080);
    if (window == NULL) {
        dico_t_destroy(args);
        return (84);
    }
    my_printf("iciok\n");
    window_loop(window, args);
    destroy_window(window);
    return (0);
}
