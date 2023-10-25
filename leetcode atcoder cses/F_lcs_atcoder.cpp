#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> dp;
int recursor(string& a, string& b, int x, int y)
{
    if(x >= a.size() || y >= b.size()) return 0;
    else if(dp[x][y] != -1) return dp[x][y];
    else 
    {
        if(a[x] == b[y]) return dp[x][y] = 1 + recursor(a, b, x+1, y+1);
        else return dp[x][y] = max(recursor(a, b, x+1, y), recursor(a, b, x, y+1));
    }
}
void solve()
{
    string s,t; cin>>s>>t;
    dp.clear(); dp.resize(s.size()+1, vector<int> (t.size()+1,-1));
    recursor(s, t, 0, 0);
    string ans="";
    int i=0, j=0;
    while(i<s.size() && j<t.size())
    {
        if(s[i] == t[j])
        {
            ans += s[i];i++, j++;
        }
        else if(dp[i+1][j]>dp[i][j+1])
        {
            i++;
        }
        else
        {
            j++;
        }
    }
    cout<<ans<<endl;
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    solve();
    return 0;
}