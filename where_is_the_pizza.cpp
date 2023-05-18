#include <bits/stdc++.h>
using namespace std;
const long long mod=1e9+7;
void traverser(vector<int>& c, vector<int>& a, vector<int>& b, vector<pair<int,int>>& graph, vector<int>& looper, int index)
{
    looper[a[index]]=1;
    looper[b[index]]=1;
    c[index] = a[index];
    int prev = b[index];
    int i = graph[prev].first;
    while(i!=index)
    {
        c[i] = a[i];
        prev = b[i];
        looper[prev]=1;
        i = graph[prev].first;
    }    
}
int main()
{
    int cases;
    cin>>cases;
    for(int i=0; i<cases; i++)
    {
        int n;
        cin>>n;
        vector<int> a;
        vector<int> b;
        vector<int> c;
        vector<pair<int,int>> graph(n+1, make_pair(0,0));
        vector<int> looper(n+1,0);
        for(int j=0; j<n; j++)
        {
            int x;
            cin>>x;
            a.push_back(x);
            graph[x].first = j;
        }
        for(int j=0; j<n; j++)
        {
            int x;
            cin>>x;
            b.push_back(x);
            graph[x].second = j;
        }
        for(int j=0; j<n; j++)
        {
            int x;
            cin>>x;
            c.push_back(x);
        }
        for(int j=0; j<n; j++)
        {
            if(c[j]!=0 && looper[c[j]]!=1)
            {
                traverser(c, a, b, graph, looper, j);
            }
            else if(a[j] == b[j]) 
            {
                c[j] = a[j];
                looper[c[j]]=1;
            }
        }
        int counter=0;
        for(int j=0; j<n; j++)
        {
            if(c[j]==0)
            {
                counter++;
                traverser(c, a, b, graph, looper, j);
            }
        }
        long long ans=1;
        while(counter)
        {
            ans = ((ans%mod)*2)%mod;
            counter--;
        }
        cout<<ans<<endl;
    }
}