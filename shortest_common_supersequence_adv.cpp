#include <bits/stdc++.h>
using namespace std;
int superSuper(vector<string> A)
{
    string unkonwn = A[0];
    int storer = 0;
    for (int i = 0; i < A.size()-1; i++)
    {
        int u = unkonwn.size();
        int a = A[i+1].size();
        vector<vector<int>> dp(u+1, vector<int> (a+1));
        for (int k = 0; k <= u; k++)
        {
            for (int j = 0; j <= a; j++)
            {
                if(k == 0 || j == 0) dp[k][j] = 0;
                else if(unkonwn[k-1] == A[i+1][j-1]) dp[k][j] = 1+dp[k-1][j-1];
                else dp[k][j] = max(dp[k-1][j], dp[k][j-1]);
            }
        }
        string dem = "";
        while(u != 0 && a != 0)
        {
            if(unkonwn[u-1] == A[i+1][a-1])
            {
                dem.push_back(unkonwn[u-1]);
                a--;u--;
            }
            else 
            {
                if(dp[u-1][a] > dp[u][a-1]) u--;
                else a--;
            }
        }
        reverse(dem.begin(), dem.end());
        cout<<dem<<endl;
        int l = 0;
        string next = "";
        int un = 0, ai = 0;
        while(un != unkonwn.size() || ai != A[i+1].size())
        {
            if(unkonwn[un] == dem[l] && A[i+1][ai] == dem[l])
            {
                next.push_back(dem[l]);
                ai++;un++;l++;
            }
            else if(unkonwn[un] != dem[l])
            {
                next.push_back(unkonwn[un]);
                un++;
            }
            else if(A[i+1][ai] != dem[l])
            {
                next.push_back(A[i+1][ai]);
                ai++;
            }
        }
        unkonwn = next;
    }
    cout<<unkonwn<<endl;
    return unkonwn.size();
}
int main()
{
    vector<string> A ={"cpsklryvmcp", "nbpbwllsrehfmx", "kecwitrsglre", "vtjmxypu"};
    cout<<superSuper(A); 
}