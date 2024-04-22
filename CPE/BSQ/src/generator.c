/*
** EPITECH PROJECT, 2022
** BSQ
** File description:
** map gen
*/

#include "my.h"
#include "bsq.h"

static int verify_patern(char *patern)
{
    for (int i = 0; patern[i] != '\0'; i++) {
        if (patern[i] != 'o' && patern[i] != '.')
            return 84;
    }
    return 0;
}

static char *write_patern(char *av, int patern_size)
{
    char *patern = malloc(sizeof(char) * (patern_size + 1));
    my_strcpy(patern, av);
    patern[patern_size + 1] = '\0';
    return patern;
}

static int is_patern_size(int count, int patern_size)
{
    if (count + 1 == patern_size)
        return 0;
    return count += 1;
}

int map_gen(char **av)
{
    int taille = my_getnbr(av[1]);
    int patern_size = my_strlen(av[2]);
    char *patern = write_patern(av[2], patern_size);
    int count = 0;
    if (!taille || av[1][0] == '-' || verify_patern(patern) == 84)
        return 84;

    char **map = malloc(sizeof(char *) * (taille + 1));
    for (int i = 0; i < taille; i++) {
        map[i] = malloc(sizeof(char *) * (taille + 2));
    }
    for (int row = 0; row < taille; row++) {
        for (int col = 0; col < taille; col++) {
            map[row][col] = patern[count];
            count = is_patern_size(count, patern_size);
        }
        map[row][taille + 1] = '\n';
        map[row][taille + 2] = '\0';
    }
    return find_square(map, taille, taille);
}
