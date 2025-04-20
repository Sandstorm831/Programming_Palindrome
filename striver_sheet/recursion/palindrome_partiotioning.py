# Leetcode solution
# Link : https://leetcode.com/problems/palindrome-partitioning/

def isPalindrom(ts):
    i = 0
    j = len(ts)-1
    while i <= j:
        if ts[i] == ts[j]:
            i+=1
            j-=1
        else:
            return False
    return True
def recursor(s, ans, temp, index):
    if index >= len(s):
        ans.append(temp[:])
        return
    for curr in range(index, len(s)):
        curr_s_p = isPalindrom(s[index: curr+1])

        if curr_s_p:
            temp.append(s[index:curr+1])
            recursor(s, ans, temp, curr+1)
            temp.pop()

class Solution:
    def partition(self, s: str) -> List[List[str]]:
        ans = []
        temp = []
        recursor(s, ans, temp, 0)
        return ans
