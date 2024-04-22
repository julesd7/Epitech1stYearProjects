/*
** EPITECH PROJECT, 2023
** my_paint.c
** File description:
** sub_about
*/

#include "paint.h"

static sfRenderWindow *init_about(void)
{
    sfVideoMode mode = {800, 600, 32};
    sfRenderWindow* window = sfRenderWindow_create(
        mode, "About", sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(window, 60);
    return window;
}

static void poll_event(sfRenderWindow* window, sfEvent event)
{
    if (event.type == sfEvtClosed) {
        sfRenderWindow_close(window);
    }
}

void show_about(void)
{
    sfEvent event;
    sfRenderWindow* window = init_about();

    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event))
            poll_event(window, event);
        sfRenderWindow_clear(window, sfWhite);
    }
    sfRenderWindow_destroy(window);
}
