# Leetcode solution
# Link : https://leetcode.com/problems/combination-sum/

class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        candidates.sort()
        x = []
        temp = []
        recursor(0, candidates, temp, x, target, 0)
        return x

def recursor(index, uniq, temp, x, target, summer):
    # print(index, temp, summer)
    if summer == target:
        x.append(temp[:])
        return
    if index >= len(uniq):
        return
    if uniq[index] > target - summer:
        return
    if uniq[index] <= target-summer:
        temp.append(uniq[index])
        recursor(index, uniq, temp, x, target, summer+uniq[index])
        temp.pop()
        recursor(index+1, uniq, temp, x, target, summer)
    else:
        recursor(index+1, uniq, temp, x, target, summer)
