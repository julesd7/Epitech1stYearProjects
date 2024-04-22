/*
** EPITECH PROJECT, 2022
** my ls
** File description:
** open_file.c
*/

#include <dirent.h>
#include <unistd.h>
#include <stdlib.h>

#include "my_ls.h"

static char **str_to_word_array(char *temp, char **buffer, int nb_files)
{
    int charact_place = 0;
    int charact = 0;
    int place_in_array = 0;

    while (nb_files > 0) {
        for (charact_place = 0; temp[charact] != ' '; charact_place++) {
            buffer[place_in_array][charact_place] = temp[charact];
            charact++;
        }
        buffer[place_in_array][charact_place + 1] = '\0';
        place_in_array++;
        charact++;
        nb_files--;
    }
    buffer[place_in_array] = '\0';
    my_sort_char_array(buffer);
    return buffer;
}

static char **get_array(char *temp, int nb_files)
{
    int i = 0;
    int number_word = 0;
    int charact = 0;
    int save = nb_files;

    char **buffer = malloc(sizeof(char *) * (nb_files + 1));

    while (nb_files > 0) {
        for (number_word = 0; temp[charact] != ' '; number_word++)
            charact++;

        buffer[i] = malloc(sizeof(char *) * (number_word + 1));

        i++;
        charact++;
        nb_files--;
    }
    return str_to_word_array(temp, buffer, save);
}

char **open_file(char *file)
{
    DIR *dir;
    struct dirent *dent;
    char temp[10000];

    dir = opendir(file);
    int nb_files = 0;
    if (dir != NULL) {
        while ((dent = readdir(dir)) != NULL) {
            my_strcat(temp, dent->d_name);
            my_strcat(temp, " ");
            nb_files++;
        }
    }
    char **buffer = get_array(temp, nb_files);
    closedir(dir);
    return buffer;
}
