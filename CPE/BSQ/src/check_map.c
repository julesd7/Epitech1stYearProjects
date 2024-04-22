/*
** EPITECH PROJECT, 2022
** BSQ
** File description:
** check_map
*/

#include "bsq.h"
#include "my.h"

static struct stat st;

int check_map(char **av)
{
    char *filepath = av[1];
    stat(filepath, &st);
    int size = st.st_size;

    char *buffer = malloc(sizeof(char) * (size + 1));
    int fd = open(filepath, O_RDONLY);
    if (fd == -1)
        return 84;
    int rd = read(fd, buffer, size);
    if (rd == 0)
        return 84;
    return 0;
}

static int check_inside(char **map, int y, int x)
{
    int i = 0;
    if (map[y][x] != 'o' && map[y][x] != '.')
        i = 1;
    return i;
}

static int check_x(char **map, int row, int col)
{
    int i = 0;
    for (int y = 0; y < row; y++) {
        if (map[y][col + 1] != '\0')
            i++;
    }
    return i;
}

int check_map_char(char **map, int col, int row)
{
    int i = 0;
    for (int y = 0; y < row; y++) {
        for (int x = 0; x < col; x++) {
            i += check_inside(map, y, x);
        }
    }
    i += check_x(map, row, col);
    if (i != 0)
        return 84;
    return 0;
}
