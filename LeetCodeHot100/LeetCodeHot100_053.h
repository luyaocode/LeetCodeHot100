#pragma once
#include <vector>
using std::vector;

class Solution053
{
public:
    /**
    * 给你一个整数数组 nums ，请你找出一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
    * 子数组是数组中的一个连续部分。
    */
    int maxSubArray(vector<int>& nums); // 前缀和
    void test();
};
