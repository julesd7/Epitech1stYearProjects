/*
** EPITECH PROJECT, 2023
** my_paint
** File description:
** dropdownmenu.c
*/

#include "paint.h"

void show_dropdown_file(
    sfRenderWindow *window,
    dropdown_rect_t rect,
    dropdown_vector_t vector,
    dropdown_text_t text
    )
{
    sfRectangleShape_setPosition(rect.file_rect, vector.first_file);
    sfRenderWindow_drawRectangleShape(window, rect.file_rect, NULL);
    sfRenderWindow_drawText(window, text.new_file, NULL);
    sfRectangleShape_setPosition(rect.file_rect, vector.second_file);
    sfRenderWindow_drawRectangleShape(window, rect.file_rect, NULL);
    sfRenderWindow_drawText(window, text.open_file, NULL);
    sfRectangleShape_setPosition(rect.file_rect, vector.third_file);
    sfRenderWindow_drawRectangleShape(window, rect.file_rect, NULL);
    sfRenderWindow_drawText(window, text.save_file, NULL);
}

void show_dropdown_edit(
    sfRenderWindow *window,
    dropdown_rect_t rect,
    dropdown_vector_t vector,
    dropdown_text_t text
    )
{
    sfRectangleShape_setPosition(rect.edit_rect, vector.first_edit);
    sfRenderWindow_drawRectangleShape(window, rect.edit_rect, NULL);
    sfRenderWindow_drawText(window, text.pencil, NULL);
    sfRectangleShape_setPosition(rect.edit_rect, vector.second_edit);
    sfRenderWindow_drawRectangleShape(window, rect.edit_rect, NULL);
    sfRenderWindow_drawText(window, text.eraser, NULL);
}

void show_dropdown_help(
    sfRenderWindow *window,
    dropdown_rect_t rect,
    dropdown_vector_t vector,
    dropdown_text_t text
    )
{
    sfRectangleShape_setPosition(rect.help_rect, vector.first_help);
    sfRenderWindow_drawRectangleShape(window, rect.help_rect, NULL);
    sfRenderWindow_drawText(window, text.about, NULL);
    sfRectangleShape_setPosition(rect.help_rect, vector.second_help);
    sfRenderWindow_drawRectangleShape(window, rect.help_rect, NULL);
    sfRenderWindow_drawText(window, text.sec_help, NULL);
}

void show_dropdown_basics(
    sfRenderWindow *window,
    dropdown_rect_t rect,
    dropdown_vector_t vector,
    dropdown_text_t text
    )
{
    sfRectangleShape_setPosition(rect.file_rect, vector.file);
    sfRenderWindow_drawRectangleShape(window, rect.file_rect, NULL);
    sfRectangleShape_setPosition(rect.edit_rect, vector.edit);
    sfRenderWindow_drawRectangleShape(window, rect.edit_rect, NULL);
    sfRectangleShape_setPosition(rect.help_rect, vector.help);
    sfRenderWindow_drawRectangleShape(window, rect.help_rect, NULL);
    sfRenderWindow_drawText(window, text.file, NULL);
    sfRenderWindow_drawText(window, text.edit, NULL);
    sfRenderWindow_drawText(window, text.help, NULL);
}
