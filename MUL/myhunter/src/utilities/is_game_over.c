/*
** EPITECH PROJECT, 2022
** my_hunter
** File description:
** is_game_over.c
*/

#include "hunter.h"

void is_game_over(utilities_t *utilities)
{
    if (utilities->life == 0) {
        sfRenderWindow_close(utilities->window);
    }
}
