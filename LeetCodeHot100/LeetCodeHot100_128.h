#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

class Solution {
public:
    /**
    * ����һ��δ������������� nums ���ҳ���������������У���Ҫ������Ԫ����ԭ�������������ĳ��ȡ�
    * ������Ʋ�ʵ��ʱ�临�Ӷ�Ϊ O(n) ���㷨��������⡣
    * ��Ч����������+����
    */
    int longestConsecutive(vector<int>& nums) 
    {
        if (nums.empty()) return 0;
        sort(nums.begin(), nums.end());
        int maxSequenceSize{ 1};
        for (int i = 0; i < nums.size(); ++i)
        {
            auto maxSequence=getMaxSequence(i,nums);
            maxSequenceSize = max(maxSequenceSize,maxSequence);
        }
        return maxSequenceSize;
    }

    int getMaxSequence(int i, vector<int>& nums)
    {
        auto init_idx{i};
        auto prev{nums[i++]};
        auto repeat{ 0 };
        while (i < nums.size())
        {
            if (prev != nums[i] - 1)
            {
                if (prev == nums[i])
                {
                    ++repeat;
                }
                else
                {
                    break;
                }
            }
            prev = nums[i];
            ++i;
        }
        return i-init_idx-repeat;
    }

    // ʹ�ù�ϣSet�Ľ�
    int longestConsecutive_A(vector<int>& nums)
    {
        unordered_set<int> set;
        int nMax{nums.size()==0?0:1};
        for (const auto& n : nums)
        {
            set.insert(n);
        }
        for (const auto& n : set)
        {
            auto curr = n;
            if (set.count(curr - 1) == 0) // ��curr��Ϊ����ͷ��
            {
                auto currMax{1};
                while (set.count(curr + 1) == 1)// ��set����curr����һ��Ԫ��
                {
                    ++curr;
                    ++currMax;
                }
                nMax = max(currMax,nMax);
            }
        }
        return nMax;
    }
};

void test() 
{
    vector<int> nums = { 9,1,4,7,3,-1,0,5,8,-1,6 };
    Solution sol;
    cout<<sol.longestConsecutive_A(nums);
}