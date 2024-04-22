/*
** EPITECH PROJECT, 2023
** my_paint
** File description:
** check_sub_edit
*/

#include "paint.h"

static int pencil(sfEvent event, brush_t *brush)
{
    if (event.type == sfEvtMouseButtonPressed &&
        event.mouseButton.x >= 110 &&
        event.mouseButton.x <= 210 &&
        event.mouseButton.y >= 35 &&
        event.mouseButton.y <= 65
            ) {
        brush->brushColor = sfBlack;
        return 1;
    }
    return 0;
}

static int eraser(sfEvent event, brush_t *brush)
{
    if (event.type == sfEvtMouseButtonPressed &&
        event.mouseButton.x >= 110 &&
        event.mouseButton.x <= 210 &&
        event.mouseButton.y >= 70 &&
        event.mouseButton.y <= 100
            ) {
        brush->brushColor = sfWhite;
        return 1;
    }
    return 0;
}

static int about(sfEvent event)
{
    if (event.type == sfEvtMouseButtonPressed &&
        event.mouseButton.x >= 220 &&
        event.mouseButton.x <= 320 &&
        event.mouseButton.y >= 35 &&
        event.mouseButton.y <= 65
            ) {
        show_about();
        return 1;
    }
    return 0;
}

static int help(sfEvent event)
{
    if (event.type == sfEvtMouseButtonPressed &&
        event.mouseButton.x >= 220 &&
        event.mouseButton.x <= 320 &&
        event.mouseButton.y >= 70 &&
        event.mouseButton.y <= 100
            ) {
        show_help();
        return 1;
    }
    return 0;
}

int check_sub_edit(
        sfRenderWindow* window,
        sfEvent event,
        brush_t *brush,
        dropdown_menu_t menu
)
{
    if (menu.edit_menu == sfTrue) {
        if (pencil(event, brush) == 1)
            return 0;
        if (eraser(event, brush) == 1)
            return 0;
    }
    if (menu.help_menu == sfTrue) {
        if (about(event) == 1)
            return 0;
        if (help(event) == 1)
            return 0;
    }
}
