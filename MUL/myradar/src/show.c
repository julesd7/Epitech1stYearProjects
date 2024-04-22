/*
** EPITECH PROJECT, 2023
** my_radar
** File description:
** show.c
*/

#include "radar.h"

static int init_textures(utils_t *utils)
{
    utils->back_screen = sfTexture_createFromFile(
        "./src/ressources/back_screen.jpg", NULL);
    utils->tower_t = sfTexture_createFromFile(
        "./src/ressources/tower.png", NULL);
    utils->plane_t = sfTexture_createFromFile(
        "./src/ressources/plane.png", NULL);
    if (!utils->tower_t || !utils->back_screen || !utils->plane_t)
        return EXIT_ERROR;
    else
        return EXIT_SUCCESS;
}

static int init_sprite(utils_t *utils)
{
    utils->back = sfSprite_create();
    utils->tower_s = sfSprite_create();
    utils->plane_s = sfSprite_create();
    sfSprite_setTexture(utils->back, utils->back_screen, sfTrue);
    sfSprite_setTexture(utils->tower_s, utils->tower_t, sfTrue);
    sfSprite_setTexture(utils->plane_s, utils->plane_t, sfTrue);
    if (!utils->back || !utils->tower_s || !utils->plane_s)
        return EXIT_ERROR;
    else
        return EXIT_SUCCESS;
}

static void render(utils_t *utils, plane_t plane, tower_t tower, radar_t radar)
{
    sfRenderWindow_clear(utils->window, sfBlack);
    sfRenderWindow_drawSprite(utils->window, utils->back, NULL);
    show_tower(utils, tower, radar);
    show_plane(utils, plane, radar);
    sfRenderWindow_display(utils->window);
}

static void destroy(utils_t *utils, radar_t *radar)
{
    sfTexture_destroy(utils->back_screen);
    sfTexture_destroy(utils->tower_t);
    sfSprite_destroy(utils->back);
    sfSprite_destroy(utils->tower_s);
    sfCircleShape_destroy(utils->circle);
    sfRenderWindow_destroy(utils->window);
    free(radar->buffer);
}

int show_simulation(plane_t plane, tower_t tower, radar_t *radar)
{
    utils_t *utils = malloc(sizeof(*utils));
    radar->l_key = 0;
    radar->s_key = 0;

    sfVideoMode mode = {1920, 1080, 32};
    utils->window = sfRenderWindow_create(
        mode, "my_radar", sfResize | sfClose, NULL);
    if (!utils->window)
        return EXIT_FAILURE;
    if (init_textures(utils) == EXIT_ERROR || init_sprite(utils) == EXIT_ERROR)
        return EXIT_ERROR;
    sfRenderWindow_setFramerateLimit(utils->window, 30);
    while (sfRenderWindow_isOpen(utils->window)) {
        while (sfRenderWindow_pollEvent(utils->window, &utils->event))
            poll_event(utils);
        key_change(utils, radar);
        render(utils, plane, tower, (*radar));
    }
    destroy(utils, radar);
    return EXIT_SUCCESS;
}
