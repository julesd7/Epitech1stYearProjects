/*
** EPITECH PROJECT, 2022
** my hunter
** File description:
** mainc
*/

#include "hunter.h"

utilities_t utilities;
music_t music;
sprite_t sprite;
text_t text;
texture_t texture;
vector_t vector;

static int init(void)
{
    init_vector(&vector);
    if (
    init_utilities(&utilities) == 84 ||
    init_texture(&texture) == 84 ||
    init_music(&music) ||
    init_text(&text, vector) == 84
    ) {
        return 84;
    }
    init_sprite(&sprite, texture, utilities);
    return 0;
}

static void destroy(void)
{
    sfRenderWindow_destroy(utilities.window);
    sfTexture_destroy(texture.texture);
    sfTexture_destroy(texture.back_screen);
    sfTexture_destroy(texture.loose);
    sfTexture_destroy(texture.texture_bonus);
    sfSprite_destroy(sprite.sprite);
    sfSprite_destroy(sprite.back);
    sfSprite_destroy(sprite.bonus);
    sfFont_destroy(text.font);
    sfText_destroy(text.text);
    sfText_destroy(text.score);
    sfText_destroy(text.life_text);
    sfText_destroy(text.life_count);
    sfMusic_destroy(music.main);
    sfMusic_destroy(music.shoot);
}

int main(void)
{
    if (init() == 84)
        return 84;
    sfMusic_play(music.main);
    sfMusic_setLoop(music.main, sfTrue);
    while (sfRenderWindow_isOpen(utilities.window)) {
        while (sfRenderWindow_pollEvent(utilities.window, &utilities.event)) {
            poll_event(&utilities, &sprite, &text, &vector);
            poll_event_sound(&utilities, &music);
        }
        if (utilities.is_bonus == 10 || utilities.show == 1)
            render_bonus_hunt(&utilities, &sprite, &text, &vector);
        else
            render_hunt(&utilities, &sprite, &text);
        utilities_events(&utilities, &music);
        vector_events(&utilities, &vector, &text);
        is_game_over(&utilities);
        ducks_animate(&utilities, &sprite, &vector);
    }
    destroy();
    return 0;
}
