# [1267] Count Servers that Communicate

**[array, depth-first-search, breadth-first-search, union-find, matrix, counting]**

### Statement

You are given a map of a server center, represented as a `m * n` integer matrix`grid`, where 1 means that on that cell there is a server and 0 means that it is no server. Two servers are said to communicate if they are on the same row or on the same column.  

  

Return the number of serversthat communicate with any other server.


**Example 1:**
![](https://assets.leetcode.com/uploads/2019/11/14/untitled-diagram-6.jpg)

```

**Input:** grid = [[1,0],[0,1]]
**Output:** 0
**Explanation:**No servers can communicate with others.
```

**Example 2:**
**![](https://assets.leetcode.com/uploads/2019/11/13/untitled-diagram-4.jpg)**

```

**Input:** grid = [[1,0],[1,1]]
**Output:** 3
**Explanation:**All three servers can communicate with at least one other server.

```

**Example 3:**
![](https://assets.leetcode.com/uploads/2019/11/14/untitled-diagram-1-3.jpg)

```

**Input:** grid = [[1,1,0,0],[0,0,1,0],[0,0,1,0],[0,0,0,1]]
**Output:** 4
**Explanation:**The two servers in the first row can communicate with each other. The two servers in the third column can communicate with each other. The server at right bottom corner can't communicate with any other server.

```

**Constraints:**
* `m == grid.length`
* `n == grid[i].length`
* `1 <= m <= 250`
* `1 <= n <= 250`
* `grid[i][j] == 0 or 1`


<br>

### Hints

- Store number of computer in each row and column.
- Count all servers that are not isolated.

<br>

### Solution

```cpp
class Solution {
  public:
    int countServers (vector <vector <int>>& grid) {
      int m = grid.size(), n = grid.front().size(), ans = 0;
      std::vector <int> rows (m), cols (n);

      for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
          if (grid[i][j] == 1) {
            ++rows[i];
            ++cols[j];
          }
        }
      }

      for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
          if (grid[i][j] == 1 and (rows[i] > 1 or cols[j] > 1))
            ++ans;
        }
      }

      return ans;
    }
};
```

<br>

### Statistics

- total accepted: 49955
- total submissions: 84147
- acceptance rate: 59.4%
- likes: 1096
- dislikes: 77

<br>

### Similar Problems

None
