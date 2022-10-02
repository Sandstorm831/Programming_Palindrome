/* Problem Link - https://www.interviewbit.com/problems/queen-attack/
Problem Solution
bool is_valid(int x,int y,int n,int m)
{
    if(x>=0 && x<n && y>=0 && y<m)
    {
        return true;
    }
    return false;
}

int recursor(vector<vector<vector<int>>> &dp,vector<pair<int,int>> &dirs,vector<string> &A,int i,int j,int n, int m,int k)
{
    if(dp[k][i][j]!=-1)
    {
        return dp[k][i][j];
    }
    int x = i + dirs[k].first;
    int y = j + dirs[k].second;
    dp[k][i][j] = 0;
    if(is_valid(x,y,n,m))
    {
        if(A[x][y] == '1')
        {
            dp[k][i][j]++;
        }
        else
        {
            dp[k][i][j] = recursor(dp,dirs,A,x,y,n,m,k);   
        }
        return dp[k][i][j];
    }
    return 0;
}
vector<vector<int> > Solution::queenAttack(vector<string> &A) 
{
    int n = A.size();
    int m = A[0].size();
    vector<pair<int,int>> dirs = {{1,0},{1,-1},{0,-1},{-1,-1},{-1,0},{-1,1},{0,1},{1,1}};
    vector<vector<vector<int>>> dp(8,vector<vector<int>>(n,vector<int>(m,-1)));
    vector<vector<int>> res(n,vector<int>(m,0));
    for(int k=0;k<8;k++)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                res[i][j] +=recursor(dp,dirs,A,i,j,n,m,k);
            }
        }
    }
    return res;
}*/
#inclue <bits/stdc++.h>
using namespace std;
bool is_valid(int x,int y,int n,int m)
{
    if(x>=0 && x<n && y>=0 && y<m)
    {
        return true;
    }
    return false;
}

int recursor(vector<vector<vector<int>>> &dp,vector<pair<int,int>> &dirs,vector<string> &A,int i,int j,int n, int m,int k)
{
    if(dp[k][i][j]!=-1)
    {
        return dp[k][i][j];
    }
    int x = i + dirs[k].first;
    int y = j + dirs[k].second;
    dp[k][i][j] = 0;
    if(is_valid(x,y,n,m))
    {
        if(A[x][y] == '1')
        {
            dp[k][i][j]++;
        }
        else
        {
            dp[k][i][j] = recursor(dp,dirs,A,x,y,n,m,k);   
        }
        return dp[k][i][j];
    }
    return 0;
}
int main()
{
    vector<string> A = {"010", "100", "001"};
    int n = A.size();
    int m = A[0].size();
    vector<pair<int,int>> dirs = {{1,0},{1,-1},{0,-1},{-1,-1},{-1,0},{-1,1},{0,1},{1,1}};
    vector<vector<vector<int>>> dp(8,vector<vector<int>>(n,vector<int>(m,-1)));
    vector<vector<int>> res(n,vector<int>(m,0));
    for(int k=0;k<8;k++)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                res[i][j] +=recursor(dp,dirs,A,i,j,n,m,k);
            }
        }
    }
    return res;
}