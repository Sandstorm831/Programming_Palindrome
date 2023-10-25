#include <bits/stdc++.h>
using namespace std;
vector<int> dp;
int recursor(int n, vector<int>& v, int k, int index)
{
    if(index >= n) return INT_MAX;
    else if(index == n-1) return 0;
    else if(dp[index] != -1) return dp[index];
    else
    {
        int count=INT_MAX;
        for(int j=1; j<=k; j++)
        {
            if(index+j < v.size())
            {
                count = min(count, abs(v[index+j] - v[index]) + recursor(n, v, k, index+j));
            }
        }
        return dp[index] = count;
    }
}
int main()
{
    int n, k;cin>>n>>k;
    vector<int> v(n);
    for(int i=0; i<n; i++)cin>>v[i];
    dp.clear(); dp.resize(n+1, -1);
    cout<<recursor(n, v, k, 0)<<endl;
}