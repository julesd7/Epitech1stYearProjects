/*
** EPITECH PROJECT, 2023
** my_radar
** File description:
** tower
*/

#include "radar.h"

sfCircleShape *create_circle(utils_t *utils, float radius)
{
    utils->circle = sfCircleShape_create();
    utils->tower_position.x = utils->tower_position.x + 20 - radius;
    utils->tower_position.y = utils->tower_position.y + 20 - radius;

    sfCircleShape_setPosition(utils->circle, utils->tower_position);
    sfCircleShape_setRadius(utils->circle, radius);
    sfCircleShape_setFillColor(utils->circle, sfTransparent);
    sfCircleShape_setOutlineThickness(utils->circle, 1);
    sfCircleShape_setOutlineColor(utils->circle, sfRed);
}

void show_tower(utils_t *utils, tower_t tower, radar_t radar)
{
    for (int i = 0; i < (tower.tower_number * 3); i++) {
        utils->temp = tower.tower_pos[i];
        utils->tower_position.x = (float)(utils->temp);
        i++;
        utils->temp = tower.tower_pos[i];
        utils->tower_position.y = (float)(utils->temp);
        i++;
        utils->temp = tower.tower_pos[i];
        sfSprite_setPosition(utils->tower_s, utils->tower_position);
        if (radar.s_key == 0)
            sfRenderWindow_drawSprite(utils->window, utils->tower_s, NULL);
        if (radar.l_key == 0) {
            create_circle(utils, (float)(utils->temp));
            sfRenderWindow_drawCircleShape(
                utils->window, utils->circle, NULL);
        }
    }
}
