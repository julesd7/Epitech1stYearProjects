/*
** EPITECH PROJECT, 2023
** my_paint
** File description:
** init_write.c
*/

#include "paint.h"

void init_write(write_t *write, brush_t *brush)
{
    write->file = sfRenderTexture_create(1980, 1080, sfFalse);
    sfRenderTexture_clear(write->file, sfWhite);
    write->sprite = sfSprite_create();
    brush->brushColor = sfBlack;
    brush->isDrawing = sfFalse;
    brush->erase = sfFalse;
}
