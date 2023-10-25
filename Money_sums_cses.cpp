#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long n;cin>>n;
    vector<long long> v(n);for(long long i=0; i<n; i++) cin>>v[i];
    vector<bool> cnt(1001, false);
    long long summer=0;
    set<long long> st;
    st.insert(0);
    for(long long i=0; i<n; i++)
    {
        set<long long> curr;
        if(!cnt[v[i]])
        {
            cnt[v[i]]=true;
            for(auto itr = st.begin(); itr!=st.end(); itr++)
            {
                curr.insert(*itr + v[i]);
            }
        }
        else
        {
            for(auto itr = st.begin(); itr!=st.end(); itr++)
            {
                curr.insert(*itr + v[i]);
            } 
        }
        for(auto itr = curr.begin(); itr!=curr.end(); itr++) st.insert(*itr);
    }
    cout<<st.size()-1<<endl;
    for(auto itr = st.begin(); itr!=st.end(); itr++)
    {
        if(*itr == 0) continue;
        else cout<<*itr<<" ";
    }
}