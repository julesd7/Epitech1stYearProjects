/*
** EPITECH PROJECT, 2023
** my_paint
** File description:
** init_main.c
*/

#include "paint.h"

void init_dropdown(
    dropdown_text_t *text,
    dropdown_rect_t *rect,
    dropdown_vector_t *vector,
    dropdown_menu_t *menu
    )
{
    text->font = sfFont_createFromFile("./src/ressources/arial.ttf");
    init_dd_rect(rect);
    init_dd_vector(vector);
    init_dd_text_name(text);
    init_dd_text_size(text);
    init_dd_text_place(text);
    menu->file_menu = sfFalse;
    menu->edit_menu = sfFalse;
    menu->help_menu = sfFalse;
}
