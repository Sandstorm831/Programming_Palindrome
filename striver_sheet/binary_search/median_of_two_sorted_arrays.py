# Leetcode solution
# Link : https://leetcode.com/problems/median-of-two-sorted-arrays/

def comparator(numsl, numsh, nl, nh):
    if nl == 0:
        return False
    elif nh == 0:
        return True
    else:
        return numsl[nl-1]>numsh[nh-1]

def calcMiner(numsl, numsh, nl, nh):
    if nl == len(numsl):
        return numsh[nh]
    elif nh == len(numsh):
        return numsl[nl]
    else:
        return min(numsl[nl], numsh[nh])

def calcMaxer(numsl, numsh, nl, nh):
    if nl == 0:
        return numsh[nh-1]
    elif nh == 0:
        return numsl[nl-1]
    else:
        return max(numsl[nl-1], numsh[nh-1])

def algorithm(numsl, numsh):
    n = len(numsl)
    hi = n
    lo = 0
    nums_to_take = (n + len(numsh) + 1) // 2
    while lo < hi:
        mid = lo + (hi-lo)//2
        nl = mid
        nh = nums_to_take - nl
        maxer = calcMaxer(numsl, numsh, nl, nh)
        miner = calcMiner(numsl, numsh, nl, nh)
        if maxer <= miner:
            if (len(numsl) + len(numsh)) % 2 == 0:
                return (maxer + miner) / 2
            else:
                return maxer
        elif comparator(numsl, numsh, nl, nh):
            hi = mid-1
        else:
            lo = mid+1
    nl = lo
    nh = nums_to_take-nl
    maxer = calcMaxer(numsl, numsh, nl, nh)
    miner = calcMiner(numsl, numsh, nl, nh)
    if (len(numsl) + len(numsh)) % 2 == 0:
        return (maxer + miner) / 2
    else:
        return maxer

class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        if len(nums1) == 0 and len(nums2) == 0:
            return 0
        elif len(nums1) == 0:
            x = len(nums2)
            if x%2==0:
                return (nums2[x//2 - 1] + nums2[x//2 ]) / 2
            else:
                return nums2[x//2]
        elif len(nums2) == 0:
            x = len(nums1)
            if x%2==0:
                return (nums1[x//2 - 1] + nums1[x//2]) / 2
            else:
                return nums1[x//2]
        elif len(nums1) > len(nums2):
            return algorithm(nums2, nums1)
        else:
            return algorithm(nums1, nums2)
