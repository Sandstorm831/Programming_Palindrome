#include<bits/stdc++.h>
using namespace std;
int main()
{
    string a,z;
    cin>>a;
    int length = a.length();
    if (length <= 6)
    {
        cout<<"NO";
    }
    else
    {
        for (int i = 0; i < length - 6; i++)
        {
            if (a.substr(i,7) == "0000000" || a.substr(i,7) == "1111111")
            {
                z = "YES";
                break;
            }
            else
            {
                z = "NO";
            }
            
            
        }
        
    }
    cout<<z;
    
    

}