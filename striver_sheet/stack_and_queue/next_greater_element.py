# Leetcode solution
# Link : https://leetcode.com/problems/next-greater-element-i/

class Solution:
    def nextGreaterElement(self, nums1: List[int], nums2: List[int]) -> List[int]:
        ans = {}
        st = []
        for i in range(len(nums2)-1, -1, -1):
            if len(st) == 0:
                ans[nums2[i]] = -1
                st.append(nums2[i])
                continue
            elif st[-1] > nums2[i]:
                ans[nums2[i]] = st[-1]
                st.append(nums2[i])
                continue
            while len(st) > 0 and st[-1] <= nums2[i]:
                st.pop()
                if len(st) > 0 and st[-1] > nums2[i]:
                    ans[nums2[i]] = st[-1]
                    st.append(nums2[i])
                    break
                elif len(st) == 0:
                    ans[nums2[i]] = -1
                    st.append(nums2[i])
                    break
        minans = []
        for i in range(len(nums1)):
            minans.append(ans[nums1[i]])
        return minans
