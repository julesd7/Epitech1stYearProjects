/*
** EPITECH PROJECT, 2022
** sokoban
** File description:
** loc.h
*/

#ifndef _LOC_H
    #define _LOC_H

    typedef struct loc {
        int p_loc_x;
        int p_loc_y;
        int cases;
        int ytemp;
        int xtemp;
        char temp[1000];
        char *storage;
    }loc_t;

#endif /* !_LOC_H */
