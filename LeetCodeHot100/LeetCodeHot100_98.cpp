#include "LeetCodeHot100_98.h"
#include "limits.h"

bool Solution098::isValidBST(TreeNode* root)
{
	return isValid(root,-(LONG_MAX),LONG_MAX);
}

bool Solution098::isValid(TreeNode* node,long min,long max)
{
	if (!node) return true;
	if (node->val >= max || node->val <= min)
	{
		return false;
	}
	return isValid(node->left,min,node->val) && isValid(node->right,node->val,max);
}