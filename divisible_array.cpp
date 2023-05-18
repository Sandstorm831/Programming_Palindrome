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
        if(n==1)
        {
            cout<<1<<endl;
            continue;
        }
        if(n==2)
        {
            cout<<2<<" "<<4<<endl;
            continue;
        }
        if(n==3)
        {
            cout<<1<<" "<<2<<" "<<3<<endl;
            continue;
        }
        vector<int> v(n, 0);
        int es=0, os=0;
        for(int i=2; i<n; i++)
        {
            v[i] = i+1;
            if(i%2 == 0) os += i+1;
            else es+=i+1;
        }
        // cout<<es<<" "<<os<<endl;
        int qe = ceil(double(es)/double(n));
        int qo = ceil(double(os)/double(n));
        int k=0;
        while(true)
        {
            int x = (qe+k)*n-es;
            if(x!=0 && x%2 == 0)
            {
                v[1] = x;
                break;
            } 
            k++;
        }
        v[0] = qo*n - os;
        for(int i=0; i<n; i++) cout<<v[i]<<" ";
        cout<<endl;
    }
}