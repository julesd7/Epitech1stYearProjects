/*
** EPITECH PROJECT, 2022
** my_hunter
** File description:
** hunter.h
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>
#include <time.h>
#include <stdlib.h>

#include "utilities.h"
#include "sprite.h"
#include "text.h"
#include "texture.h"
#include "vector.h"
#include "music.h"

#ifndef _HUNTER_H
    #define _HUNTER_H

    char *itoa(int value, char *buffer);
    void init_vector(vector_t *vector);
    int init_utilities(utilities_t *utilities);
    int init_texture(texture_t *texture);
    int init_music(music_t *music);
    int init_text(text_t *text, vector_t vector);
    void init_sprite(sprite_t *sprite,
    texture_t texture, utilities_t utilities);
    void poll_event(utilities_t *utilities, sprite_t *sprite,
    text_t *text, vector_t *vector);
    void poll_event_sound(utilities_t *utilities, music_t *music);
    void render_hunt(utilities_t *utilities,
    sprite_t *sprite, text_t *text);
    void render_bonus_hunt(utilities_t *utilities,
    sprite_t *sprite, text_t *text, vector_t *vector);
    void utilities_events(utilities_t *utilities, music_t *music);
    void vector_events(utilities_t *utilities, vector_t *vector, text_t *text);
    void is_game_over(utilities_t *utilities);
    void ducks_animate(utilities_t *utilities,
    sprite_t *sprite, vector_t *vector);

#endif /* !_HUNTER_H */
