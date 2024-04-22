/*
** EPITECH PROJECT, 2022
** my_hunter
** File description:
** init_utilities.c
*/

#include "hunter.h"

int init_utilities(utilities_t *utilities)
{
    sfVideoMode mode = {1920, 1080, 120};

    utilities->window = sfRenderWindow_create(
        mode, "my hunter", sfResize | sfClose, NULL
    );
    if (!utilities->window)
        return 84;

    sfRenderWindow_setFramerateLimit(utilities->window, 30);
    utilities->rectangle.top = 0;
    utilities->rectangle.left = 0;
    utilities->rectangle.width = 110;
    utilities->rectangle.height = 110;

    utilities->tmp = 0;
    utilities->scoring = 0;
    utilities->is_bonus = 0;
    utilities->show = 0;
    utilities->life = 5;
    return 0;
}
