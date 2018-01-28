class Solution:

    def solveSudoku(self, board):
        """
        :type board: List[List[str]]
        :rtype: void Do not return anything, modify board in-place instead.
        """
        i = 0
        while i != 81 and "." != board[i // 9][i % 9]:
            i += 1
        solve(board, i)


def solve(board, depth):
    if depth == 81:
        return True
    solve_next = depth + 1
    while solve_next != 81 and board[solve_next // 9][solve_next % 9] != '.':
        solve_next += 1
    for i in range(9):
        if isValid(board, depth // 9, depth % 9, str(i + 1)):
            board[depth // 9][depth % 9] = str(i + 1);
            if solve(board, solve_next):
                return True
            board[depth // 9][depth % 9] = '.'


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
