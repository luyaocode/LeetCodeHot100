#include "LeetCodeHot100_076.h"
#include <string>
#include <iostream>
#include <unordered_map>
#include <algorithm>
using std::string;
using std::cout;
using std::unordered_map;

string Solution076::minWindow(string s, string t)
{
	unordered_map<char, int> tar, win;
	auto check = [&]()
	{
		for (const auto& p : tar)
		{
			if (win[p.first] < p.second)
			{
				return false;
			}
		}
		return true;
	};

	for (const auto& c : t)
	{
		++tar[c];
	}

	int start{ -1 }, len{ INT_MAX };
	for (int i = 0, j = i; i<=j&& j< s.size();++j)
	{
		// j向右扩张
		if (tar.find(s[j]) != tar.end())
		{
			++win[s[j]];
		}

		// i向右收缩
		while (check() && i <= j)
		{
			if (j - i + 1 < len)
			{
				start = i;
				len = j - i + 1;
			}
			if (tar.find(s[i]) != tar.end())
			{
				--win[s[i]];
			}
			++i;
		}
	}
	return start == -1 ? "" : s.substr(start,len);
}

void Solution076::test()
{
	string s{"cwaefgcf"};
	string t{"cae"};
	auto res=minWindow(s,t);
	cout << res;
}