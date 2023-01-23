#include <bits/stdc++.h>
using namespace std;
int main()
{
    int cases;
    cin>>cases;
    for(int i=0;i<cases;i++)
    {
        int n;
        cin>>n;
        vector<int> md, tgt;
        for(int j=0; j<n; j++)
        {
            int a;
            cin>>a;
            md.push_back(a);
            // summd+=a;
        }
        for(int j=0;j<n;j++)
        {
            int b;
            cin>>b;
            tgt.push_back(b);
            // tgtd +=b;
        }
        bool final = true;
        for(int j=0; j<n; j++)
        {
            if(j==n-1)
            {
                if(md[j]>tgt[j])
                {
                    final = false;
                    break;
                }
                else if(md[j] == tgt[j] || tgt[j]-tgt[0] <= 1) continue;
                else 
                {
                    final = false;
                    break;
                }
            }
            else
            {
                if(md[j]>tgt[j])
                {
                    final = false;
                    break;
                }
                else if(md[j]==tgt[j] || tgt[j]-tgt[j+1] <=1) continue;
                else 
                {
                    final = false;
                    break;
                }
            }
        }
        if(final) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
}