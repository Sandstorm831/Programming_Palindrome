#include <bits/stdc++.h>
using namespace std;
int main()
{
    int cases;cin>>cases;
    while(cases--)
    {
        int n;cin>>n;
        vector<int> a(n), b(n);
        int suma=0, sumb=0, maxx = INT_MIN;
        for(int i=0; i<n;i++) {cin>>a[i];suma+=a[i];}
        for(int j=0; j<n;j++) {cin>>b[j];sumb+=b[j];maxx=max(maxx, a[j]-b[j]);}
        vector<int> ans;
        for(int i=0; i<n; i++)
        {
            if(a[i] - b[i] == maxx) ans.push_back(i+1);
        }
        cout<<ans.size()<<endl;
        for(int i=0; i<ans.size(); i++) cout<<ans[i]<<" ";
        cout<<endl;
    }
}