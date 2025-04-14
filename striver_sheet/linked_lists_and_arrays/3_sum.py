# Leetcode solution
# Link : https://leetcode.com/problems/3sum/
#

class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        triplets = []
        i = 0
        curr_i = 0
        while i<len(nums):

            j = i+1
            curr_j = j
            k = len(nums)-1
            curr_k = k
            while j<k:

                summer = nums[i]+nums[j]+nums[k]
                if summer == 0:
                    temp = [nums[i],nums[j],nums[k]]
                    triplets.append(temp)
                    j+=1
                    k-=1
                elif summer > 0:
                    k-=1
                elif summer < 0:
                    j+=1


                while j<k and j != curr_j and nums[j] == nums[curr_j]:
                    j+=1
                    if j<k and nums[j] != nums[curr_j]:
                        curr_j = j
                        break
                while j<k and j != curr_j and nums[j] != nums[curr_j]:
                    curr_j = j

                while j<k and k != curr_k and nums[k] == nums[curr_k]:
                    k-=1
                    if j<k and nums[k] != nums[curr_k]:
                        curr_k = k
                        break
                while j<k and k != curr_k and nums[k] != nums[curr_k]:
                    curr_k = k

            i+=1
            while i<len(nums) and i != curr_i and nums[i] == nums[curr_i]:
                i+=1
                if i<len(nums) and nums[i] != nums[curr_i]:
                    curr_i = i
                    break
            while i<len(nums) and i != curr_i and nums[i] != nums[curr_i]:
                curr_i = i
        return triplets
