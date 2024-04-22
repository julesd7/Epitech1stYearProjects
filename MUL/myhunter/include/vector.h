/*
** EPITECH PROJECT, 2022
** my_hunter
** File description:
** vector.h
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>
#include <time.h>
#include <stdlib.h>

#ifndef _VECTOR_H
    #define _VECTOR_H

    typedef struct vector {
        sfVector2f move;
        sfVector2f bonus_move;
        sfVector2f score_place;
        sfVector2f life_text_p;
        sfVector2f life_count_p;
    }vector_t;

#endif /* !_VECTOR_H */
