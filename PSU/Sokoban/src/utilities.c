/*
** EPITECH PROJECT, 2022
** sokoban.c
** File description:
** utilities.c
*/

#include "my_sokoban.h"

void cheking_conditions(sokoban_t my_sb)
{
    if (my_sb.is_win == 1) {
        write_map(my_sb);
        refresh();
        exit(0);
    }
    if (my_sb.is_blocked == 1) {
        write_map(my_sb);
        refresh();
        exit(84);
    }
}

void write_map(sokoban_t my_sb)
{
    clear();
    for (int row = 0; row < my_sb.row; row += 1)
        mvprintw(row, 0, "%s", my_sb.map[row]);
}
