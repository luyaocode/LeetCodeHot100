#include "LeetCodeHot100_114.h"

void Solution114::flatten(TreeNode* root)
{
	vector<TreeNode*> nodes;
	preorder(root,nodes);
	for (int i = 0; i < nodes.size()-1; ++i)
	{
		nodes[i]->left = nullptr;
		nodes[i]->right = nodes[i + 1];
	}
}

void Solution114::preorder(TreeNode* node,vector<TreeNode*>& nodes)
{
	if (node==nullptr) return;
	nodes.push_back(node);
	preorder(node->left,nodes);
	preorder(node->right,nodes);
}
