/*
** EPITECH PROJECT, 2023
** navy
** File description:
** print map
*/

#include "navy.h"

static void print(navy_t *navy, int code)
{
    my_putstr(" |A B C D E F G H\n");
    my_putstr("-+---------------\n");
    for (int i = 1; i <= 8; i++) {
        my_putchar(i + '0');
        my_putchar('|');
        if (code == 1)
            my_putstr(navy->enemy_map[i]);
        else
            my_putstr(navy->my_map[i]);
        my_putchar('\n');
    }
}

void print_map(navy_t *navy)
{
    my_putstr("my positions\n");
    print(navy, 0);
    my_putstr("\nenemy positions\n");
    print(navy, 1);
    my_putchar('\n');
}
