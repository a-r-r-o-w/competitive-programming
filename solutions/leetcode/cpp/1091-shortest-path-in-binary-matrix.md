# [1091] Shortest Path in Binary Matrix

**[array, breadth-first-search, matrix]**

### Statement

Given an `n x n` binary matrix `grid`, return *the length of the shortest **clear path** in the matrix*. If there is no clear path, return `-1`.

A **clear path** in a binary matrix is a path from the **top-left** cell (i.e., `(0, 0)`) to the **bottom-right** cell (i.e., `(n - 1, n - 1)`) such that:

* All the visited cells of the path are `0`.
* All the adjacent cells of the path are **8-directionally** connected (i.e., they are different and they share an edge or a corner).



The **length of a clear path** is the number of visited cells of this path.


**Example 1:**
![](https://assets.leetcode.com/uploads/2021/02/18/example1_1.png)

```

**Input:** grid = [[0,1],[1,0]]
**Output:** 2

```

**Example 2:**
![](https://assets.leetcode.com/uploads/2021/02/18/example2_1.png)

```

**Input:** grid = [[0,0,0],[1,1,0],[1,1,0]]
**Output:** 4

```

**Example 3:**

```

**Input:** grid = [[1,0,0],[1,1,0],[1,1,0]]
**Output:** -1

```

**Constraints:**
* `n == grid.length`
* `n == grid[i].length`
* `1 <= n <= 100`
* `grid[i][j] is 0 or 1`


<br>

### Hints

- Do a breadth first search to find the shortest path.

<br>

### Solution

```cpp
class Solution {
  public:
    int shortestPathBinaryMatrix (vector <vector <int>>& grid) {
      int n = grid.size(), depth = 0;
      std::queue <std::array <int, 2>> q;
      int dx[] = {+1, -1, 0, 0, +1, +1, -1, -1};
      int dy[] = {0, 0, +1, -1, +1, -1, +1, -1};

      if (grid[0][0] == 0) {
        q.push({0, 0});
        grid[0][0] = 1;
      }

      while (!q.empty()) {
        ++depth;
        int size = q.size();

        for (int i = 0; i < size; ++i) {
          auto f = q.front();
          q.pop();

          if (f[0] == n - 1 and f[1] == n - 1)
            return depth;

          for (int k = 0; k < 8; ++k) {
            int ni = f[0] + dx[k];
            int nj = f[1] + dy[k];

            if (ni < 0 or nj < 0 or ni >= n or nj >= n or grid[ni][nj] != 0)
              continue;
            
            q.push({ni, nj});
            grid[ni][nj] = 1;
          }
        }
      }

      return -1;
    }
};
```

<br>

### Statistics

- total accepted: 284262
- total submissions: 637955
- acceptance rate: 44.6%
- likes: 4310
- dislikes: 180

<br>

### Similar Problems

- [Paths in Matrix Whose Sum Is Divisible by K](https://leetcode.com/problems/paths-in-matrix-whose-sum-is-divisible-by-k) (Hard)
