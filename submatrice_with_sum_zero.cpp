/*
Problem Link - https://www.interviewbit.com/problems/sub-matrices-with-sum-zero/
int zeror(vector<int> temp)
{
    int counter=0;
    for(int i=0; i<temp.size(); i++)
    {
        int summer=0;
        for(int j=i; j<temp.size(); j++)
        {
            summer+=temp[j];
            if(summer == 0) counter++;
        }
    }
    return counter;
}
int finder(vector<vector<int>> A, int a, int b, int m)
{
    vector<int> temp;
    for(int i=0; i<m; i++)
    {
        int tempo=0;
        for(int j=a; j<=b; j++)
        {
            tempo+=A[j][i];
        }
        temp.push_back(tempo);
    }
    int turner = zeror(temp);
    return turner;
}
int Solution::solve(vector<vector<int> > &A) {
    if(A.size() == 0 || A[0].size() == 0) return 0;
    int a = A.size();
    int b = A[0].size();
    int ans=0;
    for(int i=0; i<a; i++)
    {
        for(int j=i; j<a; j++)
        {
            ans += finder(A, i, j, b);
        }
    }
    return ans;
}
////////////// Both solutions upper and below are correct,
////////////// upper implementation is a bit easy one, below one is a bit tricky
///////////// below implementation is with dp, upper dont involve dp
int maxer(vector<vector<int>> A)
{
    int a = A.size();
    int b = A[0].size();
    vector<vector<int>> dp(a, vector<int> (b, 0));
    for(int i=0;i<a; i++)
    {
        for(int j=0; j<b; j++)
        {
            dp[i][j]=A[i][j];
            if(i !=0 ) dp[i][j] += dp[i-1][j];
            if(j !=0 ) dp[i][j] += dp[i][j-1];
            if(i!=0 && j!=0) dp[i][j] -= dp[i-1][j-1];
        }
    }
    int ans=0;
    for(int i=0; i<a; i++)
    {
        for(int j=i; j<a;j++)
        {
            unordered_map<int,int> maper;
            maper[0]=1;
            for(int k=0; k<b; k++)
            {
                int val = dp[j][k];
                if( i!=0) val-=dp[i-1][k];
                if(maper.find(val) != maper.end())
                {
                    ans += maper[val];
                    maper[val]++;
                }
                else maper[val]=1;
            }
        }
    }
    return ans;
}
int Solution::solve(vector<vector<int> > &A) {
    if(A.size() == 0 || A[0].size() == 0) return 0;
    return maxer(A);
}
*/
#include <bits/stdc++.h>
using namespace std;
int maxer(vector<vector<int>> A)
{
    int a = A.size();
    int b = A[0].size();
    vector<vector<int>> dp(a, vector<int> (b, 0));
    for(int i=0;i<a; i++)
    {
        for(int j=0; j<b; j++)
        {
            dp[i][j]=A[i][j];
            if(i !=0 ) dp[i][j] += dp[i-1][j];
            if(j !=0 ) dp[i][j] += dp[i][j-1];
            if(i!=0 && j!=0) dp[i][j] -= dp[i-1][j-1];
        }
    }
    int ans=0;
    for(int i=0; i<a; i++)
    {
        for(int j=i; j<a;j++)
        {
            unordered_map<int,int> maper;
            maper[0]=1;
            for(int k=0; k<b; k++)
            {
                int val = dp[j][k];
                if( i!=0) val-=dp[i-1][k];
                if(maper.find(val) != maper.end())
                {
                    ans += maper[val];
                    maper[val]++;
                }
                else maper[val]=1;
            }
        }
    }
    return ans;
}
int main()
{
    vector<vector<int>> A = {{-8 5  7},{3  7 -8},{5 -8  9}};
    if(A.size() == 0 || A[0].size() == 0) return 0;
    return maxer(A);
}