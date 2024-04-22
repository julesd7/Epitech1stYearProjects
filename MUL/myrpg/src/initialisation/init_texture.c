/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** init_texture.c
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>

sfSprite *init_texture(char *filepath, sfSprite *sprite)
{
    if (!filepath)
        return NULL;
    sfTexture *texture = sfTexture_createFromFile(filepath, NULL);
    sprite = sfSprite_create();
    sfSprite_setTexture(sprite, texture, sfTrue);

    return sprite;
}
