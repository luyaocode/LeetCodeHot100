#pragma once

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
    /**
    * ����һ���ַ��� s �������ҳ����в������ظ��ַ�����Ӵ��ĳ��ȡ�
    * ˫ָ���γɻ������ڣ�ʹ��subStr��¼�����������Ӵ���ʹ��maxLen��¼�Ӵ���ʷ��󳤶�
    * ����ʱ�������Ӵ��ҵ��ظ�Ԫ�أ��������Ʋ��ı䴰�ڴ�С
    * ʱ�ո��Ӷȷֱ�O(n)��O(n)
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