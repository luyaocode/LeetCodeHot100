#pragma once
#include <vector>
using std::vector;
class Solution041
{
public:
    /**
    * 41. ȱʧ�ĵ�һ������
    * ����һ��δ������������� nums �������ҳ�����û�г��ֵ���С����������
    * ����ʵ��ʱ�临�Ӷ�Ϊ O(n) ����ֻʹ�ó����������ռ�Ľ��������
    */
    int firstMissingPositive(vector<int>& nums); // �ռ临�Ӷ�O(n)
    int firstMissingPositive_A(vector<int>& nums);
    void test();
};