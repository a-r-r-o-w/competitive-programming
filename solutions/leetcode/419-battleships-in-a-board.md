# [419] Battleships in a Board

**[array, depth-first-search, matrix]**

### Statement

Given an `m x n` matrix `board` where each cell is a battleship `'X'` or empty `'.'`, return *the number of the **battleships** on* `board`.

**Battleships** can only be placed horizontally or vertically on `board`. In other words, they can only be made of the shape `1 x k` (`1` row, `k` columns) or `k x 1` (`k` rows, `1` column), where `k` can be of any size. At least one horizontal or vertical cell separates between two battleships (i.e., there are no adjacent battleships).


**Example 1:**
![](https://assets.leetcode.com/uploads/2021/04/10/battelship-grid.jpg)

```

**Input:** board = [["X",".",".","X"],[".",".",".","X"],[".",".",".","X"]]
**Output:** 2

```

**Example 2:**

```

**Input:** board = [["."]]
**Output:** 0

```

**Constraints:**
* `m == board.length`
* `n == board[i].length`
* `1 <= m, n <= 200`
* `board[i][j]` is either `'.'` or `'X'`.


**Follow up:** Could you do it in one-pass, using only `O(1)` extra memory and without modifying the values `board`?

<br>

### Hints

None

<br>

### Solution

```cpp
class Solution {
  public:
    Solution () {
      std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);
    }
  
    int countBattleships (vector <vector <char>>& board) {
      int m = board.size();
      int n = board.front().size();
      int count = 0;
      
      for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
          if (board[i][j] == 'X') {
            if (
              (i > 0 and board[i - 1][j] == 'X') or
              (j > 0 and board[i][j - 1] == 'X')
            )
              continue;
            ++count;
          }
        }
      }
      
      return count;
    }
};
```

<br>

### Statistics

- total accepted: 159771
- total submissions: 215176
- acceptance rate: 74.3%
- likes: 1645
- dislikes: 792

<br>

### Similar Problems

None
