#pragma once
#include <vector>
#include <string>
using std::vector;
using std::string;

class Solution438
{
public:
    /**
    * ���������ַ��� s �� p���ҵ� s ������ p �� ��λ�� ���Ӵ���������Щ�Ӵ�����ʼ�����������Ǵ������˳��
    * ��λ�� ָ����ͬ��ĸ�������γɵ��ַ�����������ͬ���ַ�������
    * 1 <= s.length, p.length <= 3 * 104
    * s �� p ������Сд��ĸ
    * 
    */
    vector<int> findAnagrams(string s, string p); //�����ⷨ����ʱ
    vector<int> findAnagrams_A(string s, string p);
    void test();
};