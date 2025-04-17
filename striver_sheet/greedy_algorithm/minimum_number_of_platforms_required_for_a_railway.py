# GFG solution
# Link : https://www.geeksforgeeks.org/problems/minimum-platforms-1587115620/1

class Solution:
    #Function to find the minimum number of platforms required at the
    #railway station such that no train waits.
    def minimumPlatform(self,arr,dep):
        # code here
        x = []
        for i in range(len(arr)):
            x.append((arr[i], 0))
            x.append((dep[i], 1))
        x.sort(key = lambda tup: (tup[0], tup[1]))
        maxer = 1
        curr = 0
        for i in range(len(x)):
            if x[i][1] == 0:
                curr += 1
                maxer = max(maxer, curr)
            elif x[i][1] == 1:
                curr -= 1
        return maxer
