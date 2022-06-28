#include <stdio.h>
#include "node2.h"

void displayInorder(treeNode*root)
{
    if (root)
    {
        displayInorder(root->left);
        printf("%d_", root->key);
        displayInorder(root->right);
    }
}