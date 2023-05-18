#include <bits/stdc++.h>
using namespace std;
int main()
{
    int cases;
    cin>>cases;
    for(int i=0;i<cases;i++)
    {
        int n;
        cin>>n;
        int k = n-1;
        vector<int> v(n);
        while(k>=0)
        {
            int d = ceil(double(sqrt(double(k))));
            int sq = d*d;
            int diff = sq-k;

            for(int j=diff; j<=k; j++)
            {
                v[j] = k; 
                v[k] = j;
                k--;
            }
            k = diff-1;
        }
        for(int j=0; j<n; j++)
        {
            cout<<v[j]<<" ";
        }
        cout<<endl;
    }
}