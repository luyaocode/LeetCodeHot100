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
    * ����һ���������� nums ���ж��Ƿ������Ԫ�� [nums[i], nums[j], nums[k]] ���� i != j��i != k �� j != k ��
    * ͬʱ������ nums[i] + nums[j] + nums[k] == 0 �����㷵�����к�Ϊ 0 �Ҳ��ظ�����Ԫ�顣
    * ע�⣺���в����԰����ظ�����Ԫ�顣
    */
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        const int NUMBER = 10001; // ������ľ�ֵ������nums����Ԫ��ȡֵ��Χ����
        vector<vector<int>> res;
        if (nums.empty())
        {
            return res;
        }
        sort(nums.begin(), nums.end());
        auto lastI{ NUMBER }; // nums[i]��ֵ
        for (int i = 0; i < nums.size()-2; ++i)
        {
            if (nums[i]==lastI) // iָ������
            {
                continue;
            }
            auto target = 0 - nums[i]; // nums[j]+nums[k]��Ŀ��ֵ
            auto left{ NUMBER }; // nums[j]��ֵ
            auto right{ NUMBER }; // nums[k]��ֵ
            for (int j = i + 1, k = nums.size() - 1; j<k;)
            {
                if (nums[j]==left) // jָ������
                {
                    ++j;
                    continue;
                }
                if (nums[k]==right) // kָ������
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
                else if(nums[j] + nums[k] < target) // nums[j] + nums[k]ƫС��jָ������
                {
                    ++j;
                }
                else //nums[j] + nums[k]ƫ��kָ������
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
