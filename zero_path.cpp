#include <bits/stdc++.h>
using namespace std;
// vector<vector<int>> dp;
// bool recursor(vector<vector<int>>& v, int i, int j, int n, int m, int summ)
// {
//     // cout<<i<<" "<<j<<endl;
//     if(i==n && j==m) 
//     {
//         if(v[i][j]+summ == 0) return 1;
//         else return 0;
//     }
//     else if(dp[i][j] == 1) return dp[i][j];
//     else if(i==n) return dp[i][j] = recursor(v, i, j+1, n, m, summ+v[i][j]);
//     else if(j==m) return dp[i][j] = recursor(v, i+1, j, n, m, summ+v[i][j]);
//     else return dp[i][j] = (recursor(v, i+1, j, n, m, summ+v[i][j])||recursor(v, i, j+1, n, m, summ+v[i][j]));

// }
bool topdown(vector<vector<int>>& v, int n, int m)
{
    vector<vector<int>> dp1(n+1, vector<int> (m+1, 0));
    vector<vector<int>> dp2(n+1, vector<int> (m+1, 0));
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(i==1 && j==1) 
            {
                dp1[i][j]=v[i][j];
                dp2[i][j]=v[i][j];
            }
            else if(i==1) 
            {
                dp1[i][j] = v[i][j]+dp1[i][j-1];
                dp2[i][j] = v[i][j]+dp2[i][j-1];
            }
            else if(j==1) 
            {
                dp1[i][j] = v[i][j]+dp1[i-1][j];
                dp2[i][j] = v[i][j]+dp2[i-1][j];
            }
            else 
            {
                dp1[i][j] = v[i][j]+min(dp1[i-1][j], dp1[i][j-1]);
                dp2[i][j] = v[i][j]+max(dp2[i-1][j], dp2[i][j-1]);
            }
        }
    }
    // cout<<dp1[n][m]<<" "<<dp2[n][m]<<endl;
    if(dp1[n][m]<=0 && dp2[n][m]>=0) return 1;
    // else if(dp1[n][m]==dp2[n][m] && dp1[n][m] == 0) return 1;
    else return 0;
}
int main()
{
    int cases;
    cin>>cases;
    for(int i=0; i<cases; i++)
    {
        int n, m;
        cin>>n>>m;
        vector<vector<int>> v(n+1, vector<int> (m+1, -1));
        for(int j=1; j<=n; j++)
        {
            for(int k=1; k<=m; k++)
            {
                cin>>v[j][k];
            }
        }
        // dp.clear();
        // dp.resize(n+1, vector<int> (m+1, -1));
        // bool ans = recursor(v, 1,1,n,m, 0);
        if((n+m)%2==0)
        {
            cout<<"No"<<endl;
            continue;
        }
        bool ans = topdown(v, n, m);
        if(ans) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
}