#include <bits/stdc++.h>
using namespace std;
int main()
{
    string l;
    cin>>l;
    int santa=0, banta=0;
    int n = l.length();
    
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n-i; i++)
        {
            string s = l.substr(j,j+i);
            cout<<s<<endl;
            santa+=1;
            
        }
        
    }
    if (santa>banta)
    {
        cout<<"Santa"<<santa;
    }
    else
    {
        cout<<"Banta"<<banta;
    }
    
    
    
}