# Leetcode solution
# Link : https://leetcode.com/problems/powx-n/

def recursor(x, n):
    if n == 0:
        return 1
    elif n == 1:
        return x
    elif x == 0:
        return 0
    elif n%2 == 1:
        return x*recursor( x, n-1)
    elif n%2 == 0:
        a = recursor(x, n//2)
        return a*a

class Solution:
    def myPow(self, x: float, n: int) -> float:
        if n < 0:
            return 1 / recursor( x, -n)
        return recursor(x, n)