// Question Link - https://leetcode.com/problems/number-of-music-playlists/description/
// solution 

class Solution {
public:
    long long mod = 1e9+7;
    vector<vector<long long>> dp;
    long long fact(long long n)
    {
        if(n == 0 || n==1) return 1;
        else return n*fact(n-1)%(1ll*mod);
    }
    long long recursor(long long n, long long goal, long long k)
    {
        if(n == goal) return fact(goal);
        else if(goal == 1) return n;
        else if(n == 0 || n-k <= 0) return 0;
        else if(dp[n][goal] != -1) return dp[n][goal];
        else return dp[n][goal] = (recursor(n-1, goal-1, k)*n + recursor(n, goal-1, k)*(n-k))%mod;
    }
    int numMusicPlaylists(int n, int goal, int k) {
        dp.clear();
        dp.resize(n+1, vector<long long> (goal+1, -1));
        return recursor(n, goal, k);
    }
};
// Explanation - https://leetcode.com/problems/number-of-music-playlists/solutions/178415/c-java-python-dp-solution/