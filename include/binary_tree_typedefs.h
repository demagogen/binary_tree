#ifndef BINARY_TREE_TYPEDEFS_H_
#define BINARY_TREE_TYPEDEFS_H_

#include <cstddef>
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

typedef int NodeElem_t;

const size_t StartCapacity = 16;

struct NODE
{
    NodeElem_t element;
    NODE*      left_node;
    NODE*      right_node;
};

struct BINARY_TREE
{
    size_t capacity;
    size_t length;
    NODE*  memory;
    size_t free;
    NODE*  root;
};

#endif
