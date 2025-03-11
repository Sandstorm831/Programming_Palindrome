# Leetcode Solution 
# Link : https://leetcode.com/problems/merge-intervals

# Sort and Merge
class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        intervals.sort(key=lambda x: (x[0], x[1]))
        print(intervals)
        res = []
        res.append(intervals[0])
        for i in range(1, len(intervals)):
            if res[-1][1] < intervals[i][0]:
                res.append(intervals[i])
            else:
                res[-1][1] = max(intervals[i][1], res[-1][1])
        return res