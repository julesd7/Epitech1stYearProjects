/*
** EPITECH PROJECT, 2022
** my sort int array
** File description:
** sorts an char** in
** ascending order given
*/

#include <stddef.h>

#include "../include/lib.h"

static void swapping(char **buffer, int place, int i)
{
    char *temp = buffer[place];
    buffer[place] = buffer[i];
    buffer[i] = temp;
}

static int is_point(char **array, int actual_place, int compare)
{
    int i = 0;
    int verify_place = array[actual_place][i];
    if (verify_place == 46) {
        i = 1;
        verify_place = array[actual_place][i];
    }
    if (verify_place >= 65) {
        if (verify_place <= 90)
            verify_place += 32;
    }
    int vrif = array[compare][i];
    if (vrif >= 65 && vrif <= 90) {
            vrif += 32;
    }
    if (compare != 0) {
        if (vrif == verify_place) {
            return 200;
        }
    }
    return verify_place;
}

static int try_another_compare(char **array, int actual_place,\
int count, int ret)
{
    int verify_place = is_point(array, actual_place, 0);
    int verify_count = is_point(array, count, actual_place);
    int i = 1;
    if (verify_count == 200) {
        verify_place = array[actual_place][i];
        verify_count = array[count][i];
        if (verify_place >= 65 && verify_place <= 90)
            verify_place += 32;
        if (verify_count >= 65 && verify_count)
            verify_count += 32;
        if (verify_count == verify_place) {
            i++;
        }
    }
    if (ret == 1)
        return verify_count;
    return verify_place;
}

static int get_new_one(char **array, int count, int actual_place)
{
    int change_it = 0;
    int verify_place = is_point(array, actual_place, 0);
    int save = verify_place;
    int verify_upper;
    int mini = 122;

    while (array[count] != NULL) {
        verify_upper = is_point(array, count, actual_place);
        if (verify_upper == 200) {
            verify_upper = try_another_compare(array, actual_place, count, 1);
            verify_place = try_another_compare(array, actual_place, count, 0);
        }
        if (verify_place > verify_upper && mini > verify_upper) {
            change_it = count;
            mini = verify_upper;
        }
        verify_place = save;
        count++;
    }
    return change_it;
}

void my_sort_char_array(char **array)
{
    int change_it = 0;
    for (int actual_place = 0; array[actual_place] != NULL; actual_place++) {
        change_it = get_new_one(array, actual_place, actual_place);
        if (change_it != 0)
            swapping(array, actual_place, change_it);
    }
}
