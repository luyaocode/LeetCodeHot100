#pragma once
#include <vector>
using std::vector;
class Solution041
{
public:
    /**
    * 41. 缺失的第一个正数
    * 给你一个未排序的整数数组 nums ，请你找出其中没有出现的最小的正整数。
    * 请你实现时间复杂度为 O(n) 并且只使用常数级别额外空间的解决方案。
    */
    int firstMissingPositive(vector<int>& nums); // 空间复杂度O(n)
    int firstMissingPositive_A(vector<int>& nums);
    void test();
};