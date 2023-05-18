#include <bits/stdc++.h>
using namespace std;
long long opers;
vector<long long> v;
vector<vector<long long>> graph;
vector<pair<long long,long long>> range;
void grapher(long long n)
{
    for(long long j=0; j<n; j++)
    {
        graph[j+1].push_back(v[j]);
    }
    for(long long j=1; j<n; j++)
    {
        graph[v[j]].push_back(j+1);
    }
}
long long dfs(long long n)
{
    if(graph[n].size()==1)
    {
        opers++;
        return range[n-1].second;
    }
    long long rg=0;
    for(long long i=1; i<graph[n].size(); i++)
    {
        rg += dfs(graph[n][i]);
    }
    if(rg<range[n-1].first)
    {
        opers++;
        rg = range[n-1].second;
        return rg;
    }
    else 
    {
        if(rg<=range[n-1].second)
        {
            return rg;
        }
        else return range[n-1].second;
    }
}   
int main()
{
    long long cases;
    cin>>cases;
    for(long long i=0; i<cases; i++)
    {
        long long n;
        cin>>n;
        v.clear();
        v.push_back(-1);
        for(long long j=0; j<n-1; j++)
        {
            long long a;
            cin>>a;
            v.push_back(a);
        }
        range.clear();
        for(long long j=0; j<n; j++)
        {
            long long a,b;
            cin>>a>>b;
            range.push_back(make_pair(a,b));
        }
        graph.clear();
        graph.resize(n+1, vector<long long> ());
        grapher(n);
        opers = 0;
        long long x = dfs(1);
        cout<<opers<<endl;
    }
}