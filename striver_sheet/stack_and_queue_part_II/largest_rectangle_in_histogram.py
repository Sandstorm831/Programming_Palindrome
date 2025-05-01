# Leetcode solution
# Link : https://leetcode.com/problems/largest-rectangle-in-histogram/

# most optimal solution
class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        st = [-1]
        maxer = 0
        for i in range(len(heights)):
            while st[-1] != -1 and heights[i] <= heights[st[-1]]:
                hi = heights[st.pop()]
                wi = i - st[-1] -1
                maxer = max(maxer, hi*wi)
            st.append(i)
        while st[-1]!=-1:
            hi = heights[st.pop()]
            wi = len(heights) - st[-1] - 1
            maxer = max(maxer, wi*hi)
        return maxer

# slightly less optimal solution
class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        right = [0 for i in range(len(heights))]
        left = [0 for i in range(len(heights))]
        st = []
        for h in range(len(heights)):
            if len(st) == 0:
                st.append((heights[h], h))
            else:
                while len(st) > 0 and st[-1][0] > heights[h]:
                    tup = st.pop()
                    right[tup[1]] = h-tup[1]
                if len(st) > 0 and st[-1][0] <= heights[h]:
                    st.append((heights[h], h))
                if len(st) == 0:
                    st.append((heights[h], h))
        while len(st) > 0:
            tup = st.pop()
            right[tup[1]] = len(heights)-tup[1]

        st = []
        for h in range(len(heights)-1, -1, -1):
            if len(st) == 0:
                st.append((heights[h], h))
            else:
                while len(st) > 0 and st[-1][0] > heights[h]:
                    tup = st.pop()
                    left[tup[1]] = abs(h-tup[1])
                if len(st) > 0 and st[-1][0] <= heights[h]:
                    st.append((heights[h], h))
                if len(st) == 0:
                    st.append((heights[h], h))

        while len(st) > 0:
            tup = st.pop()
            left[tup[1]] = 1+tup[1]

        maxer = 0
        for i in range(len(right)):
            maxer = max(maxer, (right[i] + left[i] -1) * heights[i])
        return maxer
