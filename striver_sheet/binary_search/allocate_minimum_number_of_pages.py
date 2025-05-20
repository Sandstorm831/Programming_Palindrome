# GFG Solution
# Link : https://www.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1

def check(limit, arr, k):
    pageSum = 0
    cnt = 1
    for pages in arr:
        if pages + pageSum > limit:
            cnt += 1
            pageSum = pages
        else:
            pageSum += pages
    return cnt <= k


class Solution:
    # Function to find minimum number of pages.
    def findPages(self, arr, k):
        # code here
        if len(arr) < k:
            return -1
        miner = max(arr)
        maxer = sum(arr)
        res = -1
        while miner <= maxer:
            mid = miner + (maxer - miner)//2
            x = check(mid, arr, k)
            if x:
                res = mid
                maxer = mid - 1
            else:
                miner = mid+1
        return res
