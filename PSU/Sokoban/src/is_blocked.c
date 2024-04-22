/*
** EPITECH PROJECT, 2022
** sokoban.c
** File description:
** is_blocked.c
*/

#include "my_sokoban.h"

void is_blocked_up(loc_t *loc, sokoban_t *my_sb)
{
    if (
        my_sb->map[loc->p_loc_y - 1][loc->p_loc_x] == 'X' &&
        my_sb->vmap[loc->p_loc_y - 1][loc->p_loc_x] != 'O' &&
        my_sb->map[loc->p_loc_y - 2][loc->p_loc_x] == '#' &&
        (my_sb->map[loc->p_loc_y - 1][loc->p_loc_x + 1] == '#' ||
        my_sb->map[loc->p_loc_y - 1][loc->p_loc_x - 1] == '#')
        ) {
        my_sb->is_blocked = 1;
    }
}

void is_blocked_down(loc_t *loc, sokoban_t *my_sb)
{
    if (
        my_sb->map[loc->p_loc_y + 1][loc->p_loc_x] == 'X' &&
        my_sb->vmap[loc->p_loc_y + 1][loc->p_loc_x] != 'O' &&
        my_sb->map[loc->p_loc_y + 2][loc->p_loc_x] == '#' &&
        (my_sb->map[loc->p_loc_y + 1][loc->p_loc_x + 1] == '#' ||
        my_sb->map[loc->p_loc_y + 1][loc->p_loc_x - 1] == '#')
        ) {
        my_sb->is_blocked = 1;
    }
}

void is_blocked_left(loc_t *loc, sokoban_t *my_sb)
{
    if (
        my_sb->map[loc->p_loc_y][loc->p_loc_x - 1] == 'X' &&
        my_sb->vmap[loc->p_loc_y][loc->p_loc_x - 1] != 'O' &&
        my_sb->map[loc->p_loc_y][loc->p_loc_x - 2] == '#' &&
        (my_sb->map[loc->p_loc_y + 1][loc->p_loc_x - 1] == '#' ||
        my_sb->map[loc->p_loc_y - 1][loc->p_loc_x - 1] == '#')
        ) {
        my_sb->is_blocked = 1;
    }
}

void is_blocked_right(loc_t *loc, sokoban_t *my_sb)
{
    if (
        my_sb->map[loc->p_loc_y][loc->p_loc_x + 1] == 'X' &&
        my_sb->vmap[loc->p_loc_y][loc->p_loc_x + 1] != 'O' &&
        my_sb->map[loc->p_loc_y][loc->p_loc_x + 2] == '#' &&
        (my_sb->map[loc->p_loc_y + 1][loc->p_loc_x + 1] == '#' ||
        my_sb->map[loc->p_loc_y - 1][loc->p_loc_x + 1] == '#')
        ) {
        my_sb->is_blocked = 1;
    }
}
