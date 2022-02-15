/*
** EPITECH PROJECT, 2022
** ESP
** File description:
** parse cmdline args
*/

#include <stdlib.h>
#include "my_strings.h"
#include "my_dico.h"

dico_t *argparse(int ac, char **av)
{
    dico_t *args = NULL;

    for (int i = 1; i < ac; i++) {
        if (my_strlen(av[i]) > 2 && my_strstartswith(av[i], "--") == 1 &&
                (i + 1 < ac)) {
            args = dico_t_add_data(args, av[i] + 2, my_strdup(av[i + 1]),
                &free);
            i++;
        }
    }
    return (args);
}
