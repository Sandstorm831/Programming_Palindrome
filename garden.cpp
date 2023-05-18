#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k,ans = 0;
    cin>>n>>k;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin>>a;
        if (k%a == 0)
        {
            if (a > ans)
            {
                ans = a;
            }
            
        }
        
    }
    cout<<k/ans;
    
}