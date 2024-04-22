/*
** EPITECH PROJECT, 2022
** my_hunter
** File description:
** renders.c
*/

#include "hunter.h"

void render_hunt(utilities_t *utilities,
sprite_t *sprite, text_t *text)
{
    sfRenderWindow_drawSprite(utilities->window, sprite->back, NULL);
    sfRenderWindow_drawText(utilities->window, text->text, NULL);
    sfRenderWindow_drawText(utilities->window, text->life_count, NULL);
    sfRenderWindow_drawText(utilities->window, text->life_text, NULL);
    sfRenderWindow_drawText(utilities->window, text->score, NULL);
    sfRenderWindow_drawSprite(utilities->window, sprite->sprite, NULL);
    sfRenderWindow_display(utilities->window);
}

void render_bonus_hunt(utilities_t *utilities,
sprite_t *sprite, text_t *text, vector_t *vector)
{
    sfRenderWindow_drawSprite(utilities->window, sprite->back, NULL);
    sfRenderWindow_drawText(utilities->window, text->text, NULL);
    sfRenderWindow_drawText(utilities->window, text->score, NULL);
    sfRenderWindow_drawText(utilities->window, text->life_count, NULL);
    sfRenderWindow_drawText(utilities->window, text->life_text, NULL);
    sfRenderWindow_drawSprite(utilities->window, sprite->sprite, NULL);
    sfRenderWindow_drawSprite(utilities->window, sprite->bonus, NULL);
    sfRenderWindow_display(utilities->window);
    utilities->show = 1;
    vector->bonus_move.x += 50;
}
