#include "LeetCodeHot100_053.h"
#include <iostream>
#include <vector>
#include <algorithm>
using std::cout;
using std::vector;
using std::min;
using std::max;

int Solution053::maxSubArray(vector<int>& nums)
{
	if (nums.empty()) return 0;
	int maxSum = -INT16_MAX;
	int currSum{ 0 };
	int minFrontSum{ 0 };
	for (int i = 0; i < nums.size(); ++i)
	{
		currSum += nums[i];
		maxSum = max(maxSum,currSum-minFrontSum);
		minFrontSum = min(minFrontSum, currSum);
	}
	return maxSum;
}

void Solution053::test()
{
	vector<int> nums{ 5,4,-1,7,8 };
	auto res = maxSubArray(nums);
	cout << res;
}