// Question Link - https://www.interviewbit.com/problems/longest-arithmetic-progression/
// solution 

int Solution::solve(const vector<int> &A) {
    
// Time - O(N^3), Space - O(N^2)
// DP solution
    // int n = A.size();
    // if(n <= 2) {
    //     return n;
    // }

    // vector<vector<int>> dp(n, vector<int>(n, 2));
    // int max_len = 2;
    // for(int i = 0; i < n - 1; i++) {
    //     for(int j = i + 1; j < n; j++) {
    //         int need = 2 * A[i] - A[j];
    //         int pos = -1;
    //         for(int k = i - 1; k >= 0; k--) {
    //             if(A[k] == need) {
    //                 pos = k;
    //                 break;
    //             }
    //         }

    //         if(pos != -1) {
    //             dp[i][j] = max(dp[i][j], dp[pos][i] + 1);
    //         }
    //         max_len = max(dp[i][j], max_len);
    //     }
    // }

    // return max_len;  
    
    
    ///////
    
    
// Time - O(N^2), Space - O(N^2)
// DP with hashing solution
    int n = A.size();
    if(n <= 2) {
        return n;
    }

    vector<vector<int>> dp(n, vector<int>(n, 2));
    unordered_map<int, int> pos;
    int max_len = 2;
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            int need = 2 * A[i] - A[j];
            if(pos.count(need) && pos[need]<i) {
                dp[i][j] = max(dp[i][j], dp[pos[need]][i] + 1);
            }
            max_len = max(dp[i][j], max_len);
        }
        pos[A[i]] = i;
    }

    return max_len;
}