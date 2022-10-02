// Problem Link - https://www.interviewbit.com/problems/chain-of-pairs/
/* Problem Solution Function 
int Solution::solve(vector<vector<int> > &A) {
    int size = A.size();
    vector<int> dp(size, 1);
    int maxx =  INT_MIN;
    for(int i=1; i<size; i++)
    {
        for(int j=0; j<i; j++)
        {
            if(A[j][1]<A[i][0]) dp[i] = max(dp[j]+1, dp[i]);
            maxx = max(maxx, dp[i]);
        }
    }
    return maxx;
}
*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    A = {{5,24}, {39, 60}, {15,28}, {27, 40}, {50, 90}};
    int size = A.size();
    vector<int> dp(size, 1);
    int maxx =  INT_MIN;
    for(int i=1; i<size; i++)
    {
        for(int j=0; j<i; j++)
        {
            if(A[j][1]<A[i][0]) dp[i] = max(dp[j]+1, dp[i]);
            maxx = max(maxx, dp[i]);
        }
    }
    cout<<maxx;
}