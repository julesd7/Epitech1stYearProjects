/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** rpg.h
*/

#ifndef _RPG_H
    #define _RPG_H

    #define EXIT_SUCCESS 0
    #define EXIT_FAIL 84

    #include <SFML/Graphics.h>

    #include "character.h"
    #include "menu.h"
    #include "npc.h"

    /*Sound*/
    void main_track(menu_t *menu);

    /*Init*/
    sfRenderWindow *init_window(int w, int h);
    mainchar_t init_mainchar(menu_t *menu);
    sfSprite *init_texture(char *filepath, sfSprite *sprite);
    sfFont *init_font(char *filepath);
    sfText *init_text(const char *string, sfFont *font, unsigned int size);
    maps_t init_maps(void);

    /*Event*/
    void poll_event(sfRenderWindow *window, sfEvent event, menu_t *menu);
    void game_events(mainchar_t *character);
    void dialogue_events(sfRenderWindow *window, mainchar_t *character);


    /*Game*/
    void game_engine(
    sfRenderWindow *window,
    maps_t maps,
    menu_t *menu,
    mainchar_t *charact);
    void move(mainchar_t *charact, menu_t *menu);
    void npc_states(npc_t *npc, int state);
    void char_states(sfRenderWindow *window, mainchar_t *charact, menu_t *menu);
    void check_down_collision_30fps(mainchar_t *c);
    void check_up_collision_30fps(mainchar_t *charact);
    void check_right_collision_30fps(mainchar_t *charact);
    void check_left_collision_30fps(mainchar_t *charact);
    void check_down_collision_60fps(mainchar_t *c);
    void check_up_collision_60fps(mainchar_t *charact);
    void check_right_collision_60fps(mainchar_t *charact);
    void check_left_collision_60fps(mainchar_t *charact);

    /*Menu*/
    void  main_menu(sfRenderWindow *window, menu_t *menu);
    void text_options(
    sfText *text,
    sfVector2f text_position,
    sfColor color,
    sfRenderWindow *window);
    void options_menu(
    sfRenderWindow *window,
    menu_t *menu,
    sfVector2i mouse);
    void about_game(sfRenderWindow *window, menu_t *menu);
    void destroy_menu(menu_t *menu);
    void text_settings(options_t *options);
    void display_settings(sfRenderWindow *window, options_t *opt);

#endif /*_RPG_H*/
