#pragma once
#include <vector>
using std::vector;

class Solution239
{
public:
    /**
    * ����һ���������� nums����һ����СΪ k �Ļ������ڴ������������ƶ�����������Ҳࡣ��ֻ���Կ����ڻ��������ڵ� k �����֡���������ÿ��ֻ�����ƶ�һλ��
    * ���ػ��������е����ֵ ��
    */
    vector<int> maxSlidingWindow(vector<int>& nums, int k); //��ʱ
    vector<int> maxSlidingWindow_A(vector<int>& nums, int k);
    void test();
};