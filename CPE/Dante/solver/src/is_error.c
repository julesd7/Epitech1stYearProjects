/*
** EPITECH PROJECT, 2023
** dante/solver
** File description:
** is_error.c
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#include "solver.h"

static struct stat st;

static bool check_inside_maze(char *maze, size_t size)
{
    for (int i = 0; i != size; i++) {
        if (maze[i] != 'X' && maze[i] != '*' && maze[i] != '\n')
            return true;
    }
    return false;
}

static bool check_maze(char *path)
{
    int fd;
    int rd;
    char *maze;
    size_t size;
    stat(path, &st);

    fd = open(path, O_RDONLY);
    if (fd != -1) {
        size = st.st_size;
        maze = malloc(sizeof(char) * (size));
    } else
        return true;
    rd = read(fd, maze, size);
    if (rd != -1 && check_inside_maze(maze, size) != true)
        free(maze);
    else
        return true;
    close(fd);
    return false;
}

bool is_error(int ac, char **av)
{
    if (
    ac != 2 ||
    check_maze(av[1]) == true
    )
        return true;
    return false;
}
