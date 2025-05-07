# GFG Solution
# Link : https://www.geeksforgeeks.org/problems/minimum-spanning-tree/1

import heapq
from typing import List
class Solution:

    #Function to find sum of weights of edges of the Minimum Spanning Tree.
    def spanningTree(self, V: int, adj: List[List[int]]) -> int:
        #code here
        vis = [0 for i in range(len(adj))]
        pq = []
        heapq.heappush(pq, [0,0,-1])
        summer = 0
        while len(pq) > 0:
            x = heapq.heappop(pq)
            node = x[1]
            w = x[0]
            if vis[node] == 1:
                continue
            vis[node] = 1
            summer += w
            for e in adj[node]:
                nn = e[0]
                wn = e[1]
                if vis[nn] == 0:
                    heapq.heappush(pq, [wn, nn, node])
        return summer
