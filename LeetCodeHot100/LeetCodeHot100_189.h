#pragma once
#include <vector>
using std::vector;
class Solution189
{
public:
    /**
    * 189. 轮转数组
    * 给定一个整数数组 nums，将数组中的元素向右轮转 k 个位置，其中 k 是非负数。
    */
    void rotate(vector<int>& nums, int k); // 超时
    void rotate_A(vector<int>& nums, int k); 
    void test();
};
