#pragma once
#include <string>
using std::string;

class Solution076
{
public:
    /**
    * 给你一个字符串 s 、一个字符串 t 。返回 s 中涵盖 t 所有字符的最小子串。如果 s 中不存在涵盖 t 所有字符的子串，则返回空字符串 "" 。
    * 注意：
    * 对于 t 中重复字符，我们寻找的子字符串中该字符数量必须不少于 t 中该字符数量。
    * 如果 s 中存在这样的子串，我们保证它是唯一的答案。
    * m == s.length
    * n == t.length
    * 1 <= m, n <= 105
    * s 和 t 由英文字母组成
    */
    string minWindow(string s, string t);
    void test();
};