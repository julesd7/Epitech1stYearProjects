/*
** EPITECH PROJECT, 2022
** my_hunter
** File description:
** init_sprite.c
*/

#include "hunter.h"

void init_sprite(sprite_t *sprite, texture_t texture, utilities_t utilities)
{
    sprite->back = sfSprite_create();
    sfSprite_setTexture(sprite->back, texture.back_screen, sfTrue);

    sprite->sprite = sfSprite_create();
    sfSprite_setTexture(sprite->sprite, texture.texture, sfTrue);
    sfSprite_setTextureRect(sprite->sprite, utilities.rectangle);

    sprite->bonus = sfSprite_create();
    sfSprite_setTexture(sprite->bonus, texture.texture_bonus, sfTrue);
    sfSprite_setTextureRect(sprite->bonus, utilities.rectangle);
}
