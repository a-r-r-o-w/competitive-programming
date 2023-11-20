# [1631] Path With Minimum Effort

**[array, binary-search, depth-first-search, breadth-first-search, union-find, heap-priority-queue, matrix]**

### Statement

You are a hiker preparing for an upcoming hike. You are given `heights`, a 2D array of size `rows x columns`, where `heights[row][col]` represents the height of cell `(row, col)`. You are situated in the top-left cell, `(0, 0)`, and you hope to travel to the bottom-right cell, `(rows-1, columns-1)` (i.e.,**0-indexed**). You can move **up**, **down**, **left**, or **right**, and you wish to find a route that requires the minimum **effort**.

A route's **effort** is the **maximum absolute difference**in heights between two consecutive cells of the route.

Return *the minimum **effort** required to travel from the top-left cell to the bottom-right cell.*
**Example 1:**
![](https://assets.leetcode.com/uploads/2020/10/04/ex1.png)

```

**Input:** heights = [[1,2,2],[3,8,2],[5,3,5]]
**Output:** 2
**Explanation:** The route of [1,3,5,3,5] has a maximum absolute difference of 2 in consecutive cells.
This is better than the route of [1,2,2,2,5], where the maximum absolute difference is 3.

```

**Example 2:**
![](https://assets.leetcode.com/uploads/2020/10/04/ex2.png)

```

**Input:** heights = [[1,2,3],[3,8,4],[5,3,5]]
**Output:** 1
**Explanation:** The route of [1,2,3,4,5] has a maximum absolute difference of 1 in consecutive cells, which is better than route [1,3,5,3,5].

```

**Example 3:**
![](https://assets.leetcode.com/uploads/2020/10/04/ex3.png)

```

**Input:** heights = [[1,2,1,1,1],[1,2,1,2,1],[1,2,1,2,1],[1,2,1,2,1],[1,1,1,2,1]]
**Output:** 0
**Explanation:** This route does not require any effort.

```

**Constraints:**
* `rows == heights.length`
* `columns == heights[i].length`
* `1 <= rows, columns <= 100`
* `1 <= heights[i][j] <= 10^6`


<br />

### Hints

- Consider the grid as a graph, where adjacent cells have an edge with cost of the difference between the cells.
- If you are given threshold k, check if it is possible to go from (0, 0) to (n-1, m-1) using only edges of ≤ k cost.
- Binary search the k value.

<br />

### Solution

```cpp
class Solution {
  public:
    int minimumEffortPath(vector <vector <int>>& heights) {
      int n = heights.size(), m = heights.front().size();
      std::vector <int> dx = {0, 0, -1, +1};
      std::vector <int> dy = {+1, -1, 0, 0};

      std::vector visited(n, std::vector <bool>(m, false));
      auto dfs = [&] (auto self, int i, int j, int k) -> bool {
        if (i == n - 1 and j == m - 1)
          return true;
        visited[i][j] = true;
        bool ans = false;
        for (int h = 0; h < 4; ++h) {
          int nx = i + dx[h];
          int ny = j + dy[h];
          if (nx < 0 or ny < 0 or nx >= n or ny >= m or visited[nx][ny])
            continue;
          int diff = std::abs(heights[i][j] - heights[nx][ny]);
          if (diff > k)
            continue;
          ans |= self(self, nx, ny, k);
        }
        return ans;
      };

      int low = 0, high = 1e8;
      while (low < high) {
        int mid = (low + high) / 2;
        if (dfs(dfs, 0, 0, mid))
          high = mid;
        else
          low = mid + 1;
        for (int i = 0; i < n; ++i)
          for (int j = 0; j < m; ++j)
            visited[i][j] = false;
      }

      return low;
    }
}
```

<br />

### Statistics

- total accepted: 170804
- total submissions: 299860
- acceptance rate: 57.0%
- likes: 4863
- dislikes: 164

<br />

### Similar Problems

- [Swim in Rising Water](https://leetcode.com/problems/swim-in-rising-water) (Hard)
- [Path With Maximum Minimum Value](https://leetcode.com/problems/path-with-maximum-minimum-value) (Medium)
- [Find the Safest Path in a Grid](https://leetcode.com/problems/find-the-safest-path-in-a-grid) (Medium)
