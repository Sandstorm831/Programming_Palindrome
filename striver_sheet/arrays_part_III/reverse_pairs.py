# leetcode solution
# Link : https://leetcode.com/problems/reverse-pairs/
# merge sort and counting for the given condition in the merge step just prior to merging and then merging
def merge(l, m, h, nums):
    if l>=h:
        return 0
    counter = 0
    i = m
    j = h
    while j>=m+1 and i >= l:
        if nums[j]*2 < nums[i]:
            counter += j-(m+1)+1
            i-=1
        else:
            j-=1
    sortray = []
    i = l
    j = m+1
    while i<=m and j<=h:
        if nums[i]<nums[j]:
            sortray.append(nums[i])
            i+=1
        else:
            sortray.append(nums[j])
            j+=1
    while i<=m:
        sortray.append(nums[i])
        i+=1
    while j<=h:
        sortray.append(nums[j])
        j+=1

    for i in range(l, h+1):
        nums[i] = sortray[i-l]
    return counter


def mergerSorter(l, h, nums):
    if l>=h:
        return 0
    mid = (l+h) // 2
    ini = mergerSorter(l, mid, nums)
    fin = mergerSorter(mid+1, h, nums)
    curr = merge(l,mid,h,nums)
    return ini + fin + curr

class Solution:
    def reversePairs(self, nums: List[int]) -> int:
        return mergerSorter(0, len(nums)-1, nums)
