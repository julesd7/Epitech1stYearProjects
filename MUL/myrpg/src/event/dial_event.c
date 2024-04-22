/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** dial_event
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>

#include "character.h"
#include "rpg.h"

static void need_key_dialogue(sfRenderWindow *window, mainchar_t *character)
{
    sfRenderWindow_drawSprite(window, character->dialogue, NULL);
    sfRenderWindow_drawText(window, character->need_key_dial, NULL);
    if (sfKeyboard_isKeyPressed(sfKeyEnter) ||
    sfKeyboard_isKeyPressed(sfKeySpace))
        character->is_dial = 0;
}

static void second_dialogue(sfRenderWindow *window, mainchar_t *character)
{
    sfRenderWindow_drawSprite(window, character->dialogue, NULL);
    sfRenderWindow_drawText(window, character->second_dial, NULL);
    if (sfKeyboard_isKeyPressed(sfKeyEnter) ||
    sfKeyboard_isKeyPressed(sfKeySpace)) {
        character->is_dial = 0;
        character->state = 4;
    }
}

static void first_dialogue(sfRenderWindow *window, mainchar_t *character)
{
    int check = 0;
    sfRenderWindow_drawSprite(window, character->dialogue, NULL);
    if (character->dial_state == 0)
        sfRenderWindow_drawText(window, character->first_dial_one, NULL);
    if (character->dial_state == 1)
        sfRenderWindow_drawText(window, character->first_dial_two, NULL);
    if (character->dial_state == 2)
        sfRenderWindow_drawText(window, character->first_dial_three, NULL);
    while (sfKeyboard_isKeyPressed(sfKeyEnter) ||
    sfKeyboard_isKeyPressed(sfKeySpace)) {
        check++;
    }
    if (check >= 1)
        character->dial_state ++;
    if (character->dial_state == 3) {
        character->dial_state = 0;
        character->is_dial = 0;
        character->state = 1;
    }
    return;
}

void dialogue_events(sfRenderWindow *window, mainchar_t *character)
{
    switch (character->is_dial) {
        case 1:
            need_key_dialogue(window, character);
            break;
        case 2:
            first_dialogue(window, character);
            break;
        case 3:
            second_dialogue(window, character);
            break;
        default:
            break;
    }
}
