#include <stdio.h>

#include "binary_tree.h"

int main()
{
    BINARY_TREE binaryTreeInfo = {};
    binary_tree_ctor(&binaryTreeInfo, 10);
    binary_tree_add_element(&binaryTreeInfo, 20);
    binary_tree_add_element(&binaryTreeInfo, 100);
    binary_tree_add_element(&binaryTreeInfo, 10);
    binary_tree_add_element(&binaryTreeInfo, 10);
    binary_tree_add_element(&binaryTreeInfo, 10);
    binary_tree_add_element(&binaryTreeInfo, 10);
    // printf("node_element = %d\n", binaryTreeInfo.memory[0].element);

    return 0;
}
