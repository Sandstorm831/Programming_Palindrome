# Leetcode Solution 
# Link : https://leetcode.com/problems/rotate-image/

# Transpose the matrix and reverse each of the row
class Solution:

    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        # Trnaspose the matrix and reverse each row
        for i in range(len(matrix)):
            for j in range(i+1,len(matrix)):
                temp = matrix[i][j]
                matrix[i][j] = matrix[j][i]
                matrix[j][i] = temp

        for i in range(len(matrix)):
            matrix[i].reverse()

# apply coordinate transformation : for 90 degree clockwise rotation : i,j -> j,n-1-i

def nextIndex(i,j, n):
    return (j, n-1-i)
    
class Solution:

    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        store = set()
        for i in range(len(matrix)):
            for j in range(len(matrix[i])):
                if (i,j) not in store:
                    store.add((i,j))
                    ini = (i,j)
                    curr_num = matrix[i][j]
                    curr = nextIndex(i,j,len(matrix))
                    while curr != ini : 
                        temp = matrix[curr[0]][curr[1]]
                        matrix[curr[0]][curr[1]] = curr_num
                        curr_num = temp
                        store.add((curr[0], curr[1]))
                        curr = nextIndex(curr[0], curr[1], len(matrix))
                    matrix[curr[0]][curr[1]] = curr_num