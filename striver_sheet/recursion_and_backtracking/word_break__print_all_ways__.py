# GFG solution
# Link : https://www.geeksforgeeks.org/problems/word-break-part-23249/1

def recursor(dictSet, res, s, st, temp):
    if st >= len(s):
        res.append(temp)
    for i in range(st, len(s)):
        wrd = s[st:i+1]
        if wrd in dictSet:
            otemp=temp
            temp += wrd + " "
            recursor(dictSet, res, s, i+1, temp)
            temp = otemp



class Solution:
    def wordBreak(self, dict, s):
        # code here
        dictSet = set(dict)
        res = []
        temp = ""
        recursor(dictSet, res, s, 0, temp)
        return res
