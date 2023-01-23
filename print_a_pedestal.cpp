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
        int factor = n/3;
        if(n%3 == 0) cout<<factor<<" "<<factor+1<<" "<<factor-1<<endl;
        else if(n%3 == 1) cout<<factor<<" "<<factor+2<<" "<<factor-1<<endl;
        else if(n%3 == 2) cout<<factor+1<<" "<<factor+2<<" "<<factor-1<<endl;
    }
}