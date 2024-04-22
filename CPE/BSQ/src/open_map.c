/*
** EPITECH PROJECT, 2022
** B-CPE-110-PAR-1-2-bsbsq-jules.dufraiche
** File description:
** bootstrap
*/

#include <stdio.h>

#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


#include "my.h"
#include "bsq.h"

static struct stat st;

static int get_size(char *filepath, char *buffer)
{
    int size = 0;

    for (int i = 0; buffer[i] != '\n'; i++)
        size++;
    return size;
}

static int get_line_size(char *buffer)
{
    int size = 0;

    for (int i = 0; buffer[i] != '\n'; i++)
        size++;
    return size;
}

static void create_map(char **map, char *buffer, int row, int col)
{
    int k = 0;
    for (int i = 0;  i < row ; i++) {
        for (int j = 0; j < col; j++) {
            map[i][j] = buffer[k];
            k++;
        }
        k++;
    }
}

int new_bsq(int ac, char **av)
{
    char *filepath = av[1];
    stat(filepath, &st);
    int size = st.st_size;

    char *buffer = malloc(sizeof(char) * (size + 1));
    int fd = open(filepath, O_RDONLY);
    fd = read(fd, buffer, size);
    int row = my_getnbr(buffer);
    int size_to_cut = get_size(filepath, buffer);
    my_strncpy(buffer - (size_to_cut + 1), buffer, size + (size_to_cut + 1));
    int col = get_line_size(buffer);
    char **map = malloc(sizeof(char *) * (row + 1));
    for (int i = 0; i < row ; i++)
        map[i] = malloc(sizeof(char *) * (col + 1));
    create_map(map, buffer, row, col);
    close(fd);
    if (check_map_char(map, col, row) == 84)
        return 84;
    find_square(map, col, row);
    return 0;
}
