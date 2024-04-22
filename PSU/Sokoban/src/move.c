/*
** EPITECH PROJECT, 2022
** sokoban.c
** File description:
** move.c
*/

#include "my_sokoban.h"

void move_up(loc_t *loc, sokoban_t *my_sb)
{
    my_sb->map[loc->p_loc_y][loc->p_loc_x] = ' ';
    loc->p_loc_y -= 1;
    my_sb->map[loc->p_loc_y][loc->p_loc_x] = 'P';
}

void move_down(loc_t *loc, sokoban_t *my_sb)
{
    my_sb->map[loc->p_loc_y][loc->p_loc_x] = ' ';
    loc->p_loc_y += 1;
    my_sb->map[loc->p_loc_y][loc->p_loc_x] = 'P';
}

void move_left(loc_t *loc, sokoban_t *my_sb)
{
    my_sb->map[loc->p_loc_y][loc->p_loc_x] = ' ';
    loc->p_loc_x -= 1;
    my_sb->map[loc->p_loc_y][loc->p_loc_x] = 'P';
}

void move_right(loc_t *loc, sokoban_t *my_sb)
{
    my_sb->map[loc->p_loc_y][loc->p_loc_x] = ' ';
    loc->p_loc_x += 1;
    my_sb->map[loc->p_loc_y][loc->p_loc_x] = 'P';
}
