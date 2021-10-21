/*
** EPITECH PROJECT, 2021
** Libmy
** File description:
** sort array of length n
*/

static int do_condition(int *tab, int min, int j)
{
    if (tab[min] > tab[j])
        return j;
    else
        return min;
}

void my_sort_int_array(int *tab, int size)
{
    int min;
    int tmp;

    for (int i = 0; i < size; i++) {
        min = i;
        for (int j = i; j < size; j++)
            min = do_condition(tab, min, j);
        tmp = tab[min];
        tab[min] = tab[i];
        tab[i] = tmp;
    }
}
