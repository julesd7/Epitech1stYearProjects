/*
** EPITECH PROJECT, 2022
** my_hunter
** File description:
** music.h
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>
#include <time.h>
#include <stdlib.h>

#ifndef _MUSIC_H
    #define _MUSIC_H

    typedef struct music {
        sfMusic *main;
        sfMusic *shoot;
        sfMusic *bonus;
    }music_t;

#endif /* !_MUSIC_H */
