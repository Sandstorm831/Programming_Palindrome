// Question Link - https://www.interviewbit.com/problems/dice-throw/
// Solution 

int Solution::findDiceSum(int A, int B, int C) {
    vector<vector<int>> dp(A+1, vector<int> (C+1,0));
    int mod=1e9+7;
    dp[0][0]=1;
    for(int i=1; i<=A; i++)
    {
        for(int j=i;j<=C;j++)
        {
            dp[i][j] = (dp[i-1][j-1]%mod+dp[i][j-1]%mod)%mod;
            if(j>B)
            {
                dp[i][j] = (dp[i][j] - dp[i-1][j-B-1] + mod)%mod;
            } 
        }
    }
    return dp[A][C];
}