# [934] Shortest Bridge

**[array, depth-first-search, breadth-first-search, matrix]**

### Statement

You are given an `n x n` binary matrix `grid` where `1` represents land and `0` represents water.

An **island** is a 4-directionally connected group of `1`'s not connected to any other `1`'s. There are **exactly two islands** in `grid`.

You may change `0`'s to `1`'s to connect the two islands to form **one island**.

Return *the smallest number of* `0`*'s you must flip to connect the two islands*.


**Example 1:**

```

**Input:** grid = [[0,1],[1,0]]
**Output:** 1

```

**Example 2:**

```

**Input:** grid = [[0,1,0],[0,0,0],[0,0,1]]
**Output:** 2

```

**Example 3:**

```

**Input:** grid = [[1,1,1,1,1],[1,0,0,0,1],[1,0,1,0,1],[1,0,0,0,1],[1,1,1,1,1]]
**Output:** 1

```

**Constraints:**
* `n == grid.length == grid[i].length`
* `2 <= n <= 100`
* `grid[i][j]` is either `0` or `1`.
* There are exactly two islands in `grid`.


<br>

### Hints

None

<br>

### Solution

```cpp
class Solution {
  public:
    int shortestBridge (vector <vector <int>>& grid) {
      int n = grid.size();
      int dx[] = {+1, -1, 0, 0};
      int dy[] = {0, 0, +1, -1};
      std::vector <std::vector <std::pair <int, int>>> islands;
      std::vector <std::pair <int, int>> island;

      auto dfs = [&] (auto self, int i, int j) -> void {
        grid[i][j] = 2;
        island.push_back({i, j});
        
        for (int k = 0; k < 4; ++k) {
          int ni = i + dx[k];
          int nj = j + dy[k];

          if (ni < 0 or nj < 0 or ni >= n or nj >= n or grid[ni][nj] != 1)
            continue;
          
          self(self, ni, nj);
        }
      };

      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
          if (grid[i][j] == 1) {
            dfs(dfs, i, j);
            islands.emplace_back(std::move(island));
          }
        }
      }

      int min = 1 << 30;

      for (auto &[x1, y1]: islands[0]) {
        for (auto &[x2, y2]: islands[1])
          min = std::min(min, std::abs(x2 - x1) + std::abs(y2 - y1) - 1);
      }

      return min;
    }
};
```

<br>

### Statistics

- total accepted: 120452
- total submissions: 222191
- acceptance rate: 54.2%
- likes: 3415
- dislikes: 146

<br>

### Similar Problems

None
