/*
** EPITECH PROJECT, 2023
** my_paint
** File description:
** check_menus
*/

#include "paint.h"

static int check_file_menu(
    sfEvent event,
    dropdown_menu_t *menu,
    dropdown_rect_t rect
    )
{
    if (
    sfRectangleShape_getPosition(
    rect.file_rect).x >= event.mouseButton.x - 100
    && sfRectangleShape_getPosition(
    rect.file_rect).x <= event.mouseButton.x &&
    sfRectangleShape_getPosition(
    rect.file_rect).y >= event.mouseButton.y - 30
    ) {
        menu->file_menu = sfTrue;
        menu->edit_menu = sfFalse;
        menu->help_menu = sfFalse;
        return 1;
    }
}

static int check_edit_menu(
    sfEvent event,
    dropdown_menu_t *menu,
    dropdown_rect_t rect
    )
{
    if (
    sfRectangleShape_getPosition(
    rect.edit_rect).x >= event.mouseButton.x - 100
    && sfRectangleShape_getPosition(
    rect.edit_rect).x <= event.mouseButton.x &&
    sfRectangleShape_getPosition(
    rect.edit_rect).y >= event.mouseButton.y - 30
    ) {
        menu->edit_menu = sfTrue;
        menu->file_menu = sfFalse;
        menu->help_menu = sfFalse;
        return 1;
    }
}

static int check_help_menu(
    sfEvent event,
    dropdown_menu_t *menu,
    dropdown_rect_t rect
    )
{
    if (
    sfRectangleShape_getPosition(
    rect.help_rect).x >= event.mouseButton.x - 100
    && sfRectangleShape_getPosition(
    rect.help_rect).x <= event.mouseButton.x &&
    sfRectangleShape_getPosition(
    rect.help_rect).y >= event.mouseButton.y - 30) {
        menu->edit_menu = sfFalse;
        menu->file_menu = sfFalse;
        menu->help_menu = sfTrue;
        return 1;
    }
}

int check_menus(
    sfEvent event,
    dropdown_menu_t *menu,
    dropdown_rect_t rect
    )
{
    if (check_file_menu(event, menu, rect) == 1)
        return 1;
    if (check_edit_menu(event, menu, rect) == 1)
        return 1;
    if (check_help_menu(event, menu, rect) == 1)
        return 1;
    return 0;
}
