#include <bits/stdc++.h>
using namespace std;
int main()
{
    int cases;
    cin>>cases;
    for(int i=0; i<cases; i++)
    {
        int n,x;
        cin>>n>>x;
        if(n%x!=0) 
        {
            cout<<-1<<endl;
            continue;
        }
        vector<int> cap(n);
        cap[0]=x;
        cap[n-1]=1;
        for(int j=1; j<n-1; j++)
        {
            if(j+1 == x) cap[j] = n;
            else cap[j]=j+1;
        }
        int t = 2;
        while(t<n/x)
        {
            int a = t*x;
            if(n%a == 0)
            {
                cap[a-1] = n;
                cap[x-1] = a;
                t=1;
                x = a;
            }
            t++;
        }
        for(int j=0;j<n; j++)
        {
            cout<<cap[j]<<" ";
        }
        cout<<endl;
    }
}