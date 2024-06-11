#include "LeetCodeHot100_238.h"
#include <iostream>
#include <vector>
using std::cout;
using std::vector;

vector<int> Solution238::productExceptSelf(vector<int>& nums)
{
	auto size = nums.size();
	vector<int> res(size,1);
	auto pre{ 1 }, suf{ 1 };
	for (int i = 0; i < size; ++i)
	{
		res[i] = pre;
		pre *= nums[i];
	}
	for (int j = size - 1; j >= 0; --j)
	{
		res[j] *= suf;
		suf *= nums[j];
	}
	return res;
}

void Solution238::test()
{
	vector<int> nums{ 1,2,3,4 };
	auto res = productExceptSelf(nums);
	for (const auto& n : res)
	{
		cout << n << ",";
	}
}