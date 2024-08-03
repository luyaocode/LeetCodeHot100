#include "LeetCodeHot100_543.h"
#include <algorithm>
using std::max;
int Solution543::depth(TreeNode* node)
{
	if (node == nullptr)
	{
		return 0;
	}
	int leftDepth = depth(node->left);
	int rightDepth = depth(node->right);
	nNode = max(nNode,leftDepth+rightDepth+1);
	return max(leftDepth, rightDepth)+1;
}

int Solution543::diameterOfBinaryTree(TreeNode* root)
{
	if (root == nullptr)
	{
		return nNode;
	}
	depth(root);
	return nNode-1;
}
