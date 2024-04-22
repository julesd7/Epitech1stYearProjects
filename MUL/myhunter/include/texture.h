/*
** EPITECH PROJECT, 2022
** my_hunter
** File description:
** texture.h
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>
#include <time.h>
#include <stdlib.h>

#ifndef _TEXTURE_H
    #define _TEXTURE_H

    typedef struct texture {
        sfTexture *texture;
        sfTexture *back_screen;
        sfTexture *loose;
        sfTexture *texture_bonus;
    }texture_t;

#endif /* !_TEXTURE_H */
