/*
Given two strings ‘str1’ and ‘str2’ of size m and n respectively.
The task is to remove/delete and insert the minimum number of characters from/in str1 to transform it into str2.
It could be possible that the same character needs to be removed/deleted from one point of str1 and inserted to some another point.

Example 1: 

Input : 
str1 = "heap", str2 = "pea" 
Output : 
Minimum Deletion = 2 and
Minimum Insertion = 1
Explanation:
p and h deleted from heap
Then, p is inserted at the beginning
One thing to note, though p was required yet
it was removed/deleted first from its position and
then it is inserted to some other position.
Thus, p contributes one to the deletion_count
and one to the insertion_count.
*/
#include <bits/stdc++.h>
using namespace std;
vector<int> insdel(string A, string B)
{
    int a = A.size();
    int b = B.size();
    vector<vector<int>> dp(a+1, vector<int> (b+1));
    for (int i = 0; i <= a; i++)
    {
        for (int j = 0; j <= b; j++)
        {
            if(i == 0 || j == 0 ) dp[i][j] = 0;
            else if(A[i-1] == B[j-1]) dp[i][j] = 1+dp[i-1][j-1];
            else dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
        }
    }
    vector<int> pun;
    pun.push_back(a-dp[a][b]);
    pun.push_back(b-dp[a][b]);
    return pun;
    
}
int main()
{
    string A = "heap";
    string B = "pea";
    vector<int> punn = insdel(A,B);
    cout<<punn[0]<<" "<<punn[1];
}