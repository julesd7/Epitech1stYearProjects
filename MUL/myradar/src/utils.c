/*
** EPITECH PROJECT, 2023
** my_radar
** File description:
** utils.c
*/

#include "radar.h"

static int my_strlen(char const *str)
{
    int nbcount = 0;
    while (str[nbcount] != '\0') {
        nbcount++;
    }
    return (nbcount);
}

int my_putstr(char const *str)
{
    write(1, str, my_strlen(str));
    return 0;
}

void malloc_positions(plane_t *plane, tower_t *tower)
{
    plane->plane_number = plane->plane_c;
    tower->tower_number = tower->tower_c;
    tower->tower_pos = malloc(sizeof(int *) * (tower->tower_c * 3));
    plane->plane_pos = malloc(sizeof(int *) * (plane->plane_c * 6));
    tower->tower_c = 0;
    plane->plane_c = 0;
}
