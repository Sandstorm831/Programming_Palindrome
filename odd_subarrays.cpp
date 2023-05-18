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
        vector<int> v;
        for(int j=0; j<n; j++)
        {
            int x;
            cin>>x;
            v.push_back(x);
        }
        int counter=0;
        for(int j=0; j<n-1; j++)
        {
            if(v[j]>v[j+1]) 
            {
                counter++;
                j++;
            }
        }   
        cout<<counter<<endl;
    }
}