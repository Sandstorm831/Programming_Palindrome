/*
Given two strings X and Y, print the shortest string that has both X and Y as subsequences.
If multiple shortest super-sequence exists, print any one of them.
Examples: 
Input: X = "AGGTAB",  Y = "GXTXAYB"
Output: "AGXGTXAYB" OR "AGGXTXAYB" 
OR Any string that represents shortest
supersequence of X and Y

Input: X = "HELLO",  Y = "GEEK"
Output: "GEHEKLLO" OR "GHEEKLLO"
OR Any string that represents shortest 
supersequence of X and Y
*/
#include <bits/stdc++.h>
using namespace std;
string shortSuper(string A, string B)
{
    int a = A.size();
    int b = B.size();
    vector<vector<int>> dp(a+1, vector<int> (b+1));
    for (int i = 0; i <= a; i++)
    {
        for (int j = 0; j <= b; j++)
        {
            if(i == 0 || j == 0) dp[i][j] = 0;
            else if(A[i-1] == B[j-1]) dp[i][j] = 1+dp[i-1][j-1];
            else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }
    string pin="";
    while(a != 0 && b !=0)
    {
        if(A[a-1] == B[b-1])
        {
            pin.push_back(A[a-1]);
            a--;b--;
        }
        else
        {
            if(dp[a-1][b] > dp[a][b-1])
            {
                pin.push_back(A[a-1]);
                a--;
            }
            else{
                pin.push_back(B[b-1]);
                b--;
            }
        }
    }
    while(a != 0)
    {
        pin.push_back(A[a-1]);
        a--;
    }
    while(b != 0)
    {
        pin.push_back(B[b-1]);
        b--;
    }
    reverse(pin.begin(), pin.end());
    return pin;
}
int main()
{
    string A = "aggtab";
    string B = "gxtxayb";
    cout<<shortSuper(A,B);
}