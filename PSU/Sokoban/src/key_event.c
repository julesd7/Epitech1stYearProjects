/*
** EPITECH PROJECT, 2022
** sokoban.c
** File description:
** key_event.c
*/

#include "my_sokoban.h"

static void check_keys_ud(loc_t *loc, sokoban_t *my_sb)
{
    if (my_sb->key == KEY_UP &&
    my_sb->map[loc->p_loc_y - 1][loc->p_loc_x] != '#') {
        if (is_cross_up(loc, my_sb) == IS_NO_CROSS)
            move_up(loc, my_sb);
        is_blocked_up(loc, my_sb);
    }
    if (my_sb->key == KEY_DOWN &&
    my_sb->map[loc->p_loc_y + 1][loc->p_loc_x] != '#') {
        if (is_cross_down(loc, my_sb) == IS_NO_CROSS)
            move_down(loc, my_sb);
        is_blocked_down(loc, my_sb);
    }
}

static void check_keys_lr(loc_t *loc, sokoban_t *my_sb)
{
    if (my_sb->key == KEY_LEFT &&
    my_sb->map[loc->p_loc_y][loc->p_loc_x - 1] != '#') {
        if (is_cross_left(loc, my_sb) == IS_NO_CROSS)
            move_left(loc, my_sb);
        is_blocked_left(loc, my_sb);
    }
    if (my_sb->key == KEY_RIGHT &&
    my_sb->map[loc->p_loc_y][loc->p_loc_x + 1] != '#') {
        if (is_cross_right(loc, my_sb) == IS_NO_CROSS)
            move_right(loc, my_sb);
        is_blocked_right(loc, my_sb);
    }
}

void key_event(loc_t *loc, sokoban_t *my_sb)
{
    check_keys_ud(loc, my_sb);
    check_keys_lr(loc, my_sb);
}
