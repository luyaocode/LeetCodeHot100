#pragma once
#include <vector>
using std::vector;

class Solution560
{
public:
    /**
    * ����һ���������� nums ��һ������ k ������ͳ�Ʋ����� �������к�Ϊ k ��������ĸ��� ��
    * ��������������Ԫ�ص������ǿ����С�
    */
    int subarraySum(vector<int>& nums, int k); //�����ⷨ����ʱ
    int subarraySum_A(vector<int>& nums, int k);
    void test();
};
