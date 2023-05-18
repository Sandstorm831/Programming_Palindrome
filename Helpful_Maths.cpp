#include <bits/stdc++.h>
using namespace std;

int main(){
    string s; int i=0;
    cin>>s;
    int n = s.length();
    if (n%2==0)
    {
        int a[n/2];

        for (int m=0; m < n/2; m++)
            {
                a[m] = int(s[2*m])-48 ;
            }
        /*for (int l = 0; l < n/2; l++)
            {
                cout<<a[l]<<"a["<<l<<"]i"<<endl;
            }
        */
        sort(a,a+n/2+1);

        /*for (int k = 0; k < n/2; k++)
            {
                cout<<a[k]<<"a["<<k<<"]f"<<endl;
            }
        */
        for (int t = 0; t < n/2; t++)
        {
            if (t==n/2-1)
            {
                cout<<a[t];
                break;
            }
            
            cout<<a[t]<<"+";
        }
        
    }
    else
    {
        int a[n/2+1];

        for (int m=0; m < n/2+1; m++)
            {
                a[m] = int(s[2*m])-48 ;
            }
        /*for (int l = 0; l < n/2+1; l++)
            {
                cout<<a[l]<<"a["<<l<<"]i"<<endl;
            }
        */
        sort(a,a+n/2+1);

        /*for (int k = 0; k < n/2+1; k++)
            {
                cout<<a[k]<<"a["<<k<<"i]f"<<endl;
            }
        */
       for (int i = 0; i < n/2+1; i++)
       {
           if (i==n/2)
           {
               cout<<a[i];
               break;
           }
           
           cout<<a[i]<<"+";
       }
       
    }

}
