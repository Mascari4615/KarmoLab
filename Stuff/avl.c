#include <stdio.h>
#include <stdlib.h>
#include "avl.h"

treeNode* LL_rotate(treeNode* parent)
{
    treeNode* child = parent->left;
    parent->left = child->right;
    child->right = parent;
    return child;
}
treeNode* RR_rotate(treeNode* parent)
{
    treeNode* child = parent->left;
    parent->right = child->left;
    child->left = parent;
    return child;
}
treeNode* LR_rotate(treeNode* parent)
{
    treeNode* child = parent->left;
    parent->left = RR_rotate(child);
    return LL_rotate(parent);
}
treeNode* RL_rotate(treeNode* parent)
{
    treeNode* child = parent->right;
    parent->right = LL_rotate(child);
    return RR_rotate(parent);
}
int getHeight(treeNode* p)
{
    int height = 0;
    if (p != NULL) height = MAX(getHeight(p->left), getHeight(p->right)) + 1;
    return height;
}
int getBF(treeNode* p)
{
    if (p == NULL) return 0;
    return getHeight(p->left) - getHeight(p->right);
}
treeNode* rebalance(treeNode** p)
{
    int BF = getBF(*p);
    if (BF > 1)
    {
        if (getBF((*p)->left)>0)
        {
            *p = LL_rotate(*p);
        }
        else
        {
            *p = LR_rotate(*p);
        }
    }
    else
    {
        if (getBF((*p)->right) < 0)
        {
            *p = RR_rotate(*p);
        }
        else
        {
            *p = RL_rotate(*p);
        }
        return *p;
    }
}
treeNode* insertAVLNode(treeNode** root, element x)
{
    if (*root == NULL)
    {
        *root = (treeNode*)malloc(sizeof(treeNode));
        (*root)->key = x;
        (*root)->left = NULL;
        (*root)->right = NULL;
    }
    else if (x < (*root)->key)
    {
        (*root)->left = insertAVLNode(&((*root)->left), x);
        *root = rebalance(root);
    }
    else if (x > (*root)->key)
    {
        (*root)->right = insertAVLNode(&((*root)->right), x);
        *root = rebalance(root);
    }
    else
    {
        printf("\n 이미 같은 키가 있습니다! \n");
        return 0;
    }
}