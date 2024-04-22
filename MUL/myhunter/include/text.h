/*
** EPITECH PROJECT, 2022
** my_hunter
** File description:
** text.h
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>
#include <time.h>
#include <stdlib.h>

#ifndef _TEXT_H
    #define _TEXT_H

    typedef struct text {
        sfFont *font;
        sfText *text;
        sfText *score;
        sfText *life_text;
        sfText *life_count;
    }text_t;

#endif /* !_TEXT_H */
