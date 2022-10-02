// Problem Link -  https://www.interviewbit.com/problems/ways-to-decode/
/* Problem Solution
int l = 1e9+7;
int bottomup(string A)
{
    if(A[0] == '0') return 0;
    int len = A.length();
    vector<int> dp(len,0);
    dp[0] = 1;
    for(int i=1; i<len; i++)
    {
        int c = A[i]-48;
        int b = A[i-1]-48;
        int a = 10*b + c;
        if(c == 0)
        {
            if(a==0 || a > 26) return 0;
            if(i >=2) dp[i] = dp[i-2]%l;
            else dp[i] = dp[i-1]%l;
        } 
        else if(b == 0 || a > 26) dp[i] = dp[i-1]%l;
        else 
        {
            if(i == 1) dp[i]=2;
            else dp[i] = (dp[i-1]%l+dp[i-2]%l)%l;
        }
    }
    return dp[len-1];
}
int Solution::numDecodings(string A) 
{
    return bottomup(A);
}
*/
#include <bits/stdc++.h>
using namespace std;
int l = 1e9+7;
int bottomup(string A)
{
    if(A[0] == '0') return 0;
    int len = A.length();
    vector<int> dp(len,0);
    dp[0] = 1;
    for(int i=1; i<len; i++)
    {
        int c = A[i]-48;
        int b = A[i-1]-48;
        int a = 10*b + c;
        if(c == 0)
        {
            if(a==0 || a > 26) return 0;
            if(i >=2) dp[i] = dp[i-2]%l;
            else dp[i] = dp[i-1]%l;
        } 
        else if(b == 0 || a > 26) dp[i] = dp[i-1]%l;
        else 
        {
            if(i == 1) dp[i]=2;
            else dp[i] = (dp[i-1]%l+dp[i-2]%l)%l;
        }
    }
    return dp[len-1];
}
int main()
{
    string A = "1425245632464";
    return bottomup(A);
}