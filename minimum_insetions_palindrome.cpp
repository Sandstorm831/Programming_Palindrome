/*
Given string str, the task is to find the minimum number of characters to be inserted to convert it to a palindrome.

Before we go further, let us understand with a few examples: 

ab: Number of insertions required is 1 i.e. bab
aa: Number of insertions required is 0 i.e. aa
abcd: Number of insertions required is 3 i.e. dcbabcd
abcda: Number of insertions required is 2 i.e. adcbcda which is the same as the number of insertions in the substring bcd(Why?).
abcde: Number of insertions required is 4 i.e. edcbabcde
*/
#include <bits/stdc++.h>
using namespace std;
int minIns(string A)
{
    int a = A.size();
    string B = A;
    reverse(A.begin(), A.end());
    vector<vector<int>> dp(a+1, vector<int> (a+1));
    for (int i = 0; i <= a; i++)
    {
        for (int j = 0; j <= a; j++)
        {
            if(i == 0 || j == 0) dp[i][j] = 0;
            else if(A[i] == B[j]) dp[i][j] = 1+dp[i-1][j-1];
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return a-dp[a][a];
    
}
int main()
{
    string A = "aebcdba";
    cout<<minIns(A); // min no. of insertions and deletions to convert the string to palindrome are same
}