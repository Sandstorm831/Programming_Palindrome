#include <bits/stdc++.h>
using namespace std;
int hcf(int a, int b)
{
    if (a == 0) return b;
    if (b == 0) return a;
    if (a == b) return a;
    if (a > b) return gcd(a - b, b);
    return gcd(a, b - a);
}
int main()
{
    int cases;
    cin>>cases;
    for(int i=0; i<cases; i++)
    {
        int n;
        cin>>n;
        vector<int> count;
        vector<int> v;
        for(int j=0; j<n; j++)
        {
            int x;
            cin>>x;
            // count.push_back(j+1);
            v.push_back(x);
        }
        for(int j=0; j<n;j++)
        {
            int x = abs(v[j]-1-j);
            if(x!=0) count.push_back(x);
        }
        if(count.size()==1) 
        {
            cout<<count[0]<<endl;
            continue;
        }
        int prev = hcf(count[0], count[1]);
        for(int j=0; j<count.size()-2; j++)
        {
            prev = hcf(prev, count[j+1]);
        }
        cout<<prev<<endl;
    }
}