/*
** EPITECH PROJECT, 2022
** count island
** File description:
** count island
*/

int verify_island(char** world, int *isl, int line, int i)
{
    world[line][i] = *isl + '0';
    if (world[line + 1] != '\0' && world[line + 1][i] == 'X') {
        verify_island(world, isl, line + 1, i);
    }
    if (line - 1 >= 0 && world[line - 1][i] == 'X') {
        verify_island(world, isl, line - 1, i);
    }
    if (i - 1 >= 0 && world[line][i - 1] == 'X') {
        verify_island(world, isl, line, i - 1);
    }
    if (world[line][i + 1] == 'X') {
        verify_island(world, isl, line, i + 1);
    }
}

int verify_line(char** world, int line, int *isl)
{
    int i = 0;
    while (world[line][i] != '\0') {
        if (world[line][i] == 'X') {
            verify_island(world, isl, line, i);
            (*isl)++;
        }
        i++;
    }
}

int count_island(char** world)
{
    int i = 0;
    int line = 0;
    int isl = 0;
    while (world[line] != '\0') {
        verify_line(world, line, &isl);
        i++;
        line++;
    }
    return isl + 1;
}
