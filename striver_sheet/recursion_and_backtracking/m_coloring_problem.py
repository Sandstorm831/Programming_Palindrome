# Leetcode solution
# Link : https://www.geeksforgeeks.org/problems/m-coloring-problem-1587115620/1

# User function Template for python3

def isSafe(graph, c, colors, node):
    for i in range(len(graph[node])):
        if c == colors[graph[node][i]]:
            return False
    return True

def recursor(graph, colors, v, m, node):
    # print(node)
    if node >= v:
        return True
    for i in range(1,m+1):
        if isSafe(graph, i, colors, node):
            # print("hello")
            colors[node] = i
            if recursor(graph, colors, v, m, node+1):
                return True
            colors[node] = 0
    return False



class Solution:
    def graphColoring(self, v, edges, m):
        # code here
        graph = [set() for i in range(v)]

        for edge in edges:
            # print(edge)
            graph[edge[0]].add(edge[1])
            graph[edge[1]].add(edge[0])
            # print(graph)
            # print("-----------------")

        for i in range(len(graph)):
            graph[i] = list(graph[i])

        colors = [0 for i in range(v)]

        return recursor(graph, colors, v, m , 0)
