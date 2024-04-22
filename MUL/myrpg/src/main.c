/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** main.c
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>

#include "rpg.h"
#include "menu.h"

int main(int ac, char **av)
{
    menu_t menu;
    mainchar_t charact = init_mainchar(&menu);
    menu.menu = init_texture("src/resources/main_menu.jpg", menu.menu);
    maps_t maps = init_maps();
    sfEvent event;
    sfRenderWindow *window = init_window(1920, 1080);
    main_track(&menu);
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event))
            poll_event(window, event, &menu);
        sfRenderWindow_clear(window, sfBlack);
        if (menu.is_play == 1)
            game_engine(window, maps, &menu, &charact);
        else
            main_menu(window, &menu);
        sfRenderWindow_display(window);
    }
    sfMusic_destroy(menu.tracks);
    sfRenderWindow_destroy(window);
    return EXIT_SUCCESS;
}
