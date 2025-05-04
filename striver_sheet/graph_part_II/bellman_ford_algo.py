# GFG Solution
# Link : https://www.geeksforgeeks.org/problems/distance-from-the-source-bellman-ford-algorithm/1

#User function Template for python3

class Solution:
    def bellmanFord(self, V, edges, src):
        #code here
        dist = [int(1e8) for i in range(V)]
        dist[src] = 0
        for i in range(V-1):
            for edge in edges:
                if dist[edge[0]] != int(1e8) and dist[edge[1]] > dist[edge[0]] + edge[2]:
                    dist[edge[1]] = dist[edge[0]] + edge[2]
        for edge in edges:
            if dist[edge[0]] != int(1e8) and dist[edge[1]] > dist[edge[0]] + edge[2]:
                return [-1]
        return dist
