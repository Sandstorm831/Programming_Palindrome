// Problem LInk - https://www.interviewbit.com/problems/arrange-ii/
/*
int miner(string h, int s)
{
    int n = h.size();
    vector<vector<int>> dp(n+1, vector<int> (s+1, 0));
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=s; j++)
        {
            if(j>i) 
            {
                dp[i][j]=-1; 
                continue;
            }
            int b=0; int w=0;
            dp[i][j]=INT_MAX;
            for(int k=i; k>=1; k--)
            {
                if(j>k) break;
                if(h[k-1] == 'B') b++;
                else w++;
                if(dp[k-1][j-1]!=-1) dp[i][j] = min(dp[i][j], b*w+dp[k-1][j-1]);
            }
            if(j == 1) dp[i][j] = b*w;
        }
    }
    return dp[n][s];
}
int Solution::arrange(string A, int B) {
    return miner(A, B);
}
*/
#include <bits/stdc++.h>
using namespace std;
int miner(string h, int s)
{
    int n = h.size();
    vector<vector<int>> dp(n+1, vector<int> (s+1, 0));
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=s; j++)
        {
            if(j>i) 
            {
                dp[i][j]=-1; 
                continue;
            }
            int b=0; int w=0;
            dp[i][j]=INT_MAX;
            for(int k=i; k>=1; k--)
            {
                if(j>k) break;
                if(h[k-1] == 'B') b++;
                else w++;
                if(dp[k-1][j-1]!=-1) dp[i][j] = min(dp[i][j], b*w+dp[k-1][j-1]);
            }
            if(j == 1) dp[i][j] = b*w;
        }
    }
    return dp[n][s];
}
int main()
{
    string A = "WWBBB";
    int B = 3;
    cout<<miner(A,B);
}