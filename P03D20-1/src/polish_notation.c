#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "giga_main.h"
typedef struct t_btree {
    char op_type;
    int prioritet;
    char* data;
    struct t_btree* left;
    struct t_btree* right;
} t_btree;

t_btree* bstree_create_node(char op_type, int prioritet, char* data);
t_btree* tree_create(t_list* lexems);
t_btree* bstree_insert(t_btree* root, t_btree* node, int (*cmpf)(int, int));
void bstree_apply_prefix(t_btree* root, void (*applyf)(char*));
void destroyer(t_btree* root);

int comparing(int a, int b);
void applyf(char* data);
int calc_prioritet(char c);
char calc_type(char c);

int main() {
    t_list* lexems = main_parser();
    t_btree* root = tree_create(lexems);
    printf("\n");
    bstree_apply_prefix(root, applyf);
    destroy(lexems);
    destroyer(root);
    return 0;
}

t_btree* tree_create(t_list* lexems) {
    t_list* tmp = lexems;
    t_btree* root = NULL;
    t_btree* current_operator = NULL;
    t_btree* prev_operator = NULL;
    t_btree* operand = NULL;
    int bracket_bonus = 0;

    while (tmp != NULL) {
        char result_type = ' ';
        int prioritet = -1;
        char* data = tmp->value;

        if (data[0] == '(') {
            bracket_bonus += 10;
        } else if (data[0] == ')') {
            bracket_bonus -= 10;
        } else {
            result_type = calc_type(data[0]);
            prioritet = calc_prioritet(data[0]) + bracket_bonus;
            t_btree* node = bstree_create_node(result_type, prioritet, data);

            if (result_type == 'N' || result_type == 'P') {
                operand = node;
            } else {
                current_operator = node;

                if (prev_operator != NULL) {
                    if (current_operator->prioritet <= prev_operator->prioritet) {
                        prev_operator->right = operand;
                        operand = prev_operator;
                        prev_operator = current_operator;
                    } else {
                        current_operator->left = prev_operator->right;
                        prev_operator->right = current_operator;
                        prev_operator = current_operator;
                        current_operator = operand;
                    }
                } else {
                    prev_operator = current_operator;
                    current_operator = operand;
                }
            }
        }

        tmp = tmp->next;
    }

    if (prev_operator != NULL) {
        prev_operator->right = operand;
        root = prev_operator;
    } else {
        root = operand;
    }

    return root;
}

t_btree* bstree_create_node(char op_type, int prioritet, char* data) {
    t_btree* root = malloc(sizeof(t_btree));

    (*root).op_type = op_type;
    (*root).prioritet = prioritet;
    (*root).data = data;

    (*root).left = NULL;
    (*root).right = NULL;

    return root;
}

t_btree* bstree_insert(t_btree* root, t_btree* node, int (*cmpf)(int, int)) {
    if (root == NULL) root = node;
    switch (cmpf((*root).prioritet, (*node).prioritet)) {
        case (-1):
            if ((*root).left != NULL)
                bstree_insert((*root).left, node, cmpf);
            else
                (*root).left = node;
            break;
        case (1):
            if ((*root).right != NULL)
                bstree_insert((*root).right, node, cmpf);
            else
                (*root).right = node;
            break;
        default:;
    }
    return root;
}
void bstree_apply_prefix(t_btree* root, void (*applyf)(char*)) {
    if (root == NULL) return;

    applyf(root->data);
    if (root->op_type != 'N' && root->op_type != 'P') {
        bstree_apply_prefix(root->left, applyf);
        bstree_apply_prefix(root->right, applyf);
    } else {
        bstree_apply_prefix(root->right, applyf);
        bstree_apply_prefix(root->left, applyf);
    }
}

int comparing(int a, int b) {
    int result = 0;
    if (a > b) result = 1;
    if (b > a) result = -1;
    return result;
}

char calc_type(char c) {
    char result_type = 'O';
    if (is_digit(c)) result_type = 'N';
    if (c == 'x') result_type = 'P';
    return result_type;
}
int calc_prioritet(char c) {
    int prioritet = -1;
    if (c == 's' || c == 'c' || c == 't' || c == 'C' || c == 'S' || c == 'l') prioritet = 4;
    if (c == '~') prioritet = 3;
    if (c == '*' || c == '/') prioritet = 2;
    if (c == '+' || c == '-') prioritet = 1;
    if (c == '(') prioritet = 0;
    return prioritet;
}
void applyf(char* data) {
    printf("%s", data);
    return;
}
void destroyer(t_btree* root) {
    if (root == NULL) return;
    destroyer((*root).left);
    destroyer((*root).right);
    free(root);
}
