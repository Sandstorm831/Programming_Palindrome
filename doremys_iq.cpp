#include <bits/stdc++.h>
using namespace std;
int main()
{
    int cases;
    cin>>cases;
    for(int i=0;i<cases;i++)
    {
        int n,q;
        cin>>n>>q;
        vector<int> con;
        for(int j=0; j<n; j++)
        {
            int a;
            cin>>a;
            con.push_back(a);
        }
        vector<int> ans;
        int iq=0;
        for(int j=n-1; j>=0; j--)
        {
            if(con[j]<=iq) ans.push_back(1);
            else if(iq<q) 
            {
                ans.push_back(1);
                iq++;
            }
            else ans.push_back(0);
        }
        reverse(ans.begin(), ans.end());
        for(int i=0; i<n; i++)
        {
            cout<<ans[i];
        }
        cout<<endl;
    }
}