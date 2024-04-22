/*
** EPITECH PROJECT, 2022
** bsq.h
** File description:
** bsq.h
*/

#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#ifndef _MY_BSQ
    #define _MY_BSQ

typedef struct find_sqr {
    int actual_square;
    int row;
    int col;
    int best_square;
    int best_col;
    int best_row;
    int i;
    int j;
    int exit;
}find_square_t;

int new_bsq(int ac, char **av);
int find_square(char **map, int col, int row);
void write_square(char **map, int best_square, int b_col, int b_row);
void show_map(char **map, int row);
int map_gen(char **av);
int check_map(char **av);
int check_map_char(char **map, int col, int row);

#endif
