#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>
using namespace std;

/**
* �������飬���뽻��һ�����ڵ�����Ԫ�أ�������Ԫ�س˻������ֵ��
*/
vector<int> nums; // ���������

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
	int n;// �������
	cin >> n;
	int t;// ��ʱֵ
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
