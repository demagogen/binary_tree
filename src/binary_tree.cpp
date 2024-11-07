#include "binary_tree.h"

int binary_tree_ctor(BINARY_TREE* binaryTreeInfo, size_t capacity)
{
    assert(binaryTreeInfo);

    if (capacity == 0)
    {
        capacity = StartCapacity;
    }

    binaryTreeInfo->free     = 0;
    binaryTreeInfo->capacity = capacity;
    binaryTreeInfo->length   = 0;

    binaryTreeInfo->memory   = (NODE* ) calloc(capacity, sizeof(NODE));
    binaryTreeInfo->root     = &binaryTreeInfo->memory[binaryTreeInfo->free];

    (*binaryTreeInfo->root).element = -1;

    binaryTreeInfo->free++;
    binaryTreeInfo->length++;

    return 0;
}

int binary_tree_dtor(BINARY_TREE* binaryTreeInfo)
{
    assert(binaryTreeInfo);

    binaryTreeInfo->free     = -1;
    binaryTreeInfo->capacity = -1;
    binaryTreeInfo->root     = NULL;

    free(binaryTreeInfo->memory);

    return 0;
}

/*
    TODO define condition for binary_tree_add_element.
         Make define for add element in left and right,
         make define for condition in binary_tree_add...
*/

int binary_tree_add_element(BINARY_TREE* binaryTreeInfo, NodeElem_t element)
{
    assert(binaryTreeInfo);

    if (binaryTreeInfo->length == 1)
    {
        binaryTreeInfo->memory[0].element = element;
        printf("binaryTreeInfo->memory[0].element = %d\n", binaryTreeInfo->memory[0].element);
        binaryTreeInfo->length++;

        return 0;
    }
    else
    {
        for (size_t node_index = 0; node_index < binaryTreeInfo->length; node_index++)
        {
            if (element >= binaryTreeInfo->memory[node_index].element)
            {
                binaryTreeInfo->memory[node_index].right_node = &(binaryTreeInfo->memory[binaryTreeInfo->free]);
                binaryTreeInfo->memory[binaryTreeInfo->free].element = element;
                printf("right binaryTreeInfo->memory[binaryTreeInfo->free].element = %d\n", binaryTreeInfo->memory[binaryTreeInfo->free].element);
                binaryTreeInfo->free++;
                binaryTreeInfo->length++;

                return 0;
            }
            else
            {
                binaryTreeInfo->memory[node_index].left_node = &(binaryTreeInfo->memory[binaryTreeInfo->free]);
                binaryTreeInfo->memory[binaryTreeInfo->free].element = element;
                printf("left binaryTreeInfo->memory[binaryTreeInfo->free].element = %d\n", binaryTreeInfo->memory[binaryTreeInfo->free].element);
                binaryTreeInfo->free++;
                binaryTreeInfo->length++;

                return 0;
            }
        }
    }

    return -1;
}
