/*
** EPITECH PROJECT, 2023
** my_radar
** File description:
** get_info.c
*/

#include "radar.h"
#include <stdio.h>

static struct stat st;

static void get_plane_position(
    plane_t *plane, radar_t radar, int actual_plane, int actual_line)
{
    int i = actual_line + 2;
    int size = 0;
    int place = 0;
    int nb = 0;
    actual_plane *= 6;

    for (i; radar.buffer[i] != '\n' && radar.buffer[i] != '\0'; i++) {
        if (radar.buffer[i] != ' ') {
            nb *= 10;
            size++;
            nb += radar.buffer[i] - 48;
        } else {
            plane->plane_pos[actual_plane + place] = nb;
            nb = 0;
            place++;
        }
    }
    plane->plane_pos[actual_plane + place] = nb;
}

static void get_tower_position(
    tower_t *tower, radar_t radar, int actual_tower, int actual_line)
{
    int i = actual_line + 2;
    int size = 0;
    int place = 0;
    int nb = 0;
    actual_tower *= 3;

    for (i; radar.buffer[i] != '\n' && radar.buffer[i] != '\0'; i++) {
        if (radar.buffer[i] != ' ') {
            nb *= 10;
            size++;
            nb += radar.buffer[i] - 48;
        } else {
            tower->tower_pos[actual_tower + place] = nb;
            nb = 0;
            place++;
        }
    }
    tower->tower_pos[actual_tower + place] = nb;
}

static void get_utilities(plane_t *plane, tower_t *tower, radar_t radar)
{
    tower->tower_c = 0;
    plane->plane_c = 0;

    for (int i = 0; radar.buffer[i] != '\0'; i++) {
        if (radar.buffer[i] == 'T')
            tower->tower_c++;
        if (radar.buffer[i] == 'A')
            plane->plane_c++;
    }
    malloc_positions(plane, tower);
    for (int i = 0; radar.buffer[i] != '\0'; i++) {
        if (radar.buffer[i] == 'T') {
            get_tower_position(tower, radar, tower->tower_c, i);
            tower->tower_c++;
        }
        if (radar.buffer[i] == 'A') {
            get_plane_position(plane, radar, plane->plane_c, i);
            plane->plane_c++;
        }
    }
}

static int open_file(char *filepath, radar_t *radar)
{
    stat(filepath, &st);
    int size = st.st_size;
    int fd;
    int rd;

    radar->buffer = malloc(sizeof(char) * (size + 1));
    fd = open(filepath, O_RDONLY);
    if (fd == -1)
        return EXIT_ERROR;
    rd = read(fd, radar->buffer, size);
    if (rd == 0)
        return EXIT_ERROR;
    radar->buffer[size] = '\0';
    close(fd);
    return EXIT_SUCCESS;
}

int get_informations(int ac, char **av)
{
    plane_t plane;
    tower_t tower;
    radar_t radar;

    char *filepath = av[1];
    if (open_file(filepath, &radar) == EXIT_ERROR)
        return EXIT_ERROR;
    get_utilities(&plane, &tower, radar);
    return show_simulation(plane, tower, &radar);
}
