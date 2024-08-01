#include <stack>
#include "LeetCodeHot100_226.h"
using std::stack;

TreeNode* Solution226::invertTree(TreeNode* root)
{
	if (root != nullptr)
	{
		stack<TreeNode*> stack;
		invert(root, stack);
	}
	return root;
}

void invert(TreeNode* node,stack<TreeNode*>& stack)
{
	stack.push(node);
	while (!stack.empty())
	{
		// 交换左右孩子
		auto top = stack.top();
		TreeNode* temp = top->left;
		top->left = top->right;
		top->right = temp;
		// 自身出栈
		stack.pop();

		// 左右孩子入栈
		if (node->left != nullptr)
		{
			stack.push(node->left);
		}
		if (node->right != nullptr)
		{
			stack.push(node->right);
		}
	}

}
