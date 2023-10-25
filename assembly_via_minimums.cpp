#include <bits/stdc++.h>
using namespace std;
int main()
{
    int cases;cin>>cases;
    while(cases--)
    {
        int nn;cin>>nn;
        int n = nn*(nn-1)/2;
        // cout<<n<<" "<<nn<<endl;
        vector<int> v(n);for(int i=0; i<n; i++) cin>>v[i];
        sort(v.begin(), v.end());
        vector<int> ans;
        if(nn == 2)
        {
            cout<<v[0]<<" "<<v[0]+1<<endl;
            continue;
        }
        int x = nn-1;
        int index = 0;
        while(x>0)
        {
            ans.push_back(v[index]);
            index+=x;
            x--;
        }
        while(ans.size() < nn) ans.push_back(ans.back());
        for(int i=0; i<ans.size();i++) cout<<ans[i]<<" ";
        cout<<endl;
    }
}