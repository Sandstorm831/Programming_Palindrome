#include <bits/stdc++.h>
using namespace std;
int main()
{
    int cases;
    cin>>cases;
    for(int i=0; i<cases; i++)
    {
        int n, k;
        cin>>n>>k;
        if(n%k == 0) cout<<2<<endl<<n-1<<" "<<1<<endl;
        else cout<<1<<endl<<n<<endl;
    }
}