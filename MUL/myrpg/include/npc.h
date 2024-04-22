/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** npc.h
*/

#ifndef _NPC_H
    #define _NPC_H

    #include <SFML/Graphics.h>
    #include <SFML/Window.h>

    typedef struct npc {
        sfSprite *Shane;
        sfIntRect rectangle;
        sfVector2f move;
        int state;
    }npc_t;

#endif /* !_NPC_H */
