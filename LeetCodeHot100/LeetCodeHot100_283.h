#pragma once

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    /**
    * 给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。
    * 请注意 ，必须在不复制数组的情况下原地对数组进行操作。
    * 时间复杂度：O(n^2)
    * 空间复杂度：O(1)
    */
    void moveZeroes(vector<int>& nums)
    {
        if (nums.size() == 0)
        {
            return;
        }
        auto zeroCount{ 0 };
        for (const auto& n : nums)
        {
            if (n == 0)
            {
                ++zeroCount;
            }
        }
        if (zeroCount == 0)
        {
            return;
        }
        for (int i = 0; i < nums.size(); ++i)
        {
            for (int j = i + 1; j < nums.size(); ++j)
            {
                if (nums[i] == 0&&nums[j]!=0)
                {
                    nums[i] = nums[j];
                    nums[j] = 0;
                    break;
                }
            }
        }
    }

    // 题解1：非零元素依次往左边挪，最后在末尾补若干个零（二次遍历）
    void moveZeroes_A(vector<int>& nums)
    {
        auto j{0};
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] != 0)
            {
                nums[j++] = nums[i];
            }
        }
        for (int i = j; j < nums.size(); ++j)
        {
            nums[j] = 0;
        }
    }

    // 题解2：以0为中间点进行快排（一次遍历）
    // 双指针，i,j同时出发，i始终指向从左到右第一个非0元素，j始终指向从左到右第一个0元素，交换nums[i]和nums[j]
    void moveZeroes_B(vector<int>& nums)
    {
        int j{ 0 };
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] == 0)
            {
                continue;
            }
            if (nums[j] != 0)
            {
                ++j;
                continue;
            }
            auto t = nums[i];
            nums[i] = nums[j];
            nums[j++] = t;
        }
    }
};

void test()
{
    Solution sol;
    vector<int> vec{ 0,1,0,3,12 };
    sol.moveZeroes_B(vec);
    for (const auto& n : vec)
    {
        cout << n << ",";
    }
}