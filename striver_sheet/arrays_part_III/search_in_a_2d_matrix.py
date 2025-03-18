# Leetcode solution
# Link : https://leetcode.com/problems/search-a-2d-matrix/
# approach : first binary search to find column, next binary search to find row -> it is O(log(m) x log(n)),
#            can be reduced further to O(log(m) + log(n)), by assuming it a 1d list, and applying binary-search
#            in a smart way on it without actually flattening the array.

def rowFinder(row, ini, fin, target):
    if ini > fin:
        return False
    elif ini == fin:
        return row[ini] == target
    else:
        mid = (ini + fin)//2
        a = rowFinder(row, ini, mid, target)
        b = rowFinder(row, mid+1, fin, target)
        return a|b

def Finder(matrix, ini, fin, target):
    if ini > fin:
        return False
    elif target < matrix[ini][0] or target > matrix[fin][len(matrix[fin])-1]:
        return False
    elif ini == fin:
        return rowFinder(matrix[ini], 0, len(matrix[ini])-1, target)
    else:
        mid = (ini + fin)//2
        a = Finder(matrix, ini, mid, target)
        b = Finder(matrix, mid+1, fin, target)
        return a|b

class Solution:

    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        x = Finder(matrix, 0, len(matrix)-1, target)
        return x