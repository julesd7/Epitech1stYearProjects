/*
** EPITECH PROJECT, 2023
** my_paint
** File description:
** paint.h
*/

#ifndef _PAINT_H
    #define _PAINT_H

    #define EXIT_SUCCESS 0
    #define EXIT_FAIL 84

    #include "dropdown.h"
    #include "write.h"

    void check_event(
    sfRenderWindow* window,
    sfEvent event,
    dropdown_menu_t *menu,
    dropdown_rect_t rect
    );

    int check_sub_file(
    sfRenderWindow* window,
    sfEvent event,
    write_t *write,
    dropdown_menu_t menu
    );

    int check_sub_edit(
    sfRenderWindow* window,
    sfEvent event,
    brush_t *brush,
    dropdown_menu_t menu
    );

    int destroy_dropdown(
    dropdown_rect_t *rect,
    dropdown_text_t *text,
    sfRenderWindow *window,
    write_t *write
    );

    void show_help(void);
    void show_about(void);

#endif /* !_PAINT_H */
