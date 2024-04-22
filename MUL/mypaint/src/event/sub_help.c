/*
** EPITECH PROJECT, 2023
** my_paint.c
** File description:
** sub_help
*/

#include "paint.h"

static sfRenderWindow *init_help(void)
{
    sfVideoMode mode = {800, 600, 32};
    sfRenderWindow* window = sfRenderWindow_create(
        mode, "Help", sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(window, 60);
    return window;
}

static void poll_event(sfRenderWindow* window, sfEvent event)
{
    if (event.type == sfEvtClosed) {
        sfRenderWindow_close(window);
    }
}

void show_help(void)
{
    sfEvent event;
    sfRenderWindow* window = init_help();

    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event))
            poll_event(window, event);
    }
    sfRenderWindow_destroy(window);
}
