# Leetcode solution
# Link : https://leetcode.com/problems/sudoku-solver/

rowers = [set() for i in range(9)]
colers = [set() for i in range(9)]
blockers = [set() for i in range(9)]

def fill_arrays(board):
    for i in range(9):
        tempr = set()
        tempc = set()
        tempb = set()
        for j in range(9):
            if board[i][j] != '.':
                tempr.add(int(board[i][j]))
            if board[j][i] != ".":
                tempc.add(int(board[j][i]))
            br = 3 * (i//3) + (j%3)
            bc = 3 * (i%3) + (j//3)
            if board[br][bc] != ".":
                tempb.add(int(board[br][bc]))
        for k in range(1,10):
            if k not in tempr:
                rowers[i].add(k)
            if k not in tempc:
                colers[i].add(k)
            if k not in tempb:
                blockers[i].add(k)

def generate_possible_nums(board, row, col):
    s1 = rowers[row]
    s2 = colers[col]
    s3 = blockers[3*(row//3) + col//3]
    sf = s1&s2&s3
    return list(sf)

def adder(row, col, x):
    rowers[row].remove(x)
    colers[col].remove(x)
    blockers[3*(row//3) + col//3].remove(x)

def remover(row, col, x):
    rowers[row].add(x)
    colers[col].add(x)
    blockers[3*(row//3) + col//3].add(x)

def recursor(board, row, col):
    if row >= len(board):
        return True

    elif board[row][col] != '.':
        if col == len(board)-1:
            return recursor(board, row+1, 0)
        else:
            return recursor(board, row, col+1)
    possible_nums = generate_possible_nums(board, row, col)
    for i in range(len(possible_nums)):
        board[row][col] = str(possible_nums[i])
        adder(row, col, possible_nums[i])
        ans = False
        if col == len(board)-1:
            ans = recursor(board, row+1, 0)
        else:
            ans = recursor(board, row, col+1)

        if ans:
            return ans
        else:
            board[row][col] = "."
            remover(row, col, possible_nums[i])
    return False

class Solution:
    def solveSudoku(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        row = 0
        col = 0
        fill_arrays(board)
        recursor(board, row, col)
