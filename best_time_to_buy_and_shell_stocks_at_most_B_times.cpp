// Question Link - https://www.interviewbit.com/problems/best-time-to-buy-and-sell-stock-atmost-b-times/
// Solution

int Solution::solve(vector<int> &a, int b)
{
    if(b > a.size()) b = a.size();
    vector<vector<int>> dp(a.size()+1, vector<int> (b+1));
    for(int i=0; i<=a.size(); i++) dp[i][0]=0;
    for(int i=0;i<=b;i++)
    {
        dp[0][i]=0;
        dp[1][i]=0;
    }
    for(int i=1;i<=b; i++)
    {
        int maxx = INT_MIN;
        for(int j=2;j<=a.size(); j++)
        {
            maxx = max(maxx, dp[j-1][i-1]-a[j-2]);
            dp[j][i] = max(maxx+a[j-1], dp[j-1][i]);
        }
    }
    return dp[a.size()][b];
}
// To understand https://youtu.be/3YILP-PdEJA