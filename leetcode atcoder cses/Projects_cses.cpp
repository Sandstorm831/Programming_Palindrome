#include <bits/stdc++.h>
using namespace std;
 
int main() {
    // read the input
    int n;
    cin >> n;
    vector<tuple<long long, long long, long long>> projects(n);
    for (int i = 0; i < n; i++) {
        long long start, end, reward;
        cin >> start >> end >> reward;
        projects[i] = {end, start, reward};
    }
    sort(projects.begin(), projects.end());
 
    // compute the dp table and totalBestReward
    long long bestTotalReward = 0;
    map<long long, long long> dp; // {end: totalRewardSoFar}
    dp[0] = 0;
    for (int i=0; i<projects.size(); i++) {
        long long start, end, reward;
        tie(end, start, reward) = projects[i];
 
        auto it = dp.lower_bound(start);
        it--;
        long long totalReward = it->second + reward;
        bestTotalReward = max(bestTotalReward, totalReward);
        dp[end] = bestTotalReward;
    }
    cout << bestTotalReward;
    return 0;
}