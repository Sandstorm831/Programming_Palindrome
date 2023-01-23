#include <bits/stdc++.h>
using namespace std;
int main()
{
    int cases;
    cin>>cases;
    for(int i=0; i<cases;i++)
    {
        int n;
        cin>>n;
        int diff = n/2;
        for(int j=1; j<=diff; j++)
        {
            cout<<j+diff<<" "<<j<<" ";
            if(j==diff && n%2==1) cout<<n<<endl;
            else if(j == diff) cout<<endl;
        }
    }
}