#pragma once

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
    /**
    * 给定一个字符串 s ，请你找出其中不含有重复字符的最长子串的长度。
    * 双指针形成滑动窗口，使用subStr记录滑动过程中子串，使用maxLen记录子串历史最大长度
    * 滑动时，若在子串找到重复元素，窗口右移并改变窗口大小
    * 时空复杂度分别O(n)和O(n)
    */
    int lengthOfLongestSubstring(string s)
    {
        int maxLen{ 0 };
        if (s.empty()) return maxLen;
        if (s.size() == 1)
        {
            maxLen = 1;
            return 1;
        }
        string subStr{s[0]};
        for (int i = 0,j=i+1; i<=j&&j < s.size();)
        {
            maxLen = max(maxLen, int(subStr.size()));
            auto it = find(subStr.begin(), subStr.end(), s[j]);
            if (it==subStr.end())
            {
                subStr.append(1,s[j]);
                ++j;
            }
            else
            {
                auto idx=subStr.find_first_of(*it);
                subStr = subStr.substr(idx+1).append(1,*it);
                i += idx+1;
                ++j;
            }
        }
        maxLen = max(maxLen, int(subStr.size()));
        return maxLen;
    }
};

void test()
{
    string s = "umvejcuuk";
    Solution sol;
    auto res=sol.lengthOfLongestSubstring(s);
    cout << res;
}