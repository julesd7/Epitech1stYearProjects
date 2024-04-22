/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** menu.h
*/

#ifndef MENU_H_
    #define MENU_H_

    #include <SFML/Graphics.h>

    #include "character.h"
    #include "npc.h"

    typedef struct music {
        sfMusic *music;
    } music_t;

    typedef struct main_menu {
        sfSprite *menu;
        sfText *play;
        sfText *save;
        sfText *load;
        sfText *options;
        sfText *about;
        sfEvent event;
        sfMusic *tracks;
        struct options_menu *opt;
        int tmp_states;
        int is_play;
        int state;
    } menu_t;

    typedef struct options_menu {
        sfFont *font;
        sfText *frame;
        sfText *rate30;
        sfText *rate60;
        sfText *music;
        sfText *music0;
        sfText *music10;
        sfText *music50;
        sfText *music80;
        sfText *music100;
    } options_t;

    typedef struct about_menu {
        sfText *welc;
        sfText *lore_spr;
        sfText *game_spr;
        sfText *game_spr2;
        sfText *cmd_spr;
        sfText *expl;
        char *explstr;
        char *welcome;
        char *lore;
        char *cmd;
        char *game;
        char *game2;
    }about_t;

#endif /*MENU_H_*/
