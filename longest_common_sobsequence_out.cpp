/*
iven two sequences, print the longest subsequence present in both of them.

Examples: 

LCS for input Sequences “ABCDGH” and “AEDFHR” is “ADH” of length 3. 
LCS for input Sequences “AGGTAB” and “GXTXAYB” is “GTAB” of length 4.
We have discussed Longest Common Subsequence (LCS) problem in a previous post. The function discussed there was mainly
to find the length of LCS. To find length of LCS, a 2D table L[][] was constructed. In this post, the function to construct and print LCS is discussed.

Following is detailed algorithm to print the LCS. It uses the same 2D table L[][].

Construct L[m+1][n+1] using the steps discussed in previous post.
The value L[m][n] contains length of LCS. Create a character array lcs[] of length equal to the length of lcs plus 1 (one extra to store \0).
Traverse the 2D array starting from L[m][n]. Do following for every cell L[i][j] 
If characters (in X and Y) corresponding to L[i][j] are same (Or X[i-1] == Y[j-1]), then include this character as part of LCS. 
Else compare values of L[i-1][j] and L[i][j-1] and go in direction of greater value.
*/
#include <bits/stdc++.h>
using namespace std;
string longSub(string A, string B)
{
    int a = A.size();
    int b = B.size();
    vector<vector<int>> dp(a+1, vector<int> (b+1));
    for(int i =0; i<=a; i++)
    {
        for(int j = 0; j<=b; j++)
        {
            if(i == 0 || j == 0) dp[i][j] = 0;
            else if(A[i-1] == B[j-1]) dp[i][j] = 1+dp[i-1][j-1];
            else dp[i][j] = max(dp[i-1][j] ,dp[i][j-1]);
        }
    }
    // after the dp table is made, longest subsequence string can be made
    int l = a, m = b;
    string fin = "";
    while(a!= 0 && b!= 0)
    {
        if(A[a-1] == B[b-1])
        {
            fin.push_back(A[a-1]);
            a--;b--;
        }
        else{
            if(dp[a][b-1]>dp[a-1][b]) b--;
            else a--;
        }
    }
    reverse(fin.begin(), fin.end());
    return fin;
    
}
int main()
{
    string A = "cnbpskbecwllitrsglryvehftjmcpxypu";
    string B = "vtjmxypu";
    cout<<(longSub(A,B));
}