# GFG solution
# Link : https://www.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1

class Solution:
    def fractionalknapsack(self, val, wt, capacity):
        #code here
        x = []
        for i in range(len(wt)):
            x.append((val[i]/wt[i], val[i], wt[i]))
        x.sort(key = lambda tup: (tup[0], tup[2]))
        val = 0
        for i in range(len(x)-1, -1, -1):
            if capacity > 0:
                if capacity >= x[i][2]:
                    val += x[i][1]
                    capacity -= x[i][2]
                else:
                    val += x[i][0]*capacity
                    capacity = 0
                    break
        return val
