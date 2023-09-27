# [1293] Shortest Path in a Grid with Obstacles Elimination

**[array, breadth-first-search, matrix]**

### Statement

You are given an `m x n` integer matrix `grid` where each cell is either `0` (empty) or `1` (obstacle). You can move up, down, left, or right from and to an empty cell in **one step**.

Return *the minimum number of **steps** to walk from the upper left corner* `(0, 0)` *to the lower right corner* `(m - 1, n - 1)` *given that you can eliminate **at most*** `k` *obstacles*. If it is not possible to find such walk return `-1`.


**Example 1:**
![](https://assets.leetcode.com/uploads/2021/09/30/short1-grid.jpg)

```

**Input:** grid = [[0,0,0],[1,1,0],[0,0,0],[0,1,1],[0,0,0]], k = 1
**Output:** 6
**Explanation:** 
The shortest path without eliminating any obstacle is 10.
The shortest path with one obstacle elimination at position (3,2) is 6. Such path is (0,0) -> (0,1) -> (0,2) -> (1,2) -> (2,2) -> **(3,2)** -> (4,2).

```

**Example 2:**
![](https://assets.leetcode.com/uploads/2021/09/30/short2-grid.jpg)

```

**Input:** grid = [[0,1,1],[1,1,1],[1,0,0]], k = 1
**Output:** -1
**Explanation:** We need to eliminate at least two obstacles to find such a walk.

```

**Constraints:**
* `m == grid.length`
* `n == grid[i].length`
* `1 <= m, n <= 40`
* `1 <= k <= m * n`
* `grid[i][j]` is either `0` **or** `1`.
* `grid[0][0] == grid[m - 1][n - 1] == 0`


<br>

### Hints

- Use BFS.
- BFS on (x,y,r) x,y is coordinate, r is remain number of obstacles you can remove.

<br>

### Solution

```cpp
class Solution {
  public:
    int shortestPath (vector <vector <int>>& grid, int k) {
      int m = grid.size(), n = grid.front().size();
      std::queue <std::tuple <int, int, int>> q;
      std::vector <std::vector <std::vector <bool>>> visited (m, std::vector <std::vector <bool>> (n, std::vector <bool> (k + 1)));
      int dx[] = {+1, -1, 0, 0};
      int dy[] = {0, 0, +1, -1};
      int steps = 0;
      
      q.push({0, 0, k});
      
      while (!q.empty()) {
        int f = q.size();
        
        for (int i = 0; i < f; ++i) {
          auto [x, y, remain] = q.front();
          q.pop();

          if (x == m - 1 and y == n - 1)
            return steps;

          for (int k = 0; k < 4; ++k) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            int nr = remain;
            
            if (nx < 0 or ny < 0 or nx >= m or ny >= n)
              continue;
            if (grid[nx][ny] == 1) {
              if (nr > 0)
                --nr;
              else
                continue;
            }
            if (visited[nx][ny][nr])
              continue;
            q.push({nx, ny, nr});
            visited[nx][ny][nr] = true;
          }
        }
        
        steps += 1;
      }
      
      return -1;
    }
};
```

<br>

### Statistics

- total accepted: 162837
- total submissions: 356469
- acceptance rate: 45.7%
- likes: 3760
- dislikes: 67

<br>

### Similar Problems

- [Shortest Path to Get Food](https://leetcode.com/problems/shortest-path-to-get-food) (Medium)
- [Minimum Obstacle Removal to Reach Corner](https://leetcode.com/problems/minimum-obstacle-removal-to-reach-corner) (Hard)
