# GFG Solution
# Link : https://www.geeksforgeeks.org/problems/shortest-path-in-weighted-undirected-graph/1

#User function Template for python3
import heapq
from typing import List

def grapher(edges, nodes):
    x = [[] for i in range(nodes+1)]
    for edge in edges:
        x[edge[0]].append((edge[1], edge[2]))
        x[edge[1]].append((edge[0], edge[2]))
    return x

class Solution:
    def shortestPath(self,n:int, m:int, edges:List[List[int]] )->List[int]:
        # code here
        hpq = []
        dist = [1e7 for i in range(n+1)]
        paths = [0 for i in range(n+1)]
        graph = grapher(edges, n)
        heapq.heappush(hpq, (0,1))
        dist[1] = 0
        paths[1] = 1
        while len(hpq) > 0:
            x = heapq.heappop(hpq)
            node = x[1]
            distance = x[0]
            for nbs in graph[node]:
                if dist[nbs[0]] > distance + nbs[1]:
                    dist[nbs[0]] = distance + nbs[1]
                    paths[nbs[0]] = node
                    heapq.heappush(hpq, (dist[nbs[0]], nbs[0]))

        if dist[n] == 1e7:
            return [-1]
        output_arr = []
        noder = n
        while noder != 1:
            output_arr.append(noder)
            noder = paths[noder]
        a = [dist[n]]
        output_arr.append(1)
        output_arr.reverse()
        final = a + output_arr
        # print(final)
        return final
