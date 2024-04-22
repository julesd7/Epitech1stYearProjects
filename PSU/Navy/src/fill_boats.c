/*
** EPITECH PROJECT, 2023
** navy
** File description:
** fill_boat
*/

#include "navy.h"

static void fill_size_3(navy_t *navy, boat_t boat)
{
    if (boat.start_col != boat.end_col) {
        if (boat.start_col + 2 == boat.end_col)
            navy->my_map[boat.col + 1][boat.row * 2] = boat.size + '0';
        else
            navy->my_map[boat.col - 1][boat.row * 2] = boat.size + '0';
    }
    if (boat.start_row != boat.end_row) {
        if (boat.start_row + 2 == boat.end_row)
            navy->my_map[boat.col][(boat.row + 1) * 2] = boat.size + '0';
        else
            navy->my_map[boat.col][(boat.row - 1) * 2] = boat.size + '0';
    }
}

static void fill_size_4(navy_t *navy, boat_t boat)
{
    if (boat.start_col != boat.end_col) {
        if (boat.start_col + 3 == boat.end_col) {
            navy->my_map[boat.col + 1][boat.row * 2] = boat.size + '0';
            navy->my_map[boat.col + 2][boat.row * 2] = boat.size + '0';
        } else {
            navy->my_map[boat.col - 1][boat.row * 2] = boat.size + '0';
            navy->my_map[boat.col - 2][boat.row * 2] = boat.size + '0';
        }
    }
    if (boat.start_row != boat.end_row) {
        if (boat.start_row + 3 == boat.end_row) {
            navy->my_map[boat.col][(boat.row + 1) * 2] = boat.size + '0';
            navy->my_map[boat.col][(boat.row + 2) * 2] = boat.size + '0';
        } else {
            navy->my_map[boat.col][(boat.row - 1) * 2] = boat.size + '0';
            navy->my_map[boat.col][(boat.row - 2) * 2] = boat.size + '0';
        }
    }
}

static void fill_row_size_5(navy_t *navy, boat_t boat)
{
    if (boat.start_row != boat.end_row) {
        if (boat.start_row + 4 == boat.end_row) {
            navy->my_map[boat.col][(boat.row + 1) * 2] = boat.size + '0';
            navy->my_map[boat.col][(boat.row + 2) * 2] = boat.size + '0';
            navy->my_map[boat.col][(boat.row + 3) * 2] = boat.size + '0';
        } else {
            navy->my_map[boat.col][(boat.row - 1) * 2] = boat.size + '0';
            navy->my_map[boat.col][(boat.row - 2) * 2] = boat.size + '0';
            navy->my_map[boat.col][(boat.row - 3) * 2] = boat.size + '0';
        }
    }
}

static void fill_col_size_5(navy_t *navy, boat_t boat)
{
    if (boat.start_col != boat.end_col) {
        if (boat.start_col + 4 == boat.end_col) {
            navy->my_map[boat.col][(boat.row + 1) * 2] = boat.size + '0';
            navy->my_map[boat.col][(boat.row + 2) * 2] = boat.size + '0';
            navy->my_map[boat.col][(boat.row + 3) * 2] = boat.size + '0';
        } else {
            navy->my_map[boat.col][(boat.row - 1) * 2] = boat.size + '0';
            navy->my_map[boat.col][(boat.row - 2) * 2] = boat.size + '0';
            navy->my_map[boat.col][(boat.row - 3) * 2] = boat.size + '0';
        }
    }
}

void fill_boat(navy_t *navy, boat_t boat)
{
    if (boat.size == 3)
        fill_size_3(navy, boat);
    if (boat.size == 4)
        fill_size_4(navy, boat);
    if (boat.size == 5) {
        fill_row_size_5(navy, boat);
        fill_col_size_5(navy, boat);
    }
}
