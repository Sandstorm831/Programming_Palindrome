/*
The Longest Increasing Subsequence (LIS) problem is to find the length of the longest
subsequence of a given sequence such that all elements of the subsequence are sorted in
increasing order. For example, the length of LIS for {10, 22, 9, 33, 21, 50, 41, 60, 80}
is 6 and LIS is {10, 22, 33, 50, 60, 80}
Input: arr[] = {3, 10, 2, 1, 20}
Output: Length of LIS = 3
The longest increasing subsequence is 3, 10, 20

Input: arr[] = {3, 2}
Output: Length of LIS = 1
The longest increasing subsequences are {3} and {2}

Input: arr[] = {50, 3, 10, 7, 40, 80}
Output: Length of LIS = 4
The longest increasing subsequence is {3, 7, 40, 80
*/
#include <bits/stdc++.h>
using namespace std;
int incSub(vector<int> A)
{
    int maxx = 1;
    int n=A.size();
    vector<int> dp(n,1);
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(A[i]>A[j]) dp[i] = max(dp[i],1+dp[j]);
            if(dp[i]>maxx) maxx = dp[i];
        }
    }
    return maxx;
}
int main()
{
    vector<int> A = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};
    cout<<incSub(A);
}