#include "LeetCodeHot100_438.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using std::vector;
using std::string;
using std::cout;

vector<int> Solution438::findAnagrams(string s, string p)
{
    vector<int> res;
    if (s.empty() || p.empty()) return {};
    auto pStr = p;
    sort(pStr.begin(), pStr.end());
    for (int i = 0, j = i + p.size() - 1; j < s.size(); ++i, ++j)
    {
        auto subStr = s.substr(i, pStr.size());
        sort(subStr.begin(), subStr.end());
        if (subStr.compare(pStr) == 0)
        {
            res.push_back(i);
        }
    }
    return res;
}

vector<int> Solution438::findAnagrams_A(string s, string p)
{
    vector<int> res;
    if (s.empty() || p.empty()|| s.size() < p.size()) return {};
    vector<int> sCount(26);
    vector<int> pCount(26);
    for (int i=0;i<p.size();++i)
    {
        ++sCount[s[i] - 'a'];
        ++pCount[p[i] - 'a'];
    }
    if (sCount == pCount) res.emplace_back(0);
    for (int i = 1, j = i + p.size() - 1; j < s.size(); ++i, ++j)
    {
        --sCount[s[i-1] - 'a'];
        ++sCount[s[j] - 'a'];
        if (sCount == pCount)
        {
            res.emplace_back(i);
        }
    }
    return res;
}

void Solution438::test()
{
    string s{ "cbaebabacd" };
    string p{ "abc" };
    auto res = findAnagrams_A(s, p);
    for (const auto& n : res)
    {
        cout << n << ",";
    }
}