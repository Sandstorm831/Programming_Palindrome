# Leetcode solution
# Link : https://leetcode.com/problems/longest-substring-without-repeating-characters/
#
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        x = [0 for i in range(128)]
        i = 0
        j = 0
        l = 0
        maxer = 0
        while j<len(s):
            if x[ord(s[j])] > 0:
                x[ord(s[i])]-=1
                i+=1
                l -= 1
            elif x[ord(s[j])] == 0:
                x[ord(s[j])] += 1
                l += 1
                maxer = max(maxer, l)
                j+=1
        return maxer
