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
		// �������Һ���
		auto top = stack.top();
		TreeNode* temp = top->left;
		top->left = top->right;
		top->right = temp;
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

}
