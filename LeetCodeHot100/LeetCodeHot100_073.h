#pragma once
#include <vector>
using std::vector;
class Solution073
{
public:
    /**
    * 给定一个 m x n 的矩阵，如果一个元素为 0 ，则将其所在行和列的所有元素都设为 0 。请使用 原地 算法。
    */
    void setZeroes(vector<vector<int>>& matrix);
    void test();
};