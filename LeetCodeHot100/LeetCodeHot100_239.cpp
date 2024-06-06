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
	priority_queue<pair<int, int>> q; // ���ȶ��У��洢<Ԫ��ֵ,Ԫ������>
	for (int i = 0; i < k; ++i)
	{
		q.emplace(nums[i],i);
	}
	res.emplace_back(q.top().first);
	for (int i = k; i < nums.size(); ++i)
	{
		q.emplace(nums[i],i);
		
		// �������ƣ��������ȶ����ײ��������ڴ���֮�ڡ�ע��Ҫ��while������if��
		// ��Ϊ����ÿ���ƶ����ھ��޳������ڵ�Ԫ�أ�����ÿ���ƶ����ڣ���ѭ����鵱ǰ�ײ��ڲ��ڴ���
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
	deque<int> q; // ˫�˶���

	// ��ʼ��˫�˶��У����ֶ����е�����˳���ϸ񵥵���������������Ӧ��ֵ�ϸ񵥵�������Ҳ���Ƕ�ͷԪ�رض������ֵ
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
		// �������ƣ���β������˫�˶��У����ִ�����������Ӧ��ֵ�ϸ񵥵��ݼ�
		while (!q.empty() && nums[i] >= nums[q.back()])
		{
			q.pop_back();
		}
		q.push_back(i);

		// ��ͷ������˫�˶��У����ֶ�ͷԪ�أ������������ڴ���֮��
		while (!q.empty() && q.front()<=i-k)
		{
			q.pop_front();
		}

		// ��¼��ͷԪ�أ�Ҳ���Ǵ���������Ԫ��
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
