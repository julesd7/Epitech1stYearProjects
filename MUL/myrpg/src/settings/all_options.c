/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** all_options.c
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>

#include "rpg.h"

static void settings3(
        options_t *opt,
        sfRenderWindow *window,
        sfVector2i mouse_pos,
        menu_t *menu)
{
    if ((mouse_pos.x >= 630 && mouse_pos.x <= 700)
        && (mouse_pos.y >= 350 && mouse_pos.y <= 400)) {
        text_options(opt->music80, (sfVector2f) {632.f, 350.f}, sfRed, window);
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            sfMusic_setVolume(menu->tracks, 80.0);
        }
    }
    if ((mouse_pos.x >= 840 && mouse_pos.x <= 900)
        && (mouse_pos.y >= 350 && mouse_pos.y <= 400)) {
        text_options(opt->music0, (sfVector2f) {842.f, 350.f}, sfRed, window);
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            sfMusic_setVolume(menu->tracks, 0.0);
        }
    } else if ((mouse_pos.x >= 730 && mouse_pos.x <= 835)
        && (mouse_pos.y >= 350 && mouse_pos.y <= 400)) {
        text_options(opt->music100, (sfVector2f) {732.f, 350.f}, sfRed, window);
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            sfMusic_setVolume(menu->tracks, 100.0);
        }
    }
}

static void settings2(
        options_t *opt,
        sfRenderWindow *window,
        sfVector2i mouse_pos,
        menu_t *menu)
{
    if ((mouse_pos.x >= 430 && mouse_pos.x <= 505)
        && (mouse_pos.y >= 350 && mouse_pos.y <= 400)) {
        text_options(opt->music10, (sfVector2f) {432.f, 350.f}, sfRed, window);
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            sfMusic_setVolume(menu->tracks, 10.0);
        }
    } else if ((mouse_pos.x >= 530 && mouse_pos.x <= 600)
        && (mouse_pos.y >= 350 && mouse_pos.y <= 400)) {
        text_options(opt->music50, (sfVector2f) {532.f, 350.f}, sfRed, window);
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            sfMusic_setVolume(menu->tracks, 50.0);
        }
    } else
        settings3(opt, window, mouse_pos, menu);
}

static void settings(options_t *opt, sfRenderWindow *window, menu_t *menu)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window);
    if ((mouse_pos.x >= 400 && mouse_pos.x <= 540)
        && (mouse_pos.y >= 250 && mouse_pos.y <= 300)) {
        text_options(opt->rate30, (sfVector2f) {432.f, 250.f}, sfRed, window);
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            sfRenderWindow_setFramerateLimit(window, 30);
            menu->tmp_states = 1;
        }
    } else if ((mouse_pos.x >= 600 && mouse_pos.x <= 740)
        && (mouse_pos.y >= 250 && mouse_pos.y <= 300)) {
        text_options(opt->rate60, (sfVector2f) {632.f, 250.f}, sfRed, window);
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            sfRenderWindow_setFramerateLimit(window, 60);
            menu->tmp_states = 2;
        }
    } else
        settings2(opt, window, mouse_pos, menu);
}

void options_menu(sfRenderWindow *window, menu_t *menu, sfVector2i mouse)
{
    int tmp = 0;
    sfEvent event;
    options_t options;
    while (sfRenderWindow_isOpen(window) && tmp == 0) {
        while (sfRenderWindow_pollEvent(window, &event))
            poll_event(window, event, menu);
        if (sfKeyboard_isKeyPressed(sfKeyEscape))
            tmp = 1;
        sfRenderWindow_drawSprite(window, menu->menu, NULL);
        text_settings(&options);
        display_settings(window, &options);
        settings(&options, window, menu);
        sfRenderWindow_display(window);
    }
    return;
}
