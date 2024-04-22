/*
** EPITECH PROJECT, 2022
** my_hunter
** File description:
** init_vector.c
*/

#include "hunter.h"

void init_vector(vector_t *vector)
{
    vector->move.x = -110;
    vector->move.y = 50;

    vector->bonus_move.x = -110;
    vector->bonus_move.y = (rand() % (750 - 0 + 1)) + 0;

    vector->score_place.x = 175;
    vector->score_place.y = 2;

    vector->life_text_p.x = 1750;
    vector->life_text_p.y = 0;

    vector->life_count_p.x = 1875;
    vector->life_count_p.y = 2;
}
