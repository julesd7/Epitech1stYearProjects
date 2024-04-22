/*
** EPITECH PROJECT, 2022
** btree_search_item
** File description:
** btree_search_item
*/

#include <stdlib.h>
#include "btree.h"

void *btree_search_item(btree_t const *root,
    void const *data_ref, int (*cmpf)())
{
    void *res;

    res = NULL;
    if (root != NULL) {
        res = btree_search_item(root->left, data_ref, cmpf);
        if (res == NULL && ((cmpf)(root->item, data_ref)) == 0)
            res = root->item;
        if (res == NULL)
            res = btree_search_item(root->right, data_ref, cmpf);
    }
    return res;
}
