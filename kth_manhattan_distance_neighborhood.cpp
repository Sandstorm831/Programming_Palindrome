// Question LInk - https://www.interviewbit.com/problems/kth-manhattan-distance-neighbourhood/
// solution 

bool checker(int x, int y, int r, int c)
{
    if(x>=0 && x<r && y>=0 && y<c) return true;
    return false;
}
int recursor(vector<vector<int>> &B, int i, int j, int k, vector<vector<vector<int>>>& dp)
{
    if(k==0)
    {
        dp[i][j][0]=B[i][j];
        return B[i][j];
    }
    else if(dp[i][j][k] != -1) return dp[i][j][k];
    else
    {
        int ans=INT_MIN;
        if(checker(i+1, j, B.size(), B[0].size())) ans=max(ans,recursor(B, i+1, j, k-1, dp));
        if(checker(i, j+1, B.size(), B[0].size())) ans=max(recursor(B, i, j+1, k-1, dp),ans);
        if(checker(i-1, j, B.size(), B[0].size())) ans=max(ans, recursor(B, i-1, j, k-1, dp));
        if(checker(i, j-1, B.size(), B[0].size())) ans=max(recursor(B, i, j-1, k-1, dp), ans);
        return dp[i][j][k]=max(ans, B[i][j]);
    }
}
vector<vector<int> > Solution::solve(int A, vector<vector<int> > &B) {
    vector<vector<vector<int>>> dp(B.size(), vector<vector<int>> (B[0].size(), vector<int> (A+1,-1)));
    vector<vector<int>> ans(B.size(), vector<int> (B[0].size(), -1));
    for(int i=0;i<B.size(); i++)
    {
        for(int j=0; j<B[0].size(); j++)
        {
            ans[i][j] = recursor(B, i, j, A, dp);
        }
    }
    return ans;
}
// 4 5 8
// 5 8 8