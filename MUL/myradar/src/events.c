/*
** EPITECH PROJECT, 2023
** my_radar
** File description:
** event.c
*/

#include "radar.h"

void key_change(utils_t *utils, radar_t *radar)
{
    switch (utils->event.key.code) {
        case sfKeyL:
            radar->l_key = (radar->l_key == 0) ? 1 : 0;
            break;
        case sfKeyS:
            radar->s_key = (radar->s_key == 0) ? 1 : 0;
            break;
        default:
            break;
    }
    utils->event.key.code = 0;
}

void poll_event(utils_t *utils)
{
    if (utils->event.type == sfEvtClosed)
        sfRenderWindow_close(utils->window);
    if (utils->event.key.code == sfKeyEscape)
        sfRenderWindow_close(utils->window);
}
