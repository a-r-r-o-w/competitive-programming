# [2684] Maximum Number of Moves in a Grid



### Statement

You are given a **0-indexed** `m x n` matrix `grid` consisting of **positive** integers.

You can start at **any** cell in the first column of the matrix, and traverse the grid in the following way:

* From a cell `(row, col)`, you can move to any of the cells: `(row - 1, col + 1)`, `(row, col + 1)` and `(row + 1, col + 1)` such that the value of the cell you move to, should be **strictly** bigger than the value of the current cell.



Return *the **maximum** number of **moves** that you can perform.*
**Example 1:**
![](https://assets.leetcode.com/uploads/2023/04/11/yetgriddrawio-10.png)

```

**Input:** grid = [[2,4,3,5],[5,4,9,3],[3,4,2,11],[10,9,13,15]]
**Output:** 3
**Explanation:** We can start at the cell (0, 0) and make the following moves:
- (0, 0) -> (0, 1).
- (0, 1) -> (1, 2).
- (1, 2) -> (2, 3).
It can be shown that it is the maximum number of moves that can be made.
```

**Example 2:**

```

![](https://assets.leetcode.com/uploads/2023/04/12/yetgrid4drawio.png)
**Input:** grid = [[3,2,4],[2,1,9],[1,1,7]]
**Output:** 0
**Explanation:** Starting from any cell in the first column we cannot perform any moves.

```

**Constraints:**
* `m == grid.length`
* `n == grid[i].length`
* `2 <= m, n <= 1000`
* `4 <= m * n <= 10^5`
* `1 <= grid[i][j] <= 10^6`


<br />

### Hints

- Consider using dynamic programming to find the maximum number of moves that can be made from each cell.
- The final answer will be the maximum value in cells of the first column.

<br />

### Solution

```cpp
class Solution {
  public:
    int maxMoves (vector <vector <int>>& grid) {
      int n = grid.size(), m = grid.front().size(), ans = 0;
      std::vector <std::vector <int>> dp (n, std::vector <int> (m, -1));
      
      auto dfs = [&] (auto self, int i, int j) -> int {
        if (dp[i][j] != -1)
          return dp[i][j];
        int max = 0;
        for (int k: {-1, 0, 1}) {
          int ni = i + k, nj = j + 1;
          if (ni >= 0 and ni < n and nj < m and grid[i][j] < grid[ni][nj])
            max = std::max(max, self(self, ni, nj) + 1);
        }
        return dp[i][j] = max;
      };
      
      for (int i = 0; i < n; ++i)
        ans = std::max(ans, dfs(dfs, i, 0));
      
      return ans;
    }
};
```

<br />

### Statistics

- total accepted: 11407
- total submissions: 25731
- acceptance rate: 44.3%
- likes: 192
- dislikes: 3

<br />

### Similar Problems

None
