#include "bst.h"

#include <stdio.h>
#include <stdlib.h>

t_btree *bstree_create_node(int item) {
    t_btree *tmp = NULL;
    tmp = (t_btree *)malloc(sizeof(t_btree));
    tmp->left = NULL;
    tmp->right = NULL;
    tmp->item = item;
    return tmp;
}

void bstree_insert(t_btree *root, int item, int (*cmpf)(int, int)) {
    if (root != NULL) {
        while (cmpf(root->item, item) && root->left != NULL) root = root->left;
        while (!cmpf(root->item, item) && root->right != NULL) root = root->right;
        if (cmpf(root->item, item))
            root->left = bstree_create_node(item);
        else
            root->right = bstree_create_node(item);
    }
}

int compare(int a, int b) { return a > b ? 1 : 0; }

void print(int a) { printf("%d ", a); }

void bstree_apply_prefix(t_btree *root, void (*applyf)(int)) {
    if (root != NULL) {
        applyf(root->item);
        bstree_apply_prefix(root->left, applyf);
        bstree_apply_prefix(root->right, applyf);
    }
}

void bstree_apply_infix(t_btree *root, void (*applyf)(int)) {
    if (root != NULL) {
        bstree_apply_infix(root->left, applyf);
        applyf(root->item);
        bstree_apply_infix(root->right, applyf);
    }
}

void bstree_apply_postfix(t_btree *root, void (*applyf)(int)) {
    if (root != NULL) {
        bstree_apply_infix(root->left, applyf);
        bstree_apply_infix(root->right, applyf);
        applyf(root->item);
    }
}