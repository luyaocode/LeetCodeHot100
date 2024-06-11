#include "LeetCodeHot100_041.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using std::cout;
using std::unordered_set;
using std::vector;
using std::min;

int Solution041::firstMissingPositive(vector<int>& nums)
{
	if (nums.empty()) return 1;
	unordered_set<int> set;
	int mn{nums[0]};
	for (const auto& n : nums)
	{
		set.emplace(n);
	}
	for (int i =1;;++i)
	{
		if (set.find(i) == set.end())
		{
			return i;
		}
	}
}

int Solution041::firstMissingPositive_A(vector<int>& nums)
{
	vector<int> temp = nums;
	for (int i = 0; i < nums.size(); ++i)
	{
		if (nums[i] >= 1 && nums[i] <= nums.size())
		{
			temp[nums[i]-1] = nums[i];
		}
	}
	for (int i = 0; i < temp.size(); ++i)
	{
		if (i+1 != temp[i])
		{
			return i+1;
		}
	}
	return temp.size() + 1;
}

void Solution041::test()
{
	vector<int> nums{ 2,1 };
	auto res = firstMissingPositive_A(nums);
	cout << res;
}