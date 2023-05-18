#include <bits/stdc++.h>
using namespace std;
const long long ninf=-1e15;
vector<long long> nge(vector<long long>& v, long long sgn)
{
    long long n = v.size();
    stack<pair<long long,long long>> s;
    s.push(make_pair(v[0], 0));
    vector<long long> ng(n);
    for(long long i=1; i<v.size(); i++)
    {
        if(s.top().first<v[i]) 
        {
            while(!s.empty() && s.top().first<v[i]) 
            {
                ng[s.top().second] = i;
                // cout<<v[i]<<" ";
                s.pop();
            }
            s.push(make_pair(v[i],i));
        }
        else s.push(make_pair(v[i],i));
    }
    while(!s.empty()) 
    {
        if(!sgn) ng[s.top().second]=-1;
        else ng[s.top().second]=n;
        s.pop();
    }
    return ng;
}
long long maxy(vector<long long> &tree, long long node, long long ns, long long ne, long long qs, long long qe)
{
    if (qe < ns || qs > ne) return ninf;
    if (qs <= ns && ne <= qe) return tree[node];
 
    long long mid = ns + (ne - ns) / 2;
    long long leftQuery = maxy(tree, 2 * node, ns, mid, qs, qe);
    long long rightQuery = maxy(tree, 2 * node + 1, mid + 1, ne, qs, qe);
    return max(leftQuery, rightQuery);
}
int main()
{
    long long cases;
    cin>>cases;
    for(long long i=0; i<cases; i++)
    {
        long long n;
        cin>>n;
        vector<long long> v;
        long long summer=0;
        for(long long j=0; j<n; j++)
        {
            long long x;
            cin>>x;
            summer+=x;
            v.push_back(x);
        }
        vector<long long> prev = nge(v,1);
        vector<long long> orig = v;
        reverse(v.begin(), v.end());
        vector<long long> ahd = nge(v,0);
        reverse(ahd.begin(), ahd.end());
        for(long long i=0;i<ahd.size();i++){
            if(ahd[i]!=-1) ahd[i] = ahd.size()-ahd[i]-1;
        }
        vector<long long> prf;
        vector<long long> suff;
        prf.push_back(orig[0]);
        suff.push_back(summer);
        for(long long j=1;j<orig.size(); j++)
        {
            prf.push_back(prf[j-1]+orig[j]);
            suff.push_back(suff[j-1]-orig[j-1]);
        }
        long long _n = n;
        while (__builtin_popcount(_n) != 1) _n++;
        // cout<<n<<" "<<_n<<endl;
        vector<long long> prefixTree(2 * _n, ninf), suffixTree(2 * _n, ninf);
        for(long long j=0; j<n; j++)
        {
            prefixTree[_n + j] = prf[j];
            suffixTree[_n + j] = suff[j];
        }
        for(long long j = _n-1; j>=1; j--)
        {
            prefixTree[j] = max(prefixTree[2 * j], prefixTree[2 * j + 1]);
            suffixTree[j] = max(suffixTree[2 * j], suffixTree[2 * j + 1]);
        }
        bool ans=true;
        for(long long j=0; j<n; j++)
        {
            long long rm = maxy(prefixTree, 1, 0, _n - 1, j + 1, prev[j]-1) - prf[j];
            long long lm = maxy(suffixTree, 1, 0, _n - 1, ahd[j]+1 , j - 1) - suff[j];
            // cout<<rm<<" "<<lm<<endl;
            if(max(rm,lm)>0) 
            {
                ans=false;
                break;
            }
        }
        if(ans) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
}