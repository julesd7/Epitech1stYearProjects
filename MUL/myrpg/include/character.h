/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** character.h
*/

#ifndef _CHARACTER_H
    #define _CHARACTER_H

    #include <SFML/Audio.h>
    #include <SFML/System.h>
    #include <SFML/Graphics.h>

    typedef struct main_character {
        sfSprite *skin;
        sfSprite *dialogue;
        sfText *need_key_dial;
        sfText *first_dial_one;
        sfText *first_dial_two;
        sfText *first_dial_three;
        sfText *second_dial;
        sfIntRect rect;
        sfVector2f move;
        int tmp;
        int state;
        int is_dial;
        int dial_state;
    } mainchar_t;

    typedef struct maps {
        sfSprite *first;
        sfSprite *second;
        sfSprite *third;
        sfSprite *fourth;
        sfSprite *last;
    } maps_t;

#endif /*_CHARACTER_H*/
