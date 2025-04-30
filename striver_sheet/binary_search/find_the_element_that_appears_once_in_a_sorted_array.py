# Leetcode solution
# Link : https://leetcode.com/problems/single-element-in-a-sorted-array/

class Solution:
    def singleNonDuplicate(self, nums: List[int]) -> int:
        hi = len(nums)-1
        lo = 0
        while lo<hi:
            mid = lo + (hi-lo)//2
            print("start",lo, mid, hi)
            amid = nums[mid]
            if mid !=0 and mid != len(nums)-1:
                if amid != nums[mid-1] and amid != nums[mid+1]:
                    return amid
                elif (hi-mid) % 2 == 0:
                    if amid == nums[mid+1]:
                        lo = mid+2
                    elif amid != nums[mid+1]:
                        hi = mid-2
                elif (hi-mid) % 2 == 1:
                    if amid == nums[mid+1]:
                        hi = mid-1
                    elif amid != nums[mid+1]:
                        lo = mid+1
                print("end", lo, mid, hi)
            else:
                return amid
        # print("hello")
        return nums[lo]
