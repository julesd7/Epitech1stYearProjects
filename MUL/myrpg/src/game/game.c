/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** starting_game.c
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>

#include "character.h"
#include "menu.h"
#include "rpg.h"
#include "npc.h"

static void display_map(sfRenderWindow *window, maps_t maps, int state)
{
    switch (state) {
        case 1:
            sfRenderWindow_drawSprite(window, maps.second, NULL);
            break;
        case 2:
            sfRenderWindow_drawSprite(window, maps.third, NULL);
            break;
        case 3:
            sfRenderWindow_drawSprite(window, maps.fourth, NULL);
            break;
        case 4:
            sfRenderWindow_drawSprite(window, maps.last, NULL);
            break;
        default:
            sfRenderWindow_drawSprite(window, maps.first, NULL);
    }
}

void game_engine(sfRenderWindow *window,
maps_t maps,
menu_t *menu,
mainchar_t *charact)
{
    npc_t npc;
    sfRenderWindow_clear(window, sfBlack);
    npc_states(&npc, charact->state);
    display_map(window, maps, charact->state);
    char_states(window, charact, menu);
    if (charact->state != 4)
        sfRenderWindow_drawSprite(window, npc.Shane, NULL);
    sfRenderWindow_drawSprite(window, charact->skin, NULL);
}
