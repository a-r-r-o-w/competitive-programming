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

```cpp
class Solution {
  public:
    bool isValidSudoku (vector <vector <char>>& board) {
      int n = 9;
      std::vector <bool> filled (n);
      
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
          if (board[i][j] == '.')
            continue;
          
          int index = board[i][j] - '0' - 1;
          
          if (filled[index])
            return false;   
          
          filled[index] = true;
        }
        
        for (int j = 0; j < n; ++j)
          filled[j] = false;
      }
  
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
          if (board[j][i] == '.')
            continue;
          
          int index = board[j][i] - '0' - 1;
          
          if (filled[index])
            return false;
          
          filled[index] = true;
        }
        
        for (int j = 0; j < n; ++j)
          filled[j] = false;
      }
      
      for (int i = 0; i < n; i += 3) {
        for (int j = 0; j < n; j += 3) {
          for (int k = 0; k < 3; ++k) {
            for (int l = 0; l < 3; ++l) {
              if (board[i + k][j + l] == '.')
                continue;
              
              int index = board[i + k][j + l] - '0' - 1;
              
              if (filled[index])
                return false;
              
              filled[index] = true;
            }
          }
          
          for (int k = 0; k < n; ++k)
            filled[k] = false;
        }
      }
      
      return true;
    }
};
```

<br>

### Statistics

- total accepted: 858258
- total submissions: 1521490
- acceptance rate: 56.4%
- likes: 6298
- dislikes: 791

<br>

### Similar Problems

- [Sudoku Solver](https://leetcode.com/problems/sudoku-solver) (Hard)
- [Check if Every Row and Column Contains All Numbers](https://leetcode.com/problems/check-if-every-row-and-column-contains-all-numbers) (Easy)
