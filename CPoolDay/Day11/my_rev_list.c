/*
** EPITECH PROJECT, 2022
** my rev list
** File description:
** my rev list
*/

#include <stddef.h>
#include "mylist.h"

void my_rev_list(linked_list_t **begin)
{
    linked_list_t* rev = *begin;
    linked_list_t* stock = 0;
    linked_list_t* n;

    while (rev->next) {
        n = rev->next;
        rev->next = stock;
        stock = rev;
        rev = n;
    }
    rev->next = stock;
    *begin = rev;
}
