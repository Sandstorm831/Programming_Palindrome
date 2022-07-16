/*
Given two strings ‘X’ and ‘Y’, find the length of the longest common substring. 

Examples : 

Input : X = “GeeksforGeeks”, y = “GeeksQuiz” 
Output : 5 
Explanation:
The longest common substring is “Geeks” and is of length 5.

Input : X = “abcdxyz”, y = “xyzabcd” 
Output : 4 
Explanation:
The longest common substring is “abcd” and is of length 4.

Input : X = “zxabcdezy”, y = “yzabcdezx” 
Output : 6 
Explanation:
The longest common substring is “abcdez” and is of length 6.
*/
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> dp;
int deep(string A, string B)
{
    int a = A.size();
    int b = B.size();
    int maxx = INT_MIN;
    vector<vector<int>> dpp(a+1, vector<int>(b+1));
    for (int i = 0; i <= a; i++)
    {
        for (int j = 0; j <= b; j++)
        {
            if(i == 0 || j == 0) dpp[i][j] = 0;
            else if(A[i-1] == B[j-1])
            {
                dpp[i][j] = 1+dpp[i-1][j-1];
                maxx = max(maxx, dpp[i][j]);
            }
            else dpp[i][j] = 0;
        }
    }
    return maxx;
    
}
int recursor(string A,string B,int a,int b,int count)
{
    if(a == 0||b == 0) return count;
    if(dp[a][b] != -1) return dp[a][b];
    if(A[a-1] == B[b-1]) return recursor(A,B,a-1,b-1,count+1);
    int count1 = recursor(A,B,a,b-1,0);
    int count2 = recursor(A,B,a-1,b,0);
    dp[a][b] = max({count,count1,count2});
    return dp[a][b];
}
int longestSub(string A, string B)
{
    int a = A.size();
    int b = B.size();
    int count = 0;
    dp.resize(a+1,vector<int> (b+1,-1));
    return recursor(A,B,a,b,count);
}
int main()
{
    string A = "abcdxyzabcdexyzauvbekd";
    string B = "xyzabcdexyza";
    cout<<longestSub(A,B)<<endl<<deep(A,B);
}