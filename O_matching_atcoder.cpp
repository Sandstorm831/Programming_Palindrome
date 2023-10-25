#include <bits/stdc++.h>
using namespace std;
vector<vector<long long>> dp;
const int mod = 1e9+7;
long long recursor(vector<vector<long long>>& v, long long n, long long index, long long& bit)
{
    if(index >= n) return 1;
    else if(dp[index][bit] != -1) return dp[index][bit]; 
    else
    {
        long long counter=0;
        for(long long i=0; i<n; i++)
        {
            if(v[index][i] == 1 && !(bit&(1<<i)))
            {
                bit |= (1<<i);
                counter = (counter%mod + recursor(v, n, index+1, bit)%mod)%mod;
                bit &= ~(1 << (i));
            }
        }
        return dp[index][bit] = counter%mod;
    }
}
int main()
{
    long long n;cin>>n;
    vector<vector<long long>> v(n, vector<long long> (n));
    for(long long i=0; i<n; i++) for(long long j=0; j<n; j++) cin>>v[i][j];
    long long bit = 0;
    long long k = (1<<(n))+1;
    dp.resize(n+1, vector<long long> (k, -1));
    cout<<recursor(v, n, 0, bit);
}