#include <bits/stdc++.h>
using namespace std;
int main()
{
    int cases;
    cin>>cases;
    while(cases--)
    {
        int n,k; cin>>n>>k;
        if(n%k<=1) cout<<min(n,(n/k)+1)<<endl;
        else cout<<min(n,(n/k)+2)<<endl;
    }
}