/*
** EPITECH PROJECT, 2023
** navy
** File description:
** create_map
*/

#include <stdlib.h>
#include <fcntl.h>
#include <stddef.h>
#include <unistd.h>

#include "navy.h"

static int place_boat(navy_t *navy, boat_t boat)
{
    navy->my_map[boat.start_col][boat.start_row * 2] = boat.size + '0';
    navy->my_map[boat.end_col][boat.end_row * 2] = boat.size + '0';
    boat.col = boat.start_col;
    boat.row = boat.start_row;
    fill_boat(navy, boat);
}

static int check_pos(boat_t boat)
{
    if (boat.start_col > 8 || boat.start_col < 1 ||
    boat.end_col > 8 || boat.end_col < 1) {
        return EXIT_FAIL;
    }
    if (boat.start_row > 7 || boat.start_row < 0 ||
    boat.end_row > 7 || boat.end_row < 0) {
        return EXIT_FAIL;
    }
    return EXIT_SUCCESS;
}

static int fill_my_map(navy_t *navy)
{
    boat_t boat;

    for (int i = 0; i <= 28; i += 8) {
        boat.size = navy->buffer[i] - '0';
        boat.start_row = navy->buffer[i + 2] - 'A';
        boat.start_col = navy->buffer[i + 3] - '0';
        boat.end_row = navy->buffer[i + 5] - 'A';
        boat.end_col = navy->buffer[i + 6] - '0';
        if (check_pos(boat) == EXIT_FAIL)
            return EXIT_FAIL;
        place_boat(navy, boat);
    }
    return EXIT_SUCCESS;
}

static int create_map(navy_t *navy)
{
    navy->my_map = malloc(sizeof(char *) * 9);
    navy->enemy_map = malloc(sizeof(char *) * 9);
    for (int i = 0; i <= 8; i++) {
        navy->my_map[i] = malloc(sizeof(char *) * 16);
        navy->enemy_map[i] = malloc(sizeof(char *) * 16);
        my_strcpy(navy->my_map[i], ". . . . . . . .");
        my_strcpy(navy->enemy_map[i], ". . . . . . . .");
    }
    navy->my_map[9] = NULL;
    navy->enemy_map[9] = NULL;
    return fill_my_map(navy);
}

int open_pos(navy_t *navy, char *filepath)
{
    navy->size = 32;

    navy->buffer = malloc(sizeof(char) * (navy->size + 1));
    navy->fd = open(filepath, O_RDONLY);
    navy->rd = read(navy->fd, navy->buffer, navy->size);
    if (navy->fd == OPEN_ERROR || navy->rd == READ_ERROR)
        return EXIT_FAIL;
    return create_map(navy);
}
