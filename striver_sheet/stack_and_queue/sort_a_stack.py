# GFG Solution
# Link : https://www.geeksforgeeks.org/problems/sort-a-stack/0

class Solution:
    # your task is to complete this function
    # function sort the stack such that top element is max
    # funciton should return nothing
    # s is a stack
    def Sorted(self, s):
        # Code here
        l = []
        while len(s) > 0:
            temp = s.pop()
            while len(l) > 0 and l[-1]<temp:
                s.append(l.pop())
            l.append(temp)
            # print(l)
        while len(l) > 0:
            s.append(l.pop())
