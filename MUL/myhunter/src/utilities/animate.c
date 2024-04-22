/*
** EPITECH PROJECT, 2022
** my_hunter
** File description:
** animate.c
*/

#include "hunter.h"

void ducks_animate(utilities_t *utilities, sprite_t *sprite, vector_t *vector)
{
    sfSprite_setTextureRect(sprite->sprite, utilities->rectangle);
    sfSprite_setTextureRect(sprite->bonus, utilities->rectangle);
    sfSprite_setPosition(sprite->sprite, vector->move);
    sfSprite_setPosition(sprite->bonus, vector->bonus_move);
}
