#pragma once

#include <vector>

using std::vector;

class Solution001
{
public:
    /**
    * ����һ���������� nums ��һ������Ŀ��ֵ target�������ڸ��������ҳ� ��ΪĿ��ֵ target  ���� ���� ���������������ǵ������±ꡣ
    * ����Լ���ÿ������ֻ���Ӧһ���𰸡����ǣ�������ͬһ��Ԫ���ڴ��ﲻ���ظ����֡�
    * ����԰�����˳�򷵻ش𰸡�
    */
    vector<int> twoSum(vector<int>& nums, int target);

    /**
    * ���Σ��ҵ�����������������������
    * 
    */
    vector<vector<int>> twoSumAll(vector<int>& nums, int target);

    void test();
};

