/*
** EPITECH PROJECT, 2022
** my_hunter
** File description:
** utilities_events.c
*/

#include "hunter.h"

void utilities_events(utilities_t *utilities, music_t *music)
{
    if (utilities->is_bonus == 10) {
        sfMusic_stop(music->bonus);
        sfMusic_play(music->bonus);
    }
    utilities->tmp += 1;
    utilities->is_bonus = (rand() % (555 - 0 + 1)) + 0;
    if (utilities->tmp >= 10) {
        utilities->rectangle.left += 110;
        utilities->tmp = 0;
    }
    if (utilities->rectangle.left == 330)
        utilities->rectangle.left = 0;
}
