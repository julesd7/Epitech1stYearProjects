/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** tracks.c
*/

#include "rpg.h"

void main_track(menu_t *menu)
{
    menu->tracks = sfMusic_createFromFile("./src/resources/sound.ogg");
    if (!menu->tracks)
        return;
    sfMusic_setLoop(menu->tracks, sfTrue);
    sfMusic_play(menu->tracks);
}
