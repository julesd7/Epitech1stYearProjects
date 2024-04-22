/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** poll_event
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>

#include "menu.h"
#include "rpg.h"

void poll_event(sfRenderWindow *window, sfEvent event, menu_t *menu)
{
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(window);
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape)
        menu->is_play = 0;
}
