# [1289] Minimum Falling Path Sum II

**[array, dynamic-programming, matrix]**

### Statement

Given an `n x n` integer matrix `grid`, return *the minimum sum of a **falling path with non-zero shifts***.

A **falling path with non-zero shifts** is a choice of exactly one element from each row of `grid` such that no two elements chosen in adjacent rows are in the same column.


**Example 1:**
![](https://assets.leetcode.com/uploads/2021/08/10/falling-grid.jpg)

```

**Input:** arr = [[1,2,3],[4,5,6],[7,8,9]]
**Output:** 13
**Explanation:** 
The possible falling paths are:
[1,5,9], [1,5,7], [1,6,7], [1,6,8],
[2,4,8], [2,4,9], [2,6,7], [2,6,8],
[3,4,8], [3,4,9], [3,5,7], [3,5,9]
The falling path with the smallest sum is[1,5,7], so the answer is13.

```

**Example 2:**

```

**Input:** grid = [[7]]
**Output:** 7

```

**Constraints:**
* `n == grid.length == grid[i].length`
* `1 <= n <= 200`
* `-99 <= grid[i][j] <= 99`


<br />

### Hints

- Use dynamic programming.
- Let dp[i][j] be the answer for the first i rows such that column j is chosen from row i.
- Use the concept of cumulative array to optimize the complexity of the solution.

<br />

### Solution

```cpp
class Solution {
  public:
    int minFallingPathSum (vector <vector <int>>& grid) {
      int n = grid.size();

      for (int i = 1; i < n; ++i) {
        int mindex = -1, second_mindex = -1;
        for (int j = 0; j < n; ++j) {
          if (mindex == -1 or grid[i - 1][j] < grid[i - 1][mindex]) {
            second_mindex = mindex;
            mindex = j;
          }
          else if (second_mindex == -1 or grid[i - 1][j] < grid[i - 1][second_mindex])
            second_mindex = j;
        }
        for (int j = 0; j < n; ++j) {
          if (j != mindex and mindex != -1)
            grid[i][j] += grid[i - 1][mindex];
          else if (j != second_mindex and second_mindex != -1)
            grid[i][j] += grid[i - 1][second_mindex];
        }
      }

      return *std::min_element(grid.back().begin(), grid.back().end());
    }
};
```

<br />

### Statistics

- total accepted: 41095
- total submissions: 70320
- acceptance rate: 58.4%
- likes: 1383
- dislikes: 78

<br />

### Similar Problems

- [Minimum Falling Path Sum](https://leetcode.com/problems/minimum-falling-path-sum) (Medium)
