/*
** EPITECH PROJECT, 2023
** my_radar
** File description:
** radar.h
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stddef.h>
#include <string.h>

#include "plane.h"
#include "tower.h"
#include "utils.h"

#ifndef _RADAR_H
    #define _RADAR_H

    #define EXIT_ERROR 84
    #define EXIT_SUCCESS 0

    typedef struct radar {
        char *buffer;
        int s_key;
        int l_key;
    }radar_t;

int get_informations(int ac, char **av);
void malloc_positions(plane_t *plane, tower_t *tower);
int show_simulation(plane_t plane, tower_t tower, radar_t *radar);
void show_tower(utils_t *utils, tower_t tower, radar_t radar);
void show_plane(utils_t *utils, plane_t plane, radar_t radar);
void key_change(utils_t *utils, radar_t *radar);
void poll_event(utils_t *utils);
int my_putstr(char const *str);

#endif /* !_RADAR_H */
