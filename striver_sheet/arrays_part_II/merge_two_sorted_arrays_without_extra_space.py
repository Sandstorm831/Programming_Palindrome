# Leetcode Solution 
# Link : https://leetcode.com/problems/merge-sorted-array/

class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """

        # Slightly more efficient solution 
        # Start from the rightmost, of nums1 array and place the biggest element to the rightmost index, reduxing it by after every addition.
        pn1 = m-1
        pn2 = n-1

        for i in range(n+m-1, -1, -1):
            if pn1 < 0:
                nums1[i] = nums2[pn2]
                pn2-=1
                continue
            elif pn2 < 0:
                nums1[i] = nums1[pn1]
                pn1-=1
                continue
            if nums1[pn1] >= nums2[pn2]:
                nums1[i] = nums1[pn1]
                pn1-=1
            elif nums1[pn1] < nums2[pn2]:
                nums1[i] = nums2[pn2]
                pn2-=1

        # Normal solution
        # In this, I shift nums 1 non-zero elements to the maximum right, then, iterate through the arrays placing each element in sorted order 1 by 1
        pn1 = n
        pn2 = 0
        for i in range(m):
            nums1[n+m-1-i] = nums1[m-1-i]

        for i in range(len(nums1)):
            if pn1 >= n+m:
                nums1[i] = nums2[pn2]
                pn2+=1
                continue
            elif pn2 >= n:
                nums1[i] = nums1[pn1]
                pn1+=1
                continue
            if nums1[pn1] <= nums2[pn2]:
                nums1[i] = nums1[pn1]
                pn1+=1
            elif nums1[pn1] > nums2[pn2]:
                nums1[i] = nums2[pn2]
                pn2+=1