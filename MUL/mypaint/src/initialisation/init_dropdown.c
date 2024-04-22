/*
** EPITECH PROJECT, 2023
** my_paint
** File description:
** init_dropbar
*/

#include "dropdown.h"

void init_dd_vector(dropdown_vector_t *vector)
{
    vector->file = (sfVector2f){0.f, 0.f};
    vector->first_file = (sfVector2f){0.f, 35.f};
    vector->second_file = (sfVector2f){0.f, 70.f};
    vector->third_file = (sfVector2f){0.f, 105.f};
    vector->edit = (sfVector2f){110.f, 0.f};
    vector->first_edit = (sfVector2f){110.f, 35.f};
    vector->second_edit = (sfVector2f){110.f, 70.f};
    vector->help = (sfVector2f){220.f, 0.f};
    vector->first_help = (sfVector2f){220.f, 35.f};
    vector->second_help = (sfVector2f){220.f, 70.f};
}

void init_dd_rect(dropdown_rect_t *rect)
{
    rect->file_rect = sfRectangleShape_create();
    rect->edit_rect = sfRectangleShape_create();
    rect->help_rect = sfRectangleShape_create();
    rect->select = sfRectangleShape_create();
    sfRectangleShape_setFillColor(rect->file_rect, sfBlue);
    sfRectangleShape_setFillColor(rect->edit_rect, sfBlue);
    sfRectangleShape_setFillColor(rect->help_rect, sfBlue);
    sfRectangleShape_setFillColor(rect->select, sfBlue);
    sfRectangleShape_setSize(rect->file_rect, (sfVector2f){100.f, 30.f});
    sfRectangleShape_setSize(rect->edit_rect, (sfVector2f){100.f, 30.f});
    sfRectangleShape_setSize(rect->help_rect, (sfVector2f){100.f, 30.f});
    sfRectangleShape_setSize(rect->select, (sfVector2f){100.f, 30.f});
    sfRectangleShape_setPosition(rect->file_rect, (sfVector2f){0.f, 0.f});
    sfRectangleShape_setPosition(rect->edit_rect, (sfVector2f){110.f, 0.f});
    sfRectangleShape_setPosition(rect->help_rect, (sfVector2f){220.f, 0.f});
    sfRectangleShape_setPosition(rect->select, (sfVector2f){220.f, 0.f});
}

void init_dd_text_name(dropdown_text_t *text)
{
    text->file = sfText_create();
    text->new_file = sfText_create();
    text->open_file = sfText_create();
    text->save_file = sfText_create();
    text->edit = sfText_create();
    text->pencil = sfText_create();
    text->eraser = sfText_create();
    text->help = sfText_create();
    text->about = sfText_create();
    text->sec_help = sfText_create();
    sfText_setString(text->file, "File");
    sfText_setString(text->new_file, "New file");
    sfText_setString(text->open_file, "Open file");
    sfText_setString(text->save_file, "Save file");
    sfText_setString(text->edit, "Edit");
    sfText_setString(text->pencil, "Pencil");
    sfText_setString(text->eraser, "Eraser");
    sfText_setString(text->help, "Help");
    sfText_setString(text->about, "About");
    sfText_setString(text->sec_help, "Help");
}

void init_dd_text_size(dropdown_text_t *text)
{
    sfText_setFont(text->file, text->font);
    sfText_setFont(text->new_file, text->font);
    sfText_setFont(text->open_file, text->font);
    sfText_setFont(text->save_file, text->font);
    sfText_setFont(text->edit, text->font);
    sfText_setFont(text->pencil, text->font);
    sfText_setFont(text->eraser, text->font);
    sfText_setFont(text->help, text->font);
    sfText_setFont(text->about, text->font);
    sfText_setFont(text->sec_help, text->font);
    sfText_setCharacterSize(text->file, 16);
    sfText_setCharacterSize(text->new_file, 16);
    sfText_setCharacterSize(text->open_file, 16);
    sfText_setCharacterSize(text->save_file, 16);
    sfText_setCharacterSize(text->edit, 16);
    sfText_setCharacterSize(text->pencil, 16);
    sfText_setCharacterSize(text->eraser, 16);
    sfText_setCharacterSize(text->help, 16);
    sfText_setCharacterSize(text->about, 16);
    sfText_setCharacterSize(text->sec_help, 16);
}

void init_dd_text_place(dropdown_text_t *text)
{
    sfText_setPosition(text->file, (sfVector2f){10.f, 5.f});
    sfText_setPosition(text->new_file, (sfVector2f){10.f, 40.f});
    sfText_setPosition(text->open_file, (sfVector2f){10.f, 75.f});
    sfText_setPosition(text->save_file, (sfVector2f){10.f, 110.f});
    sfText_setPosition(text->edit, (sfVector2f){120.f, 5.f});
    sfText_setPosition(text->pencil, (sfVector2f){120.f, 40.f});
    sfText_setPosition(text->eraser, (sfVector2f){120.f, 75.f});
    sfText_setPosition(text->help, (sfVector2f){230.f, 5.f});
    sfText_setPosition(text->about, (sfVector2f){230.f, 40.f});
    sfText_setPosition(text->sec_help, (sfVector2f){230.f, 75.f});
}
