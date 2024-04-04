#include <stdio.h>
#include <stdlib.h>

#include "bst.h"

void bst_insert_test(int a, int b, int c) {
    t_btree *root = bstree_create_node(a);
    int (*cmp)(int, int) = &compare;
    bstree_insert(root, b, cmp);
    bstree_insert(root, c, cmp);
    if (root != NULL) {
        printf("Root: %d\n", root->item);
        if (root->left != NULL) {
            printf("Left: %d\n", root->left->item);
            free(root->left);
        }
        if (root->right != NULL) {
            printf("Right: %d\n", root->right->item);
            free(root->right);
        }
        free(root);
    }
}

int main() {
    bst_insert_test(10, 11, 8);
    return 0;
}