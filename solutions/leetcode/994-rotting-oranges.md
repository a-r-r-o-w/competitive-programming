# [994] Rotting Oranges

**[array, breadth-first-search, matrix]**

### Statement

You are given an `m x n` `grid` where each cell can have one of three values:

* `0` representing an empty cell,
* `1` representing a fresh orange, or
* `2` representing a rotten orange.



Every minute, any fresh orange that is **4-directionally adjacent** to a rotten orange becomes rotten.

Return *the minimum number of minutes that must elapse until no cell has a fresh orange*. If *this is impossible, return* `-1`.


**Example 1:**
![](https://assets.leetcode.com/uploads/2019/02/16/oranges.png)

```

**Input:** grid = [[2,1,1],[1,1,0],[0,1,1]]
**Output:** 4

```

**Example 2:**

```

**Input:** grid = [[2,1,1],[0,1,1],[1,0,1]]
**Output:** -1
**Explanation:** The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.

```

**Example 3:**

```

**Input:** grid = [[0,2]]
**Output:** 0
**Explanation:** Since there are already no fresh oranges at minute 0, the answer is just 0.

```

**Constraints:**
* `m == grid.length`
* `n == grid[i].length`
* `1 <= m, n <= 10`
* `grid[i][j]` is `0`, `1`, or `2`.


<br>

### Hints

None

<br>

### Solution

```cpp
class Solution {
  public:
    int orangesRotting (vector <vector <int>>& grid) {
      const int inf32 = 1 << 30;
      
      int max = -inf32, m = grid.size(), n = grid.front().size();
      std::vector <std::vector <bool>> visited (m, std::vector <bool> (n));
      std::vector <std::vector <int>> min_d (m, std::vector <int> (n, inf32));
      std::vector <int> dx = {+1, -1, 0, 0};
      std::vector <int> dy = {0, 0, +1, -1};
      
      for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
          if (grid[i][j] != 2)
            continue;
          
          int d = 0;
          std::queue <std::pair <int, int>> q;
          
          q.push({i, j});
          visited[i][j] = true;
          d += 1;
          
          while (!q.empty()) {
            int k = q.size();
            
            while (k--) {
              auto [u, v] = q.front();
              q.pop();
              
              for (int l = 0; l < 4; ++l) {
                int nu = u + dx[l];
                int nv = v + dy[l];
                
                if (nu < 0 or nv < 0 or nu >= m or nv >= n or visited[nu][nv] or grid[nu][nv] == 0)
                  continue;
                
                q.push({nu, nv});
                visited[nu][nv] = true;
                min_d[nu][nv] = std::min(min_d[nu][nv], d);
              }
            }
            
            d += 1;
          }
          
          for (int k = 0; k < m; ++k)
            for (int l = 0; l < n; ++l)
              visited[k][l] = false;
        }
      }
      
      for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
          if (grid[i][j] == 1) {
            if (min_d[i][j] == inf32)
              return -1;
            max = std::max(max, min_d[i][j]);
          }
        }
      }
      
      if (max == -inf32)
        max = 0;
      
      return max;
    }
};
```

<br>

### Statistics

- total accepted: 480840
- total submissions: 919052
- acceptance rate: 52.3%
- likes: 8300
- dislikes: 304

<br>

### Similar Problems

- [Walls and Gates](https://leetcode.com/problems/walls-and-gates) (Medium)
- [Detonate the Maximum Bombs](https://leetcode.com/problems/detonate-the-maximum-bombs) (Medium)
- [Escape the Spreading Fire](https://leetcode.com/problems/escape-the-spreading-fire) (Hard)
