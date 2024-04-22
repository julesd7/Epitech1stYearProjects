/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** destroy_txt.c
*/
#include "rpg.h"

void destroy_menu(menu_t *menu)
{
    sfText_destroy(menu->load);
    sfText_destroy(menu->save);
    sfText_destroy(menu->play);
    sfText_destroy(menu->options);
    sfText_destroy(menu->about);
}
