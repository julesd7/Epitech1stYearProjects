/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** init_maps
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>

#include "character.h"
#include "rpg.h"

maps_t init_maps(void)
{
    maps_t maps;

    maps.first = init_texture("src/resources/maps/first.jpg", maps.first);
    maps.second = init_texture("src/resources/maps/second.jpg", maps.second);
    maps.third = init_texture("src/resources/maps/third.jpg", maps.third);
    maps.fourth = init_texture("src/resources/maps/fourth.jpg", maps.fourth);
    maps.last = init_texture("src/resources/maps/last.jpg", maps.fourth);

    return maps;
}
