# Leetcode solution
# Link : https://leetcode.com/problems/4sum/

class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        x = []
        previ = 0
        i=0
        nums.sort()
        while i<len(nums):
            if previ != i and nums[previ] == nums[i]:
                i+=1
                continue
            elif previ != i and nums[previ] != nums[i]:
                previ = i
            j = i+1
            prevj = j
            while j < len(nums):
                if prevj != j and nums[prevj] == nums[j]:
                    j+=1
                    continue
                elif prevj != j and nums[prevj] != nums[j]:
                    prevj = j

                k = j+1
                prevk = k
                l = len(nums)-1
                prevl = l

                # print("I am coming here ??")

                while k<l:
                    if prevk != k and nums[prevk] == nums[k]:
                        k+=1
                        continue
                    elif prevk != k and nums[prevk] != nums[k]:
                        prevk = k

                    if prevl != l and nums[prevl] == nums[l]:
                        l-=1
                        continue
                    elif prevl != l and nums[prevl] != nums[l]:
                        prevl = l

                    summ = nums[i] + nums[j] + nums[k] + nums[l]
                    if  summ == target:
                        temp = [nums[i],nums[j],nums[k],nums[l]]
                        x.append(temp)
                        k+=1
                        l-=1
                        continue
                    elif summ < target:
                        k+=1
                        continue
                    elif summ > target:
                        l-=1
                        continue

                j+=1
            i+=1
        return x
