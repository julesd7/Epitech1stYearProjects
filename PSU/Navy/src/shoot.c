/*
** EPITECH PROJECT, 2023
** navy
** File description:
** shoot.c
*/

#include "navy.h"

void is_my_missed(navy_t *navy, char row, char col)
{
    my_putchar(col);
    my_putchar(row);
    my_putstr(": missed\n\n");
    navy->enemy_map[row - '0'][(col - 'A') * 2] = 'o';
}

void is_my_hit(navy_t *navy, char row, char col)
{
    my_putchar(col);
    my_putchar(row);
    my_putstr(": hit\n\n");
    navy->enemy_map[row - '0'][(col - 'A') * 2] = 'x';
}

void is_he_missed(navy_t *navy, int pos)
{
    my_putchar(pos / 10 + 'A');
    my_putchar(pos % 10 + '0');
    my_putstr(": missed\n\n");
    navy->my_map[pos % 10][pos / 10 * 2] = 'o';
}

void is_he_hit(navy_t *navy, int pos)
{
    my_putchar(pos / 10 + 'A');
    my_putchar(pos % 10 + '0');
    my_putstr(": hit\n\n");
    navy->my_map[pos % 10][pos / 10 * 2] = 'x';
}
