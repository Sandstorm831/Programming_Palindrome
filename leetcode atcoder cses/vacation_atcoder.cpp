#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> dp;
int recursor(int N, vector<vector<int>>& v, int index, int ps)
{
    if(index >= v.size()) return 0;
    else if(dp[index][ps] != -1) return dp[index][ps];
    else
    {
        int counter = INT_MIN;
        for(int i=0; i<3; i++)
        {
            if(i == ps) continue;
            counter = max(counter, v[index][i]+recursor(N, v, index+1, i));
        }
        return dp[index][ps] = counter;
    }
}
int main()
{
    int N;cin>>N;
    vector<vector<int>> v(N, vector<int> (3));
    dp.clear(); dp.resize(N+1, vector<int> (3, -1));
    for(int i=0; i<N; i++) cin>>v[i][0]>>v[i][1]>>v[i][2];
    cout<<max(recursor(N, v, 0, 0), recursor(N, v, 0, 1))<<endl;
}