# [36] Valid Sudoku

**[array, hash-table, matrix]**

### Statement

Determine if a`9 x 9` Sudoku boardis valid.Only the filled cells need to be validated**according to the following rules**:

1. Each rowmust contain thedigits`1-9` without repetition.
2. Each column must contain the digits`1-9`without repetition.
3. Each of the nine`3 x 3` sub-boxes of the grid must contain the digits`1-9`without repetition.


**Note:**
* A Sudoku board (partially filled) could be valid but is not necessarily solvable.
* Only the filled cells need to be validated according to the mentionedrules.


**Example 1:**
![](https://upload.wikimedia.org/wikipedia/commons/thumb/f/ff/Sudoku-by-L2G-20050714.svg/250px-Sudoku-by-L2G-20050714.svg.png)

```

**Input:** board = 
[["5","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
**Output:** true

```

**Example 2:**

```

**Input:** board = 
[["8","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
**Output:** false
**Explanation:** Same as Example 1, except with the **5** in the top left corner being modified to **8**. Since there are two 8's in the top left 3x3 sub-box, it is invalid.

```

**Constraints:**
* `board.length == 9`
* `board[i].length == 9`
* `board[i][j]` is a digit `1-9` or `'.'`.


<br>

### Hints

None

<br>

### Solution

```py
class Solution:
    def isValidSudoku (self, board: List[List[str]]) -> bool:
      for row in board:
        r = [i for i in row if i != '.']
        if len(set(r)) != len(r):
          return False
      
      for col in range(9):
        c = [i[col] for i in board if i[col] != '.']
        if len(set(c)) != len(c):
          return False
      
      for row in range(0, 9, 3):
        for col in range(0, 9, 3):
          b = [board[r][c] for r in range(row, row + 3) for c in range(col, col + 3) if board[r][c] != '.']
          if len(set(b)) != len(b):
            return False
      
      return True
```

<br>

### Statistics

- total accepted: 927869
- total submissions: 1628251
- acceptance rate: 57.0%
- likes: 6951
- dislikes: 819

<br>

### Similar Problems

- [Sudoku Solver](https://leetcode.com/problems/sudoku-solver) (Hard)
- [Check if Every Row and Column Contains All Numbers](https://leetcode.com/problems/check-if-every-row-and-column-contains-all-numbers) (Easy)
