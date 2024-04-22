/*
** EPITECH PROJECT, 2022
** btree apply suffix
** File description:
** btree apply suffix
*/

#include <stdlib.h>
#include "btree.h"

void btree_apply_suffix(btree_t *root, int (*applyf)(void *))
{
    if (root->right != NULL)
        btree_apply_suffix(root->right, applyf);
    if (root->left != NULL)
        btree_apply_suffix(root->left, applyf);
    (*applyf)(root->item);
}
