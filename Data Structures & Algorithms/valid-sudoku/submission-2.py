class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        n = len(board)
        rows = [set() for _ in range(n)]
        columns = [set() for _ in range(n)]
        squares = [set() for _ in range(n)]
        for i in range(n):
            for j in range(n):
                curr = board[i][j]
                if curr == ".":
                    continue
                currRow, currColumn, currSquare = rows[i], columns[j], squares[3 * (i // 3) + j // 3]
                if curr in currRow or curr in currColumn or curr in currSquare:
                    return False
                currRow.add(curr), currColumn.add(curr), currSquare.add(curr)
        return True