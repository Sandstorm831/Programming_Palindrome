#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> dp;
int csum(vector<int> holder, int a, int b)
{
    int summer=0;
    for(int i=a; i<=b; i++)
    {
        summer+=holder[i];
    }
    return summer%100;
}
int recursor(vector<int>& holder, int starter, int ender)
{
    if(starter== ender) return 0;
    if(dp[starter][ender]!=INT_MAX) return dp[starter][ender];
    int minn = INT_MAX;
    for(int itr = starter; itr<ender; itr++)
    {
        minn = min(minn,recursor(holder, starter, itr)+recursor(holder, itr+1, ender)+csum(holder, starter,itr)*csum(holder, itr+1, ender));
    }
    return dp[starter][ender]=minn;
}
int minSmoke(vector<int> &A) {
    int n = A.size();
    dp.clear();
    dp.resize(n, vector<int> (n,INT_MAX));
    return recursor(A, 0, n-1);
}