/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** init_character
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>

#include "character.h"
#include "menu.h"
#include "rpg.h"

static void init_second_dialogue(mainchar_t *character, sfFont *font)
{
    character->second_dial = init_text("???:\n\t\tThank you ! \
Come follow me let's find your daughter *leave*", font, 25);
    sfText_setColor(character->second_dial, sfBlack);
    sfText_setPosition(character->second_dial, (sfVector2f){520, 910});
}

static void init_first_dialogue(mainchar_t *character, sfFont *font)
{
    character->first_dial_one = init_text("You:\n\t\tHi, \
i'm looking for Shane... My daughter, i can't find her", font, 25);
    sfText_setColor(character->first_dial_one, sfBlack);
    sfText_setPosition(character->first_dial_one, (sfVector2f){520, 910});

    character->first_dial_two = init_text("???:\
\n\t\t\t\tOh, hum, I'm sorry to hear that. I need your help !!!\
\n\t\t\t\tI lost my box can you bring it to me and i'll help you", font, 20);
    sfText_setColor(character->first_dial_two, sfBlack);
    sfText_setPosition(character->first_dial_two, (sfVector2f){520, 910});

    character->first_dial_three = init_text("???:\n\t\tOh, and..\
*give a key* I found that key it can be useful for you", font, 25);
    sfText_setColor(character->first_dial_three, sfBlack);
    sfText_setPosition(character->first_dial_three, (sfVector2f){520, 910});
}

static void init_dialogue_key(mainchar_t *character, sfFont *font)
{
    character->dialogue = init_texture
    ("src/resources/dialogue.png", character->dialogue);
    character->need_key_dial = init_text
    ("*May I need a key......*", font, 30);
    sfText_setColor(character->need_key_dial, sfBlack);
    sfText_setPosition(character->need_key_dial, (sfVector2f){750, 930});
    sfSprite_setPosition(character->dialogue, (sfVector2f){465, 864});
    sfSprite_setScale(character->dialogue, (sfVector2f){1.0, 0.62});
}

mainchar_t init_mainchar(menu_t *menu)
{
    mainchar_t charact;
    sfFont *font = init_font("src/resources/police/arial.ttf");
    charact.skin = init_texture("src/resources/character.png", charact.skin);
    menu->state = 2;
    menu->tmp_states = 1;
    charact.state = 0;
    charact.rect.top = 0;
    charact.tmp = 0;
    charact.is_dial = 0;
    charact.dial_state = 0;
    charact.move = (sfVector2f){1357, 165};
    sfSprite_setPosition(charact.skin, charact.move);
    init_dialogue_key(&charact, font);
    init_first_dialogue(&charact, font);
    init_second_dialogue(&charact, font);

    return charact;
}
