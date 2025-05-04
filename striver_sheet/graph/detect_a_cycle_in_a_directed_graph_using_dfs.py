# Leetcode solution
# Link : https://leetcode.com/problems/course-schedule/submissions/1625145421/

from collections import deque

def makegraph(cons, num):
    graph = [[] for i in range(num)]
    for i in cons:
        graph[i[0]].append(i[1])
    return graph

def dfs(graph, node, vis, tempvis, ans):
    if ans[0]:
        return
    vis[node] = True
    tempvis[node] = True
    for nbs in graph[node]:
        if ans[0]:
            return
        elif not vis[nbs]:
            dfs(graph, nbs, vis, tempvis, ans)
        elif tempvis[nbs]:
            ans[0] = True
            return
    tempvis[node] = False

class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        visited = [False for i in range(numCourses)]
        graph = makegraph(prerequisites, numCourses)
        cycleExist = [False]
        tempVis = [False for i in range(numCourses)]
        # print(graph)
        for i in range(numCourses):
            if visited[i] == 0:
                dfs(graph, i, visited, tempVis, cycleExist)
                if cycleExist[0]:
                    return False
        return True
