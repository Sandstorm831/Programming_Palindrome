# Leetcode solution
# Link : https://leetcode.com/problems/trapping-rain-water/

class Solution:
    def trap(self, height: List[int]) -> int:
        left = []
        maxer = -1
        for i in range(len(height)):
            maxer = max(maxer, height[i])
            left.append(maxer)
        right = []
        maxer = -1
        for i in range(len(height)-1, -1, -1):
            maxer = max(maxer, height[i])
            right.append(maxer)
        right.reverse()
        trapped_water = 0
        for i in range(len(left)):
            trapped_water += abs(min(left[i], right[i]) - height[i])
        return trapped_water
