#include <bits/stdc++.h>
using namespace std;
vector<int> palindrome;
void filler(void)
{
    // palindrome.push_back(0);
    for(int j=1; j<=9; j++)
    {
        palindrome.push_back(j);
        int x = 10*j+j;
        palindrome.push_back(x);
    }
    for(int j=10; j<=99; j++){
        int x = 10*j+j/10;
        // if(j==45) cout<<x<<endl;
        palindrome.push_back(x);
        int y = 100*j+(10*(j%10)+j/10);
        // if(j==67) cout<<y<<endl;
        palindrome.push_back(y);
    }
    for(int j=100; j<400; j++)
    {
        int x = j/10;
        int y = 100*j+(10*(x%10)+x/10);
        // if(j == 246) cout<<y<<endl;
        palindrome.push_back(y);
    }
}
int main()
{
    int mod = 1e9+7;
    int cases;
    cin>>cases;
    filler();
    sort(palindrome.begin(), palindrome.end());
    int s=palindrome.size();
    int N = 4e4+4;
    // cout<<N<<endl;
    vector<vector<int>> dp(N+1, vector<int> (s+1,0));
    for(int i=1; i<=N; i++)
    {
        for(int j=0; j<=s; j++)
        {
            if(i==1 || j==0) dp[i][j]=1;
            else if(palindrome[j]<i) dp[i][j] = (dp[i][j-1]+dp[i-palindrome[j]][j])%mod;
            else dp[i][j] = dp[i][j-1];
        }
    }
    for(int i=0; i<cases; i++)
    {
        int n;
        cin>>n;
        cout<<dp[n+1][s-1]<<endl;
    }
}