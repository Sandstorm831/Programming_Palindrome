// The recursive approach will not work due to memory limit, memory limit will exceed, and Runtime Error will be given.
// vector<vector<long long>> dp;
// long long recursor(vector<long long>& h, vector<long long>& b, long long index, long long prev)
// {
//     long long hh = 1ll*(h.size());
//     if(index >= hh) return 0;
//     else if(h[index] > h[prev] && dp[index][1] != -1) return dp[index][1];
//     else if(h[index] < h[prev] && dp[index][0] != -1) return dp[index][0];
//     else
//     {
//         long long counter=0;
//         if(h[index] > h[prev]) counter = max(b[index]+recursor(h, b, index+1, index), recursor(h, b, index+1, prev));
//         else counter = recursor(h, b, index+1, prev);
//         if(h[index]  > h[prev]) return dp[index][1] = counter;
//         if(h[index]  < h[prev]) return dp[index][0] = counter;
//         return counter;
//     }
// }
// long long main()
// {
//     long long n;cin>>n;
//     vector<long long> h(n+1, 0), b(n+1, 0);
//     for(long long i=1;i<=n; i++) cin>>h[i];
//     for(long long i=1;i<=n; i++) cin>>b[i];
//     dp.clear(); dp.resize(n+5, vector<long long> (2, -1));
//     cout<<recursor(h, b, 1, 0);
// }

#include <bits/stdc++.h>
using namespace std;
vector<long long> tree;
vector<long long> dp;
void build(long long node, long long st, long long en)
{
    if(st == en)
    {
        tree[node] = dp[st];
        return;
    }
    long long mid = (st + en)/2;
    build(2*node, st, mid);
    build(2*node+1, mid+1, en);
    tree[node] = max(tree[2*node],tree[2*node+1]);
}
long long query(long long node, long long st, long long en, long long l, long long r)
{
    if(st > r || en < l) return INT_MIN;
    else if(st >=l && en <=r) return tree[node];
    long long mid = (st + en)/2;
    long long a = query(2*node, st, mid, l, r);
    long long b = query(2*node+1, mid+1, en, l ,r);
    return max(a, b);
}
void update(long long node, long long st, long long en, long long idx, long long val)
{
    if(st==en) {tree[node] = val;dp[st]=val;return;}
    long long mid = (st+en)/2;
    if(idx <= mid) update(2*node, st, mid, idx, val);
    else if(idx > mid) update(2*node+1, mid+1, en, idx, val);
    tree[node] = max(tree[2*node], tree[2*node+1]);
}
int main()
{
    long long n;cin>>n;
    vector<long long> h(n), b(n);
    for(long long i=0;i<n; i++) cin>>h[i];
    for(long long i=0;i<n; i++) cin>>b[i];
    dp.clear(); dp.resize(n+1, 0);
    tree.clear(); tree.resize(4*n+5, 0);
    /* The following for loop points out the basic working of the algorithm in O(N^2), but as it will get TLE, an efficient
    approch is highlighted in original code

    for(long long i=0; i<n; i++)
    {
        for(long long j=0; j<h[i]; j++)
        {
            dp[h[i]] = max(dp[h[i]], b[i]+dp[j]);
        }
    }
    
    */
    for(long long i=0; i<n;i++)
    {
        long long a =  query(1, 0, n, 0, h[i]-1);
        update(1, 0, n, h[i], b[i]+a);
    }
    cout<<query(1, 0, n-1, 0, n);
}   