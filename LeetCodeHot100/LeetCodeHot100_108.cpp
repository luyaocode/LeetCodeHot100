#include "LeetCodeHot100_108.h"

TreeNode* Solution108::sortedArrayToBST(vector<int>& nums)
{
	if (nums.size() == 0) return nullptr;
	auto size = nums.size();
	TreeNode* root = new TreeNode(nums[size/2]);
	root->left = leftChild(nums,size/2,root);
	root->right = rightChild(nums,size/2,root);
	return root;
}

TreeNode* Solution108::leftChild(vector<int>& nums, int idx,TreeNode* node)
{
	if (idx == 0) return nullptr;
	auto child=leftChild(nums, (idx - 1) / 2, node);
	node->left = child;
	return child;
}

TreeNode* Solution108::rightChild(vector<int>& nums, int idx, TreeNode* node)
{
	if (idx == 0) return nullptr;
	auto child= rightChild(nums, (nums.size() + idx) / 2, node);
	node->right = child;
	return child;
}