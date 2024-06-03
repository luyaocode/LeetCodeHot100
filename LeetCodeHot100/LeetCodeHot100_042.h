#pragma once
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution
{
public:
    /**
    * ���� n ���Ǹ�������ʾÿ�����Ϊ 1 �����ӵĸ߶�ͼ�����㰴�����е����ӣ�����֮���ܽӶ�����ˮ��
    * 205 / 322 ��ͨ���Ĳ�������
    */
    int trap(vector<int>& height)
    {
        int maxWater{0};
        if (height.size() < 3) return maxWater;
        for (int i = 0; i < height.size()-2; ++i)
        {
            if (height[i] <= height[i + 1])
            {
                continue;
            }
            auto block{ 0}; 
            auto left{height[i+1]};
            for (int j = i + 1; j < height.size(); ++j)
            {
                if (j > i + 1)
                {
                    left = max(left, height[j - 1]);
                }
                if (height[j] < height[i])
                {
                    if (j == height.size()-1&&j>i+1&&height[j]>=left)
                    {
                        maxWater += height[j] * (j - i - 1) - block;
                        cout << maxWater << ",";
                        i = j - 1;
                        break;
                    }
                    block += height[j];
                    continue;
                }
                else
                {
                    maxWater += height[i] * (j - i - 1) - block;
                    cout << maxWater << ",";
                    i = j-1;
                    break;
                }
            }
        }
        return maxWater;
    }

    // ���3��˫ָ��
    int trap_A(vector<int>& height)
    {
        auto maxWater{0};
        if (height.size() < 3) return maxWater;
        auto leftMax{ height[0]};
        auto rightMax{ height[height.size()-1]};
        for (int i = 0,j=height.size()-1; i<j;)
        {
            leftMax = max(leftMax,height[i]);
            rightMax = max(rightMax, height[j]);
            if (leftMax >= rightMax)
            {
                maxWater += rightMax - height[j];
                --j;
            }
            else
            {
                maxWater += leftMax - height[i];
                ++i;
            }
        }
        return maxWater;
    }
};

void test()
{
    Solution sol;
    vector<int> height2{ 0,1,2,0,3,0,1,2,0,0,4,2,1,2,5,0,1,2,0,2 };
    auto res2 = sol.trap_A(height2);
    cout <<endl<<res2;
}