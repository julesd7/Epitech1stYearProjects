/*
** EPITECH PROJECT, 2023
** my_paint
** File description:
** event.c
*/

#include "paint.h"

static void is_closed(sfRenderWindow* window, sfEvent event)
{
    if (event.type == sfEvtClosed) {
        sfRenderWindow_close(window);
    }
}

void check_event(
    sfRenderWindow* window,
    sfEvent event,
    dropdown_menu_t *menu,
    dropdown_rect_t rect
    )
{
    is_closed(window, event);
    if (event.type == sfEvtMouseButtonPressed &&
    event.mouseButton.button == sfMouseLeft) {
        if (check_menus(event, menu, rect) == 0) {
            menu->file_menu = sfFalse;
            menu->edit_menu = sfFalse;
            menu->help_menu = sfFalse;
        }
    }
}
