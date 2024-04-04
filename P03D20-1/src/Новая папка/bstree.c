#include "bstree.h"

#include <stdio.h>
#include <stdlib.h>

t_btree *bstree_create_node(char data) {
    t_btree *root = malloc(sizeof(t_btree));
    (*root).data = data;
    (*root).left = NULL;
    (*root).right = NULL;
    return root;
}

void bstree_apply_prefix(t_btree *root, void (*applyf)(char)) {
    if (root == NULL) return;
    applyf((*root).value);
    if ((*root).left != NULL) bstree_apply_infix((*root).left, applyf);
    if ((*root).right != NULL) bstree_apply_infix((*root).right, applyf);
}

void applyf(char value) {
    printf("%s", value);
    return;
}

void destroyer(t_btree *root) {
    if (root == NULL) return;
    destroyer((*root).left);
    destroyer((*root).right);
    free(root);
}

// alphabet letter
int is_alpha(char c) {
    int result = 0;
    if ((c >= 97) && (c <= 122)) result = 1;
    if ((c >= 65) && (c <= 90)) result = 1;
    return result;
}
