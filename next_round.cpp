#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> s;
    int n, k, l=0;
    cin>>n>>k;
    cout<<endl;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin>>a;
        s.push_back(a);
    }

    int p = s[k-1] ;
    
    for (int i = 0; i < n; i++)
    {
        int u = int(s[i]) ;


        if ( u == 0)
        {
            l += 0;
        }
        

       else if ( u >=p)
       {
            l+= 1;
       }
        else
        {
            l += 0;
        }  
    }
    cout<<endl<<l;     
    
    
}