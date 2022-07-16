/*
Given an array ‘ARR’, partition it into two subsets (possibly empty) such that their union is the original array. Let the sum of the elements of these two subsets be ‘S1’ and ‘S2’.
Given a difference ‘D’, count the number of partitions in which ‘S1’ is greater than or equal to ‘S2’ and the difference between ‘S1’ and ‘S2’ is equal to ‘D’

If ‘Pi_Sj’ denotes the Subset ‘j’ for Partition ‘i’. Then, two partitions P1 and P2 are considered different if:
1) P1_S1 != P2_S1 i.e, at least one of the elements of P1_S1 is different from P2_S2.
2) P1_S1 == P2_S2, but the indices set represented by P1_S1 is not equal to the indices set of P2_S2. Here, the indices set of P1_S1 is formed by taking the indices of the elements from which the subset is formed.
Refer to the example below for clarification.
*/
#include <bits/stdc++.h>
using namespace std;
int differencesubset(vector<int> A, int diff)
{
    int size = A.size();
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum+=A[i];
    }
    int sumfind = (sum+diff)/2;
    vector<vector<int>> dp(size+1, vector<int> (sumfind+1));
    for (int i = 0; i < size+1; i++)
    {
        for (int j = 0; j < sumfind+1; j++)
        {
            if(j == 0) dp[i][j] = 1;
            else if(i == 0) dp[i][j]  = 0;
            else if(A[i-1] > j) dp[i][j] = dp[i-1][j];
            else if(A[i-1] <= j) dp[i][j] = dp[i-1][j - A[i-1]] + dp[i-1][j];
        }
    }
    return dp[size][sumfind];
}
int main()
{
    vector<int> A = {1,1,2,3};
    int difference = 1;
    cout<<differencesubset(A, difference);
}