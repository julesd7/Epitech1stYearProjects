/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** about_game.c
*/
#include "menu.h"
#include "../../include/rpg.h"

static void destroy_all(about_t *abt)
{
    sfText_destroy(abt->game_spr);
    sfText_destroy(abt->lore_spr);
    sfText_destroy(abt->game_spr2);
    sfText_destroy(abt->welc);
}

static void text_about_game(about_t *abt)
{
    abt->welcome = "WELCOME EVERYONE TO OUR GAME";
    abt->lore = "The goal of this game is to save your lovely daughter";
    abt->game = "How to play :\nUse your key arrows and move the character";
    abt->game2 = "Use 'E' to interact with npc\n\
Use 'Space' or 'Enter' for dialogues";
    abt->explstr = "To come back to previous page press escape";
    sfFont *font = init_font("src/resources/police/BouwsUnc.ttf");
    abt->welc = init_text(abt->welcome, font, 55);
    abt->lore_spr = init_text(abt->lore, font, 35);
    abt->game_spr = init_text(abt->game, font, 35);
    abt->game_spr2 = init_text(abt->game2, font, 35);
    abt->expl = init_text(abt->explstr, font, 35);
}

static void display_all(about_t *abt, sfRenderWindow *window)
{
    text_options(abt->welc, (sfVector2f) {400.f, 200.f}, sfBlack, window);
    text_options(abt->lore_spr, (sfVector2f) {400.f, 300.f}, sfBlack, window);
    text_options(abt->game_spr, (sfVector2f) {400.f, 380.f}, sfBlack, window);
    text_options(abt->game_spr2, (sfVector2f) {400.f, 480.f}, sfBlack, window);
    text_options(abt->expl, (sfVector2f) {400.f, 680.f}, sfBlack, window);
}

void about_game(sfRenderWindow *window, menu_t *menu)
{
    about_t abt;
    sfEvent event;
    int tmp = 0;
    text_about_game(&abt);
    while (sfRenderWindow_isOpen(window) && tmp == 0) {
        while (sfRenderWindow_pollEvent(window, &event))
            poll_event(window, event, menu);
        if (sfKeyboard_isKeyPressed(sfKeyEscape))
            tmp = 1;
        sfRenderWindow_drawSprite(window, menu->menu, NULL);
        display_all(&abt, window);
        sfRenderWindow_display(window);
    }
    destroy_all(&abt);
    return;
}
