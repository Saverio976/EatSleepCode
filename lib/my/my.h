/*
** EPITECH PROJECT, 2021
** Libmy
** File description:
** the lib header
*/

#ifndef LIBMY_H_INCLUSION_
#define LIBMY_H_INCLUSION_

int my_compute_power_rec(int, int);
int my_compute_square_root(int);
int my_find_prime_sup(int);
int my_getnbr(char const *);
int my_isneg(int);
int my_is_prime(int);
void my_sort_int_array(int *, int);
void my_swap(int *, int *);

void my_putchar(char c);
int my_putnbr_base(int, char const *);
int my_put_nbr(int);
int my_putstr(char const *);
int my_showmem(char const *, int);
int my_showstr(char const *);

char *my_revstr(char *);
char *my_strcapitalize(char *);
char *my_strcat(char *, char const *);
int my_strcmp(char const *, char const *);
char *my_strcpy(char *, char const *);
char *my_strdup(char const *);
int my_str_isalpha(char const *);
int my_str_islower(char const *);
int my_str_isnum(char const *);
int my_str_isprintable(char const *);
int my_str_isupper(char const *);
int my_strlen(char const *);
char *my_strlowcase(char *);
char *my_strncat(char *, char const *, int);
int my_strncmp(char const *, char const *, int);
char *my_strncpy(char *, char const *, int);
char *my_strstr(char *, char const *);
char *my_strupcase(char *);
char **my_str_to_word_array(char const *);

int open_readonly(char *);

#endif //LIBMY_H_INCLUSION_
