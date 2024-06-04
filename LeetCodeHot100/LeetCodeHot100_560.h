#pragma once
#include <vector>
using std::vector;

class Solution560
{
public:
    /**
    * 给你一个整数数组 nums 和一个整数 k ，请你统计并返回 该数组中和为 k 的子数组的个数 。
    * 子数组是数组中元素的连续非空序列。
    */
    int subarraySum(vector<int>& nums, int k); //暴力解法，超时
    int subarraySum_A(vector<int>& nums, int k);
    void test();
};
