#include "binary_tree.h"

TREE_ERROR tree_ctor(TREE* treeInfo)
{
    assert(treeInfo);

    treeInfo->capacity = StartCapacity;

    treeInfo->root = (NODE* ) calloc(1, sizeof(NODE));

    treeInfo->root->left   = NULL;
    treeInfo->root->right  = NULL;
    treeInfo->root->parent = NULL;

    treeInfo->error = TREE_NONE;

    return treeInfo->error;
}

TREE_ERROR tree_dtor(TREE* treeInfo)
{
    assert(treeInfo);

    treeInfo->capacity = TREE_POISON;

    treeInfo->root->left   = NULL;
    treeInfo->root->right  = NULL;
    treeInfo->root->parent = NULL;

    treeInfo->error = TREE_DED_INSIDE;

    return treeInfo->error;
}

NODE* tree_node_ctor(NodeElem_t element)
{
    assert(element);

    NODE* newNodeInfo = (NODE* ) calloc(1, sizeof(NODE));

    newNodeInfo->element = element;

    newNodeInfo->parent  = NULL;
    newNodeInfo->left    = NULL;
    newNodeInfo->right   = NULL;

    return newNodeInfo;
}

TREE_ERROR tree_add(TREE* treeInfo, NODE* parentNodeInfo, TREE_UTILS add_rule, NodeElem_t element)
{
    assert(treeInfo);
    // assert(parentNodeInfo);

    switch(add_rule)
    {
        case(RIGHT):
            parentNodeInfo->right = tree_node_ctor(element);
            parentNodeInfo->right->parent = parentNodeInfo;
            break;

        case(LEFT):
            parentNodeInfo->left = tree_node_ctor(element);
            parentNodeInfo->left->parent = parentNodeInfo;
            break;

        case(ROOT):
            treeInfo->root->element = element;

        default:
            return TREE_ERROR_SIDE;
    }

    treeInfo->capacity++;

    return treeInfo->error;
}

TREE_ERROR tree_node_dtor(NODE* nodeInfo)
{
    assert(nodeInfo);

    if (!nodeInfo)
    {
        return TREE_NODE_ALLOCATION_ERROR;
    }

    nodeInfo->right   = NULL;
    nodeInfo->left    = NULL;
    nodeInfo->parent  = NULL;
    nodeInfo->element = NULL;

    return TREE_NONE;
}
