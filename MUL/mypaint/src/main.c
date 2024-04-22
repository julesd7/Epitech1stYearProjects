/*
** EPITECH PROJECT, 2023
** my_paint
** File description:
** main.c
*/

#include <SFML/Graphics.h>

#include "paint.h"

sfEvent event;
dropdown_rect_t rect;
dropdown_text_t text;
dropdown_vector_t vector;
dropdown_menu_t menu;
write_t write;
brush_t brush;

static sfRenderWindow *init_window(void)
{
    sfVideoMode mode = {1980, 1080, 32};
    sfRenderWindow* window = sfRenderWindow_create(
        mode, "My paint", sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(window, 60);
    return window;
}

int main(void)
{
    sfRenderWindow* window = init_window();
    init_dropdown(&text, &rect, &vector, &menu);
    init_write(&write, &brush);
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            check_sub_file(window, event, &write, menu);
            check_sub_edit(window, event, &brush, menu);
            check_event(window, event, &menu, rect);
            check_write(event, &write, &brush);
        }
        if (menu.file_menu == sfTrue)
            show_dropdown_file(window, rect, vector, text);
        if (menu.edit_menu == sfTrue)
            show_dropdown_edit(window, rect, vector, text);
        if (menu.help_menu == sfTrue)
            show_dropdown_help(window, rect, vector, text);
        show_dropdown_basics(window, rect, vector, text);
        display_base_windows(window, &write);
    }
    return destroy_dropdown(&rect, &text, window, &write);
}
