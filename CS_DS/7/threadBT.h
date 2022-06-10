#pragma once

typedef struct treeThNode
{
    char data;
    struct treeThNode *left;
    struct treeThNode *right;
    int isThreadRight;
} treeThNode;

treeThNode *makeRootThNode(char data, treeThNode *leftNode, treeThNode *rightNode, int isTreadRight);
treeThNode *findThreadSuccessor(treeThNode *p);
void threadInorder(treeThNode *root);
