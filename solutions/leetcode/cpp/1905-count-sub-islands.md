# [1905] Count Sub Islands

**[array, depth-first-search, breadth-first-search, union-find, matrix]**

### Statement

You are given two `m x n` binary matrices `grid1` and `grid2` containing only `0`'s (representing water) and `1`'s (representing land). An **island** is a group of `1`'s connected **4-directionally** (horizontal or vertical). Any cells outside of the grid are considered water cells.

An island in `grid2` is considered a **sub-island** if there is an island in `grid1` that contains **all** the cells that make up **this** island in `grid2`.

Return the ***number** of islands in* `grid2` *that are considered **sub-islands***.


**Example 1:**
![](https://assets.leetcode.com/uploads/2021/06/10/test1.png)

```

**Input:** grid1 = [[1,1,1,0,0],[0,1,1,1,1],[0,0,0,0,0],[1,0,0,0,0],[1,1,0,1,1]], grid2 = [[1,1,1,0,0],[0,0,1,1,1],[0,1,0,0,0],[1,0,1,1,0],[0,1,0,1,0]]
**Output:** 3
**Explanation:** In the picture above, the grid on the left is grid1 and the grid on the right is grid2.
The 1s colored red in grid2 are those considered to be part of a sub-island. There are three sub-islands.

```

**Example 2:**
![](https://assets.leetcode.com/uploads/2021/06/03/testcasex2.png)

```

**Input:** grid1 = [[1,0,1,0,1],[1,1,1,1,1],[0,0,0,0,0],[1,1,1,1,1],[1,0,1,0,1]], grid2 = [[0,0,0,0,0],[1,1,1,1,1],[0,1,0,1,0],[0,1,0,1,0],[1,0,0,0,1]]
**Output:** 2 
**Explanation:** In the picture above, the grid on the left is grid1 and the grid on the right is grid2.
The 1s colored red in grid2 are those considered to be part of a sub-island. There are two sub-islands.

```

**Constraints:**
* `m == grid1.length == grid2.length`
* `n == grid1[i].length == grid2[i].length`
* `1 <= m, n <= 500`
* `grid1[i][j]` and `grid2[i][j]` are either `0` or `1`.


<br>

### Hints

- Let's use floodfill to iterate over the islands of the second grid
- Let's note that if all the cells in an island in the second grid if they are represented by land in the first grid then they are connected hence making that island a sub-island

<br>

### Solution

```cpp
class Solution {
  public:
    int countSubIslands (vector <vector <int>>& grid1, vector <vector <int>>& grid2) {
      int m = grid1.size(), n = grid1.front().size();
      int dx[] = {+1, -1, 0, 0};
      int dy[] = {0, 0, +1, -1};
      std::vector <std::pair <int, int>> islands;

      auto dfs = [&] (auto self, int i, int j) -> void {
        grid2[i][j] = 2;
        islands.emplace_back(i, j);

        for (int k = 0; k < 4; ++k) {
          int ni = i + dx[k];
          int nj = j + dy[k];

          if (ni < 0 or nj < 0 or ni >= m or nj >= n or grid2[ni][nj] != 1)
            continue;
          
          self(self, ni, nj);
        }
      };

      int subislands = 0;

      for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
          if (grid2[i][j] == 1) {
            dfs(dfs, i, j);
            
            bool okay = true;
            
            for (auto &[p, q]: islands) {
              if (grid1[p][q] != 1) {
                okay = false;
                break;
              }
            }

            if (okay)
              ++subislands;
            
            islands.clear();
          }
        }
      }

      return subislands;
    }
};
```

<br>

### Statistics

- total accepted: 57940
- total submissions: 85746
- acceptance rate: 67.6%
- likes: 1548
- dislikes: 49

<br>

### Similar Problems

- [Number of Islands](https://leetcode.com/problems/number-of-islands) (Medium)
- [Number of Distinct Islands](https://leetcode.com/problems/number-of-distinct-islands) (Medium)
- [Find All Groups of Farmland](https://leetcode.com/problems/find-all-groups-of-farmland) (Medium)
