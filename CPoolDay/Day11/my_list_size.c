/*
** EPITECH PROJECT, 2022
** my list size
** File description:
** my list size
*/

#include "mylist.h"

int my_list_size(linked_list_t const *begin)
{
    int size = 0;
    linked_list_t* s = begin;

    while (s) {
        size++;
        s = s->next;
    }
    return size;
}
