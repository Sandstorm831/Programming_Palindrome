// Problem Link  -  https://www.interviewbit.com/problems/max-rectangle-in-binary-matrix/
/*
int maxer(vector<vector<int>> A)
{
    int n=A.size();
    int m=A[0].size();
    vector<vector<int>> dp(n, vector<int> (m,0));
    for(int i=0; i<n; i++)
    {
        int count=0;
        for(int j=m-1; j>=0; j--)
        {
            if(A[i][j]==1) count++;
            else count=0;
            dp[i][j]=count;
        }
    }
    int maxa = INT_MIN;
    for(int i=0; i<m; i++)
    {
        vector<int> pre(n);
        vector<int> next(n);
        stack<int> s;
        for(int j=0;j<n; j++)
        {
            while(!s.empty() && dp[s.top()][i]>=dp[j][i]) s.pop();
            if(s.empty()) pre[j]=0;
            else pre[j] = s.top()+1;
            s.push(j);
        }
        while(!s.empty()) s.pop();
        for(int j=n-1; j>=0; j--)
        {
            while(!s.empty() && dp[s.top()][i]>=dp[j][i]) s.pop();
            if(s.empty()) next[j]=n-1;
            else next[j] = s.top()-1;
            s.push(j);
        }
        for(int j=0; j<n; j++)
        maxa = max(maxa, dp[j][i]*(next[j]-pre[j]+1));
    }
    return maxa;
}
int Solution::maximalRectangle(vector<vector<int> > &A) {
    return maxer(A);
}
*/
#include <bits/stdc++.h>
using namespace std;
int maxer(vector<vector<int>> A)
{
    int n=A.size();
    int m=A[0].size();
    vector<vector<int>> dp(n, vector<int> (m,0));
    for(int i=0; i<n; i++)
    {
        int count=0;
        for(int j=m-1; j>=0; j--)
        {
            if(A[i][j]==1) count++;
            else count=0;
            dp[i][j]=count;
        }
    }
    int maxa = INT_MIN;
    for(int i=0; i<m; i++)
    {
        vector<int> pre(n);
        vector<int> next(n);
        stack<int> s;
        for(int j=0;j<n; j++)
        {
            while(!s.empty() && dp[s.top()][i]>=dp[j][i]) s.pop();
            if(s.empty()) pre[j]=0;
            else pre[j] = s.top()+1;
            s.push(j);
        }
        while(!s.empty()) s.pop();
        for(int j=n-1; j>=0; j--)
        {
            while(!s.empty() && dp[s.top()][i]>=dp[j][i]) s.pop();
            if(s.empty()) next[j]=n-1;
            else next[j] = s.top()-1;
            s.push(j);
        }
        for(int j=0; j<n; j++)
        maxa = max(maxa, dp[j][i]*(next[j]-pre[j]+1));
    }
    return maxa;
}
int main()
{
    vector<vector<int>> A = {{1,0,0}, {0,1,1}, {0,1,1}};
    cout<<maxer(A);
}