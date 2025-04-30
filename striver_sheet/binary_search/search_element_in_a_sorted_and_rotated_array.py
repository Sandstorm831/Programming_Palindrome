# Leetcode solution
# Link : https://leetcode.com/problems/search-in-rotated-sorted-array/

def findPivot(arr):
    if arr[0] < arr[-1]:
        return -1
    ini = arr[0]
    fin = arr[-1]
    hi = len(arr)-1
    lo = 0
    while hi > lo:
        mid = lo + (hi-lo)//2
        # print("started", lo, mid, hi)
        if mid > 0 and mid < len(arr)-1:
            if arr[mid] > arr[mid-1] and arr[mid] > arr[mid+1]:
                return mid
            elif arr[mid] < arr[mid-1] and arr[mid] < arr[mid+1]:
                return mid-1
            elif arr[mid] > fin:
                lo = mid+1
            elif arr[mid] < fin:
                hi = mid-1
            # print("end1", lo, mid, hi)
        else:
            if mid == 0 and arr[mid] > arr[mid+1]:
                return 0
            elif mid == 0:
                return -1
            elif mid == len(arr)-1 and arr[mid] < arr[mid-1]:
                return len(arr)-2
            else:
                print("i don't know why it's here")
                return -1
    return lo

def searchIn(arr, lo, hi, target):
    while lo < hi:
        mid = lo + (hi-lo)//2
        if arr[mid] == target:
            return mid
        elif target>arr[mid]:
            lo = mid+1
        elif target<arr[mid]:
            hi = mid-1
    # print(lo)
    if arr[lo] != target:
        return -1
    return lo

class Solution:
    def search(self, nums: List[int], target: int) -> int:
        if len(nums)==1:
            if nums[0] == target:
                return 0
            return -1
        pivot = findPivot(nums)
        if pivot == -1:
            return searchIn(nums, 0, len(nums)-1, target)
        miner = nums[pivot+1]
        maxer = nums[pivot]
        divider = nums[-1]
        if target>= miner and target <= divider:
            return searchIn(nums, pivot+1, len(nums)-1, target)
        else:
            return searchIn(nums, 0, pivot, target)
