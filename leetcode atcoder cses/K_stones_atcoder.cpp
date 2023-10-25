#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> dp;
int recursor(vector<int>& v, int index,int stones)
{
    if(v[0]>stones) return (index+1)%2;
    else if(dp[index][stones] != -1) return dp[index][stones];
    else
    {
        int ans=0;
        for(int i=0; i<v.size(); i++)
        {
            if(v[i]>stones) break;
            ans = recursor(v, (index+1)%2, stones-v[i]);
            if(ans == index) break;
        }
        return dp[index][stones] = ans;
    }
}
int main()
{
    int n, k; cin>>n>>k;
    vector<int> v(n);
    for(int i=0; i<n; i++)cin>>v[i];
    sort(v.begin(), v.end());
    dp.clear(); dp.resize(n+1, vector<int> (k+1,-1));
    cout<<(recursor(v, 0, k) == 0?"First":"Second");
}