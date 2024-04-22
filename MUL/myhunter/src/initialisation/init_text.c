/*
** EPITECH PROJECT, 2022
** my_hunter
** File description:
** init_text.c
*/

#include "hunter.h"

static void set_size(text_t *text)
{
    int size = 50;
    sfText_setCharacterSize(text->text, size);
    sfText_setCharacterSize(text->score, size);
    sfText_setCharacterSize(text->life_text, size);
    sfText_setCharacterSize(text->life_count, size);
}

static void set_pos(text_t *text, vector_t vector)
{
    sfText_setPosition(text->score, vector.score_place);
    sfText_setPosition(text->life_text, vector.life_text_p);
    sfText_setPosition(text->life_count, vector.life_count_p);
}

static void set_font(text_t *text)
{
    sfText_setFont(text->text, text->font);
    sfText_setFont(text->score, text->font);
    sfText_setFont(text->life_text, text->font);
    sfText_setFont(text->life_count, text->font);
}

static void set_string(text_t *text)
{
    sfText_setString(text->text, "score :");
    sfText_setString(text->score, "0");
    sfText_setString(text->life_text, "life :");
    sfText_setString(text->life_count, "5");
}

int init_text(text_t *text, vector_t vector)
{
    text->font = sfFont_createFromFile("./src/ressources/arial.ttf");
    if (!text->font)
        return 84;

    text->text = sfText_create();
    text->score = sfText_create();
    text->life_text = sfText_create();
    text->life_count = sfText_create();
    set_string(text);
    set_font(text);
    set_pos(text, vector);
    set_size(text);

    return 0;
}
