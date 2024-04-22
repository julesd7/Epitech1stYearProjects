/*
** EPITECH PROJECT, 2023
** my_radar
** File description:
** utils.h
*/

#include <SFML/Graphics.h>

#ifndef _UTILS_H
    #define _UTILS_H

    typedef struct utils {
        sfRenderWindow *window;
        sfTexture *back_screen;
        sfTexture *tower_t;
        sfTexture *plane_t;
        sfSprite *sprite;
        sfSprite *back;
        sfSprite *tower_s;
        sfSprite *plane_s;
        sfCircleShape *circle;
        sfRectangleShape *box;
        sfVector2f tower_position;
        sfVector2f plane_start_pos;
        sfEvent event;
        int temp;
    }utils_t;

#endif /* !_UTILS_H */
