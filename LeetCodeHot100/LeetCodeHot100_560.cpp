#include "LeetCodeHot100_560.h"
#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>

using std::vector;
using std::cout;
using std::unordered_map;

int Solution560::subarraySum(vector<int>& nums, int k)
{
	if (nums.empty()) return 0;
	if (nums.size() == 1)
	{
		return nums[0] == k ? 1 : 0;
	}
	int all{ 0 };
	int sum{0};
	for (int i = 0,j=i; i<=j&&i<nums.size();)
	{
		if (i == j) sum = nums[i];
		if (j == nums.size())
		{
			++i; j=i;
		}
		else
		{
			if (sum == k)
			{
				++all;
			}
			++j;
			sum += (j < nums.size() ? nums[j] : 0);
		}

	}

	return all;
}

int Solution560::subarraySum_A(vector<int>& nums, int k)
{
	unordered_map<int, int> map{ {0,1} };
	int preSum{0};
	int count{ 0 };
	for (auto& n : nums)
	{
		preSum += n;
		auto need = preSum - k;
		if (map.count(need) != 0)
		{
			count+=map[need];
		}
		++map[preSum];
	}

	return count;
}

void Solution560::test()
{
	vector<int> nums{ 1,-1,0};
	int k{ 0 };
	auto res = subarraySum_A(nums,k);
	cout << res;
}