/*
** EPITECH PROJECT, 2022
** my sokoban
** File description:
** get map
*/

#include "my_sokoban.h"

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

static char **create_map(char **map, char *buffer, int row, int col)
{
    int k = 0;
    for (int i = 0;  i < row ; i++) {
        for (int j = 0; j < col; j++) {
            map[i][j] = buffer[k];
            k++;
        }
        k++;
    }
    return map;
}

static int get_row_size(char *buffer)
{
    int size = 0;
    int nb = 0;
    for (int i = 0; buffer[i] != '\0'; i++) {
        if (buffer[i] == '\n')
            size++;
        nb++;
    }
    if (buffer[nb - 1] != '\n')
        size++;
    return size;
}

void get_map(sokoban_t *my_sb, int ac, char **av)
{
    char *filepath = av[1];
    stat(filepath, &st);
    my_sb->size = st.st_size;
    my_sb->buffer = malloc(sizeof(char) * (my_sb->size + 1));
    my_sb->fd = open(filepath, O_RDONLY);
    my_sb->fd = read(my_sb->fd, my_sb->buffer, my_sb->size);
    my_sb->row = get_row_size(my_sb->buffer);
    my_sb->col = get_line_size(my_sb->buffer);
    my_sb->map = malloc(sizeof(char *) * (my_sb->row + 1));
    for (int i = 0; i < my_sb->row ; i++)
        my_sb->map[i] = malloc(sizeof(char *) * (my_sb->col + 1));
    my_sb->map = create_map(my_sb->map, my_sb->buffer, my_sb->row, my_sb->col);
    close(my_sb->fd);
}
