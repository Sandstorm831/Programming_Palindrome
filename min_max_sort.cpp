#include <bits/stdc++.h>
using namespace std;
int main()
{
    int cases;
    cin>>cases;
    for(int k=0; k<cases; k++)
    {
        int n;cin>>n;
        vector<int> v;
        for(int h=0; h<n; h++)
        {
            int x;cin>>x;
            v.push_back(x);
        }
        int i=0, j=0;
        int fid, ged;
        if(n%2==1) fid=n/2+1;
        else fid=n/2;
        for(i=0; i<n; i++)
        {
            if(v[i]==fid) break;
        }
        int ans = n/2;
        if(n%2==0)
        {
            ged = 1+fid;
            for(j=i; j<n; j++)
            {
                if(v[j]==ged) break;
            }
            if(j==n) 
            {
                cout<<n/2<<endl;
                continue;
            }
        }
        if(n%2==1)
        {
            j = i;
            ged = fid+1;
            fid--;
        }

        while(i>=0 && j<n)
        {
            if(v[i]==fid && v[j]==ged)
            {
                ans--;
                i--;
                j++;
                fid--;
                ged++;
            }
            else if(v[i] == fid) j++;
            else if(v[j] == ged) i--;
            else i--, j++;
        }
        cout<<ans<<endl;
    }
}