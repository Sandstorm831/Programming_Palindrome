# GFG Solution
# Link: https://www.geeksforgeeks.org/problems/implementing-floyd-warshall2042/1

class Solution:
	def floydWarshall(self, dist):
		#Code here
		for k in range(len(dist)):
		    for i in range(len(dist)):
		        for j in range(len(dist)):
		            if dist[i][k] == 1e8 or dist[k][j] == 1e8:
		                continue
		            dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])

        return
