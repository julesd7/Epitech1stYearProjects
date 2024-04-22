/*
** EPITECH PROJECT, 2022
** my_hunter
** File description:
** sprite.h
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>
#include <time.h>
#include <stdlib.h>

#ifndef _SPRITE_H
    #define _SPRITE_H

    typedef struct sprite {
        sfSprite *sprite;
        sfSprite *back;
        sfSprite *bonus;
    }sprite_t;

#endif /* !_SPRITE_H */
