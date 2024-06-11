#include "LeetCodeHot100_056.h"
#include <iostream>
#include <vector>
#include <algorithm>
using std::cout;
using std::endl;
using std::vector;
using std::sort;
using std::max;
using std::min;

vector<vector<int>> Solution056::merge(vector<vector<int>>& intervals)
{
	if (intervals.empty()) return { {} };
	// ������������������
	sort(intervals.begin(), intervals.end(), [&](vector<int>& v1, vector<int>& v2)
		{
			return v1[0] < v2[0];
		});
	// ����һ���ϲ�����[left,right]
	auto left{ intervals[0][0]};
	auto right{ intervals[0][1] };
	vector<vector<int>> res;
	for (const auto& v:intervals)
	{
		// �����ǰ��������������ڡ��ϲ����䡿���У��������ڵ������
		// �Ǿͽ��ϲ������������ֵ�޸ĵ�����λ��
		if (v[0] <= right)
		{
			right = max(right, v[1]);
		}
		// ����˵����ǰ����ͺϲ����䲻�������Ǿͽ��ϲ�����ӵ��������
		else
		{
			res.emplace_back(vector<int>{left, right });
			left = v[0];
			right = v[1];
		}
	}
	// ������ĺϲ�������뵽�������
	res.emplace_back(vector<int>{left, right});
	return res;
}

void Solution056::test()
{
	vector<vector<int>> intervals = { {1,3},{2,6},{8,10},{15,18} };
	auto res = merge(intervals);
	for (const auto& v : res)
	{
		for (const auto& n : v)
		{
			cout << n << ",";
		}
		cout << endl;
	}
}