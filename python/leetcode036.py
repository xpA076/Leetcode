class Solution(object):
    def isValidSudoku(self, board):
        """
        :type board: List[List[str]]
        :rtype: bool
        """
        for row in range(9):
            for col in range(9):
                if board[row][col] == '.':
                    continue
                if isValid(board, row, col, board[row][col]):
                    continue
                return False
        return True

def isValid(board, row, col, val):
    # is row valid
    for i in range(9):
        if i == col:
            continue
        if board[row][i] == val:
            return False
    # is col valid
    for i in range(9):
        if i == row:
            continue
        if board[i][col] == val:
            return False
    # is box valid
    for i in range(3):
        for j in range(3):
            if i == row % 3 and j == col % 3:
                continue
            if board[row - row % 3 + i][col - col % 3 + j] == val:
                return False
    return True
