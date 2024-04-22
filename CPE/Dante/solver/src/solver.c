/*
** EPITECH PROJECT, 2023
** dante/solver
** File description:
** solver.c
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <stdio.h>

#include "solver.h"

static struct stat st;

static char *open_maze(char *path)
{
    size_t size;
    char *maze;

    stat(path, &st);
    size = st.st_size;
    maze = malloc(sizeof(char) * (size + 1));

    read(open(path, O_RDONLY), maze, size);
    maze[size] = '\0';

    return maze;
}

static bool is_impossible(char *maze)
{
    if (
    maze[0] == '*' &&
    maze[strlen(maze) - 1] == '*' &&
    maze[0] != IMPOSSIBLE
    )
        return false;
    return true;
}

int solver(char *path)
{
    char *maze = open_maze(path);
    char *solved_maze = process(maze);

    if (is_impossible(solved_maze) == true)
        printf("no solution found");
    else
        printf("%s\n", solved_maze);
    free(solved_maze);
    return EXIT_SUCCESS;
}
