#include <bits/stdc++.h>
using namespace std;
int main()
{
    int cases;
    cin>>cases;
    for(int i=0;i<cases; i++)
    {
        int n;
        cin>>n;
        vector<int>pos;
        unordered_set<int> sety;
        int zeros=0;
        int nonzero=0;
        for(int j=0; j<n; j++)
        {
            int a;
            cin>>a;
            if(a>0 || a<0) 
            {
                if(nonzero<=4)
                {
                    pos.push_back(a);
                    sety.insert(a);
                }
                nonzero++;
            }
            else{
                if(zeros<=2)
                {
                    pos.push_back(0);
                    sety.insert(0);
                }
                zeros++;
            }
        }
        if(nonzero>4)
        {
            cout<<"No"<<endl;
            continue;
        }
        if(zeros==n)
        {
            cout<<"Yes"<<endl;
            continue;
        }
        // int summ=0;
        bool f=true;
        for(int j=0; j<pos.size()-2; j++)
        {
            for(int k=j+1; k<pos.size()-1; k++)
            {
                for(int l=k+1; l<pos.size(); l++)
                {
                    if(!f) break;
                    else if(sety.find(pos[j]+pos[k]+pos[l]) == sety.end())
                    {
                        cout<<"No"<<endl;
                        f=false;
                        break;
                    }
                }
                if(!f) break;
            }
            if(!f) break;
        }
        if(f) cout<<"Yes"<<endl;
        // cout<<cases<<endl;
    }
}