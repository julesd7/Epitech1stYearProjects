/*
** EPITECH PROJECT, 2022
** sokoban.c
** File description:
** init.c
*/

#include "my_sokoban.h"

static int get_actual_place(sokoban_t my_sb, loc_t *loc, int y)
{
    for (int col = 0; my_sb.col > col + 1; col++) {
        if (my_sb.map[y][col] == 'P') {
            loc->p_loc_x = col;
            loc->p_loc_y = y;
            return 0;
        }
    }
    y++;
    if (y < my_sb.row)
        get_actual_place(my_sb, loc, y);
    else
        exit(EXIT_FAILURE);
}

void init(sokoban_t *my_sb, loc_t *loc, char **av, int ac)
{
    get_map(my_sb, ac, av);
    get_verif_map(my_sb, av);
    get_actual_place(*(my_sb), loc, 0);
    loc->cases = 0;
    get_stock_location(*(my_sb), loc, 0);
    initscr();
    noecho();
    keypad(stdscr, TRUE);
    refresh();
}
