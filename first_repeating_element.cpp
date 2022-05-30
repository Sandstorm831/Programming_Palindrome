// Problem Link - https://www.interviewbit.com/problems/first-repeating-element/
#include <bits/stdc++.h>
using namespace std;
int solve(vector<int> A)
{
    unordered_map<int, int> inty;
    int n = A.size();
    int i, small = -1;
    for (i = 0; i < n; i++)
    {
        if (inty.find(A[n - 1 - i]) != inty.end())
        {
            small = n - 1 - i;
        }

        inty[A[n - 1 - i]] = n - 1 - i;
    }
    if (small == -1)
        return -1;
    else
        return A[small];
}
int main()
{
    vector<int> A = {10, 5, 3, 4, 3, 5, 6}; // This has to be assumed
    cout << solve(A);
}