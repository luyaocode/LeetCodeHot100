// LeetCodeHot100.h: 标准系统包含文件的包含文件
// 或项目特定的包含文件。

#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <memory>
using namespace std;

class Solution_049 
{
public:
    /*
    * 给你一个字符串数组，请你将 字母异位词 组合在一起。可以按任意顺序返回结果列表。
    * 字母异位词 是由重新排列源单词的所有字母得到的一个新单词。
    * 使用哈希表存储每个字母出现的频次，用两张哈希表的键值对是否完全一致来判断两个字符串是否属于字母异位词。
    */
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        vector<vector<string>> resVec;
        unordered_map<string, vector<string>> tempMap;
        unordered_map<string, unordered_map<char, int>> allMap;
        for (int i = 0; i < strs.size(); ++i) 
        {
            // 构造字母频次表
            auto str = strs[i];
            unordered_map<char, int> charFreqMap;
            for (int c = 'a'; c <= 'z'; ++c) 
            {
                charFreqMap.insert({c,0});
            }
            for (auto c : str) 
            {
                ++charFreqMap[c];
            }
            // 遍历之前的字母频次表
            bool isSame = false;
            string prevStr;
            for (auto it = allMap.begin(); it != allMap.end(); ++it)
            {
                auto prevCharFreqMap = it->second;
                bool flag = true;
                if (it->first.size() != str.size())
                {
                    flag = false;
                    continue;
                }
                else 
                {
                    for (auto c : str)
                    {
                        if (charFreqMap[c] != prevCharFreqMap[c])
                        {
                            flag = false;
                            break;
                        }
                    }
                }
                if (flag)
                {
                    isSame = true;
                    prevStr = it->first;
                }
            }
            if (isSame)
            {
                tempMap[prevStr].emplace_back(str);
            }
            else
            {
                tempMap.insert({ str,vector<string>{str}});
                allMap.insert({ str,charFreqMap });
            }
        }

        // 构造结果
        for (auto cit = tempMap.cbegin(); cit != tempMap.cend(); ++cit)
        {
            auto vec = cit->second;
            resVec.emplace_back(vec);
        }
        return resVec;
    }

    // 改进
    vector<vector<string>> groupAnagrams_A(vector<string>& strs)
    {
        vector<vector<string>> resVec;
        unordered_map<string, vector<string>> temp;
        for (auto& str:strs)
        {
            auto original_str = str;
            sort(str.begin(), str.end());
            temp[str].emplace_back(original_str);
        }
        for (auto cit = temp.cbegin(); cit != temp.cend(); ++cit)
        {
            resVec.emplace_back(cit->second);
        }
        return resVec;
    }
};

void test()
{
    Solution_049 sol;
    vector<string> testArr = { "eat", "tea", "tan", "ate", "nat", "bat" };
    auto res = sol.groupAnagrams_A(testArr);
    for (int i = 0; i < res.size(); ++i)
    {
        auto sonArr = res[i];
        if (sonArr.size() > 0)
        {
            for (int j = 0; j < sonArr.size(); ++j)
            {
                cout << sonArr[j];
                if (j != sonArr.size() - 1)
                {
                    cout << ",";
                }
            }
        }
        cout << endl;
    }
}
