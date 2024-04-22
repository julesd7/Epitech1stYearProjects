/*
** EPITECH PROJECT, 2023
** my_paint
** File description:
** check_sub_file
*/

#include "paint.h"

static int new_file(sfEvent event, write_t *write)
{
    if (event.type == sfEvtMouseButtonPressed &&
    event.mouseButton.x >= 0 &&
    event.mouseButton.x <= 100 &&
    event.mouseButton.y >= 35 &&
    event.mouseButton.y <= 65
    ) {
        sfRenderTexture_clear(write->file, sfWhite);
        return 1;
    }
    return 0;
}

static int open_file(sfEvent event, write_t *write)
{
    if (event.type == sfEvtMouseButtonPressed &&
    event.mouseButton.x >= 0 &&
    event.mouseButton.x <= 100 &&
    event.mouseButton.y >= 70 &&
    event.mouseButton.y <= 100
    ) {
        const sfTexture *load_file;
        sfImage *image = sfImage_createFromFile("My_paint.jpg");
        load_file = sfTexture_createFromImage(image, NULL);

        return 1;
    }
    return 0;
}

static int save_file(sfEvent event, write_t *write)
{
    if (event.type == sfEvtMouseButtonPressed &&
    event.mouseButton.x >= 0 &&
    event.mouseButton.x <= 100 &&
    event.mouseButton.y >= 105 &&
    event.mouseButton.y <= 135
    ) {
        const sfTexture *save_texture = sfRenderTexture_getTexture(write->file);
        sfImage *image = sfTexture_copyToImage(save_texture);
        sfImage_saveToFile(image, "My_paint.jpg");
        return 1;
    }
    return 0;
}

int check_sub_file(
    sfRenderWindow* window,
    sfEvent event,
    write_t *write,
    dropdown_menu_t menu
    )
{
    if (menu.file_menu == sfTrue) {
        if (new_file(event, write) == 1)
            return 0;
        if (open_file(event, write) == 1)
            return 0;
        if (save_file(event, write) == 1)
            return 0;
    }
}
