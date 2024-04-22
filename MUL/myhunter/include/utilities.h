/*
** EPITECH PROJECT, 2022
** my_hunter
** File description:
** utilities.h
*/

#ifndef _UTILITIES_H
    #define _UTILITIES_H

    typedef struct utilities {
        sfRenderWindow *window;
        sfEvent event;
        sfIntRect rectangle;
        char temp[1000];
        char temp_life[5];
        int tmp;
        int scoring;
        int is_bonus;
        int show;
        int life;
    }utilities_t;

#endif /* !_UTILITIES_H */
