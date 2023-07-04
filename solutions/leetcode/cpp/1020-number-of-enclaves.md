# [1020] Number of Enclaves

**[array, depth-first-search, breadth-first-search, union-find, matrix]**

### Statement

You are given an `m x n` binary matrix `grid`, where `0` represents a sea cell and `1` represents a land cell.

A **move** consists of walking from one land cell to another adjacent (**4-directionally**) land cell or walking off the boundary of the `grid`.

Return *the number of land cells in* `grid` *for which we cannot walk off the boundary of the grid in any number of **moves***.


**Example 1:**
![](https://assets.leetcode.com/uploads/2021/02/18/enclaves1.jpg)

```

**Input:** grid = [[0,0,0,0],[1,0,1,0],[0,1,1,0],[0,0,0,0]]
**Output:** 3
**Explanation:** There are three 1s that are enclosed by 0s, and one 1 that is not enclosed because its on the boundary.

```

**Example 2:**
![](https://assets.leetcode.com/uploads/2021/02/18/enclaves2.jpg)

```

**Input:** grid = [[0,1,1,0],[0,0,1,0],[0,0,1,0],[0,0,0,0]]
**Output:** 0
**Explanation:** All 1s are either on the boundary or can reach the boundary.

```

**Constraints:**
* `m == grid.length`
* `n == grid[i].length`
* `1 <= m, n <= 500`
* `grid[i][j]` is either `0` or `1`.


<br>

### Hints

- Can you model this problem as a graph problem?  Create n * m + 1 nodes where n * m nodes represents each cell of the map and one extra node to represent the exterior of the map.
- In the map add edges between neighbors on land cells. And add edges between the exterior and land nodes which are in the boundary.
Return as answer the number of nodes that are not reachable from the exterior node.

<br>

### Solution

```cpp
class Solution {
  public:
    int numEnclaves (vector <vector <int>>& grid) {
      int n = grid.size(), m = grid.front().size();
      int dx[] = {-1, +1, 0, 0};
      int dy[] = {0, 0, +1, -1};
      int ans = 0;

      auto dfs = [&] (auto self, int i, int j, int &c) -> bool {
        bool result = false;
        result |= i == 0 or j == 0 or i == n - 1 or j == m - 1;
        grid[i][j] = 2;
        ++c;
        for (int k = 0; k < 4; ++k) {
          int ni = i + dx[k];
          int nj = j + dy[k];
          if (ni < 0 or nj < 0 or ni >= n or nj >= m or grid[ni][nj] != 1)
            continue;
          result |= self(self, ni, nj, c);
        }
        return result;
      };

      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
          if (grid[i][j] == 1) {
            int size = 0;
            if (!dfs(dfs, i, j, size))
              ans += size;
          }
        }
      }

      return ans;
    }
};
```

<br>

### Statistics

- total accepted: 87925
- total submissions: 134814
- acceptance rate: 65.2%
- likes: 2048
- dislikes: 40

<br>

### Similar Problems

None
