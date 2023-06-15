#include <bits/stdc++.h>
using namespace std;
int main()
{
    int cases;cin>>cases;
    while(cases--)
    {
        int n;cin>>n;
        int one, two, maxx;
        for(int i=0; i<n; i++)
        {
            int x;cin>>x;
            if(x==1) one = i;
            if(x==2) two = i;
            if(x==n) maxx = i;
        }
        if(maxx > one && two > maxx) cout<<1<<" "<<1<<endl;
        else if(maxx<one && two < maxx) cout<<1<<" "<<1<<endl;
        else if(two > one && maxx > two) cout<<two+1<<" "<<maxx+1<<endl;
        else if(two < one && maxx < two) cout<<two+1<<" "<<maxx+1<<endl;
        else if(one > two && maxx > one) cout<<one+1<<" "<<maxx+1<<endl;
        else if(one < two && maxx < one) cout<<one+1<<" "<<maxx+1<<endl;

    }
}