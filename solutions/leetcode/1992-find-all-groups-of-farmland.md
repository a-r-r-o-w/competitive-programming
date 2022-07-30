# [1992] Find All Groups of Farmland

**[array, depth-first-search, breadth-first-search, matrix]**

### Statement

You are given a **0-indexed** `m x n` binary matrix `land` where a `0` represents a hectare of forested land and a `1` represents a hectare of farmland.

To keep the land organized, there are designated rectangular areas of hectares that consist **entirely** of farmland. These rectangular areas are called **groups**. No two groups are adjacent, meaning farmland in one group is **not** four-directionally adjacent to another farmland in a different group.

`land` can be represented by a coordinate system where the top left corner of `land` is `(0, 0)` and the bottom right corner of `land` is `(m-1, n-1)`. Find the coordinates of the top left and bottom right corner of each **group** of farmland. A **group** of farmland with a top left corner at `(r1, c1)` and a bottom right corner at `(r2, c2)` is represented by the 4-length array `[r1, c1, r2, c2].`

Return *a 2D array containing the 4-length arrays described above for each **group** of farmland in* `land`*. If there are no groups of farmland, return an empty array. You may return the answer in **any order***.


**Example 1:**
![](https://assets.leetcode.com/uploads/2021/07/27/screenshot-2021-07-27-at-12-23-15-copy-of-diagram-drawio-diagrams-net.png)

```

**Input:** land = [[1,0,0],[0,1,1],[0,1,1]]
**Output:** [[0,0,0,0],[1,1,2,2]]
**Explanation:**
The first group has a top left corner at land[0][0] and a bottom right corner at land[0][0].
The second group has a top left corner at land[1][1] and a bottom right corner at land[2][2].

```

**Example 2:**
![](https://assets.leetcode.com/uploads/2021/07/27/screenshot-2021-07-27-at-12-30-26-copy-of-diagram-drawio-diagrams-net.png)

```

**Input:** land = [[1,1],[1,1]]
**Output:** [[0,0,1,1]]
**Explanation:**
The first group has a top left corner at land[0][0] and a bottom right corner at land[1][1].

```

**Example 3:**
![](https://assets.leetcode.com/uploads/2021/07/27/screenshot-2021-07-27-at-12-32-24-copy-of-diagram-drawio-diagrams-net.png)

```

**Input:** land = [[0]]
**Output:** []
**Explanation:**
There are no groups of farmland.

```

**Constraints:**
* `m == land.length`
* `n == land[i].length`
* `1 <= m, n <= 300`
* `land` consists of only `0`'s and `1`'s.
* Groups of farmland are **rectangular** in shape.


<br>

### Hints

- Since every group of farmland is rectangular, the top left corner of each group will have the smallest x-coordinate and y-coordinate of any farmland in the group.
- Similarly, the bootm right corner of each group will have the largest x-coordinate and y-coordinate of any farmland in the group.
- Use DFS to traverse through different groups of farmlands and keep track of the smallest and largest x-coordinate and y-coordinates you have seen in each group.

<br>

### Solution

```cpp
class Solution {
  public:
    Solution () {
      std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);
    }
  
    vector <vector <int>> findFarmland (vector <vector <int>>& land) {
      int m = land.size();
      int n = land.front().size();
      std::vector <std::vector <int>> ans;
      
      for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
          if (land[i][j] == 0)
            continue;
          
          int r = i, c = j;
          
          while (c < n and land[i][c] == 1)
            ++c;
          while (r < m and land[r][j] == 1)
            ++r;
          
          --r;
          --c;
          
          for (int a = i; a <= r; ++a)
            for (int b = j; b <= c; ++b)
              land[a][b] = 0;
          
          ans.push_back({i, j, r, c});
        }
      }
      
      return ans;
    }
};
```

<br>

### Statistics

- total accepted: 16048
- total submissions: 23635
- acceptance rate: 67.9%
- likes: 451
- dislikes: 18

<br>

### Similar Problems

- [Number of Islands](https://leetcode.com/problems/number-of-islands) (Medium)
- [Count Sub Islands](https://leetcode.com/problems/count-sub-islands) (Medium)
