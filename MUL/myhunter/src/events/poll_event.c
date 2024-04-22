/*
** EPITECH PROJECT, 2022
** my_hunter
** File description:
** poll_event.c
*/

#include "hunter.h"

static void is_sprite_touched(utilities_t *utilities, sprite_t *sprite,
text_t *text, vector_t *vector)
{
    if (utilities->event.type == sfEvtMouseButtonPressed &&
        utilities->event.mouseButton.button == sfMouseLeft &&
        utilities->event.mouseButton.x <=
        sfSprite_getPosition(sprite->sprite).x + 110 &&
        utilities->event.mouseButton.x >=
        sfSprite_getPosition(sprite->sprite).x - 50 &&
        utilities->event.mouseButton.y <=
        sfSprite_getPosition(sprite->sprite).y + 90 &&
        utilities->event.mouseButton.y >=
        sfSprite_getPosition(sprite->sprite).y) {
            utilities->scoring++;
            itoa(utilities->scoring, utilities->temp);
            sfText_setString(text->score, utilities->temp);
            vector->move.x = -110;
            vector->move.y = (rand() % (750 - 0 + 1)) + 0;
        }
}

static void is_bonus_touched(utilities_t *utilities, sprite_t *sprite,
text_t *text, vector_t *vector)
{
    if (utilities->event.type == sfEvtMouseButtonPressed &&
        utilities->event.mouseButton.button == sfMouseLeft &&
        utilities->event.mouseButton.x <=
        sfSprite_getPosition(sprite->bonus).x + 110 &&
        utilities->event.mouseButton.x >=
        sfSprite_getPosition(sprite->bonus).x - 50 &&
        utilities->event.mouseButton.y <=
        sfSprite_getPosition(sprite->bonus).y + 90 &&
        utilities->event.mouseButton.y >=
        sfSprite_getPosition(sprite->bonus).y &&
        utilities->show == 1) {
            utilities->scoring += 15;
            itoa(utilities->scoring, utilities->temp);
            sfText_setString(text->score, utilities->temp);
            utilities->show = 0;
            vector->bonus_move.x = -110;
            vector->bonus_move.y = (rand() % (750 - 0 + 1)) + 0;
        }
}

void poll_event(utilities_t *utilities, sprite_t *sprite,
text_t *text, vector_t *vector)
{
    if (utilities->event.type == sfEvtClosed)
        sfRenderWindow_close(utilities->window);
    is_sprite_touched(utilities, sprite, text, vector);
    is_bonus_touched(utilities, sprite, text, vector);
}

void poll_event_sound(utilities_t *utilities, music_t *music)
{
    if (utilities->event.type == sfEvtMouseButtonPressed &&
        utilities->event.mouseButton.button == sfMouseLeft) {
            sfMusic_stop(music->shoot);
            sfMusic_play(music->shoot);
        }
}
