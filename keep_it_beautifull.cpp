#include <bits/stdc++.h>
using namespace std;
int main()
{
    int cases;
    cin>>cases;
    while(cases--)
    {
        int q;cin>>q;
        vector<int> ans;
        int prev = -1, ul=-1;
        bool up=true, drp=false;
        while(q--)
        {
            int x;cin>>x;
            if(up)
            {
                ul = x;
                prev = x;
                up=false;
                ans.push_back(1);
                continue;
            }
            else if(x < prev && !drp)
            {
                if(x<=ul)
                {
                    drp=true;
                    prev=x;
                    ans.push_back(1);
                    continue;
                }
                else ans.push_back(0);
                continue;
            }
            else if(x>=prev && !drp)
            {
                ans.push_back(1);
                prev = x;
                continue;
            }
            else if(drp)
            {
                if(x>=prev && x<=ul)
                {
                    ans.push_back(1);
                    prev = x;
                }
                else ans.push_back(0);
            }
        }
        for(int i=0; i<ans.size(); i++)cout<<ans[i];
        cout<<endl;
    }
}