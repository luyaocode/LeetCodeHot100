#pragma once
#include <vector>
using std::vector;

class Solution238
{
public:
    /**
    * 238. ��������������ĳ˻�
    * ����һ���������� nums������ ���� answer ������ answer[i] ���� nums �г� nums[i] ֮�������Ԫ�صĳ˻� ��
    * ��Ŀ���� ��֤ ���� nums֮������Ԫ�ص�ȫ��ǰ׺Ԫ�غͺ�׺�ĳ˻�����  32 λ ������Χ�ڡ�
    * �벻Ҫʹ�ó��������� O(n) ʱ�临�Ӷ�����ɴ��⡣
    */
    vector<int> productExceptSelf(vector<int>& nums);
    void test();
};