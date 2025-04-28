# Leetcode solution
# Link : https://leetcode.com/problems/n-queens/

def assigner(board, row, col, rpc):
    lst = list(board[row])
    lst[col] = rpc
    alt_str = ''.join(lst)
    board[row] = alt_str

def checker(col, row, board):
    limit = len(board)
    orow = row
    ocol = col

    # Vertical check
    for r in range(row, limit):
        if board[r][ocol] == 'Q':
            return False
    for r in range(row, -1, -1):
        if board[r][ocol] == 'Q':
            return False

    # top-left to bottom-right diagonal check
    r, c = orow, ocol
    while r<limit and c < limit and r >= 0 and c>= 0:
        if board[r][c] == 'Q':
            return False
        r+=1
        c+=1
    r, c = orow, ocol
    while r<limit and c < limit and r >= 0 and c>= 0:
        if board[r][c] == 'Q':
            return False
        r-=1
        c-=1


    # top-right to bottom-left diagonal check
    r, c = orow, ocol
    while r<limit and c < limit and r >= 0 and c>= 0:
        if board[r][c] == 'Q':
            return False
        r-=1
        c+=1
    r, c = orow, ocol
    while r<limit and c < limit and r >= 0 and c>= 0:
        if board[r][c] == 'Q':
            return False
        r+=1
        c-=1

    return True

def recursor(index, board, ans_array):
    # print(board)
    if index >= len(board):
        ans_array.append(board[:])
        return
    for i in range(len(board)):
        if checker(i, index, board):
            assigner(board, index, i, 'Q')
            # board[index][i] = 'Q'
            recursor(index+1, board, ans_array)
            assigner(board, index, i, '.')
            # board[index][i] = '.'


class Solution:
    def solveNQueens(self, n: int) -> List[List[str]]:
        if n == 1:
            return [["Q"]]
        elif n == 2 or n == 3:
            return []
        ans_array = []
        board = ["."*n for i in range(n)]
        index = 0
        recursor(index, board, ans_array)
        return ans_array
