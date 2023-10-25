#include <bits/stdc++.h>
using namespace std;
int main()
{
    int cases;cin>>cases;
    while(cases--)
    {
        int n;cin>>n;
        int summ=0;
        for(int i=0;i<n; i++) 
        {
            int x;cin>>x;
            summ+=x;
        }
        if(summ%2 == 0) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
}