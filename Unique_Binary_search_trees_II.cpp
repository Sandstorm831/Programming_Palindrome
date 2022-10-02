// Problem Link - https://www.interviewbit.com/problems/unique-binary-search-trees-ii/
/* Problem solution ---------------------------------------------------------------+
int recursor(pair<int,int> pairy, vector<vector<int>>& dp)      <------------------+
{
    int a = pairy.first;
    int b = pairy.second;
    if(a>b) return 0;
    int ans=0;
    if(a == b) return 1;    
    if(dp[a][b] != -1) return dp[a][b];
    for(int i=pairy.first; i<=pairy.second; i++)
    {
        int left = recursor(make_pair(a,i-1), dp);
        left=left>0?left:1;
        int right;
        right = recursor(make_pair(i+1, b), dp);
        right=right>0?right:1;
        ans+=left*right;
    }
    return dp[a][b] = ans;
}
int Solution::numTrees(int A) {
    pair<int,int> pairy = {0,A-1};
    vector<vector<int>> dp(A+1, vector<int> (A+1,-1));
    return recursor(pairy, dp);
}
*/
#include <bits/stdc++.h>
using namespace std;
int recursor(pair<int,int> pairy, vector<vector<int>>& dp)
{
    int a = pairy.first;
    int b = pairy.second;
    if(a>b) return 0;
    int ans=0;
    if(a == b) return 1;
    if(dp[a][b] != -1) return dp[a][b];
    for(int i=pairy.first; i<=pairy.second; i++)
    {
        int left = recursor(make_pair(a,i-1), dp);
        left=left>0?left:1;
        int right;
        right = recursor(make_pair(i+1, b), dp);
        right=right>0?right:1;
        ans+=left*right;
    }
    return dp[a][b] = ans;
}
int main(){
    int A = 8;
    pair<int,int> pairy = {0,A-1};
    vector<vector<int>> dp(A+1, vector<int> (A+1,-1));
    return recursor(pairy, dp);
}