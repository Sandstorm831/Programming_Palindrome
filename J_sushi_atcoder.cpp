#include <bits/stdc++.h>
using namespace std;
vector<vector<vector<double>>> DP(301, vector<vector<double>>(301, vector<double>(301, 0)));
int N;

double solve(int x, int y, int z) {
    if (x < 0 || y < 0 || z < 0) {
        return 0;
    }
    if (x == 0 && y == 0 && z == 0) {
        return 0;
    }
    if (DP[x][y][z] > 0) {
        return DP[x][y][z];
    }
    DP[x][y][z] = double(N + x * solve(x - 1, y, z) + y * solve(x + 1, y - 1, z) + z * solve(x, y + 1, z - 1)) / double(x + y + z);
    return DP[x][y][z];
}
int main() {
    cin >> N;
    vector<int> counts(4, 0);
    for (int i = 0; i < N; i++) {
        int amount;
        cin >> amount;
        counts[amount]++;
    }   
    cout << fixed << setprecision(10) << solve(counts[1], counts[2], counts[3]);
}