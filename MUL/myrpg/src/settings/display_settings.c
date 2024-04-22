/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** display_settings.c
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>

#include "rpg.h"

void text_settings(options_t *options)
{
    options->font = init_font("src/resources/police/arial.ttf");
    options->frame = init_text("SET FRAME RATE : ", options->font, 40);
    options->rate30 = init_text("30fps", options->font, 40);
    options->rate60 = init_text("60fps", options->font, 40);
    options->music = init_text("VOLUME :", options->font, 40);
    options->music0 = init_text("0%", options->font, 40);
    options->music10 = init_text("10%", options->font, 40);
    options->music50 = init_text("50%", options->font, 40);
    options->music80 = init_text("80%", options->font, 40);
    options->music100 = init_text("100%", options->font, 40);
}

void display_settings(sfRenderWindow *window, options_t *opt)
{
    text_options(opt->frame, (sfVector2f){432.f, 200.f}, sfBlack, window);
    text_options(opt->rate30, (sfVector2f){432.f, 250.f}, sfBlack, window);
    text_options(opt->rate60, (sfVector2f){632.f, 250.f}, sfBlack, window);
    text_options(opt->music, (sfVector2f){432.f, 300.f}, sfBlack, window);
    text_options(opt->music10, (sfVector2f){432.f, 350.f}, sfBlack, window);
    text_options(opt->music50, (sfVector2f){532.f, 350.f}, sfBlack, window);
    text_options(opt->music80, (sfVector2f){632.f, 350.f}, sfBlack, window);
    text_options(opt->music100, (sfVector2f){732.f, 350.f}, sfBlack, window);
    text_options(opt->music0, (sfVector2f){842.f, 350.f}, sfBlack, window);
}
