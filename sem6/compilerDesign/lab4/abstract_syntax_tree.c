#include "abstract_syntax_tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

expression_node *init_exp_node(char *val, expression_node *left,
                               expression_node *right) {
  // function to allocate memory for an AST node and set the left and right
  // children of the nodes
  expression_node *new_node =
      (expression_node *)malloc(sizeof(expression_node));
  if (new_node == NULL) {
    fprintf(stderr, "Memory allocation failed\n");
    exit(1);
  }

  new_node->val = strdup(val);
  new_node->left = left;
  new_node->right = right;

  return new_node;
}

void display_exp_tree(expression_node *exp_node) {
  // traversing the AST in preorder and displaying the nodes
  if (exp_node == NULL)
    return;

  printf("%s\n", exp_node->val);
  display_exp_tree(exp_node->left);
  display_exp_tree(exp_node->right);
}
