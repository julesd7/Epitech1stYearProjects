/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** collision
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>

#include "character.h"
#include "rpg.h"

static void check_down_0_state(mainchar_t *c, int check)
{
    if (check <= 155 ||
    (c->move.x >= 1337 && c->move.x <= 1372 &&
    check <= 360 && check >= 155) ||
    (check <= 550 && check >= 340 && c->move.x <= 187) ||
    (check <= 550 && check >= 360 && c->move.x >= 188))
        c->move.y += 2.5;
}

void check_down_collision_60fps(mainchar_t *c)
{
    int check = c->move.y + 2.5;

    if (c->state <= 1) {
        check_down_0_state(c, check);
        return;
    }
    if (check <= 155 ||
    (c->move.x >= 1337 && c->move.x <= 1372 &&
    check <= 360 && check >= 155) ||
    (check <= 550 && check >= 340 && c->move.x <= 187) ||
    (check <= 550 && check >= 360 && c->move.x >= 188) ||
    (check <= 915 && check >= 785 && c->move.x >= 592) ||
    (check <= 915 && check >= 550 && c->move.x >= 1082 && c->move.x <= 1302) ||
    (check <= 915 && check >= 670 && c->move.x >= 612 && c->move.x <= 637) ||
    (check <= 690 && check >= 670 && c->move.x <= 1012 && c->move.x >= 297) ||
    (check <= 780 && check >= 690 && c->move.x <= 327 && c->move.x >= 297) ||
    (check <= 780 && check >= 750 && c->move.x <= 297 && c->move.x >= 102) ||
    (check <= 780 && check >= 670 && c->move.x <= 127 && c->move.x >= 102))
        c->move.y += 2.5;
}

void check_up_collision_60fps(mainchar_t *c)
{
    int check = c->move.y - 2.5;
    if ((check >= 30 && check <= 155) ||
    (c->move.x >= 1337 && c->move.x <= 1372 &&
    check <= 360 && check >= 155) ||
    (check <= 550 && check >= 340 && c->move.x <= 187) ||
    (check <= 550 && check >= 360 && c->move.x >= 262) ||
    (check <= 550 && check >= 415 && c->move.x >= 187 && c->move.x <= 262) ||
    (check <= 915 && check >= 800 && c->move.x >= 592) ||
    (check <= 915 && check >= 670 && c->move.x >= 612 && c->move.x <= 637) ||
    (check <= 915 && check >= 550 &&
    c->move.x >= 1082 && c->move.x <= 1302) ||
    (check <= 690 && check >= 670 && c->move.x <= 1012 && c->move.x >= 297) ||
    (check <= 780 && check >= 690 && c->move.x <= 327 && c->move.x >= 297) ||
    (check <= 780 && check >= 750 && c->move.x <= 297 && c->move.x >= 102) ||
    (check <= 780 && check >= 670 && c->move.x <= 127 && c->move.x >= 102))
        c->move.y -= 2.5;
}

void check_right_collision_60fps(mainchar_t *c)
{
    int check = c->move.x + 2.5;
    if ((check <= 1667 && c->move.y <= 155) ||
    (c->move.y >= 155 && c->move.y <= 360 &&
    check >= 1337 && check <= 1372) ||
    (check <= 1792 && check >= 262 && c->move.y >= 360 && c->move.y <= 410) ||
    (check <= 187 && check >= 32 && c->move.y >= 340 && c->move.y <= 410) ||
    (check <= 1792 && c->move.y >= 410 && c->move.y <= 550) ||
    (check <= 1302 && check >= 1082 &&
    c->move.y >= 550 && c->move.y <= 785) ||
    (check <= 1537 && c->move.y >= 785 && c->move.y <= 915) ||
    (check <= 1012 && check >= 297 && c->move.y >= 670 && c->move.y <= 690) ||
    (check <= 327 && check >= 297 && c->move.y >= 670 && c->move.y <= 780) ||
    (check <= 637 && check >= 612 && c->move.y >= 670 && c->move.y <= 780) ||
    (check <= 327 && check >= 102 && c->move.y >= 750 && c->move.y <= 780) ||
    (check <= 127 && check >= 102 && c->move.y >= 670 && c->move.y <= 780))
        c->move.x += 2.5;
}

void check_left_collision_60fps(mainchar_t *c)
{
    int check = c->move.x - 2.5;
    if ((check >= 1042 && c->move.y <= 155) ||
    (c->move.y >= 155 && c->move.y <= 360 &&
    check >= 1337 && check <= 1372) ||
    (check >= 262 && c->move.y >= 360 && c->move.y <= 410) ||
    (check <= 1792 && check >= 32 && c->move.y >= 410 && c->move.y <= 550) ||
    (check <= 187 && check >= 32 && c->move.y >= 340 && c->move.y <= 410) ||
    (check >= 1082 && c->move.y >= 550 && c->move.y <= 785) ||
    (check >= 592 && c->move.y >= 785 && c->move.y <= 915) ||
    (check >= 297 && check <= 1012 && c->move.y >= 670 && c->move.y <= 690) ||
    (check >= 297 && check <= 327 && c->move.y >= 670 && c->move.y <= 780) ||
    (check <= 637 && check >= 612 && c->move.y >= 670 && c->move.y <= 780) ||
    (check >= 102 && check <= 327 && c->move.y >= 750 && c->move.y <= 780) ||
    (check >= 102 && check <= 127 && c->move.y >= 670 && c->move.y <= 780))
        c->move.x -= 2.5;
}
