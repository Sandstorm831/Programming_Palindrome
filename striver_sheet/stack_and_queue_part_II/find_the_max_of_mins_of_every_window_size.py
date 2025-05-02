# GFG Solution
# Link : https://www.geeksforgeeks.org/problems/maximum-of-minimum-for-every-window-size3453/1

class Solution:
    def maxOfMins(self, arr):
       # code here
        winSize=[0 for i in range(len(arr))]
        st = [-1]

        for i in range(len(arr)):
            while st[-1] != -1 and arr[st[-1]] >= arr[i]:
                x = st.pop()
                width = i - st[-1] - 1
                winSize[x] = width
            st.append(i)

        while st[-1] != -1:
            x = st.pop()
            width = len(arr) - st[-1] - 1
            winSize[x] = width
        res = [0 for i in range(len(arr))]
        for i in range(len(arr)):
            res[winSize[i]-1] = max(res[winSize[i]-1], arr[i])
        for i in range(len(arr)-2, -1, -1):
            res[i] = max(res[i], res[i+1])
        return res
