#include <bits/stdc++.h>
using namespace std;
int main()
{
    int cases;
    cin>>cases;
    for(int i=0; i<cases; i++)
    {
        int n, m,k;
        cin>>n>>m>>k;
        string a,b;
        cin>>a>>b;
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        int t=0;
        int l=-1;
        string c="";
        int ni=0;
        int mi=0;
        // cout<<a<<endl;
        // cout<<b<<endl;
        while(n>0 && m>0)
        {
            if(t==k)
            {
                if(l==0)
                {
                    c+=b[mi];
                    mi++;
                    t=1;
                    l=1;
                    m--;
                    // continue;
                }
                else if(l==1)
                {
                    c+=a[ni];
                    ni++;
                    t=1;
                    l=0;
                    n--;
                    // continue;
                }
                continue;
            }
            if(a[ni]<b[mi])
            {
                if(l==0) t++;
                else 
                {
                    t=1;
                    l=0;
                }
                c+=a[ni];
                ni++;
                n--;
            }
            else
            {
                if(l==1) t++;
                else
                {
                    t=1;
                    l=1;
                }
                c+=b[mi];
                mi++;
                m--;
            }
        }
        cout<<c<<endl;
    }
}