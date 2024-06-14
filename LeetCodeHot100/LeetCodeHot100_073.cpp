#include "LeetCodeHot100_073.h"
#include <iostream>
#include <vector>
#include <unordered_set>
using std::cout;
using std::endl;
using std::vector;
using std::unordered_set;

void Solution073::setZeroes(vector<vector<int>>& matrix)
{
	unordered_set<int> rows;
	unordered_set<int> cols;
	for (int i = 0; i < matrix.size(); ++i)
	{
		for (int j = 0; j < matrix[i].size(); ++j)
		{
			if (matrix[i][j] == 0)
			{
				rows.insert(i);
				cols.insert(j);
			}
		}
	}
	for (int i = 0; i < matrix.size(); ++i)
	{
		if (rows.find(i) != rows.end())
		{
			for (int j = 0; j < matrix[i].size(); ++j)
			{
				matrix[i][j] = 0;
			}
		}
	}
	for (int i = 0; i < matrix.size(); ++i)
	{
		for (int j = 0; j < matrix[i].size(); ++j)
		{
			if (cols.find(j) != cols.end())
			{
				matrix[i][j] = 0;
			}
		}
	}
}

void Solution073::test()
{
	vector<vector<int>> matrix{ {0,1,2,0} ,{3,4,5,2},{1,3,1,5} };
	for (const auto& v : matrix)
	{
		for (const auto& n : v)
		{
			cout << n << " ";
		}
		cout << endl;
	}
	setZeroes(matrix);
	cout << "ÖÃÁãºó" << endl;
	for (const auto& v : matrix)
	{
		for (const auto& n : v)
		{
			cout << n << " ";
		}
		cout << endl;
	}
}
