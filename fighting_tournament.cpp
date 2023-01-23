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
        vector<int> v;
        vector<int> maxray;
        int maxx=INT_MIN;
        for(int j=0;j<n;j++)
        {
            int x;
            cin>>x;
            v.push_back(x);
            maxx = max(maxx, x);
            if(j>0) maxray.push_back(maxx);
        }
        // for(int j=0;j<maxray.size(); j++)
        // {
        //     cout<<maxray[j]<<endl;
        // }
        vector<vector<int>> score(n+1, vector<int> ());
        for(int j=0; j<n-1; j++)
        {
            // score[j+1][maxray[j]] = score[j][maxray[j]]+1;
            score[maxray[j]].push_back(j+1);
        }
        // }
        // for(int j=0; j<score.size(); j++)
        // {
        //     for(int k=0; k<score[0].size(); k++)
        //     {
        //         cout<<score[j][k]<<" ";
        //     }
        //     cout<<endl;
        // }
        for(int j=0;j<q;j++)
        {
            int x,y;
            cin>>x>>y;
            if(y<n) cout<<upper_bound(score[v[x-1]].begin(), score[v[x-1]].end(), y)-score[v[x-1]].begin()<<endl;
            else 
            {
                // cout<<x<<" "<<n<<" "<<v[x-1]<<endl;
                if(v[x-1] == maxx) cout<<score[v[x-1]].size()+y-n+1<<endl;
                else cout<<score[v[x-1]].size()<<endl;
            }
        }

    }
}