/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** init_text.c
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>

#include "menu.h"

sfFont *init_font(char *filepath)
{
    if (!filepath)
        return NULL;
    sfFont *font = sfFont_createFromFile(filepath);

    return font;
}

sfText *init_text(const char *string, sfFont *font, unsigned int size)
{
    if (!string || !font)
        return NULL;

    sfText *text = sfText_create();
    sfText_setFont(text, font);
    sfText_setString(text, string);
    sfText_setCharacterSize(text, size);

    return text;
}

void text_options(
        sfText *text,
        sfVector2f text_position,
        sfColor color,
        sfRenderWindow *window)
{
    if (!text)
        return;
    sfText_setColor(text, color);
    sfText_setPosition(text, text_position);
    sfRenderWindow_drawText(window, text, NULL);
}
