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
        int index=0;
        int index2=0;
        vector<int> v;
        vector<int> nv;
        for(int j=0; j<n; j++)
        {
            int x;
            cin>>x;
            if(x==n) index = j;
            if(x==n-1) index2 = j;
            v.push_back(x);
        }
        if(index != 0 && index != n-1)
        {
            int in = index-1;
            int fin=-1;
            for(int j=in-1; j>=0; j--)
            {
                if(v[j] < v[0]) 
                {
                    fin = min(j+1, in);
                    break;
                }
            }
            if(fin == -1) fin = 0;
            for(int j=index; j<n; j++)
            {
                nv.push_back(v[j]);
            }
            for(int j=in; j>=fin; j--)
            {
                nv.push_back(v[j]);
            }
            for(int j=0; j<fin; j++)
            {
                nv.push_back(v[j]);
            }
        }
        else if(index !=0 && index == n-1)
        {
            int in = index;
            int fin=-1;
            for(int j=in-1; j>=0; j--)
            {
                if(v[j] < v[0]) 
                {
                    fin = min(j+1, in);
                    break;
                }
            }
            if(fin == -1) fin = 0;
            for(int j=in; j>=fin; j--)
            {
                nv.push_back(v[j]);
            }
            for(int j=0; j<fin; j++)
            {
                nv.push_back(v[j]);
            }
        }
        else if(index==0 && index2 != n-1)
        {
            for(int j=index2; j<n; j++)
            {
                nv.push_back(v[j]);
            }
            for(int j=index2-1; j>=index2-1; j--)
            {
                nv.push_back(v[j]);
            }
            for(int j=0; j<index2-1; j++)
            {
                nv.push_back(v[j]);
            }
        }
        else if(index ==0 && index2 == n-1)
        {
            for(int j=index2; j<n; j++)
            {
                nv.push_back(v[j]);
            }
            for(int j=0; j<=index2-1; j++)
            {
                nv.push_back(v[j]);
            }
        }
        for(int j=0; j<nv.size(); j++) cout<<nv[j]<<" ";
        cout<<endl;
    }
}