/*
** EPITECH PROJECT, 2022
** my sokoban
** File description:
** get map
*/

#include "my_sokoban.h"

static struct stat st;

static char **create_map(char **vmap, char *buffer, int row, int col)
{
    int k = 0;
    for (int i = 0;  i < row ; i++) {
        for (int j = 0; j < col; j++) {
            vmap[i][j] = buffer[k];
            k++;
        }
        k++;
    }
    return vmap;
}

void get_verif_map(sokoban_t *my_sb, char **av)
{
    char *filepath = av[1];
    my_sb->vbuffer = malloc(sizeof(char) * (my_sb->size + 1));
    my_sb->fd = open(filepath, O_RDONLY);
    my_sb->fd = read(my_sb->fd, my_sb->vbuffer, my_sb->size);
    my_sb->vmap = malloc(sizeof(char *) * (my_sb->row + 1));
    for (int i = 0; i < my_sb->row ; i++)
        my_sb->vmap[i] = malloc(sizeof(char *) * (my_sb->col + 1));
    my_sb->vmap = create_map(my_sb->vmap, my_sb->vbuffer,
    my_sb->row, my_sb->col);
    close(my_sb->fd);
}
