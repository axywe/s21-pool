#include <stdio.h>
#include <stdlib.h>

#include "bst.h"

void destroy(t_btree *root) {
    if (root != NULL) {
        destroy(root->left);
        destroy(root->right);
        free(root);
    }
}

void bst_traverse_test(int a, int b, int c, int d, int e, int f) {
    t_btree *root = bstree_create_node(a);
    int (*cmp)(int, int) = &compare;
    bstree_insert(root, b, cmp);
    bstree_insert(root, c, cmp);
    bstree_insert(root, d, cmp);
    bstree_insert(root, e, cmp);
    bstree_insert(root, f, cmp);
    if (root != NULL) {
        printf("Pre-order: ");
        bstree_apply_prefix(root, print);
        printf("\nIn-order: ");
        bstree_apply_infix(root, print);
        printf("\nPost-order: ");
        bstree_apply_postfix(root, print);
        printf("\b");
        destroy(root);
    }
}

int main() {
    printf("Test 1:\n");
    bst_traverse_test(10, 11, 8, 12, 5, 1);
    printf("\nTest 2:\n");
    bst_traverse_test(15, 48, 13, 55, 84, 21);
    printf("\nTest 3:\n");
    bst_traverse_test(21, 13, 55, 33, 2, 1);
    return 0;
}