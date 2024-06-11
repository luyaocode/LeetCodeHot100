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
	// 按照左区间升序排序
	sort(intervals.begin(), intervals.end(), [&](vector<int>& v1, vector<int>& v2)
		{
			return v1[0] < v2[0];
		});
	// 定义一个合并区间[left,right]
	auto left{ intervals[0][0]};
	auto right{ intervals[0][1] };
	vector<vector<int>> res;
	for (const auto& v:intervals)
	{
		// 如果当前区间的左区间落在【合并区间】当中（包含相邻的情况）
		// 那就将合并区间的右区间值修改到合适位置
		if (v[0] <= right)
		{
			right = max(right, v[1]);
		}
		// 否则说明当前区间和合并区间不连续，那就将合并区间加到结果当中
		else
		{
			res.emplace_back(vector<int>{left, right });
			left = v[0];
			right = v[1];
		}
	}
	// 最后将最后的合并区间加入到结果当中
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