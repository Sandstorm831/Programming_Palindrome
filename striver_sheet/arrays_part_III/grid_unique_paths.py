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

# Combinatorics solution: more efficient
# we have n rows, so can take n-1 down steps and m columns, so can take m-1 right steps
# so this question boild down to arranging the n-1 down and m-1 right steps
# in an empty m+n-2 long empty string, it's equal to selecting m-1 or n-1 places, thus the solution.
class ESolution:
    def uniquePaths(self, m: int, n: int) -> int:
        N = m+n-2
        r = m-1
        res = 1
        for i in range(1, r+1):
            res *= (N-r+i)/i
        res = round(res)
        return int(res)
