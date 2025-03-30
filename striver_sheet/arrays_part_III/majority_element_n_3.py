# Leetcode solution
# Link : https://leetcode.com/problems/majority-element-ii/

class Solution:
    def majorityElement(self, nums: List[int]) -> List[int]:
        maj1 = maj2 = c1 = c2 = 0
        for i in range(len(nums)):
            if nums[i] == maj1:
                c1+=1
            elif nums[i] == maj2:
                c2+=1
            elif c1 == 0:
                maj1 = nums[i]
                c1+=1
            elif c2 == 0:
                maj2 = nums[i]
                c2+=1
            else:
                c1-=1
                c2-=1

        c1,c2 = 0, 0
        for i in range(len(nums)):
            if nums[i] == maj1:
                c1+=1
            elif nums[i] == maj2:
                c2+=1
        res = []
        if c1 > len(nums)//3:
            res.append(maj1)
        if c2 > len(nums)//3:
            res.append(maj2)
        return res