# geeks for geeks solution:
# link : https://practice.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1
#
class Solution:
    def maxLen(self, arr):
        # code here
        x = {}
        summer = 0
        maxer = -1
        x[0] = -1
        for i in range(len(arr)):
            summer += arr[i]
            if summer in x:
                maxer = max(maxer, i - x[summer])
            else:
                x[summer] = i
        return max(maxer, 0)
