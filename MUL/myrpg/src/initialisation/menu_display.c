/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** menu_display.c
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>

#include "menu.h"
#include "rpg.h"

static void main_menu_click3(
        sfRenderWindow *window,
        menu_t *menu,
        sfVector2i mouse,
        sfEvent event)
{
    if ((mouse.x >= 400 && mouse.x <= 850) &&
        (mouse.y >= 715 && mouse.y <= 761)) {
        text_options(menu->about, (sfVector2f){400.f, 700.f}, sfRed, window);
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            destroy_menu(menu);
            about_game(window, menu);
        }
    }
}

static void main_menu_click2(
        sfRenderWindow *window,
        menu_t *menu,
        sfVector2i mouse,
        sfEvent event)
{
    if ((mouse.x >= 397 && mouse.x <= 751)
        && (mouse.y >= 512 && mouse.y <= 562)) {
        text_options(menu->load, (sfVector2f){400.f, 500.f}, sfRed, window);
    } else if ((mouse.x >= 397 && mouse.x <= 693)
        && (mouse.y >= 617 && mouse.y <= 658)) {
        text_options(menu->options, (sfVector2f){400.f, 600.f}, sfRed, window);
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            destroy_menu(menu);
            options_menu(window, menu, mouse);
        }
    } else {
        main_menu_click3(window, menu, mouse, event);
    }
}

static void main_menu_click(sfRenderWindow *window, menu_t *menu)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window);
    sfEvent event;
    if ((mouse.x >= 389 && mouse.x <= 847)
        && (mouse.y >= 308 && mouse.y <= 361)) {
        text_options(menu->play, (sfVector2f){400.f, 300.f}, sfRed, window);
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            destroy_menu(menu);
            menu->is_play = 1;
        }
    } else if ((mouse.x >= 395 && mouse.x <= 575)
        && (mouse.y >= 416 && mouse.y <= 461)) {
        text_options(menu->save, (sfVector2f){400.f, 400.f}, sfRed, window);
    } else {
        main_menu_click2(window, menu, mouse, event);
    }
}

void main_menu(sfRenderWindow *window, menu_t *menu)
{
    sfRenderWindow_drawSprite(window, menu->menu, NULL);
    sfFont *font = init_font("src/resources/police/BouwsUnc.ttf");
    menu->play = init_text("START GAME", font, 60);
    menu->load = init_text("LOAD SAVE", font, 60);
    menu->save = init_text("SAVE", font, 60);
    menu->about = init_text("ABOUT GAME", font, 60);
    menu->options = init_text("SETTINGS", font, 60);
    text_options(menu->play, (sfVector2f){400.f, 300.f}, sfBlack, window);
    text_options(menu->save, (sfVector2f){400.f, 400.f}, sfBlack, window);
    text_options(menu->load, (sfVector2f){400.f, 500.f}, sfBlack, window);
    text_options(menu->options, (sfVector2f){400.f, 600.f}, sfBlack, window);
    text_options(menu->about, (sfVector2f){400.f, 700.f}, sfBlack, window);
    main_menu_click(window, menu);
}
