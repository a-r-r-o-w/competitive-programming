# [1970] Last Day Where You Can Still Cross

**[array, binary-search, depth-first-search, breadth-first-search, union-find, matrix]**

### Statement

There is a **1-based** binary matrix where `0` represents land and `1` represents water. You are given integers `row` and `col` representing the number of rows and columns in the matrix, respectively.

Initially on day `0`, the **entire** matrix is **land**. However, each day a new cell becomes flooded with **water**. You are given a **1-based** 2D array `cells`, where `cells[i] = [ri, ci]` represents that on the `i^th` day, the cell on the `ri^th` row and `ci^th` column (**1-based** coordinates) will be covered with **water** (i.e., changed to `1`).

You want to find the **last** day that it is possible to walk from the **top** to the **bottom** by only walking on land cells. You can start from **any** cell in the top row and end at **any** cell in the bottom row. You can only travel in the **four** cardinal directions (left, right, up, and down).

Return *the **last** day where it is possible to walk from the **top** to the **bottom** by only walking on land cells*.


**Example 1:**
![](https://assets.leetcode.com/uploads/2021/07/27/1.png)

```

**Input:** row = 2, col = 2, cells = [[1,1],[2,1],[1,2],[2,2]]
**Output:** 2
**Explanation:** The above image depicts how the matrix changes each day starting from day 0.
The last day where it is possible to cross from top to bottom is on day 2.

```

**Example 2:**
![](https://assets.leetcode.com/uploads/2021/07/27/2.png)

```

**Input:** row = 2, col = 2, cells = [[1,1],[1,2],[2,1],[2,2]]
**Output:** 1
**Explanation:** The above image depicts how the matrix changes each day starting from day 0.
The last day where it is possible to cross from top to bottom is on day 1.

```

**Example 3:**
![](https://assets.leetcode.com/uploads/2021/07/27/3.png)

```

**Input:** row = 3, col = 3, cells = [[1,2],[2,1],[3,3],[2,2],[1,1],[1,3],[2,3],[3,2],[3,1]]
**Output:** 3
**Explanation:** The above image depicts how the matrix changes each day starting from day 0.
The last day where it is possible to cross from top to bottom is on day 3.

```

**Constraints:**
* `2 <= row, col <= 2 * 10^4`
* `4 <= row * col <= 2 * 10^4`
* `cells.length == row * col`
* `1 <= ri <= row`
* `1 <= ci <= col`
* All the values of `cells` are **unique**.


<br />

### Hints

- What graph algorithm allows us to find whether a path exists?
- Can we use binary search to help us solve the problem?

<br />

### Solution

```cpp
class Solution {
  public:
    int latestDayToCross (int row, int col, vector <vector <int>>& cells) {
      int nrow = row + 2, ncol = col + 2;
      int total = nrow * ncol;
      std::vector <int> parent (total), rank (total), grid (total, 1);

      std::iota(parent.begin(), parent.end(), 0);
      
      auto find = [&] (auto self, int u) -> int {
        return parent[u] = u == parent[u] ? u : self(self, parent[u]);
      };

      auto unite = [&] (int u, int v) {
        u = find(find, u);
        v = find(find, v);
        if (u == v)
          return;
        if (rank[u] < rank[v])
          std::swap(u, v);
        parent[v] = u;
        ++rank[u];
      };

      for (int i = 1; i + 1 <= col; ++i) {
        unite(i, i + 1);
        unite(total - ncol + i, total - ncol + i + 1);
        grid[i] = 0;
        grid[total - ncol + i] = 0;
      }
      grid[col] = 0;
      grid[total - 2] = 0;

      int days = 0;
      std::vector <int> dx = {+1, -1, 0, 0};
      std::vector <int> dy = {0, 0, +1, -1};

      for (int i = row * col - 1; i >= 0; --i) {
        if (find(find, 1) == find(find, total - 2))
          return row * col - days;
        ++days;
        
        int x = cells[i][0], y = cells[i][1];
        int c = ncol * x + y;
        grid[c] = 0;
        
        for (int k = 0; k < 4; ++k) {
          int nx = x + dx[k];
          int ny = y + dy[k];
          if (grid[ncol * nx + ny] == 1)
            continue;
          unite(c, ncol * nx + ny);
        }
      }

      return row * col - days;
    }
};
```

<br />

### Statistics

- total accepted: 43711
- total submissions: 69228
- acceptance rate: 63.1%
- likes: 1586
- dislikes: 28

<br />

### Similar Problems

- [Bricks Falling When Hit](https://leetcode.com/problems/bricks-falling-when-hit) (Hard)
- [Escape the Spreading Fire](https://leetcode.com/problems/escape-the-spreading-fire) (Hard)
