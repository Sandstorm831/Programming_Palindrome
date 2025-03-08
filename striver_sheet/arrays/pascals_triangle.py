# Leetcode Solution 
# Link : https://leetcode.com/problems/pascals-triangle/

class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        x = []
        for i in range(numRows):
            if i==0:
                x.append([1])
            elif i==1:
                x.append([1,1])
            else:
                y = []
                y.append(1)
                for dx in range(len(x[-1])-1):
                    y.append(x[-1][dx] + x[-1][dx+1])
                y.append(1)
                x.append(y)
        return x