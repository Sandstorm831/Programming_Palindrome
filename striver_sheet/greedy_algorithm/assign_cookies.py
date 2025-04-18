# Leetcode solution
# Link : https://leetcode.com/problems/assign-cookies

class Solution:
    def findContentChildren(self, g: List[int], s: List[int]) -> int:
        g.sort()
        s.sort()
        sj = 0
        gi = 0
        count = 0
        while sj < len(s) and gi < len(g):
            if s[sj] >= g[gi]:
                count+=1
                sj+=1
                gi+=1
            elif s[sj] < g[gi]:
                sj+=1
        return count
