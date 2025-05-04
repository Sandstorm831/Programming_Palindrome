# Leetcode solution
# Link :
# I am using toposort algo, if the final toposort array is smaller than number of nodes
# then we say that the graph have an cycle as toposort only applicable to DAGs

from collections import deque

def makegraph(cons, num):
    graph = [[] for i in range(num)]
    for i in cons:
        graph[i[0]].append(i[1])
    return graph


class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        visited = [False for i in range(numCourses)]
        graph = makegraph(prerequisites, numCourses)
        inedges = [0 for i in range(numCourses)]
        for i in range(numCourses):
            for nbs in graph[i]:
                inedges[nbs]+=1
        q = deque()
        for i in range(len(inedges)):
            if inedges[i]==0:
                q.append(i)
        toposort = []
        while len(q) > 0:
            x = q.popleft()
            toposort.append(x)
            for nbs in graph[x]:
                inedges[nbs]-=1
                if inedges[nbs] == 0:
                    q.append(nbs)
        if len(toposort) < numCourses:
            return False
        return True
