/*
** EPITECH PROJECT, 2023
** my_paint
** File description:
** dropdown.h
*/

#ifndef _DROPDOWN_H
    #define _DROPDOWN_H

    #include <SFML/Graphics.h>

    typedef struct dropdown_rect {
        sfRectangleShape *file_rect;
        sfRectangleShape *edit_rect;
        sfRectangleShape *help_rect;
        sfRectangleShape *select;
    }dropdown_rect_t;

    typedef struct dropdown_text {
        sfFont *font;
        sfText *file;
        sfText *new_file;
        sfText *open_file;
        sfText *save_file;
        sfText *edit;
        sfText *pencil;
        sfText *eraser;
        sfText *help;
        sfText *about;
        sfText *sec_help;
    }dropdown_text_t;

    typedef struct dropdown_vector {
        sfVector2f file;
        sfVector2f first_file;
        sfVector2f second_file;
        sfVector2f third_file;
        sfVector2f edit;
        sfVector2f first_edit;
        sfVector2f second_edit;
        sfVector2f help;
        sfVector2f first_help;
        sfVector2f second_help;
    }dropdown_vector_t;

    typedef struct dropdown_menu {
        sfBool file_menu;
        sfBool edit_menu;
        sfBool help_menu;
    }dropdown_menu_t;

    void init_dropdown(
    dropdown_text_t *text,
    dropdown_rect_t *rect,
    dropdown_vector_t *vector,
    dropdown_menu_t *menu
    );

    void init_dd_vector(dropdown_vector_t *vector);
    void init_dd_rect(dropdown_rect_t *rect);
    void init_dd_text_name(dropdown_text_t *text);
    void init_dd_text_size(dropdown_text_t *text);
    void init_dd_text_place(dropdown_text_t *text);

    void show_dropdown_basics(
    sfRenderWindow *window,
    dropdown_rect_t rect,
    dropdown_vector_t vector,
    dropdown_text_t text
    );

    void show_dropdown_file(
    sfRenderWindow *window,
    dropdown_rect_t rect,
    dropdown_vector_t vector,
    dropdown_text_t text
    );

    void show_dropdown_edit(
    sfRenderWindow *window,
    dropdown_rect_t rect,
    dropdown_vector_t vector,
    dropdown_text_t text
    );

    void show_dropdown_help(
    sfRenderWindow *window,
    dropdown_rect_t rect,
    dropdown_vector_t vector,
    dropdown_text_t text
    );

    int check_menus(
    sfEvent event,
    dropdown_menu_t *menu,
    dropdown_rect_t rect
    );

#endif /* !_DROPDOWN_H */
