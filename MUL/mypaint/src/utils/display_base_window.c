/*
** EPITECH PROJECT, 2023
** my_paint
** File description:
** display_base_window.c
*/

#include "paint.h"

void display_base_windows(
    sfRenderWindow *window,
    write_t *write)
{
    sfSprite_setTexture(write->sprite,
    sfRenderTexture_getTexture(write->file), sfTrue);
    sfRenderWindow_display(window);
    sfRenderWindow_drawSprite(window, write->sprite, NULL);
    sfRenderTexture_display(write->file);
}
