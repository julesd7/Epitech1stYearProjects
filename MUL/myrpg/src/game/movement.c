/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** movement.c
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>

#include "character.h"
#include "menu.h"
#include "rpg.h"

static void animate(mainchar_t *charact, int check, int state)
{
    if (check != 0) {
        charact->tmp += 75;
        if ((charact->tmp == 300 && state == 1) ||
            (charact->tmp == 600 && state == 2)) {
            charact->rect.left += 102;
            charact->tmp = 0;
        }
    } else
        charact->rect.left = 204;
}

static int move2(mainchar_t *charact, menu_t *menu, int check)
{
    if (sfKeyboard_isKeyPressed(sfKeyLeft)) {
        if (menu->tmp_states == 1)
            check_left_collision_30fps(charact);
        else
            check_left_collision_60fps(charact);
        check++;
    }
    if (sfKeyboard_isKeyPressed(sfKeyRight)) {
        if (menu->tmp_states == 1)
            check_right_collision_30fps(charact);
        else
            check_right_collision_60fps(charact);
        check++;
    }
    return check;
}

void move(mainchar_t *charact, menu_t *menu)
{
    int check = 0;
    if (charact->rect.left >= 500)
        charact->rect.left = 0;
    if (sfKeyboard_isKeyPressed(sfKeyUp)) {
        if (menu->tmp_states == 1)
            check_up_collision_30fps(charact);
        else
            check_up_collision_60fps(charact);
        check++;
    }
    if (sfKeyboard_isKeyPressed(sfKeyDown)) {
        if (menu->tmp_states == 1)
            check_down_collision_30fps(charact);
        else
            check_down_collision_60fps(charact);
        check++;
    }
    check = move2(charact, menu, check);
    animate(charact, check, menu->tmp_states);
}
