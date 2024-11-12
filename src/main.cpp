#include "binary_tree.h"
#include "binary_tree_log.h"

int main()
{
    TREE treeInfo = {};

    tree_ctor(&treeInfo);
    tree_add(&treeInfo, NULL, ROOT, "вашу мысль");
    tree_add(&treeInfo, treeInfo.root, RIGHT, "мечтающую на размягченном мозгу");
    tree_add(&treeInfo, treeInfo.root, LEFT,  "как выжиревший лакей на засаленной кушетке");
    tree_add(&treeInfo, treeInfo.root->left, RIGHT, "буду дразнить об окровавленный сердца лоскут");
    tree_add(&treeInfo, treeInfo.root->left, LEFT, "досыта изиздеваюсь нахальный и едкий");
    tree_graphic_dump(&treeInfo);
    tree_dtor(&treeInfo);

    return 0;
}
