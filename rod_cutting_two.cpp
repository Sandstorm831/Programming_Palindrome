// Problem Link - https://www.interviewbit.com/problems/rod-cutting/ 
/*complete problem solution
void getans(vector<int>& finale, vector<vector<int>> dp, int i, int j, vector<int> p)
{
    if(j-i <= 1) return ;
    for(int mid = i; mid<=j; mid++)
    {
        if(dp[i][mid]+dp[mid][j]+p[j]-p[i] == dp[i][j])
        {
            finale.push_back(p[mid]);
            getans(finale, dp, i, mid, p);
            getans(finale, dp, mid, j, p);
            return;
        }
    }
    return;
}
vector<int> Solution::rodCut(int A, vector<int> &B) {
    vector<int> p;
    p.push_back(0);
    for(int b:B) p.push_back(b);
    p.push_back(A);
    int n = p.size();
    sort(p.begin(), p.end());
    vector<vector<int>> dp(n+1, vector<int> (n+1,0));
    for(int diff = 2; diff<=n; diff++)
    {
        for(int i = 0; i<n-diff+1; i++)
        {
            dp[i][i+diff-1] = INT_MAX;
            for(int j = i+1; j<i+diff-1; j++)
            {
                dp[i][i+diff-1] = min(dp[i][i+diff-1], p[i+diff-1]-p[i]+dp[i][j]+dp[j][i+diff-1]);
            }
        }   
    }
    vector<int> finale;
    getans(finale, dp, 0, n-1, p);
    return finale;
}
*/
#include <bits/stdc++.h>
using namespace std;
void getans(vector<int>& finale, vector<vector<int>> dp, int i, int j, vector<int> p)
{
    if(j-i <= 1) return ;
    for(int mid = i; mid<=j; mid++)
    {
        if(dp[i][mid]+dp[mid][j]+p[j]-p[i] == dp[i][j])
        {
            finale.push_back(p[mid]);
            getans(finale, dp, i, mid, p);
            getans(finale, dp, mid, j, p);
            return;
        }
    }
    return;
}
vector<int> rodCut(int A, vector<int> &B) {
    vector<int> p;
    p.push_back(0);
    for(int b:B) p.push_back(b);
    p.push_back(A);
    int n = p.size();
    sort(p.begin(), p.end());
    vector<vector<int>> dp(n+1, vector<int> (n+1,0));
    for(int diff = 2; diff<=n; diff++)
    {
        for(int i = 0; i<n-diff+1; i++)
        {
            dp[i][i+diff-1] = INT_MAX;
            for(int j = i+1; j<i+diff-1; j++)
            {
                dp[i][i+diff-1] = min(dp[i][i+diff-1], p[i+diff-1]-p[i]+dp[i][j]+dp[j][i+diff-1]);
            }
        }   
    }
    vector<int> finale;
    getans(finale, dp, 0, n-1, p);
    return finale;
}
int main()
{
    vector<int> weak_p = {5,2,1};
    int len = 6;
    vector<int> hell = rodCut(len, weak_p);
    for (int i = 0; i < hell.size(); i++)
    {
        cout<<hell[i]<<endl;
    }
}