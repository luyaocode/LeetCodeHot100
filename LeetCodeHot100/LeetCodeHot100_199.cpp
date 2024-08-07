#include "LeetCodeHot100_199.h"
#include <queue>
using std::queue;

vector<int> Solution199::rightSideView(TreeNode* root)
{
	queue<TreeNode*> queue;
	if (!root) return vector<int>();
	queue.push(root);
	vector<int> ans;
	while (!queue.empty())
	{
		ans.push_back(queue.front()->val);

		vector<TreeNode*> temp;
		while (!queue.empty())
		{
			auto tNode = queue.front();
			if (tNode->right) temp.push_back(tNode->right);
			if (tNode->left) temp.push_back(tNode->left);
			queue.pop();
		}

		for (auto& node : temp)
		{
			queue.push(node);
		}
	}
	return ans;
}
