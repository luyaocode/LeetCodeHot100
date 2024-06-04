#include "LeetCodeHot100_001.h"
#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>
using std::vector;
using std::unordered_map;
using std::cout;

vector<int> Solution001::twoSum(vector<int>& nums, int target)
{
    unordered_map<int, int> map;
    vector<int> res;
    for (int i = 0; i < nums.size(); ++i)
    {
        auto it = map.find(target - nums[i]);
        if (it == map.end())
        {
            map[nums[i]] = i;
        }
        else
        {
            res.emplace_back(it->second);
            res.emplace_back(i);
            break;
        }
    }
    return res;
}
vector<vector<int>> Solution001::twoSumAll(vector<int>& nums, int target)
{
    vector<vector<int>> res;
    unordered_map<int, int> map;
    for (int i = 0; i < nums.size(); ++i)
    {
        auto another = target - nums[i];
        if (map.count(another) != 0)
        {
            res.emplace_back(vector<int>{i, map[another]});
        }
        else
        {
            map[nums[i]] = i;
        }
    }
    return res;
}


void Solution001::test()
{
    vector<int> nums{ 2,7,11,15 };
    int target{ 9 };
    auto res = twoSum(nums, target);
    for (auto& n : res)
    {
        cout << n << ",";
    }
}
