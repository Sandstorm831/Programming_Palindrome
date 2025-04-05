# Leetcode solution
# Link: https://leetcode.com/problems/unique-paths/


def recursor(rc, cc, m, n, dp):
    if rc == 1 or cc == 1:
        dp[rc-1][cc-1] = 1
        return 1
    elif dp[rc-1][cc-1] != 0:
        # print( rc, cc, dp[rc-1][cc-1])
        return dp[rc-1][cc-1]
    else:
        # print(dp)
        dp[rc-1][cc-1] = recursor(rc-1, cc, m, n, dp) + recursor(rc, cc-1, m, n, dp)
        # print(rc, cc, "--", dp[rc-1][cc-1])
        # print(dp)
        return dp[rc-1][cc-1]

class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        dp = [[0 for x in range(n)] for y in range(m)]
        return recursor(m, n, m, n, dp)
