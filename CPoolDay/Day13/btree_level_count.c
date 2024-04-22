/*
** EPITECH PROJECT, 2022
** btree_level_count
** File description:
** btree_level_count
*/

#include <stddef.h>
#include "btree.h"

int ret(int a, int b)
{
    return (a > b ? a : b);
}

size_t btree_level_count(btree_t const *root)
{
    size_t res = 0;

    if (root != NULL)
        return (1 + ret(btree_level_count(root->left), \
                btree_level_count(root->right)));
    return 0;
}
