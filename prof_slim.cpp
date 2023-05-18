#include <bits/stdc++.h>
using namespace std;
int main()
{
    int cases;
    cin>>cases;
    for(int i=0; i<cases; i++)
    {
        int n;
        cin>>n;
        vector<int> v;
        int ng=0;
        for(int j=0; j<n; j++)
        {
            int x;
            cin>>x;
            if(x<0)
            {
                ng++;
                x *= -1;
            }
            v.push_back(x);
        }
        int prev =  INT_MAX;
        if(ng==0) prev = 0;
        bool ans=true;
        for(int j=0;j<n; j++)
        {
            if(ng>0)
            {
                if(v[j]>prev)
                {
                    cout<<"No"<<endl;
                    ans=false;
                    break;
                }
                ng--;
                prev = v[j];
                if(ng==0) prev=0;
            }
            else
            {
                if(v[j]<prev)
                {
                    cout<<"No"<<endl;
                    ans=false;
                    break;
                }
                prev = v[j];
            }
        }
        if(ans) cout<<"Yes"<<endl;
    }
}