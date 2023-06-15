#include <bits/stdc++.h>
using namespace std;
int main()
{
    int cases;
    cin>>cases;
    for(int i=0; i<cases; i++)
    {
        int n,k;
        cin>>n>>k;
        string a, b;
        cin>>a>>b;
        if(a==b) 
        {
            cout<<"Yes"<<endl;
            continue;
        }
        // int xx = a.size();
        int ini = max(0,n-1-k+1);
        int fin = min(n-1,k-1);
        bool ans=true;
        if(ini<=fin)
        {
            for(int j=ini; j<=fin; j++)
            {
                if(a[j] != b[j])
                {
                    ans=false;
                    break;
                }
            }
        }
        if(!ans)
        {
            cout<<"No"<<endl;
            continue;
        }
        vector<int> aa(26,0);
        vector<int> bb(26,0);
        for(int j=0; j<a.size(); j++)
        {
            aa[a[j]-'a']++;
        }
        for(int j=0; j<b.size(); j++)
        {
            bb[b[j]-'a']++;
        }
        if(aa != bb)
        {
            cout<<"No"<<endl;
            continue;
        }
        cout<<"Yes"<<endl;
        continue;
    }
}