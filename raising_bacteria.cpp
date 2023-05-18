#include<bits/stdc++.h>
using namespace std;
int main()
{
    long int n;
    int bacteria = 1;
    cin>>n;
    while(n != 1)
    {
        if (n%2 == 0)
        {
            n /= 2;
        }
        else
        {
            bacteria += 1;
            n = (n-1)/2;
        }
    }
        
    cout<<bacteria;
}