#include <bits/stdc++.h>
using namespace std;
bool check(int x, int y, int a, int b)
{
    if(x>=0 && y>=0 && x<a && y<b) return true;
    return false;
}
int main()
{
    int cases;
    cin>>cases;
    for(int i=0; i<cases; i++)
    {
        int n,m;
        cin>>n>>m;
        vector<vector<int>> v(n, vector<int> (m,0));
        vector<pair<int,int>> ind;
        int counter=0;
        for(int j=0; j<n; j++)
        {
            for(int k=0; k<m; k++)
            {
                char t;
                cin>>t;
                v[j][k] = t-'0';
                if(v[j][k] == 1) counter++;
                else ind.push_back(make_pair(j,k));
            }
        }
        if(counter == n*m){
            cout<<n*m-2<<endl;
            continue;
        } 
        if(counter == 0)
        {
            cout<<0<<endl;
            continue;
        }
        bool checker=false;
        // for(int j=0; j<n; j++)
        // {
        //     for(int k=0; k<m; k++)
        //     {
        //         cout<<v[j][k]<<" ";
        //     }
        //     cout<<endl;
        // }
        // cout<<counter<<endl;
        for(int j=0; j<ind.size(); j++)
        {
            int x = ind[j].first;
            int y = ind[j].second;
            vector<int> dx = {1,1,0,-1,-1,-1,0,1};
            vector<int> dy = {0,-1,-1,-1,0,1,1,1};
            for(int k=0;k<4;k++)
            {
                // cout<<check(x+dx[k],y+dy[k], n, m)<<" "<<x+dx[k]<<" "<<y+dy[k]<<" "<<n<<" "<<m<<endl;
                if(check(x+dx[k],y+dy[k], n, m) && v[x+dx[k]][y+dy[k]]==0) 
                {
                    checker=true;
                    break;
                }
            }
            if(checker) 
            {
                cout<<counter<<endl;
                break;
            }
        }
        if(!checker)
        {
            cout<<counter-1<<endl;
        }
        // cout<<checker<<endl;
    }
}