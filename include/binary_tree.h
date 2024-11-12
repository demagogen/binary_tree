#ifndef BINARY_TREE_H_
#define BINARY_TREE_H_

#include "binary_tree_typedefs.h"

TREE_ERROR tree_ctor      (TREE* treeInfo);
TREE_ERROR tree_dtor      (TREE* treeInfo);
NODE*      tree_node_ctor (NodeElem_t element);
TREE_ERROR tree_node_dtor (NODE* nodeInfo);
TREE_ERROR tree_add       (TREE* treeInfo, NODE* newNodeInfo, TREE_UTILS add_rule, NodeElem_t element);

#endif
