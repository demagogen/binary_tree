#ifndef BINARY_TREE_H_
#define BINARY_TREE_H_

#include "binary_tree_typedefs.h"

int binary_tree_ctor (BINARY_TREE* binaryTreeInfo, size_t capacity);
int binary_tree_dtor (BINARY_TREE* binaryTreeInfo);
int binary_tree_add_element(BINARY_TREE* binaryTreeInfo, NodeElem_t element);

#endif
