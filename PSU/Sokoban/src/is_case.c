/*
** EPITECH PROJECT, 2022
** sokoban.c
** File description:
** is_case.c
*/

#include "my_sokoban.h"

void get_stock_location(sokoban_t my_sb, loc_t *loc, int y)
{
    char temploc[100];
    int cases = 0;
    for (int x = 0; my_sb.col > x + 1; x++) {
        if (my_sb.map[y][x] == 'O') {
            my_strcat(loc->temp, my_itoa(x, temploc));
            my_strcat(loc->temp, "_");
            my_strcat(loc->temp, my_itoa(y, temploc));
            my_strcat(loc->temp, ":");
            cases++;
        }
    }
    loc->cases += cases;
    y++;
    if (y < my_sb.row)
        get_stock_location(my_sb, loc, y);
    loc->storage = malloc(sizeof(char) * (my_strlen(loc->temp) + 1));
    my_strcpy(loc->storage, loc->temp);
}

static int win_condition(sokoban_t *my_sb, loc_t loc)
{
    if (my_sb->map[loc.ytemp][loc.xtemp] == 'X')
        return 0;
    else
        return 1;
}

static int is_two_int(loc_t *loc, int i, int j, int key)
{
    if (loc->storage[j + 1] != '_' && key == 0)
        loc->xtemp *= 10;
    if (loc->storage[j + 1] != ':' && key == 1)
        loc->ytemp *= 10;
    return i += 1;
}

void check_condition(sokoban_t *my_sb, loc_t *loc, int cases)
{
    int count = 0;
    for (int i = 0; i < my_strlen(loc->storage); i++) {
        loc->ytemp = 0;
        loc->xtemp = 0;
        for (int j = i; loc->storage[j] != '_'; j++) {
            loc->xtemp += loc->storage[j] - 48;
            i = is_two_int(loc, i, j, 0);
        }
        i++;
        for (int j = i; loc->storage[j] != ':'; j++) {
            loc->ytemp += loc->storage[j] - 48;
            i = is_two_int(loc, i, j, 1);
        }
        if (my_sb->map[loc->ytemp][loc->xtemp] == ' ')
            my_sb->map[loc->ytemp][loc->xtemp] = 'O';
        if (win_condition(my_sb, *(loc)) == 0)
            count++;
        if (count == cases)
            my_sb->is_win = 1;
    }
}
