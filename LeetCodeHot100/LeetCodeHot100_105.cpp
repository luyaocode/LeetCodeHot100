#include "LeetCodeHot100_105.h"

TreeNode* Solution105::buildTree(vector<int>& preorder, vector<int>& inorder)
{
	if (preorder.empty()) return nullptr;
	int n = preorder.size();
	for (int i = 0; i < inorder.size(); ++i)
	{
		index[inorder[i]] = i;
	}
	return buildTree(preorder,0,n-1,0,n-1);
}

TreeNode* Solution105::buildTree(vector<int>& preorder, int preLeft, int preRight, int inLeft, int inRight)
{
	if (preLeft > preRight||inLeft>inRight)
	{
		return nullptr;
	}
	TreeNode* root = new TreeNode(preorder[preLeft]);
	int idx_inorder = index[preorder[preLeft]];
	// x-preLeft=idx_inorder-inLeft
	root->left = buildTree(preorder,preLeft+1,idx_inorder-inLeft+preLeft,inLeft, idx_inorder-1);
	root->right = buildTree(preorder, idx_inorder - inLeft + preLeft+1,preRight, idx_inorder+1,inRight);
	return root;
}
