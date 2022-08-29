# [200] Number of Islands

**[array, depth-first-search, breadth-first-search, union-find, matrix]**

### Statement

Given an `m x n` 2D binary grid `grid` which represents a map of `'1'`s (land) and `'0'`s (water), return *the number of islands*.

An **island** is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.


**Example 1:**

```

**Input:** grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
**Output:** 1

```

**Example 2:**

```

**Input:** grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
**Output:** 3

```

**Constraints:**
* `m == grid.length`
* `n == grid[i].length`
* `1 <= m, n <= 300`
* `grid[i][j]` is `'0'` or `'1'`.


<br>

### Hints

None

<br>

### Solution

```cpp
class Solution {
  public:
    int numIslands (vector <vector <char>>& grid) {
      int ans = 0;
      int m = grid.size(), n = grid.front().size();
      std::vector <int> dx = {+1, -1, 0, 0};
      std::vector <int> dy = {0, 0, +1, -1};
      std::vector <std::vector <bool>> visited (m, std::vector <bool> (n));
      
      auto dfs = [&] (auto self, int i, int j) -> void {
        visited[i][j] = true;
        for (int k = 0; k < 4; ++k) {
          int ni = i + dx[k];
          int nj = j + dy[k];
          if (ni < 0 or nj < 0 or ni >= m or nj >= n or visited[ni][nj] or grid[ni][nj] == '0')
            continue;
          self(self, ni, nj);
        }
      };
      
      for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
          if (visited[i][j])
            continue;
          if (grid[i][j] == '0') {
            visited[i][j] = true;
            continue;
          }
          dfs(dfs, i, j);
          ++ans;
        }
      }
      
      return ans;
    }
};
```

<br>

### Statistics

- total accepted: 1790329
- total submissions: 3229198
- acceptance rate: 55.4%
- likes: 16224
- dislikes: 378

<br>

### Similar Problems

- [Surrounded Regions](https://leetcode.com/problems/surrounded-regions) (Medium)
- [Walls and Gates](https://leetcode.com/problems/walls-and-gates) (Medium)
- [Number of Islands II](https://leetcode.com/problems/number-of-islands-ii) (Hard)
- [Number of Connected Components in an Undirected Graph](https://leetcode.com/problems/number-of-connected-components-in-an-undirected-graph) (Medium)
- [Number of Distinct Islands](https://leetcode.com/problems/number-of-distinct-islands) (Medium)
- [Max Area of Island](https://leetcode.com/problems/max-area-of-island) (Medium)
- [Count Sub Islands](https://leetcode.com/problems/count-sub-islands) (Medium)
- [Find All Groups of Farmland](https://leetcode.com/problems/find-all-groups-of-farmland) (Medium)
- [Count Unreachable Pairs of Nodes in an Undirected Graph](https://leetcode.com/problems/count-unreachable-pairs-of-nodes-in-an-undirected-graph) (Medium)
