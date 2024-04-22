/*
** EPITECH PROJECT, 2023
** my_radar
** File description:
** plane.c
*/

#include "radar.h"

static void create_box(utils_t *utils)
{
    utils->box = sfRectangleShape_create();

    sfRectangleShape_setPosition(utils->box, utils->plane_start_pos);
    sfRectangleShape_setFillColor(utils->box , sfTransparent);
    sfRectangleShape_setOutlineColor(utils->box, sfYellow);
    sfRectangleShape_setOutlineThickness(utils->box, 1);
    sfRectangleShape_setSize(utils->box, (sfVector2f){20.0, 20.0});
}

void show_plane(utils_t *utils, plane_t plane, radar_t radar)
{
    for (int i = 0; i < (plane.plane_number * 6); i++) {
        utils->temp = plane.plane_pos[i];
        utils->plane_start_pos.x = (float)(utils->temp);
        i++;
        utils->temp = plane.plane_pos[i];
        utils->plane_start_pos.y = (float)(utils->temp);
        i += 4;
        sfSprite_setPosition(utils->plane_s, utils->plane_start_pos);
        if (radar.s_key == 0)
            sfRenderWindow_drawSprite(utils->window, utils->plane_s, NULL);
        if (radar.l_key == 0) {
            create_box(utils);
            sfRenderWindow_drawRectangleShape(
                utils->window, utils->box, NULL);
        }
    }
}
