/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** init_window
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>

sfRenderWindow *init_window(int w, int h)
{
    sfVideoMode mode = {w, h, 30};

    sfRenderWindow *window = sfRenderWindow_create(
        mode, "my RPG", sfResize | sfClose, NULL
    );
    sfRenderWindow_setFramerateLimit(window, 30);

    return window;
}
