#include <stdio.h>
#include <stdlib.h>

#include "bst.h"

void bst_create_test(int a, int b) {
    t_btree *root1 = bstree_create_node(a);
    if (root1 != NULL) printf("%d\n", root1->item);
    t_btree *root2 = bstree_create_node(b);
    if (root2 != NULL) printf("%d\n", root2->item);
    if (root1 != NULL) free(root1);
    if (root2 != NULL) free(root2);
}

int main() {
    bst_create_test(10, 11);
    return 0;
}