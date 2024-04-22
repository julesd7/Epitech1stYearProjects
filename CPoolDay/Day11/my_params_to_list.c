/*
** EPITECH PROJECT, 2022
** my params to list
** File description:
** my params to list
*/

#include <stdlib.h>
#include "mylist.h"

int add_in_list(linked_list_t **list, char *data)
{
    linked_list_t *newone;

    newone = malloc(sizeof(*newone));
    if (newone == NULL)
        return 1;
    newone->data = data;
    newone->next = *list;
    *list = newone;
    return 0;
}

linked_list_t *my_params_to_list(int ac, char * const *av)
{
    linked_list_t *list = NULL;
    int i = 0;

    while (i < ac) {
        add_in_list(&list, av[i]);
        i++;
    }
    return list;
}
