/*
** EPITECH PROJECT, 2022
** LIBLIST
** File description:
** add elem
*/

#include <stdlib.h>
#include <unistd.h>
#include "my_dico.h"

static int my_coppy(char dest[255], char const *src)
{
    int i = 0;

    if (src == NULL) {
        return (0);
    }
    for (; i < 254 && src[i] != '\0'; i++) {
        dest[i] = src[i];
    }
    dest[i] = '\0';
    return (1);
}

dico_t *dico_t_create(char const *key, void *value, void (*destroy)(void *data))
{
    dico_t *new;

    new = malloc(sizeof(dico_t));
    if (new == NULL) {
        return (NULL);
    }
    new->destroy = destroy;
    if (my_coppy(new->key, key) == 0) {
        write(2, "[libdico][error]: cannot create entry\n", 38);
        free(new);
        return (NULL);
    }
    new->value = value;
    new->last = new;
    new->next = new;
    return (new);
}

dico_t *dico_t_add_data(dico_t *dico, char const *key, void *value,
        void (*destroy)(void *data))
{
    dico_t *new;

    if (dico_t_get_elem(dico, key) != NULL) {
        write(2, "[libdico][error]: key already exists\n", 38);
        return (dico);
    }
    new = dico_t_create(key, value, destroy);
    if (new == NULL) {
        return (NULL);
    }
    if (dico == NULL) {
        return (new);
    }
    new->last = dico->last;
    new->next = dico;
    dico->last->next = new;
    dico->last = new;
    return (dico);
}

dico_t *dico_t_add_elem(dico_t *dico, dico_t *elem)
{
    if (elem == NULL) {
        return (dico);
    }
    if (dico == NULL) {
        return (elem);
    }
    if (dico_t_get_elem(dico, elem->key) != NULL) {
        write(2, "[libdico][error]: key already exists\n", 38);
        return (dico);
    }
    elem->last = dico->last;
    elem->next = dico;
    dico->last->next = elem;
    dico->last = elem;
    return (dico);
}
