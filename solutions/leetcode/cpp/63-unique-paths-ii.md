# [63] Unique Paths II

**[array, dynamic-programming, matrix]**

### Statement

You are given an `m x n` integer array `grid`. There is a robot initially located at the **top-left corner** (i.e., `grid[0][0]`). The robot tries to move to the **bottom-right corner** (i.e., `grid[m-1][n-1]`). The robot can only move either down or right at any point in time.

An obstacle and space are marked as `1` or `0` respectively in `grid`. A path that the robot takes cannot include **any** square that is an obstacle.

Return *the number of possible unique paths that the robot can take to reach the bottom-right corner*.

The testcases are generated so that the answer will be less than or equal to `2 * 109`.


**Example 1:**
![](https://assets.leetcode.com/uploads/2020/11/04/robot1.jpg)

```

**Input:** obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
**Output:** 2
**Explanation:** There is one obstacle in the middle of the 3x3 grid above.
There are two ways to reach the bottom-right corner:
1. Right -> Right -> Down -> Down
2. Down -> Down -> Right -> Right

```

**Example 2:**
![](https://assets.leetcode.com/uploads/2020/11/04/robot2.jpg)

```

**Input:** obstacleGrid = [[0,1],[0,0]]
**Output:** 1

```

**Constraints:**
* `m == obstacleGrid.length`
* `n == obstacleGrid[i].length`
* `1 <= m, n <= 100`
* `obstacleGrid[i][j]` is `0` or `1`.


<br>

### Hints

- The robot can only move either down or right. Hence any cell in the first row can only be reached from the cell left to it. However, if any cell has an obstacle, you don't let that cell contribute to any path. So, for the first row, the number of ways will simply be 

<pre>
if obstacleGrid[i][j] is not an obstacle
     obstacleGrid[i,j] = obstacleGrid[i,j - 1] 
else
     obstacleGrid[i,j] = 0
</pre>

You can do a similar processing for finding out the number of ways of reaching the cells in the first column.
- For any other cell, we can find out the number of ways of reaching it, by making use of the number of ways of reaching the cell directly above it and the cell to the left of it in the grid. This is because these are the only two directions from which the robot can come to the current cell.
- Since we are making use of pre-computed values along the iteration, this becomes a dynamic programming problem.

<pre>
if obstacleGrid[i][j] is not an obstacle
     obstacleGrid[i,j] = obstacleGrid[i,j - 1]  + obstacleGrid[i - 1][j]
else
     obstacleGrid[i,j] = 0
</pre>

</pre>

<br>

### Solution

Time: O(m.n)
Space: O(m.n)

```cpp
class Solution {
  public:
    int uniquePathsWithObstacles (vector <vector <int>>& obstacleGrid) {
      int m = obstacleGrid.size(), n = obstacleGrid.front().size();
      std::vector <std::vector <int>> dp (m, std::vector <int> (n));
      dp[0][0] = obstacleGrid[0][0] == 0;
      
      for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
          if (obstacleGrid[i][j] == 1)
            continue;
          
          if (i)
            dp[i][j] += dp[i - 1][j];
          if (j)
            dp[i][j] += dp[i][j - 1];
        }
      }
      
      return dp[m - 1][n - 1];
    }
};
```

Time: O(m.n)
Space: O(n)

```cpp
class Solution {
  public:
    int uniquePathsWithObstacles (vector <vector <int>>& obstacleGrid) {
      int m = obstacleGrid.size(), n = obstacleGrid.front().size();
      std::vector <std::vector <int>> dp (2, std::vector <int> (n));
      dp[0][0] = obstacleGrid[0][0] == 0;
      
      for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
          if (obstacleGrid[i][j] == 1) {
            dp[i % 2][j] = 0;
            continue;
          }
          
          if (i and j)
            dp[i % 2][j] = dp[(i + 1) % 2][j] + dp[i % 2][j - 1];
          else if (i)
            dp[i % 2][j] = dp[(i + 1) % 2][j];
          else if (j)
            dp[i % 2][j] = dp[i % 2][j - 1];
        }
      }
      
      return dp[(m + 1) % 2][n - 1];
    }
};
```

<br>

### Statistics

- total accepted: 557888
- total submissions: 1446684
- acceptance rate: 38.6%
- likes: 5338
- dislikes: 393

<br>

### Similar Problems

- [Unique Paths](https://leetcode.com/problems/unique-paths) (Medium)
- [Unique Paths III](https://leetcode.com/problems/unique-paths-iii) (Hard)
- [Minimum Path Cost in a Grid](https://leetcode.com/problems/minimum-path-cost-in-a-grid) (Medium)
