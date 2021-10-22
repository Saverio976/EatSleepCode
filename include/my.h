/*
** EPITECH PROJECT, 2021
** Libmy
** File description:
** the lib header
*/

#ifndef LIBMY_H_INCLUSION_
#define LIBMY_H_INCLUSION_

int my_putstr(char const *);

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

int my_arraylen(char **);

int open_readonly(char *);
int file_is_exists(char const *);
int file_is_readable(char const *);
int file_is_writable(char const *);

#endif //LIBMY_H_INCLUSION_
