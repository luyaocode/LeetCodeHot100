#pragma once
#include <vector>
using std::vector;

class Solution238
{
public:
    /**
    * 238. 除自身以外数组的乘积
    * 给你一个整数数组 nums，返回 数组 answer ，其中 answer[i] 等于 nums 中除 nums[i] 之外其余各元素的乘积 。
    * 题目数据 保证 数组 nums之中任意元素的全部前缀元素和后缀的乘积都在  32 位 整数范围内。
    * 请不要使用除法，且在 O(n) 时间复杂度内完成此题。
    */
    vector<int> productExceptSelf(vector<int>& nums);
    void test();
};