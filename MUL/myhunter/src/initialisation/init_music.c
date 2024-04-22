/*
** EPITECH PROJECT, 2022
** my_hunter
** File description:
** init_music.c
*/

#include "hunter.h"

int init_music(music_t *music)
{
    music->main = sfMusic_createFromFile("./src/ressources/main.ogg");
    if (!music->main)
        return 84;
    music->shoot = sfMusic_createFromFile("./src/ressources/gun.ogg");
    if (!music->shoot)
        return 84;
    music->bonus = sfMusic_createFromFile("./src/ressources/bonus_sound.ogg");
    if (!music->shoot)
        return 84;
    return 0;
}
