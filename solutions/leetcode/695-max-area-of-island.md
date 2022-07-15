# [695] Max Area of Island

**[array, depth-first-search, breadth-first-search, union-find, matrix]**

### Statement

You are given an `m x n` binary matrix `grid`. An island is a group of `1`'s (representing land) connected **4-directionally** (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

The **area** of an island is the number of cells with a value `1` in the island.

Return *the maximum **area** of an island in* `grid`. If there is no island, return `0`.


**Example 1:**
![](https://assets.leetcode.com/uploads/2021/05/01/maxarea1-grid.jpg)

```

**Input:** grid = [[0,0,1,0,0,0,0,1,0,0,0,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,1,1,0,1,0,0,0,0,0,0,0,0],[0,1,0,0,1,1,0,0,1,0,1,0,0],[0,1,0,0,1,1,0,0,1,1,1,0,0],[0,0,0,0,0,0,0,0,0,0,1,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,0,0,0,0,0,0,1,1,0,0,0,0]]
**Output:** 6
**Explanation:** The answer is not 11, because the island must be connected 4-directionally.

```

**Example 2:**

```

**Input:** grid = [[0,0,0,0,0,0,0,0]]
**Output:** 0

```

**Constraints:**
* `m == grid.length`
* `n == grid[i].length`
* `1 <= m, n <= 50`
* `grid[i][j]` is either `0` or `1`.


<br>

### Hints

None

<br>

### Solution

```cpp
class Solution {
  public:
    int maxAreaOfIsland (vector <vector <int>> &grid) {
      int m = grid.size();
      int n = grid.front().size();
      std::vector <int> dx = {+1, -1, 0, 0};
      std::vector <int> dy = {0, 0, +1, -1};
      std::vector <std::vector <bool>> visited (m, std::vector <bool> (n));
      int ans = 0;
      
      auto dfs = [&] (auto self, int i, int j, int &count) -> void {
        visited[i][j] = true;
        for (int k = 0; k < 4; ++k) {
          int ni = i + dx[k];
          int nj = j + dy[k];
          
          if (ni >= 0 and nj >= 0 and ni < m and nj < n and not visited[ni][nj] and grid[ni][nj] == 1) {
            count += 1;
            self(self, ni, nj, count);
          }
        }
      };
      
      for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
          if (visited[i][j])
            continue;
          if (grid[i][j] == 0)
            visited[i][j] = true;
          else {
            int count = 1;
            dfs(dfs, i, j, count);
            ans = std::max(ans, count);
          }
        }
      }
      
      return ans;
    }
};
```

<br>

### Statistics

- total accepted: 523402
- total submissions: 741931
- acceptance rate: 70.5%
- likes: 6704
- dislikes: 158

<br>

### Similar Problems

- [Number of Islands](https://leetcode.com/problems/number-of-islands) (Medium)
- [Island Perimeter](https://leetcode.com/problems/island-perimeter) (Easy)
- [Largest Submatrix With Rearrangements](https://leetcode.com/problems/largest-submatrix-with-rearrangements) (Medium)
- [Detonate the Maximum Bombs](https://leetcode.com/problems/detonate-the-maximum-bombs) (Medium)
