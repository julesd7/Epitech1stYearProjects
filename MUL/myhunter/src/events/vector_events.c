/*
** EPITECH PROJECT, 2022
** my_hunter
** File description:
** vector_event.c
*/

#include "hunter.h"

void vector_events(utilities_t *utilities, vector_t *vector, text_t *text)
{
    vector->move.x += 20;
    if (vector->move.x >= 1920) {
        utilities->life--;
        vector->move.x = -110;
        vector->move.y = (rand() % (750 - 0 + 1)) + 0;
        sfText_setString(text->life_count,
        itoa(utilities->life, utilities->temp_life));
    }
    if (vector->bonus_move.x >= 1920) {
        utilities->show = 0;
        vector->bonus_move.x = -110;
        vector->bonus_move.y = (rand() % (750 - 0 + 1)) + 0;
    }
}
