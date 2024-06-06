#include "LeetCodeHot100_239.h"
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using std::vector;
using std::cout;
using std::max;
using std::priority_queue;
using std::pair;
using std::deque;

vector<int> Solution239::maxSlidingWindow(vector<int>& nums, int k)
{
	if (nums.empty()||k==0) return {};
	vector<int> res;
	for (int i = 0; i+k < nums.size()+1;++i)
	{
		vector<int> t;
		for (int j = i; j < i + k; ++j)
		{
			t.emplace_back(nums[j]);
		}
		sort(t.begin(),t.end());
		res.emplace_back(t[k-1]);
	}
	return res;
}

vector<int> Solution239::maxSlidingWindow_A(vector<int>& nums, int k)
{
	if (nums.empty() || k == 0) return {};
	vector<int> res;
	priority_queue<pair<int, int>> q; // 优先队列，存储<元素值,元素索引>
	for (int i = 0; i < k; ++i)
	{
		q.emplace(nums[i],i);
	}
	res.emplace_back(q.top().first);
	for (int i = k; i < nums.size(); ++i)
	{
		q.emplace(nums[i],i);
		
		// 窗口右移，保持优先队列首部的索引在窗口之内。注意要用while而不是if，
		// 因为并非每次移动窗口就剔除不存在的元素，而是每次移动窗口，才循环检查当前首部在不在窗口
		while (q.top().second <= i - k)
		{
			q.pop();
		}
		res.emplace_back(q.top().first);
	}
	return res;
}

vector<int> Solution239::maxSlidingWindow_B(vector<int>& nums, int k)
{
	if (nums.empty() || k == 0) return {};
	vector<int> res;
	deque<int> q; // 双端队列

	// 初始化双端队列，保持队列中的索引顺序严格单调递增，且索引对应的值严格单调递增，也就是队头元素必定是最大值
	for (int i = 0; i < k; ++i)
	{
		while (!q.empty() && nums[i] >= nums[q.back()])
		{
			q.pop_back();
		}
		q.push_back(i);
	}
	res.push_back(nums[q.front()]);

	for (int i = k; i < nums.size(); ++i)
	{
		// 窗口右移，从尾部更新双端队列，保持从左到右索引对应的值严格单调递减
		while (!q.empty() && nums[i] >= nums[q.back()])
		{
			q.pop_back();
		}
		q.push_back(i);

		// 从头部更新双端队列，保持队头元素（数组索引）在窗口之内
		while (!q.empty() && q.front()<=i-k)
		{
			q.pop_front();
		}

		// 记录队头元素，也就是窗口中最大的元素
		res.push_back(nums[q.front()]);
	}

	return res;
}

void Solution239::test()
{
	vector<int> vec{ 9,10,9,-7,-4,-8,2,-6 };
	auto k{ 5};
	auto res = maxSlidingWindow_B(vec,k);
	for (auto& n : res)
	{
		cout << n << ",";
	}
}
