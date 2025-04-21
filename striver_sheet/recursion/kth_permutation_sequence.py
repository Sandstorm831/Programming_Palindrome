# Leetcode solution
# Link : https://leetcode.com/problems/permutation-sequence/

import math

class Solution:
    def getPermutation(self, n: int, k: int) -> str:
        origk = k
        a = [False for i in range(n)]
        if n == 1:
            return "1"
        elif n == 2:
            if k == 1: return "12"
            else:
                return "21"
        else:
            num = ""
            for i in range(n-1, -1, -1):
                if k == 0:
                    k = math.factorial(i+1) # i.e. old or previous iteration factorial
                fct = math.factorial(i)
                cl = math.ceil(k/fct)
                for j in range(len(a)):
                    if not a[j]:
                        cl -= 1
                        if cl == 0:
                            a[j] = True
                            num += str(j+1)
                            break

                cr = k%fct
                k = cr
            for j in range(len(a)):
                if not a[j]:
                    a[j] = True
                    num += str(j+1)
                    break

            return num
