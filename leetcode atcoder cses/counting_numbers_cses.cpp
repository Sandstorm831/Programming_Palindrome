#include <bits/stdc++.h>
using namespace std;
vector<vector<vector<vector<long long>>>> dp(20, vector<vector<vector<long long>>>(10, vector<vector<long long>> (2, vector<long long> (2, -1))));
long long recursor(string num, int len, int prev, int tight, int lz)
{
    if(len == 0) return 1;
    else if(prev != -1 && dp[len][prev][tight][lz] != -1) return dp[len][prev][tight][lz];
    int lb = 0;
    int ub = tight ? (num[num.size()-len]-'0') : 9;
    long long ans = 0;
    for(int i=lb; i<=ub; i++)
    {
        if(i == prev && i != 0) continue;
        else if(i ==  prev && i == 0 && !lz) continue;
        else
        {
            ans += recursor(num, len-1, i, tight & (i == ub), lz & (i == 0));
        }
    }
    if(prev == -1) return ans;
    return dp[len][prev][tight][lz] = ans;
}
int main()
{
    long long a, b;
    cin>>a>>b; a--;
    string aa = to_string(a);
    string bb = to_string(b);
    long long xb = recursor(bb, bb.length(), -1, 1, 1);
    dp.clear(); dp.resize(20, vector<vector<vector<long long>>>(10, vector<vector<long long>>(2, vector<long long> (2, -1))));
    long long xa = recursor(aa, aa.length(), -1, 1, 1);
    cout<<xb-xa<<endl;
}