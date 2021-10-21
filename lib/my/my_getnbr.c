/*
** EPITECH PROJECT, 2021
** Libmy
** File description:
** get nbr from string
*/

int my_strlen(char const *);

static int is_in_array(char const *str, char c)
{
    int in_arr = 0;

    for (int i = 0; !in_arr && i < my_strlen(str); i++)
        if (str[i] == c)
            in_arr = 1;
    return in_arr;
}

static char const *go_to_number(char const *str)
{
    int i = 0;

    while (is_in_array("\t\n\f\r\v -+", str[i]) && str[i] != '\0')
        i++;
    if (i == 0)
        return str;
    else
        return str + i;
}

static int count_nb_minus(char const *str)
{
    int i = 0;
    int counter = 0;

    while (is_in_array("\t\n\f\r\v -+", str[i]) && str[i] != '\0') {
        i++;
        if (str[i] == '-')
            counter++;
    }
    return counter;
}

static int check_if_int(char const *str)
{
    int i = 0;
    int ok = 1;
    char const check[] = "2147483648";

    while (is_in_array("0123456789", str[i]))
        i++;
    if (i > 10 || i < 10)
        return (i < 10);
    for (int i = 0; ok && i < 10; i++)
        if (str[i] > check[i])
            ok = 0;
    return ok;
}

int my_getnbr(char const *str)
{
    char const *my_str = go_to_number(str);
    int result = 0;
    int i = 0;
    int nb_minus = count_nb_minus(str);

    if (!check_if_int(my_str))
        return (0);
    while (is_in_array("0123456789", my_str[i])) {
        result = (result * 10) - (my_str[i] - 48);
        i++;
    }
    if (!(nb_minus % 2) && result == -2147483648)
        return (0);
    if (!(nb_minus % 2))
        result = result * (-1);
    return result;
}
