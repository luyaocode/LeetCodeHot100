#pragma once
#include <string>
using std::string;

class Solution076
{
public:
    /**
    * ����һ���ַ��� s ��һ���ַ��� t ������ s �к��� t �����ַ�����С�Ӵ������ s �в����ں��� t �����ַ����Ӵ����򷵻ؿ��ַ��� "" ��
    * ע�⣺
    * ���� t ���ظ��ַ�������Ѱ�ҵ����ַ����и��ַ��������벻���� t �и��ַ�������
    * ��� s �д����������Ӵ������Ǳ�֤����Ψһ�Ĵ𰸡�
    * m == s.length
    * n == t.length
    * 1 <= m, n <= 105
    * s �� t ��Ӣ����ĸ���
    */
    string minWindow(string s, string t);
    void test();
};