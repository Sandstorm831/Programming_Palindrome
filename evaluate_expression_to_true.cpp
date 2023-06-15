// Question link - https://www.interviewbit.com/problems/evaluate-expression-to-true/
// Solution 

vector<vector<vector<int>>> dp;
const int mod = 1e3+3;
int founder(string A, int ini, int fin, int target)
{
    int ans=0;
    if(ini == fin)
    {
        if(target==1)
        {
            if(A[ini]=='T') return 1;
            return 0;
        }
        else if(target==0)
        {
            if(A[ini]=='F') return 1;
            return 0;
        }
    }
    if(dp[ini][fin][target] != -1) return dp[ini][fin][target];
    for(int i=ini; i<=fin; i++)
    {
        if(A[i] == '|')
        {
            if(target == 1) ans = (ans%mod + (((founder(A, ini, i-1,1)%mod)*(founder(A, i+1, fin, 0)%mod)%mod) + (((founder(A, ini, i-1,0)%mod)*(founder(A, i+1, fin, 1)%mod)%mod) + ((founder(A, ini, i-1,1)%mod)*(founder(A, i+1, fin, 1)%mod))%mod)%mod)%mod)%mod;
            else if(target == 0) ans = (ans%mod + ((founder(A, ini, i-1,0)%mod)*(founder(A, i+1, fin, 0)%mod))%mod)%mod;
        }
        else if(A[i] == '&')
        {
            if(target==1) ans = (ans%mod + (founder(A, ini, i-1,1)%mod*founder(A, i+1, fin, 1)%mod)%mod)%mod;
            else if(target==0) ans = ans%mod + ((founder(A, ini, i-1,0)%mod)*(founder(A, i+1, fin, 0)%mod))%mod + ((founder(A, ini, i-1,1)%mod)*(founder(A, i+1, fin, 0)%mod))%mod + ((founder(A, ini, i-1,0)%mod)*(founder(A, i+1, fin, 1)%mod))%mod;
        }
        else if(A[i] == '^')
        {
            if(target == 1) ans = ans%mod + ((founder(A, ini, i-1,1)%mod)*(founder(A, i+1, fin, 0)%mod))%mod + (founder(A, ini, i-1,0)%mod)*(founder(A, i+1, fin, 1)%mod);
            else if(target == 0) ans = ans%mod + ((founder(A, ini, i-1,1)%mod)*(founder(A, i+1, fin, 1)%mod))%mod + ((founder(A, ini, i-1,0)%mod)*(founder(A, i+1, fin, 0)%mod))%mod;
        }
    }
    return dp[ini][fin][target] = ans;
}
int Solution::cnttrue(string A) {
    int ans=0;
    dp.clear();
    dp.resize(A.size()+1, vector<vector<int>> (A.size()+1, vector<int> (2, -1)));
    int ini=0,fin=A.size()-1;
    for(int i=0; i<A.size(); i++)
    {
        if(A[i] == '|')
        {
            ans = (ans%mod + ((founder(A, 0, i-1,1)%mod)*(founder(A, i+1, A.size()-1, 0)%mod))%mod + ((founder(A, 0, i-1,0)%mod)*(founder(A, i+1, A.size()-1, 1)%mod))%mod + ((founder(A, 0, i-1,1)%mod)*(founder(A, i+1, A.size()-1, 1)%mod))%mod)%mod;
        }
        else if(A[i] == '&')
        {
            ans = ans%mod + ((founder(A, 0, i-1,1)%mod)*(founder(A, i+1, A.size()-1, 1)%mod))%mod;
        }
        else if(A[i] == '^')
        {
            ans = (ans%mod + ((founder(A, 0, i-1,1)%mod)*(founder(A, i+1, A.size()-1, 0)%mod))%mod + ((founder(A, 0, i-1,0)%mod)*(founder(A, i+1, A.size()-1, 1)%mod))%mod)%mod;
        }
    }
    return dp[0][A.size()-1][1] = ans;
}
