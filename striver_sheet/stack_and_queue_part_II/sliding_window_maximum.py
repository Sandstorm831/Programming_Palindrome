# Leetcode solution
# Link : https://leetcode.com/problems/sliding-window-maximum/

from collections import deque

class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        slider = []
        dq = deque()
        for i in range(k):
            while len(dq) > 0 and nums[dq[-1]] < nums[i]:
                dq.pop()
            dq.append(i)
        slider.append(nums[dq[0]])
        for i in range(k, len(nums)):
            while len(dq) > 0 and i - dq[0] > k-1:
                dq.popleft()
            while len(dq) > 0 and nums[dq[-1]] < nums[i]:
                dq.pop()
            dq.append(i)
            slider.append(nums[dq[0]])
        return slider
