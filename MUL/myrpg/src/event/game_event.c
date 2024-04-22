/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** game event.c
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>

#include "character.h"
#include "menu.h"

static void talk_to_npc(mainchar_t *character)
{
    if (character->state == 0 &&
    character->move.x >= 62 && character->move.x <= 157 &&
    character->move.y >= 340 && character->move.y <= 355 &&
    sfKeyboard_isKeyPressed(sfKeyE))
        character->is_dial = 2;
    if (character->state == 3 &&
    character->move.x >= 62 && character->move.x <= 157 &&
    character->move.y >= 340 && character->move.y <= 355 &&
    sfKeyboard_isKeyPressed(sfKeyE))
        character->is_dial = 3;
}

static void open_chain(mainchar_t *character)
{
    if (character->state == 1 &&
    character->move.x >= 1082 && character->move.x <= 1297 &&
    character->move.y == 550 &&
    sfKeyboard_isKeyPressed(sfKeyE))
        character->state = 2;
    if (character->state < 1 && character->is_dial == 0 &&
    character->move.x >= 1082 && character->move.x <= 1297 &&
    character->move.y == 550 &&
    sfKeyboard_isKeyPressed(sfKeyE)) {
        character->is_dial = 1;
    }
}

static void take_stairs(mainchar_t *character)
{
    if (character->move.y >= 645)
        sfSprite_setScale(character->skin, (sfVector2f){0.5, 0.5});
    if (character->move.y >= 625)
        sfSprite_setScale(character->skin, (sfVector2f){0.62, 0.62});
    if (character->move.y == 610)
        sfSprite_setScale(character->skin, (sfVector2f){0.67, 0.67});
    if (character->move.y <= 595)
        sfSprite_setScale(character->skin, (sfVector2f){0.75, 0.75});
}

static void get_package(mainchar_t *character)
{
    if (character->state == 2 &&
    character->move.x >= 102 && character->move.x <= 127 &&
    character->move.y >= 670 && character->move.y <= 710 &&
    sfKeyboard_isKeyPressed(sfKeyE))
        character->state = 3;
}

void game_events(mainchar_t *character)
{
    take_stairs(character);
    talk_to_npc(character);
    open_chain(character);
    get_package(character);
}
