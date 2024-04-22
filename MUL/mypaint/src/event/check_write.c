/*
** EPITECH PROJECT, 2023
** my_paint
** File description:
** check_write.c
*/

#include "paint.h"

void check_write(sfEvent event, write_t *write, brush_t *brush)
{
    if (event.type == sfEvtMouseButtonPressed &&
    event.mouseButton.button == sfMouseLeft) {
        brush->brushPos.x = event.mouseButton.x;
        brush->brushPos.y = event.mouseButton.y;
        brush->isDrawing = sfTrue;
    }
    if (event.type == sfEvtMouseButtonReleased &&
    event.mouseButton.button == sfMouseLeft) {
        brush->isDrawing = sfFalse;
    }
    if (event.type == sfEvtMouseMoved && brush->isDrawing == sfTrue) {
        sfVertex line[] = {
            {{brush->brushPos.x, brush->brushPos.y}, brush->brushColor},
            {{event.mouseMove.x, event.mouseMove.y},
            brush->brushColor}
        };
        sfRenderTexture_drawPrimitives(write->file, line, 4, sfLines, NULL);
        brush->brushPos.x = event.mouseMove.x;
        brush->brushPos.y = event.mouseMove.y;
    }
}
