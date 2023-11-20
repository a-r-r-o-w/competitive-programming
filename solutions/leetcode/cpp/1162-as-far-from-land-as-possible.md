# [1162] As Far from Land as Possible

**[array, dynamic-programming, breadth-first-search, matrix]**

### Statement

Given an `n x n` `grid`containing only values `0` and `1`, where`0` represents waterand `1` represents land, find a water cell such that its distance to the nearest land cell is maximized, and return the distance.If no land or water exists in the grid, return `-1`.

The distance used in this problem is the Manhattan distance:the distance between two cells `(x0, y0)` and `(x1, y1)` is `|x0 - x1| + |y0 - y1|`.


**Example 1:**
![](https://assets.leetcode.com/uploads/2019/05/03/1336_ex1.JPG)

```

**Input:** grid = [[1,0,1],[0,0,0],[1,0,1]]
**Output:** 2
**Explanation:** The cell (1, 1) is as far as possible from all the land with distance 2.

```

**Example 2:**
![](https://assets.leetcode.com/uploads/2019/05/03/1336_ex2.JPG)

```

**Input:** grid = [[1,0,0],[0,0,0],[0,0,0]]
**Output:** 4
**Explanation:** The cell (2, 2) is as far as possible from all the land with distance 4.

```

**Constraints:**
* `n == grid.length`
* `n == grid[i].length`
* `1 <= n<= 100`
* `grid[i][j]`is `0` or `1`


<br>

### Hints

- Can you think of this problem in a backwards way ?
- Imagine expanding outward from each land cell. What kind of search does that ?
- Use BFS starting from all land cells in the same time.
- When do you reach the furthest water cell?

<br>

### Solution

```cpp
class Solution {
  public:
    int maxDistance (vector <vector <int>>& grid) {
      int n = grid.size(), ans = 0;
      std::queue <std::array <int, 2>> q;
      int dx[] = {+1, -1, 0, 0};
      int dy[] = {0, 0, +1, -1};

      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
          if (grid[i][j] == 1) {
            q.push({i, j});
            grid[i][j] = 2;
          }
        }
      }

      if (q.empty() or (int)q.size() == n * n)
        return -1;

      while (!q.empty()) {
        ++ans;
        int size = q.size();

        for (int i = 0; i < size; ++i) {
          auto f = q.front();
          q.pop();

          for (int k = 0; k < 4; ++k) {
            int ni = f[0] + dx[k];
            int nj = f[1] + dy[k];

            if (ni < 0 or nj < 0 or ni >= n or nj >= n or grid[ni][nj] != 0)
              continue;
            
            q.push({ni, nj});
            grid[ni][nj] = 2;
          }
        }
      }

      return ans - 1;
    }
};
```

<br>

### Statistics

- total accepted: 81690
- total submissions: 168497
- acceptance rate: 48.5%
- likes: 2416
- dislikes: 69

<br>

### Similar Problems

- [Shortest Distance from All Buildings](https://leetcode.com/problems/shortest-distance-from-all-buildings) (Hard)
- [K Highest Ranked Items Within a Price Range](https://leetcode.com/problems/k-highest-ranked-items-within-a-price-range) (Medium)
