#include<stdio.h>
#include<stdlib.h>

typedef struct binaryTree
{
    int data;
    struct binaryTree *left;
    struct binaryTree *right;
}BTREE;

typedef struct rootPoint
{
    BTREE* root;
}BinaryTree;

int main()
{
    BinaryTree *bt;

    bt->root = NULL;    


    return 0;
}