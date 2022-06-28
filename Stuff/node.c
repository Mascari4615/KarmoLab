#include <stdio.h>
#include "node.h"

void displayInorder(treeNode* root)
{
	if (root)
	{
		displayInorder(root->left);
		printf("%c", root->key);
		displayInorder(root->right);
	}
}