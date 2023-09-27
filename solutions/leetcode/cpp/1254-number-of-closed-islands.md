# [1254] Number of Closed Islands

**[array, depth-first-search, breadth-first-search, union-find, matrix]**

### Statement

Given a 2D`grid` consists of `0s` (land)and `1s` (water). An *island* is a maximal 4-directionally connected group of `0s` and a *closed island*is an island **totally**(all left, top, right, bottom) surrounded by `1s.`

Return the number of *closed islands*.


**Example 1:**
![](https://assets.leetcode.com/uploads/2019/10/31/sample_3_1610.png)

```

**Input:** grid = [[1,1,1,1,1,1,1,0],[1,0,0,0,0,1,1,0],[1,0,1,0,1,1,1,0],[1,0,0,0,0,1,0,1],[1,1,1,1,1,1,1,0]]
**Output:** 2
**Explanation:** 
Islands in gray are closed because they are completely surrounded by water (group of 1s).
```

**Example 2:**
![](https://assets.leetcode.com/uploads/2019/10/31/sample_4_1610.png)

```

**Input:** grid = [[0,0,1,0,0],[0,1,0,1,0],[0,1,1,1,0]]
**Output:** 1

```

**Example 3:**

```

**Input:** grid = [[1,1,1,1,1,1,1],
              [1,0,0,0,0,0,1],
              [1,0,1,1,1,0,1],
              [1,0,1,0,1,0,1],
              [1,0,1,1,1,0,1],
              [1,0,0,0,0,0,1],
               [1,1,1,1,1,1,1]]
**Output:** 2

```

**Constraints:**
* `1 <= grid.length, grid[0].length <= 100`
* `0 <= grid[i][j] <=1`


<br>

### Hints

- Exclude connected group of 0s on the corners because they are not closed island.
- Return number of connected component of 0s on the grid.

<br>

### Solution

```cpp
class Solution {
  public:
    int closedIsland (vector <vector <int>>& grid) {
      int n = grid.size(), m = grid.front().size();
      int dx[] = {-1, +1, 0, 0};
      int dy[] = {0, 0, +1, -1};
      int ans = 0;

      auto dfs = [&] (auto self, int i, int j) -> bool {
        bool result = false;
        result |= i == 0 or j == 0 or i == n - 1 or j == m - 1;
        grid[i][j] = 2;
        for (int k = 0; k < 4; ++k) {
          int ni = i + dx[k];
          int nj = j + dy[k];
          if (ni < 0 or nj < 0 or ni >= n or nj >= m or grid[ni][nj] != 0)
            continue;
          result |= self(self, ni, nj);
        }
        return result;
      };

      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
          if (grid[i][j] == 0) {
            if (!dfs(dfs, i, j))
              ++ans;
          }
        }
      }

      return ans;
    }
};
```

<br>

### Statistics

- total accepted: 121387
- total submissions: 189210
- acceptance rate: 64.2%
- likes: 2642
- dislikes: 64

<br>

### Similar Problems

None
