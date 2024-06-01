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
    * 给你一个整数数组 nums ，判断是否存在三元组 [nums[i], nums[j], nums[k]] 满足 i != j、i != k 且 j != k ，
    * 同时还满足 nums[i] + nums[j] + nums[k] == 0 。请你返回所有和为 0 且不重复的三元组。
    * 注意：答案中不可以包含重复的三元组。
    */
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        const int NUMBER = 10001; // 无意义的旧值，超出nums所有元素取值范围即可
        vector<vector<int>> res;
        if (nums.empty())
        {
            return res;
        }
        sort(nums.begin(), nums.end());
        auto lastI{ NUMBER }; // nums[i]旧值
        for (int i = 0; i < nums.size()-2; ++i)
        {
            if (nums[i]==lastI) // i指针右移
            {
                continue;
            }
            auto target = 0 - nums[i]; // nums[j]+nums[k]的目标值
            auto left{ NUMBER }; // nums[j]旧值
            auto right{ NUMBER }; // nums[k]旧值
            for (int j = i + 1, k = nums.size() - 1; j<k;)
            {
                if (nums[j]==left) // j指针右移
                {
                    ++j;
                    continue;
                }
                if (nums[k]==right) // k指针左移
                {
                    --k;
                    continue;
                }
                if (nums[j] + nums[k] == target)
                {
                    res.emplace_back(vector<int>{nums[i],nums[j],nums[k]});
                    left = nums[j]; right = nums[k];
                    ++j; --k;
                }
                else if(nums[j] + nums[k] < target) // nums[j] + nums[k]偏小，j指针右移
                {
                    ++j;
                }
                else //nums[j] + nums[k]偏大，k指针左移
                {
                    --k;
                }
            }
        }
        return res;
    }
};

void test()
{
    vector<int> vec{ 1,1,-2 };
    Solution sol;
    auto res=sol.threeSum(vec);
    for (const auto& v : res)
    {
        for (const auto& n : v)
        {
            cout << n << ",";
        }
        cout << endl;
    }
}
