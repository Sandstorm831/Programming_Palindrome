# GFG solution
# Link : https://www.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1
# disjoint set + standard solution, used disjoint set to reaching the last empty index efficiently,
# here, returning -1 means none is empty before the deadline, and anyother number in return means,
# there was something empty and was occupied, the empty cell is represented by the number insede it,
# if the number inside a cell is equal to it's index, it means it is empty otherwise it will point to
# a cell which it think might be empty

def putt(x, di):
    if x[di] == 0:
        return -1
    elif x[di] == di:
        x[di] = x[di-1]
        return x[di-1]
    else:
        y = putt(x, x[di])
        if y == -1:
            return -1
        x[di] = y
        return x[di]

class Solution:
    def jobSequencing(self, deadline, profit):
        # code here
        x = [i for i in range(len(profit)+1)]
        y = []
        mj = 0
        for i in range(len(deadline)):
            y.append((profit[i], deadline[i]))
            mj = max(mj, deadline[i])
        y.sort(key = lambda tup: (tup[0], tup[1]))
        profits = 0
        omj = mj
        for i in range(len(y)-1, -1, -1):
            if mj == 0:
                break
            nm = putt(x, y[i][1])
            if nm == -1:
                continue
            profits += y[i][0]
            mj -= 1
        return [omj-mj, profits]
