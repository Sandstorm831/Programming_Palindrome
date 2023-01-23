#include <bits/stdc++.h>
using namespace std;
int main()
{
    int cases;
    cin>>cases;
    for(int i=0; i<cases; i++)
    {
        int n, k;
        cin>>n>>k;
        vector<int> vc;
        long long summ=0;
        for(int j=0; j<n; j++)
        {
            int a;
            cin>>a;
            vc.push_back(a);
            // if(j<k) summ+=a;
        }
        for(int j=0; j<k; j++)
        {
            int t=j;
            int maxx = INT_MIN;
            while(t<n)
            {
                maxx = max(maxx, vc[t]);
                t+=k;
            }
            summ += maxx;
        }
        cout<<summ<<endl;
    }
}