#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> a  = {1,2,3,4,5,6, 7,7,7,7,7,7,7,7};
    set<int> c;
    int f = a.size();
    for (int i = 0; i < f; i++)
    {
        c.insert(a[i]);
    }
    int n = c.size();
    int count[n][2];
    sort(a.begin(),a.end());
    int j=1;
    for (int i = 0; i < f; i++)
    {
        if (i==0)
        {
            count[i][0] = a[i];
            count[i][1] = 1;

        }
        else
        {
            if (a[i]==count[j-1][0])
            {
                count[j-1][1] += 1;
            }
            else
            {
                count[j][0] = a[i];
                count[j][1] = 1;
                j+=1;
            } 
        }  
    }
    
    for (int i = 0; i < n; i++)
    {
        for (int l = 0; l < 2; l++)
        {
            cout<<count[i][l]<<" ";
        }
        cout<<endl;
        
    }
    int longest, d;
    for (int i = 0; i < n; i++)
    {
        if (i==0)
        {
            longest = count[i][1];
            d=i;
        }
        else
        {
            if (longest>=count[i][1])
            {
                longest = longest;
            }
            else
            {
                longest = count[i][1];
                d=i;
            }
            
        }
    }
    cout<<count[d][0];
     
}