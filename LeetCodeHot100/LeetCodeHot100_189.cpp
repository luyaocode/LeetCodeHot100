#include "LeetCodeHot100_189.h"
#include <iostream>
#include <vector>
using std::cout;
using std::vector;
using std::swap;

void Solution189::rotate(vector<int>& nums, int k)
{
	vector<int> temp;
	auto i{ 0 };
	k = k % nums.size();
	while (i++<k)
	{
		temp.emplace_back(nums[nums.size()-1]);
		nums.pop_back();
	}
	for (int i = 0; i < temp.size(); ++i)
	{
		nums.emplace(nums.begin(),temp[i]);
	}
}

void Solution189::rotate_A(vector<int>& nums, int k)
{
	auto reverse = [&](int start, int end)
	{
		while (start < end)
		{
			swap(nums[start++],nums[end--]);
		}
	};
	k %= nums.size();
	reverse(0,nums.size()-1);
	reverse(0,k-1);
	reverse(k,nums.size()-1);
}

void Solution189::test()
{
	vector<int> nums{ 1,2,3,4,5,6,7 };
	auto k{ 3 };
	rotate_A(nums,k);
	for (const auto& n : nums)
	{
		cout << n<<",";
	}
}