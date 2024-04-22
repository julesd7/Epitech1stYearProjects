/*
** EPITECH PROJECT, 2022
** sokoban.c
** File description:
** is_square.c
*/

#include "my_sokoban.h"

int is_cross_up(loc_t *loc, sokoban_t *my_sb)
{
    if (
        my_sb->map[loc->p_loc_y - 1][loc->p_loc_x] == 'X' &&
        my_sb->map[loc->p_loc_y - 2][loc->p_loc_x] != '#' &&
        my_sb->map[loc->p_loc_y - 2][loc->p_loc_x] != 'X'
        ) {
        my_sb->map[loc->p_loc_y - 1][loc->p_loc_x] = ' ';
        my_sb->map[loc->p_loc_y - 2][loc->p_loc_x] = 'X';
        move_up(loc, my_sb);
        return IS_CROSS;
    }
    if (my_sb->map[loc->p_loc_y - 1][loc->p_loc_x] == 'X')
        return IS_END_CROSS;
    return IS_NO_CROSS;
}

int is_cross_down(loc_t *loc, sokoban_t *my_sb)
{
    if (
        my_sb->map[loc->p_loc_y + 1][loc->p_loc_x] == 'X' &&
        my_sb->map[loc->p_loc_y + 2][loc->p_loc_x] != '#' &&
        my_sb->map[loc->p_loc_y + 2][loc->p_loc_x] != 'X'
        ) {
        my_sb->map[loc->p_loc_y + 1][loc->p_loc_x] = ' ';
        my_sb->map[loc->p_loc_y + 2][loc->p_loc_x] = 'X';
        move_down(loc, my_sb);
        return IS_CROSS;
    }
    if (my_sb->map[loc->p_loc_y + 1][loc->p_loc_x] == 'X')
        return IS_END_CROSS;
    return IS_NO_CROSS;
}

int is_cross_left(loc_t *loc, sokoban_t *my_sb)
{
    if (
        my_sb->map[loc->p_loc_y][loc->p_loc_x - 1] == 'X' &&
        my_sb->map[loc->p_loc_y][loc->p_loc_x - 2] != '#' &&
        my_sb->map[loc->p_loc_y][loc->p_loc_x - 2] != 'X'
        ) {
        my_sb->map[loc->p_loc_y][loc->p_loc_x - 1] = ' ';
        my_sb->map[loc->p_loc_y][loc->p_loc_x - 2] = 'X';
        move_left(loc, my_sb);
        return IS_CROSS;
    }
    if (my_sb->map[loc->p_loc_y][loc->p_loc_x - 1] == 'X')
        return IS_END_CROSS;
    return IS_NO_CROSS;
}

int is_cross_right(loc_t *loc, sokoban_t *my_sb)
{
    if (
        my_sb->map[loc->p_loc_y][loc->p_loc_x + 1] == 'X' &&
        my_sb->map[loc->p_loc_y][loc->p_loc_x + 2] != '#' &&
        my_sb->map[loc->p_loc_y][loc->p_loc_x + 2] != 'X'
        ) {
        my_sb->map[loc->p_loc_y][loc->p_loc_x + 1] = ' ';
        my_sb->map[loc->p_loc_y][loc->p_loc_x + 2] = 'X';
        move_right(loc, my_sb);
        return IS_CROSS;
    }
    if (my_sb->map[loc->p_loc_y][loc->p_loc_x + 1] == 'X')
        return IS_END_CROSS;
    return IS_NO_CROSS;
}
