#include <bits/stdc++.h>
using namespace std;
int sumer(int a)
{
    int count=0;
    while(a>0)
    {
        count += a%10;
        a = a/10;
    }
    return count;
}
int main()
{
    int cases;
    cin>>cases;
    for(int p=0; p<cases; p++)
    {
        int n, k;cin>>n>>k;
        vector<int> v;
        set<int> s;
        // set<int>ss;
        for(int i=0; i<n; i++) 
        {
            int x; cin>>x;
            v.push_back(x);
            if(x>9) s.insert(i);
        }
        for(int j=0; j<k; j++)
        {
            int nm; cin>>nm;
            if(nm==1)
            {
                int a,b;cin>>a>>b;
                a--; b--;
                int lst = a;
                while(!s.empty())
                {
                    auto itr = s.lower_bound(lst);
                    if(itr == s.end() || *itr > b) break;
                    v[*itr] = sumer(v[*itr]);
                    int temp = *itr;
                    if(v[*itr]<=9) itr = s.erase(itr);
                    lst = temp+1;
                }
            }
            else
            {
                int a; cin>>a;
                a--;
                cout<<v[a]<<endl;
            }

        }

    }
}