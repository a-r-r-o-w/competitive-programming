# [2328] Number of Increasing Paths in a Grid

**[array, dynamic-programming, depth-first-search, breadth-first-search, graph, topological-sort, memoization, matrix]**

### Statement

You are given an `m x n` integer matrix `grid`, where you can move from a cell to any adjacent cell in all `4` directions.

Return *the number of **strictly** **increasing** paths in the grid such that you can start from **any** cell and end at **any** cell.* Since the answer may be very large, return it **modulo** `10^9 + 7`.

Two paths are considered different if they do not have exactly the same sequence of visited cells.


**Example 1:**
![](https://assets.leetcode.com/uploads/2022/05/10/griddrawio-4.png)

```

**Input:** grid = [[1,1],[3,4]]
**Output:** 8
**Explanation:** The strictly increasing paths are:
- Paths with length 1: [1], [1], [3], [4].
- Paths with length 2: [1 -> 3], [1 -> 4], [3 -> 4].
- Paths with length 3: [1 -> 3 -> 4].
The total number of paths is 4 + 3 + 1 = 8.

```

**Example 2:**

```

**Input:** grid = [[1],[2]]
**Output:** 3
**Explanation:** The strictly increasing paths are:
- Paths with length 1: [1], [2].
- Paths with length 2: [1 -> 2].
The total number of paths is 2 + 1 = 3.

```

**Constraints:**
* `m == grid.length`
* `n == grid[i].length`
* `1 <= m, n <= 1000`
* `1 <= m * n <= 10^5`
* `1 <= grid[i][j] <= 10^5`


<br />

### Hints

- How can you calculate the number of increasing paths that start from a cell (i, j)? Think about dynamic programming.
- Define f(i, j) as the number of increasing paths starting from cell (i, j). Try to find how f(i, j) is related to each of f(i, j+1), f(i, j-1), f(i+1, j) and f(i-1, j).

<br />

### Solution

```cpp
class Solution {
  public:
    int countPaths (vector <vector <int>>& grid) {
      const int mod = 1000000007;
      int m = grid.size(), n = grid.front().size();
      std::vector <int> dx = {+1, -1, 0, 0};
      std::vector <int> dy = {0, 0, +1, -1};
      std::vector dp (m, std::vector <int> (n, -1));

      auto dfs = [&] (auto self, int i, int j) -> int {
        if (dp[i][j] != -1)
          return dp[i][j];
        int64_t ans = 1;
        for (int k = 0; k < 4; ++k) {
          int ni = i + dx[k], nj = j + dy[k];
          if (ni < 0 or nj < 0 or ni >= m or nj >= n or grid[ni][nj] <= grid[i][j])
            continue;
          ans = (ans + self(self, ni, nj)) % mod;
        }
        return dp[i][j] = ans;
      };

      int64_t ans = 0;
      for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j)
          ans = (ans + dfs(dfs, i, j)) % mod;
      }
      return ans;
    }
};
```

<br />

### Statistics

- total accepted: 33716
- total submissions: 60469
- acceptance rate: 55.8%
- likes: 1205
- dislikes: 27

<br />

### Similar Problems

- [Longest Increasing Path in a Matrix](https://leetcode.com/problems/longest-increasing-path-in-a-matrix) (Hard)
- [All Paths From Source to Target](https://leetcode.com/problems/all-paths-from-source-to-target) (Medium)
- [Maximum Strictly Increasing Cells in a Matrix](https://leetcode.com/problems/maximum-strictly-increasing-cells-in-a-matrix) (Hard)
