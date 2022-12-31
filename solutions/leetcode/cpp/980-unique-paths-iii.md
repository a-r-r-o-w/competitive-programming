# [980] Unique Paths III

**[array, backtracking, bit-manipulation, matrix]**

### Statement

You are given an `m x n` integer array `grid` where `grid[i][j]` could be:

* `1` representing the starting square. There is exactly one starting square.
* `2` representing the ending square. There is exactly one ending square.
* `0` representing empty squares we can walk over.
* `-1` representing obstacles that we cannot walk over.



Return *the number of 4-directional walks from the starting square to the ending square, that walk over every non-obstacle square exactly once*.


**Example 1:**
![](https://assets.leetcode.com/uploads/2021/08/02/lc-unique1.jpg)

```

**Input:** grid = [[1,0,0,0],[0,0,0,0],[0,0,2,-1]]
**Output:** 2
**Explanation:** We have the following two paths: 
1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2)
2. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2)

```

**Example 2:**
![](https://assets.leetcode.com/uploads/2021/08/02/lc-unique2.jpg)

```

**Input:** grid = [[1,0,0,0],[0,0,0,0],[0,0,0,2]]
**Output:** 4
**Explanation:** We have the following four paths: 
1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2),(2,3)
2. (0,0),(0,1),(1,1),(1,0),(2,0),(2,1),(2,2),(1,2),(0,2),(0,3),(1,3),(2,3)
3. (0,0),(1,0),(2,0),(2,1),(2,2),(1,2),(1,1),(0,1),(0,2),(0,3),(1,3),(2,3)
4. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2),(2,3)

```

**Example 3:**
![](https://assets.leetcode.com/uploads/2021/08/02/lc-unique3-.jpg)

```

**Input:** grid = [[0,1],[2,0]]
**Output:** 0
**Explanation:** There is no path that walks over every empty square exactly once.
Note that the starting and ending square can be anywhere in the grid.

```

**Constraints:**
* `m == grid.length`
* `n == grid[i].length`
* `1 <= m, n <= 20`
* `1 <= m * n <= 20`
* `-1 <= grid[i][j] <= 2`
* There is exactly one starting cell and one ending cell.


<br>

### Hints

None

<br>

### Solution

```cpp
class Solution {
  public:
    int uniquePathsIII (vector <vector <int>>& grid) {
      int m = grid.size(), n = grid.front().size();
      int dx[] = {+1, -1, 0, 0};
      int dy[] = {0, 0, +1, -1};
      int ans = 0, count = m * n, start_x = -1, start_y = -1;

      for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
          if (grid[i][j] == -1)
            --count;
          else if (grid[i][j] == 1) {
            start_x = i;
            start_y = j;
          }
        }
      }

      auto dfs = [&] (auto self, int i, int j, int steps) -> void {
        if (grid[i][j] == 2) {
          if (count == steps)
            ++ans;
          return;
        }

        grid[i][j] = 3;

        for (int k = 0; k < 4; ++k) {
          int ni = i + dx[k];
          int nj = j + dy[k];

          if (ni < 0 or nj < 0 or ni >= m or nj >= n or grid[ni][nj] == -1 or grid[ni][nj] == 3)
            continue;
          
          self(self, ni, nj, steps + 1);
        }

        grid[i][j] = 0;
      };

      dfs(dfs, start_x, start_y, 1);

      return ans;
    }
};
```

<br>

### Statistics

- total accepted: 150368
- total submissions: 185595
- acceptance rate: 81.0%
- likes: 4012
- dislikes: 156

<br>

### Similar Problems

- [Sudoku Solver](https://leetcode.com/problems/sudoku-solver) (Hard)
- [Unique Paths II](https://leetcode.com/problems/unique-paths-ii) (Medium)
- [Word Search II](https://leetcode.com/problems/word-search-ii) (Hard)
