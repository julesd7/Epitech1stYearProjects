/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** states.c
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>

#include "character.h"
#include "menu.h"
#include "npc.h"
#include "rpg.h"

void npc_states(npc_t *npc, int state)
{
    if (state != 4) {
        npc->Shane = init_texture("src/resources/npc.png", npc->Shane);
        npc->rectangle.width = 60;
        npc->rectangle.height = 110;
        npc->rectangle.top = 0;
        npc->rectangle.left = 0;
        sfSprite_setPosition(npc->Shane, (sfVector2f){130, 340});
        sfSprite_setScale(npc->Shane, (sfVector2f){0.5, 0.5});
        sfSprite_setTextureRect(npc->Shane, npc->rectangle);
    }
}

void char_states(sfRenderWindow *window, mainchar_t *charact, menu_t *menu)
{
    charact->rect.width = 100;
    charact->rect.height = 100;
    if (charact->is_dial == 0) {
        if (sfKeyboard_isKeyPressed(sfKeyUp))
            charact->rect.top = 300;
        if (sfKeyboard_isKeyPressed(sfKeyDown))
            charact->rect.top = 0;
        if (sfKeyboard_isKeyPressed(sfKeyLeft))
            charact->rect.top = 100;
        if (sfKeyboard_isKeyPressed(sfKeyRight))
            charact->rect.top = 200;
        move(charact, menu);
    } else
        dialogue_events(window, charact);
    game_events(charact);
    sfSprite_setPosition(charact->skin, charact->move);
    sfSprite_setTextureRect(charact->skin, charact->rect);
}
