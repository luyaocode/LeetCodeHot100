#pragma once

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    /**
    * ����һ������ nums����дһ������������ 0 �ƶ��������ĩβ��ͬʱ���ַ���Ԫ�ص����˳��
    * ��ע�� �������ڲ���������������ԭ�ض�������в�����
    * ʱ�临�Ӷȣ�O(n^2)
    * �ռ临�Ӷȣ�O(1)
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

    // ���1������Ԫ�����������Ų�������ĩβ�����ɸ��㣨���α�����
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

    // ���2����0Ϊ�м����п��ţ�һ�α�����
    // ˫ָ�룬i,jͬʱ������iʼ��ָ������ҵ�һ����0Ԫ�أ�jʼ��ָ������ҵ�һ��0Ԫ�أ�����nums[i]��nums[j]
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