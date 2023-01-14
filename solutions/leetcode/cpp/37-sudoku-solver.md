# [37] Sudoku Solver

**[array, backtracking, matrix]**

### Statement

Write a program to solve a Sudoku puzzle by filling the empty cells.

A sudoku solution must satisfy **all of the following rules**:

1. Each of the digits `1-9` must occur exactly once in each row.
2. Each of the digits `1-9` must occur exactly once in each column.
3. Each of the digits `1-9` must occur exactly once in each of the 9 `3x3` sub-boxes of the grid.



The `'.'` character indicates empty cells.


**Example 1:**
![](https://upload.wikimedia.org/wikipedia/commons/thumb/f/ff/Sudoku-by-L2G-20050714.svg/250px-Sudoku-by-L2G-20050714.svg.png)

```

**Input:** board = [["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]
**Output:** [["5","3","4","6","7","8","9","1","2"],["6","7","2","1","9","5","3","4","8"],["1","9","8","3","4","2","5","6","7"],["8","5","9","7","6","1","4","2","3"],["4","2","6","8","5","3","7","9","1"],["7","1","3","9","2","4","8","5","6"],["9","6","1","5","3","7","2","8","4"],["2","8","7","4","1","9","6","3","5"],["3","4","5","2","8","6","1","7","9"]]
**Explanation:**The input board is shown above and the only valid solution is shown below:

![](https://upload.wikimedia.org/wikipedia/commons/thumb/3/31/Sudoku-by-L2G-20050714_solution.svg/250px-Sudoku-by-L2G-20050714_solution.svg.png)

```

**Constraints:**
* `board.length == 9`
* `board[i].length == 9`
* `board[i][j]` is a digit or `'.'`.
* It is **guaranteed** that the input board has only one solution.


<br>

### Hints

None

<br>

### Solution

```cpp
class Solution {
  public:
    void solveSudoku (vector <vector <char>>& board) {
      auto is_placeable = [&] (int x, int y, char c) -> bool {
        for (int i = 0; i < 9; ++i) {
          if (board[x][i] != '.' and board[x][i] == c)
            return false;
          if (board[i][y] != '.' and board[i][y] == c)
            return false;
          if (board[x / 3 * 3 + i / 3][y / 3 * 3 + i % 3] != '.' and
              board[x / 3 * 3 + i / 3][y / 3 * 3 + i % 3] == c)
            return false;
        }
        return true;
      };

      auto solver = [&] (auto self) -> bool {
        for (int i = 0; i < 9; ++i) {
          for (int j = 0; j < 9; ++j) {
            if (board[i][j] != '.')
              continue;
            
            for (char c = '1'; c <= '9'; ++c) {
              if (is_placeable(i, j, c)) {
                board[i][j] = c;
                if (self(self))
                  return true;
                board[i][j] = '.';
              }
            }

            return false;
          }
        }

        return true;
      };

      solver(solver);
    }
};
```

<br>

### Statistics

- total accepted: 429228
- total submissions: 750259
- acceptance rate: 57.2%
- likes: 7203
- dislikes: 193

<br>

### Similar Problems

- [Valid Sudoku](https://leetcode.com/problems/valid-sudoku) (Medium)
- [Unique Paths III](https://leetcode.com/problems/unique-paths-iii) (Hard)
