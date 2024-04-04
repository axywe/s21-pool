#ifndef BSTREE_H
#define BSTREE_H

// Tree Structure
typedef struct s_btree {
    struct s_btree *left;
    struct s_btree *right;
    char data;
} t_btree;

t_btree *bstree_create_node(char data);

void bstree_apply_prefix(t_btree *root, void (*)(char));
void applyf(char value);
void destroyer(t_btree *root);
int is_alpha(char c);
#endif
