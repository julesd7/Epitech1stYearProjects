/*
** EPITECH PROJECT, 2022
** my sokoban
** File description:
** my_sokoban.h
*/

#include <ncurses.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "my.h"
#include "loc.h"

typedef struct my_sokoban {
    int fd;
    int key;
    char *buffer;
    char **map;
    int row;
    int col;
    int size;
    int is_win;
    int is_blocked;
    char *vbuffer;
    char **vmap;
}sokoban_t;


#ifndef _MY_SOKOBAN_H
    #define _MY_SOKOBAN_H

    #define IS_CROSS 3
    #define IS_NO_CROSS 0
    #define IS_END_CROSS 1

void get_map(sokoban_t *my_sb, int ac, char **av);
void get_verif_map(sokoban_t *my_sb, char **av);
void move_up(loc_t *loc, sokoban_t *my_sb);
void move_down(loc_t *loc, sokoban_t *my_sb);
void move_left(loc_t *loc, sokoban_t *my_sb);
void move_right(loc_t *loc, sokoban_t *my_sb);
int is_cross_up(loc_t *loc, sokoban_t *my_sb);
int is_cross_down(loc_t *loc, sokoban_t *my_sb);
int is_cross_left(loc_t *loc, sokoban_t *my_sb);
int is_cross_right(loc_t *loc, sokoban_t *my_sb);
void is_blocked_up(loc_t *loc, sokoban_t *my_sb);
void is_blocked_down(loc_t *loc, sokoban_t *my_sb);
void is_blocked_left(loc_t *loc, sokoban_t *my_sb);
void is_blocked_right(loc_t *loc, sokoban_t *my_sb);
void get_stock_location(sokoban_t my_sb, loc_t *loc, int y);
void check_condition(sokoban_t *my_sb, loc_t *loc, int cases);
void write_map(sokoban_t my_sb);
void cheking_conditions(sokoban_t my_sb);
void init(sokoban_t *my_sb, loc_t *loc, char **av, int ac);
void key_event(loc_t *loc, sokoban_t *my_sb);
void error_handling(int ac, char **av);


#endif
