# [64] Minimum Path Sum

**[array, dynamic-programming, matrix]**

### Statement

Given a `m x n` `grid` filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

**Note:** You can only move either down or right at any point in time.


**Example 1:**
![](https://assets.leetcode.com/uploads/2020/11/05/minpath.jpg)

```

**Input:** grid = [[1,3,1],[1,5,1],[4,2,1]]
**Output:** 7
**Explanation:** Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.

```

**Example 2:**

```

**Input:** grid = [[1,2,3],[4,5,6]]
**Output:** 12

```

**Constraints:**
* `m == grid.length`
* `n == grid[i].length`
* `1 <= m, n <= 200`
* `0 <= grid[i][j] <= 100`


<br>

### Hints

None

<br>

### Solution

```cpp
class Solution {
  public:
    int minPathSum (vector <vector <int>>& grid) {
      int m = grid.size();
      int n = grid[0].size();
      
      for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
          if (i and j)
            grid[i][j] += std::min(grid[i - 1][j], grid[i][j - 1]);
          else if (i)
            grid[i][j] += grid[i - 1][j];
          else if (j)
            grid[i][j] += grid[i][j - 1];
        }
      }
      
      return grid[m - 1][n - 1];
    }
};
```

<br>

### Statistics

- total accepted: 719993
- total submissions: 1207894
- acceptance rate: 59.6%
- likes: 7498
- dislikes: 104

<br>

### Similar Problems

- [Unique Paths](https://leetcode.com/problems/unique-paths) (Medium)
- [Dungeon Game](https://leetcode.com/problems/dungeon-game) (Hard)
- [Cherry Pickup](https://leetcode.com/problems/cherry-pickup) (Hard)
- [Maximum Number of Points with Cost](https://leetcode.com/problems/maximum-number-of-points-with-cost) (Medium)
- [Minimum Cost Homecoming of a Robot in a Grid](https://leetcode.com/problems/minimum-cost-homecoming-of-a-robot-in-a-grid) (Medium)
