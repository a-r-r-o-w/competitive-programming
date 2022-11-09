# [51] N-Queens

**[array, backtracking]**

### Statement

The **n-queens** puzzle is the problem of placing `n` queens on an `n x n` chessboard such that no two queens attack each other.

Given an integer `n`, return *all distinct solutions to the **n-queens puzzle***. You may return the answer in **any order**.

Each solution contains a distinct board configuration of the n-queens' placement, where `'Q'` and `'.'` both indicate a queen and an empty space, respectively.


**Example 1:**
![](https://assets.leetcode.com/uploads/2020/11/13/queens.jpg)

```

**Input:** n = 4
**Output:** [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
**Explanation:** There exist two distinct solutions to the 4-queens puzzle as shown above

```

**Example 2:**

```

**Input:** n = 1
**Output:** [["Q"]]

```

**Constraints:**
* `1 <= n <= 9`


<br>

### Hints

None

<br>

### Solution

```cpp
class Solution {
  public:
    vector <vector <string>> solveNQueens (int n) {
      int col = 0, diag1 = 0, diag2 = 0;
      std::vector <std::vector <std::string>> solutions;
      std::vector <std::string> grid (n, std::string(n, '.'));
      
      auto dfs = [&] (auto self, int row) -> void {
        if (row == n) {
          solutions.push_back(grid);
          return;
        }
        
        for (int c = 0; c < n; ++c) {
          int d1 = row + c, d2 = row + n - c - 1;
          
          if ((col & (1 << c)) or (diag1 & (1 << d1)) or (diag2 & (1 << d2)))
            continue;
          
          col ^= 1 << c;
          diag1 ^= 1 << d1;
          diag2 ^= 1 << d2;
          grid[row][c] = 'Q';
          
          self(self, row + 1);
          
          grid[row][c] = '.';
          col ^= 1 << c;
          diag1 ^= 1 << d1;
          diag2 ^= 1 << d2;
        }
      };
      
      dfs(dfs, 0);
      
      return solutions;
    }
};
```

<br>

### Statistics

- total accepted: 486771
- total submissions: 772612
- acceptance rate: 63.0%
- likes: 8683
- dislikes: 192

<br>

### Similar Problems

- [N-Queens II](https://leetcode.com/problems/n-queens-ii) (Hard)
- [Grid Illumination](https://leetcode.com/problems/grid-illumination) (Hard)
