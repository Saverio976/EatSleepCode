/*
** EPITECH PROJECT, 2021
** Libmy
** File description:
** capitalize all first letter of words
*/

int my_strlen(char const *);

static int check_if_digit_or_alpha(char c)
{
    int ok = 0;

    if (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z'))
        ok = 1;
    if ('0' <= c && c <= '9')
        ok = 1;
    return ok;
}

static void do_upper(char *str, int i)
{
    if ('a' <= str[i] && str[i] <= 'z')
        str[i] = str[i] - 32;
}

static void do_lower(char *str, int i)
{
    if ('A' <= str[i] && str[i] <= 'Z')
        str[i] = str[i] + 32;
}

static void do_logic_with(char *str, int i)
{
    if (i == 0)
        do_upper(str, i);
    if (check_if_digit_or_alpha(str[i + 1]))
        do_lower(str, i + 1);
    if (!(check_if_digit_or_alpha(str[i])))
        if (check_if_digit_or_alpha(str[i + 1]))
            do_upper(str, i + 1);
}

char *my_strcapitalize(char *str)
{
    for (int i = 0; i < my_strlen(str) - 1; i++) {
        do_logic_with(str, i);
    }
    return str;
}
