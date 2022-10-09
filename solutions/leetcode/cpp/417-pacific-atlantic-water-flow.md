# [417] Pacific Atlantic Water Flow

**[array, depth-first-search, breadth-first-search, matrix]**

### Statement

There is an `m x n` rectangular island that borders both the **Pacific Ocean** and **Atlantic Ocean**. The **Pacific Ocean** touches the island's left and top edges, and the **Atlantic Ocean** touches the island's right and bottom edges.

The island is partitioned into a grid of square cells. You are given an `m x n` integer matrix `heights` where `heights[r][c]` represents the **height above sea level** of the cell at coordinate `(r, c)`.

The island receives a lot of rain, and the rain water can flow to neighboring cells directly north, south, east, and west if the neighboring cell's height is **less than or equal to** the current cell's height. Water can flow from any cell adjacent to an ocean into the ocean.

Return *a **2D list** of grid coordinates* `result` *where* `result[i] = [ri, ci]` *denotes that rain water can flow from cell* `(ri, ci)` *to **both** the Pacific and Atlantic oceans*.


**Example 1:**
![](https://assets.leetcode.com/uploads/2021/06/08/waterflow-grid.jpg)

```

**Input:** heights = [[1,2,2,3,5],[3,2,3,4,4],[2,4,5,3,1],[6,7,1,4,5],[5,1,1,2,4]]
**Output:** [[0,4],[1,3],[1,4],[2,2],[3,0],[3,1],[4,0]]
**Explanation:** The following cells can flow to the Pacific and Atlantic oceans, as shown below:
[0,4]: [0,4] -> Pacific Ocean 
      [0,4] -> Atlantic Ocean
[1,3]: [1,3] -> [0,3] -> Pacific Ocean 
      [1,3] -> [1,4] -> Atlantic Ocean
[1,4]: [1,4] -> [1,3] -> [0,3] -> Pacific Ocean 
      [1,4] -> Atlantic Ocean
[2,2]: [2,2] -> [1,2] -> [0,2] -> Pacific Ocean 
      [2,2] -> [2,3] -> [2,4] -> Atlantic Ocean
[3,0]: [3,0] -> Pacific Ocean 
      [3,0] -> [4,0] -> Atlantic Ocean
[3,1]: [3,1] -> [3,0] -> Pacific Ocean 
      [3,1] -> [4,1] -> Atlantic Ocean
[4,0]: [4,0] -> Pacific Ocean 
       [4,0] -> Atlantic Ocean
Note that there are other possible paths for these cells to flow to the Pacific and Atlantic oceans.

```

**Example 2:**

```

**Input:** heights = [[1]]
**Output:** [[0,0]]
**Explanation:** The water can flow from the only cell to the Pacific and Atlantic oceans.

```

**Constraints:**
* `m == heights.length`
* `n == heights[r].length`
* `1 <= m, n <= 200`
* `0 <= heights[r][c] <= 105`


<br>

### Hints

None

<br>

### Solution

```cpp
class Solution {
  public:
    Solution () {
      std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);
    }
  
    vector <vector <int>> pacificAtlantic (vector <vector <int>>& heights) {
      std::vector <std::vector <int>> ans;
      int m = heights.size();
      int n = heights.front().size();
      std::vector <std::vector <std::pair <bool, bool>>> visited (m, std::vector <std::pair <bool, bool>> (n));
      std::vector <int> dx = {+1, -1, 0, 0};
      std::vector <int> dy = {0, 0, +1, -1};
      
      auto is_valid = [&] (int i, int j) -> bool {
        return i >= 0 and i < m and j >= 0 and j < n;
      };
      
      std::queue <std::pair <int, int>> pacific, atlantic;
      
      for (int i = -1; i <= n; ++i) {
        pacific.push({-1, i});
        atlantic.push({m, i});
      }
      
      for (int i = -1; i <= m; ++i) {
        pacific.push({i, -1});
        atlantic.push({i, n});
      }
      
      while (!pacific.empty()) {
        auto [i, j] = pacific.front();
        pacific.pop();
        
        for (int k = 0; k < 4; ++k) {
          int ni = i + dx[k];
          int nj = j + dy[k];
          
          if (!is_valid(ni, nj) or visited[ni][nj].first)
            continue;
          
          if (!is_valid(i, j)) {
            pacific.push({ni, nj});
            visited[ni][nj].first = true;
          }
          else if (heights[ni][nj] >= heights[i][j]) {
            pacific.push({ni, nj});
            visited[ni][nj].first = true;
          }
        }
      }
      
      while (!atlantic.empty()) {
        auto [i, j] = atlantic.front();
        atlantic.pop();
        
        for (int k = 0; k < 4; ++k) {
          int ni = i + dx[k];
          int nj = j + dy[k];
          
          if (!is_valid(ni, nj) or visited[ni][nj].second)
            continue;
          
          if (!is_valid(i, j)) {
            atlantic.push({ni, nj});
            visited[ni][nj].second = true;
          }
          else if (heights[ni][nj] >= heights[i][j]) {
            atlantic.push({ni, nj});
            visited[ni][nj].second = true;
          }
        }
      }
      
      for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j)
          if (visited[i][j].first and visited[i][j].second)
            ans.push_back({i, j});
      }
      
      return ans;
    }
};
```

<br>

### Statistics

- total accepted: 276693
- total submissions: 522906
- acceptance rate: 52.9%
- likes: 5290
- dislikes: 1003

<br>

### Similar Problems

None
