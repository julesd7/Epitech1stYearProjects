/*
** EPITECH PROJECT, 2022
** my_hunter
** File description:
** init_texture.c
*/

#include "hunter.h"

int init_texture(texture_t *texture)
{
    texture->texture = sfTexture_createFromFile(
        "./src/ressources/duck.png", NULL);
    if (!texture->texture)
        return 84;
    texture->texture_bonus = sfTexture_createFromFile(
        "./src/ressources/bonus_duck.png", NULL);
    if (!texture->texture_bonus)
        return 84;
    texture->back_screen = sfTexture_createFromFile(
        "./src/ressources/back_screen.jpg", NULL);
    if (!texture->back_screen)
        return 84;
    texture->loose = sfTexture_createFromFile(
        "./src/ressources/loose_screen.jpg", NULL);
    if (!texture->loose)
        return 84;
    return 0;
}
