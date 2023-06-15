//Question LInk - https://www.interviewbit.com/problems/ways-to-color-a-3xn-board/
// Solution 

using ll = long long;
int Solution::solve(int A) {
    vector<vector<int> > valid;
    ll mod = 1e9 + 7;
    ll dp[A + 1][4][4][4];
    for(int j = 0; j <= 3; j ++){
        for(int k = 0; k <= 3; k ++){
            if(k == j)
                continue;
            for(int l = 0; l <= 3; l ++){
                if(l == k)
                    continue;
                valid.push_back(vector<int>{j, k, l});
                dp[1][j][k][l] = 1;
            }
        }
    }
    
    for(int i = 2; i <= A; i ++){
        for(auto &v1: valid){
            dp[i][v1[0]][v1[1]][v1[2]] = 0;
            for(auto &v2: valid){
                if((v1[0] == v2[0]) || (v1[1] == v2[1]) || (v1[2] == v2[2]))
                    continue;
                dp[i][v1[0]][v1[1]][v1[2]] += dp[i - 1][v2[0]][v2[1]][v2[2]];
                dp[i][v1[0]][v1[1]][v1[2]] %= mod;
            }
        }
    }   
    ll ans = 0;
    for(auto &v1: valid){
        ans += dp[A][v1[0]][v1[1]][v1[2]];
        ans %= mod;
    }
    return ans;
}
