/*
** EPITECH PROJECT, 2023
** my_paint
** File description:
** write.h
*/

#ifndef _WRITE_H
    #define _WRITE_H

    #include <SFML/Graphics.h>

    typedef struct write {
        sfRenderTexture *file;
        sfSprite *sprite;
    }write_t;

    typedef struct brush {
        sfVector2f brushPos;
        sfColor brushColor;
        sfBool isDrawing;
        sfBool erase;
    }brush_t;

    void init_write(write_t *write, brush_t *brush);

    void check_write(sfEvent event, write_t *write, brush_t *brush);

    void display_base_windows(
    sfRenderWindow *window,
    write_t *write);

#endif /* !_WRITE_H */
