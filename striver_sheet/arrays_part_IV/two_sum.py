# leetcode solution
# link : https://leetcode.com/problems/two-sum/
# Hashmap solution

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        hashmap = {}
        indexes = []
        for i in range(len(nums)):
            rem = target - nums[i]
            if rem in hashmap:
                indexes.append(hashmap[rem])
                indexes.append(i)
            else:
                hashmap[nums[i]] = i
        return indexes
