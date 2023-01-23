#include <bits/stdc++.h>
using namespace std;
int main()
{
    int cases;
    cin>>cases;
    for(int i=0; i<cases; i++)
    {
        int tp, nfp;
        cin>>tp>>nfp;
        vector<pair<int,int>> nfholder;
        for(int j=0;j<nfp; j++)
        {
            int a, b;
            cin>>a>>b;
            nfholder.push_back(make_pair(min(a,b)-1, max(a,b)-1));
        }
        vector<int> dp(tp, -1);
        for(int j=0; j<nfholder.size(); j++)
        {
            if(dp[nfholder[j].first] == -1) dp[nfholder[j].first] = nfholder[j].second;
            else if(dp[nfholder[j].first] > nfholder[j].second) dp[nfholder[j].first] = nfholder[j].second;
        }
        int pred = tp;
        for(int j=tp-1; j>=0; j--)
        {
            if(dp[j] == -1) dp[j] = pred; 
            else pred = dp[j];
        }
        for(int j=tp-2; j>=0; j--)
        {
            dp[j] = min(dp[j], dp[j+1]);
        }
        long long counter=0;
        for(int j=0; j<tp; j++)
        {
            counter += dp[j]-j;
        }
        cout<<counter<<endl;
    }
}
//
