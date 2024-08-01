#include "LeetCodeHot100_104.h"
#include <algorithm>
using std::max;
int Solution104::maxDepth(TreeNode* root)
{
		if (root != nullptr)
		{
			inorder(root,0);
		}
		return _maxDepth;
}

void Solution104::inorder(TreeNode* node,int level)
{
	level++;
	_maxDepth = max(level,_maxDepth);
	if (node->left != nullptr)
	{
		inorder(node->left,level);
		level--;
	}
	if (node->right != nullptr)
	{
		inorder(node->right, level);
		level--;
	}
}
