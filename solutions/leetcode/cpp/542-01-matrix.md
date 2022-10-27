# [542] 01 Matrix

**[array, dynamic-programming, breadth-first-search, matrix]**

### Statement

Given an `m x n` binary matrix `mat`, return *the distance of the nearest* `0` *for each cell*.

The distance between two adjacent cells is `1`.


**Example 1:**
![](https://assets.leetcode.com/uploads/2021/04/24/01-1-grid.jpg)

```

**Input:** mat = [[0,0,0],[0,1,0],[0,0,0]]
**Output:** [[0,0,0],[0,1,0],[0,0,0]]

```

**Example 2:**
![](https://assets.leetcode.com/uploads/2021/04/24/01-2-grid.jpg)

```

**Input:** mat = [[0,0,0],[0,1,0],[1,1,1]]
**Output:** [[0,0,0],[0,1,0],[1,2,1]]

```

**Constraints:**
* `m == mat.length`
* `n == mat[i].length`
* `1 <= m, n <= 104`
* `1 <= m * n <= 104`
* `mat[i][j]` is either `0` or `1`.
* There is at least one `0` in `mat`.


<br>

### Hints

None

<br>

### Solution

```cpp
class Solution {
  public:
    vector <vector <int>> updateMatrix (vector <vector <int>>& mat) {
      const int inf32 = 1 << 30;
      int m = mat.size(), n = mat.front().size();
      std::queue <std::pair <int, int>> q;
      int dx[] = {+1, -1, 0, 0};
      int dy[] = {0, 0, +1, -1};
      std::vector <std::vector <int>> distance (m, std::vector <int> (n, inf32));
      
      for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
          if (mat[i][j] == 0) {
            q.push({i, j});
            distance[i][j] = 0;
          }
      
      while (!q.empty()) {
        auto [i, j] = q.front();
        q.pop();
        
        for (int k = 0; k < 4; ++k) {
          int ni = i + dx[k];
          int nj = j + dy[k];
          
          if (ni < 0 or nj < 0 or ni >= m or nj >= n or distance[ni][nj] < distance[i][j] + 1)
            continue;
          
          distance[ni][nj] = distance[i][j] + 1;
          q.push({ni, nj});
        }
      }
      
      return distance;
    }
};
```

<br>

### Statistics

- total accepted: 303605
- total submissions: 689145
- acceptance rate: 44.1%
- likes: 5624
- dislikes: 280

<br>

### Similar Problems

- [Shortest Path to Get Food](https://leetcode.com/problems/shortest-path-to-get-food) (Medium)
- [Minimum Operations to Remove Adjacent Ones in Matrix](https://leetcode.com/problems/minimum-operations-to-remove-adjacent-ones-in-matrix) (Hard)
