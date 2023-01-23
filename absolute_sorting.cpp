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
        vector<int> a(n);
        for(int k=0; k<n; k++)
        {
            cin>>a[k];
        }
        double minn = double(0), maxx = double(1e9);
        for(int j=0; j<n-1; j++)
        {
            double midl = double(a[j]+a[j+1])/2;
            if(a[j] < a[j+1]) maxx = min(maxx, midl);
            else if(a[j]>a[j+1]) minn = max(minn, midl);
        }
        if(ceil(minn)<=floor(maxx)) cout<<int(ceil(minn))<<endl;
        else cout<<-1<<endl;
    }
}