/*
** EPITECH PROJECT, 2022
** LIBLIST
** File description:
** liblist header
*/

#ifndef LIB_LIST_H_
    #define LIB_LIST_H_

typedef struct list_t list_t;

struct list_t {
    list_t *next;
    list_t *last;
    void *data;
    void (*destroy)(void *data);
};

int list_t_len(list_t *list);

list_t *list_t_create(void *data, void (*destroy)(void *data));

list_t *list_t_add_data(list_t *list, void *data, void (*destroy)(void *data));

list_t *list_t_add_elem(list_t *list, list_t *elem);

void *list_t_pop_data(list_t *elem);

list_t *list_t_pop_elem(list_t *elem);

int list_t_rem(list_t *elem);

int list_t_destroy(list_t *list);

#endif
