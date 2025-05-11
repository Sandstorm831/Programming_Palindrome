# Leetcode solution
# Link : https://leetcode.com/problems/kth-largest-element-in-an-array/

import heapq

class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        hq = []
        for i in nums:
            heapq.heappush(hq, -i)
        for i in range(k-1):
            heapq.heappop(hq)
        return -heapq.heappop(hq)
