/*
** EPITECH PROJECT, 2022
** btree
** File description:
** btree
*/

#include <stdlib.h>
#include "btree.h"

btree_t *btree_create_node(void *item)
{
    btree_t *new = malloc(sizeof(btree_t));
    new->item = item;
    new->right = NULL;
    new->left = NULL;

    return new;
}
