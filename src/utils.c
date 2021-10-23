/*
** Saverio976, 2021
** EatSleepCode
** File description:
** utilities functions
*/

#include "my.h"
#include <unistd.h>
#include <stddef.h>

static const char *KEYWORDS[] = {"for", "if", "else", "while", "return", NULL};
static const char *TYPES[] = {"void", "char", "int", "long", 
                                "unsigned", "struct", "static", 
                                NULL};
static const char *PREPROCES[] = {"#define", "#ifdef", "#ifndef", "#include",
                                    "#endif", NULL};

char *sanitize_string(char *str)
{
    char tab[2] = {0};

    for (int i = 0; str[i] != '\0'; i++) {
        tab[0] = str[i];
        if (!my_str_isprintable(tab))
            str[i] = '?';
    }
    return str;
}

// return 0 if it is not a keyword, else, the length of the keyword;
int check_if_keyword(char *cursor)
{
    int ok = 0;

    for (int i = 0; !ok && KEYWORDS[i] != NULL; i++) {
        if (my_strncmp(cursor, KEYWORDS[i], my_strlen(KEYWORDS[i]) + 1) == 0)
            ok = my_strlen(KEYWORDS[i]);
    }
    return (ok);
}

// return 0 if it is not a type, else, the length of the type;
int check_if_type(char *cursor)
{
    int ok = 0;

    for (int i = 0; !ok && TYPES[i] != NULL; i++) {
        if (my_strncmp(cursor, TYPES[i], my_strlen(TYPES[i]) + 1) == 0)
            ok = my_strlen(TYPES[i]);
    }
    return (ok);
}

// return 0 if it is not a pre-processor-directiv, else, the length of the type;
int check_if_preprocess(char *cursor)
{
    int ok = 0;

    for (int i = 0; !ok && PREPROCES[i] != NULL; i++) {
        if (my_strncmp(cursor, PREPROCES[i], my_strlen(PREPROCES[i]) + 1) == 0)
            ok = my_strlen(PREPROCES[i]);
    }
    return (ok);
}

int write_file_error(char *file, char *msg)
{
    write(2, file, my_strlen(file));
    write(2, msg, my_strlen(msg));
    return (84);
}
