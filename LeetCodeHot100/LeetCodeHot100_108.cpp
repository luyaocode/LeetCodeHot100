#include "LeetCodeHot100_108.h"

TreeNode* Solution108::sortedArrayToBST(vector<int>& nums)
{
	return createNode(nums,0,nums.size()-1);
}

TreeNode* Solution108::createNode(vector<int>& nums, int left,int right)
{
	if (left > right)
	{
		return nullptr;
	}
	auto mid = (right + left) / 2;
	auto root = new TreeNode(nums[mid]);
	root->left = createNode(nums,left,mid-1);
	root->right = createNode(nums,mid+1,right);
	return root;
}