/*
Catalan numbers are a sequence of natural numbers that occurs in many interesting counting problems like following.

Count the number of expressions containing n pairs of parentheses which are correctly matched. For n = 3, possible expressions are ((())), ()(()), ()()(), (())(), (()()).
Count the number of possible Binary Search Trees with n keys (See this)
Count the number of full binary trees (A rooted binary tree is full if every vertex has either two children or no children) with n+1 leaves.
Given a number n, return the number of ways you can draw n chords in a circle with 2 x n points such that no 2 chords intersect.
*/
int src=1e9+7;
int catalan(long long int A)
{
    if(A==1 || A==0) return 1;
    else if(A == 2) return 2;
    vector<long long int> dp(A+1);
    dp[0]=1;
    dp[1]=1;
    dp[2]=2;
    for(int i=3; i<=A; i++)
    {
        dp[i]=0;
        for(int j=0; j<i; j++)
        {
            dp[i] = (dp[i]+dp[j]*dp[i-1-j])%src;
        }
    }
    return dp[A];
}
int Solution::chordCnt(int A) {
    long long int n = (long long int)A;
    return catalan(n);
}