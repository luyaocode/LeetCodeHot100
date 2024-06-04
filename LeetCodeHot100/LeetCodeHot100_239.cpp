#include "LeetCodeHot100_239.h"
#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>

using std::vector;
using std::cout;
using std::unordered_map;
using std::max;

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



	return res;
}

void Solution239::test()
{
	vector<int> vec{ 1,3,-1,-3,5,3,6,7 };
	auto k{ 3 };
	auto res = maxSlidingWindow_A(vec,k);
	for (auto& n : res)
	{
		cout << n << ",";
	}
}
