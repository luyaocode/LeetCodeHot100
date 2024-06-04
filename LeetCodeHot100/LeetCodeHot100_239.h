#pragma once
#include <vector>
using std::vector;

class Solution239
{
public:
    /**
    * 给你一个整数数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口内的 k 个数字。滑动窗口每次只向右移动一位。
    * 返回滑动窗口中的最大值 。
    */
    vector<int> maxSlidingWindow(vector<int>& nums, int k); //超时
    vector<int> maxSlidingWindow_A(vector<int>& nums, int k);
    void test();
};