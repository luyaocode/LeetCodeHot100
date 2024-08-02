#include <stack>
#include "LeetCodeHot100_226.h"
using std::stack;

TreeNode* Solution226::invertTree(TreeNode* root)
{
	if (root == nullptr)
	{
		return root;
	}
	stack<TreeNode*> stack;
	stack.push(root);
	while (!stack.empty())
	{
		// �������Һ���
		auto node = stack.top();
		TreeNode* temp = node->left;
		node->left = node->right;
		node->right = temp;
		// �����ջ
		stack.pop();
		// ���Һ�����ջ
		if (node->left != nullptr)
		{
			stack.push(node->left);
		}
		if (node->right != nullptr)
		{
			stack.push(node->right);
		}
	}
	return root;
}