#pragma once
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n,nt;
    cin >> n;
    nt = n;
    vector<int> a;
    int in;
    int q;
    while (n > 0 && cin >> in)
    {
        a.push_back(in);
        --n;
    }
    cin >> q;
    int times = q;
    vector<int> qs;
    while (q > 0 && cin >> in)
    {
        qs.push_back(in);
        --q;
    }
    for (int i = 0; i < times; ++i)
    {
        int sum = 0;
        for (int j = 0; j < nt; ++j)
        {
            a[j] += qs[i];
            sum += a[j] > 0 ? a[j] : (0 - a[j]);
        }
        cout << sum << endl;
    }
}