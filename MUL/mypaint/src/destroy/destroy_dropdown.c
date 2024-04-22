/*
** EPITECH PROJECT, 2023
** my_paint
** File description:
** destroy_dropdown
*/

#include "paint.h"

static void destroy_rect(dropdown_rect_t *rect)
{
    sfRectangleShape_destroy(rect->edit_rect);
    sfRectangleShape_destroy(rect->select);
    sfRectangleShape_destroy(rect->file_rect);
    sfRectangleShape_destroy(rect->help_rect);
}

static void destroy_text(dropdown_text_t *text)
{
    sfText_destroy(text->about);
    sfText_destroy(text->edit);
    sfText_destroy(text->eraser);
    sfText_destroy(text->file);
    sfFont_destroy(text->font);
    sfText_destroy(text->help);
    sfText_destroy(text->new_file);
    sfText_destroy(text->open_file);
    sfText_destroy(text->pencil);
    sfText_destroy(text->save_file);
    sfText_destroy(text->sec_help);
}

int destroy_dropdown(
        dropdown_rect_t *rect,
        dropdown_text_t *text,
        sfRenderWindow *window,
        write_t *write
)
{
    destroy_rect(rect);
    destroy_text(text);
    sfRenderTexture_destroy(write->file);
    sfSprite_destroy(write->sprite);
    sfRenderWindow_destroy(window);
    return EXIT_SUCCESS;
}
