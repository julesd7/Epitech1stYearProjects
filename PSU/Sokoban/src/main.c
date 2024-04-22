/*
** EPITECH PROJECT, 2022
** my sokoban
** File description:
** main,c
*/

#include "my_sokoban.h"

int main(int ac, char **av)
{
    error_handling(ac, av);
    sokoban_t *my_sb;
    my_sb = NULL;
    my_sb = malloc(sizeof(my_sb));
    loc_t loc;
    init(my_sb, &loc, av, ac);
    while (1) {
        write_map(*(my_sb));
        my_sb->key = getch();
        if (my_sb->key == 32)
            return 0;
        key_event(&loc, my_sb);
        check_condition(my_sb, &loc, loc.cases);
        refresh();
        cheking_conditions(*(my_sb));
    }
    endwin();
    return 0;
}
