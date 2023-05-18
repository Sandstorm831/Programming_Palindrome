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
        if(n%2==1)cout<<-1<<endl;
        else
        {
            n=n/2;
            cout<<3<<" "<<(3^n)<<" "<<3<<endl;
        }
    }
}