#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>
using namespace std;

/**
* 输入数组，必须交换一次相邻的两个元素，求相邻元素乘积的最大值。
*/
vector<int> nums; // 输入的数组

int max_multi()
{
	int ans = -INT_MAX;
	for (int i = 0; i < nums.size()-1; ++i)
	{
		ans = max(ans,nums[i]*nums[i+1]);
	}
	return ans;
}

int swap_two_make_max_multi()
{
	int n;// 数组个数
	cin >> n;
	int t;// 临时值
	int time = n;
	int ans = -INT_MAX;
	while (time > 0 && cin >> t)
	{
		nums.push_back(t);
		time--;
	}
	if (n == 1) return nums[0];
	if (n == 2) return nums[0] * nums[1];
	for (int i = 0; i < nums.size() - 1; ++i)
	{
		// swap
		int t = nums[i];
		nums[i] = nums[i+1];
		nums[i + 1] = t;
		ans = max(ans, max_multi());
		// unswap
		nums[i + 1] = nums[i];
		nums[i] = t;
	}
	return ans;
}

int main()
{
	cout << swap_two_make_max_multi();
}
