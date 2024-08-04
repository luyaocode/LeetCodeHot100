#include "LeetCodeHot100_102.h"
#include <stack>
using std::stack;

vector<vector<int>> Solution102::levelOrder(TreeNode* root)
{
	if (!root) return vector<vector<int>>();
	stack<TreeNode*> st;
	st.push(root);
	vector<vector<int>> ans;
	vector<TreeNode*> childs;
	vector<int> vals;
	while (!st.empty())
	{
		childs.clear();
		vals.clear();
		// 当前层级的所有节点出栈
		while (!st.empty())
		{
			auto node = st.top();
			st.pop();
			vals.push_back(node->val);
			childs.push_back(node->left);
			childs.push_back(node->right);
		}
		ans.emplace_back(vals);
		// 下一层级的所有节点入栈
		for (auto it = childs.crbegin(); it != childs.crend(); ++it)
		{
			if (*it) st.push(*it);
		}
	}
	return ans;
}