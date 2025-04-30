# GFG solution
# Link : https://www.geeksforgeeks.org/problems/median-in-a-row-wise-sorted-matrix1527/1

def sm_or_equal(row, std):
    lo = 0
    hi = len(row)
    while lo<hi:
        mid = lo + (hi-lo)//2
        if row[mid] > std:
            hi = mid
        else:
            lo = mid+1
    return lo

class Solution:
    def median(self, mat):
        r = len(mat)
        c = len(mat[0])
        rc_max, rc_min = -1, 2001
        for i in range(len(mat)):
            rc_max = max(rc_max, mat[i][-1])
            rc_min = min(rc_min, mat[i][0])
        lo, hi = rc_min, rc_max
        desired = (r*c+1)//2
        # print(lo, hi)
        while lo<hi:
            mid = lo + (hi-lo)//2
            sm_till = 0
            for i in range(len(mat)):
                sm_till += sm_or_equal(mat[i], mid)
                # print(mat[i], "|", desired, sm_till)
            if sm_till < desired:
                lo = mid+1
            else:
                hi = mid
        return lo
