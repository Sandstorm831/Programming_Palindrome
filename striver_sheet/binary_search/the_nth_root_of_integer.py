# GFG solution
# Link : https://www.geeksforgeeks.org/problems/find-nth-root-of-m5843/1


class Solution:
	def nthRoot(self, n: int, m: int) -> int:
		# Code here
		ini = 1
		fin = m
		while fin - ini >= 5:
		    mid = (fin + ini) / 2
		    x = pow(mid, n)
		    if x >= m:
		        fin =  math.ceil(mid)
		    else:
		        ini = math.floor(mid)

	    for i in range(ini, fin+1):
	        if pow(i, n) == m:
	            return i
	    return -1
