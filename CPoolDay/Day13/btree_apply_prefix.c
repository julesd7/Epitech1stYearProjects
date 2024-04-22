/*
** EPITECH PROJECT, 2022
** apply prefix
** File description:
** apply prefix
*/

#include <stdlib.h>
#include "btree.h"

void btree_apply_prefix(btree_t *root, int (*applyf)(void *))
{
    (*applyf)(root->item);
    if (root->right != NULL)
        btree_apply_prefix(root->right, applyf);
    if (root->left != NULL)
        btree_apply_prefix(root->left, applyf);
}
