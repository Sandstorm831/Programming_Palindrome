// //****************************Template Begins****************************//
 
// // Header Files
// #include<iostream>
// #include<iomanip>
// #include<algorithm>
// #include<vector>
// #include<utility>
// #include<set>
// #include<unordered_set>
// #include<list>
// #include<iterator>
// #include<deque>
// #include<queue>
// #include<stack>
// #include<set>
// #include<bitset>
// #include<random>
// #include<map>
// #include<unordered_map>
// #include<stdio.h>
// #include<complex>
// #include<math.h>
// #include<cstring>
// #include<chrono>
// #include<string>
// #include "ext/pb_ds/assoc_container.hpp"
// #include "ext/pb_ds/tree_policy.hpp"
// // Header Files End
 
// using namespace std;
// using namespace __gnu_pbds;
// template<class T>
// using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update> ;
 
// template<class key, class value, class cmp = std::less<key>>
// using ordered_map = tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;
// // find_by_order(k)  returns iterator to kth element starting from 0;
// // order_of_key(k) returns count of elements strictly smaller than k;
 
// #define DIVYA ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
// #define ll long long
// #define umap unordered_map
// #define uset unordered_set
// #define lb lower_bound
// #define ub upper_bound
// #define fo(i,a,b) for(i=a;i<=b;i++)
// #define all(v) (v).begin(),(v).end()
// #define all1(v) (v).begin()+1,(v).end()
// #define allr(v) (v).rbegin(),(v).rend()
// #define allr1(v) (v).rbegin()+1,(v).rend()
// #define sort0(v) sort(all(v))
// typedef pair<int, int> pii;
// typedef vector<int> vi;
// typedef vector<ll> vll;
// typedef pair<ll, ll> pll;
// #define sz(x) (ll)x.size()
// #define pb push_back
// #define ppb pop_back
// #define mkp make_pair
// #define inf 1000000000000000005
// const ll mod = 1e9 + 7;
 
// ll inv(ll i) {if (i == 1) return 1; return (mod - ((mod / i) * inv(mod % i)) % mod) % mod;}
 
// ll mod_mul(ll a, ll b) {a = a % mod; b = b % mod; return (((a * b) % mod) + mod) % mod;}
 
// ll mod_add(ll a, ll b) {a = a % mod; b = b % mod; return (((a + b) % mod) + mod) % mod;}
 
// ll gcd(ll a, ll b) { if (b == 0) return a; return gcd(b, a % b);}
 
// ll ceil_div(ll a, ll b) {return a % b == 0 ? a / b : a / b + 1;}
 
// ll pwr(ll a, ll b) {a %= mod; ll res = 1; while (b > 0) {if (b & 1) res = res * a % mod; a = a * a % mod; b >>= 1;} return res;}
// //****************************Template Ends*******************************//
////////////
#include <bits/stdc++.h>
using namespace std;
vector<vector<long long>> adj;
vector<vector<pair<long long, long long>>> dp;
vector<bool> verd;
void dfs(long long curr, long long elder)
{
    for(long long j=0; j<adj[curr].size(); j++)
    {
        if(adj[curr][j] == elder) continue;
        dfs(adj[curr][j], curr);
    }
    pair<long long, long long> take = {1, -adj[curr].size()};
    pair<long long , long long> drop = {0, -1};
    for(long long j=0; j<adj[curr].size(); j++)
    {
        if(adj[curr][j] == elder) continue;
        take.first += dp[adj[curr][j]][0].first;
        take.second += dp[adj[curr][j]][0].second;
        if(dp[adj[curr][j]][0] >= dp[adj[curr][j]][1])
        {
            drop.first += dp[adj[curr][j]][0].first;
            drop.second += dp[adj[curr][j]][0].second;
        }
        else
        {
            drop.first += dp[adj[curr][j]][1].first;
            drop.second += dp[adj[curr][j]][1].second;
        }
    }
    dp[curr][0] = drop;
    dp[curr][1] = take;
}
void builder(long long curr, long long elder, bool took)
{
    bool cury = true;
    if(took || dp[curr][0]>dp[curr][1])
    {
        verd[curr]= false;
        cury=false;
    }
    else
    {
        verd[curr]=true;
    }
    for(long long j=0; j<adj[curr].size(); j++)
    {
        if(adj[curr][j]==elder) continue;
        builder(adj[curr][j], curr, cury);
    }
}
int main()
{
    long long n;
    cin>>n;
    adj.resize(n+1, vector<long long> ());
    for(long long j=1;j<n; j++)
    {
        long long x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    if(n==2)
    {
        cout<<"2 2"<<endl;
        cout<<"1 1"<<endl;
        return 0;
    }
    verd.resize(n+1, false);
    dp.resize(n+1, vector<pair<long long, long long>> (2,{0,0}));
    dfs(1,-1);
    builder(1,-1, false);
    vector<long long> final(n+1, 0);
    long long sum=0;
    long long ans=0;
    for(long long j=1; j<=n; j++)
    {
        if(verd[j])
        {
            ans++;
            sum+=adj[j].size();
            final[j] = adj[j].size();
        }
        else
        {
            sum++;
            final[j]=1;
        }
    }
    cout<<ans<<" "<<sum<<endl;
    for(long long j=1;j<=n; j++)cout<<final[j]<<" ";
    cout<<endl;
}