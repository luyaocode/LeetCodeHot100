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
    vector<int> maxSlidingWindow(vector<int>& nums, int k); //�����ⷨO((n-k)(klogk))
    vector<int> maxSlidingWindow_A(vector<int>& nums, int k);//���ȶ���O(nlogn)
    vector<int> maxSlidingWindow_B(vector<int>& nums, int k);//��������O(n)
    void test();
};