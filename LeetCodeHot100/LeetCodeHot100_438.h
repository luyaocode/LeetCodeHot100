#pragma once
#include <vector>
#include <string>
using std::vector;
using std::string;

class Solution438
{
public:
    /**
    * 给定两个字符串 s 和 p，找到 s 中所有 p 的 异位词 的子串，返回这些子串的起始索引。不考虑答案输出的顺序。
    * 异位词 指由相同字母重排列形成的字符串（包括相同的字符串）。
    * 1 <= s.length, p.length <= 3 * 104
    * s 和 p 仅包含小写字母
    * 
    */
    vector<int> findAnagrams(string s, string p); //暴力解法，超时
    vector<int> findAnagrams_A(string s, string p);
    void test();
};