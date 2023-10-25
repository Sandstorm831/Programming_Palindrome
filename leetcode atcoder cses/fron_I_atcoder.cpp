#include <bits/stdc++.h>
using namespace std;
vector<long long> dp;
long long recursor(vector<long long>& v, long long N, long long index)
{
    long long xx = v.size();
    if(index >= xx) return INT_MAX;
    else if(index == xx-1) return 0;
    else if(dp[index] != -1) return dp[index];
    else
    {
        return dp[index] = min(abs(v[index+1]-v[index])+recursor(v, N, index+1), abs(v[index+2]-v[index])+recursor(v, N, index+2));
    }
    
}
int main()
{
    long long N;cin>>N;
    vector<long long> v(N);
    for(long long i=0; i<N; i++) cin>>v[i];
    dp.clear();dp.resize(N+1, -1);
    cout<<recursor(v, N, 0)<<endl;
}