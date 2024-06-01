#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    /**
    * 给定一个长度为 n 的整数数组 height 。有 n 条垂线，第 i 条线的两个端点是 (i, 0) 和 (i, height[i]) 
    * 找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。
    * 返回容器可以储存的最大水量。
    * 说明：你不能倾斜容器。
    */
    int maxArea(vector<int>& height)
    {
        int maxArea = 0;
        for (int i = 0; i < height.size(); ++i)
        {
            for (int j = i+1; j < height.size(); ++j)
            {
                maxArea = max(maxArea,min(height[i],height[j])*(j-i));
            }
        }
        return maxArea;
    }

    int maxArea_A(vector<int>& height)
    {
        int left = 0;
        int right = 0;
        int maxArea = 0;
        for (int i = 0,j = height.size() - 1; j>i&&i < height.size();)
        {
            if (left <= right&& height[i] <= left)
            {
                ++i;
                continue;
            }
            else if (left > right&&height[j] <= right)
            {
                --j;
                continue;
            }
            if (height[i] >= height[j])
            {
                left = height[i];
                maxArea = max(maxArea,height[j]*(j-i));
                --j;
            }
            else
            {
                right = height[j];
                maxArea = max(maxArea, height[i] * (j - i));
                ++i;
            }
        }
        return maxArea;
    }
};

void test()
{
    Solution sol;
    vector<int> vec{ 1,8,6,2,5,4,8,3,7 };
    int res=sol.maxArea_A(vec);
    cout << res;
}