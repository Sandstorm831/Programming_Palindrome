# GFG solution
# Link : https://www.geeksforgeeks.org/problems/rat-in-a-maze-problem/1&selectedLang=python3

mp = {
    "R": [0,1],
    "L": [0, -1],
    "D": [1, 0],
    "U": [-1, 0]
}

def get_possible_directions(maze, x, y):
    temp = ""
    dirs = "RLDU"
    ox = x
    oy = y
    for i in range(len(dirs)):
        tempj = mp[dirs[i]]
        x = ox+tempj[0]
        y = oy+tempj[1]
        if x>=0 and x<len(maze) and y >= 0 and y<len(maze[0]):
            if maze[x][y]==1:
                temp += dirs[i]
    # print(temp)
    return temp

def converto(l):
    temp = ""
    for i in range(len(l)):
        temp+=str(l[i])
    return temp

def recursor(maze, x, y,ans, temp):
    if x == len(maze)-1 and y == len(maze[0])-1:
        ans.append(converto(temp))
    poss = get_possible_directions(maze, x, y)
    for dir in poss:
        temp.append(dir)
        maze[x][y] = 0
        mov = mp[dir]
        recursor(maze, x+mov[0], y+mov[1], ans, temp)
        temp.pop()
        maze[x][y]=1

class Solution:
    # Function to find all possible paths
    def ratInMaze(self, maze):
        # code here
        ans = []
        temp = []
        recursor(maze, 0, 0, ans, temp)
        ans.sort()
        return ans
