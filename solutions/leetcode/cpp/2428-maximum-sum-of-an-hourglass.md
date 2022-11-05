# [2428] Maximum Sum of an Hourglass

**[array, matrix, prefix-sum]**

### Statement

You are given an `m x n` integer matrix `grid`.

We define an **hourglass** as a part of the matrix with the following form:
![](https://assets.leetcode.com/uploads/2022/08/21/img.jpg)
Return *the **maximum** sum of the elements of an hourglass*.

**Note** that an hourglass cannot be rotated and must be entirely contained within the matrix.


**Example 1:**
![](https://assets.leetcode.com/uploads/2022/08/21/1.jpg)

```

**Input:** grid = [[6,2,1,3],[4,2,1,5],[9,2,8,7],[4,1,2,9]]
**Output:** 30
**Explanation:** The cells shown above represent the hourglass with the maximum sum: 6 + 2 + 1 + 2 + 9 + 2 + 8 = 30.

```

**Example 2:**
![](https://assets.leetcode.com/uploads/2022/08/21/2.jpg)

```

**Input:** grid = [[1,2,3],[4,5,6],[7,8,9]]
**Output:** 35
**Explanation:** There is only one hourglass in the matrix, with the sum: 1 + 2 + 3 + 5 + 7 + 8 + 9 = 35.

```

**Constraints:**
* `m == grid.length`
* `n == grid[i].length`
* `3 <= m, n <= 150`
* `0 <= grid[i][j] <= 106`


<br>

### Hints

- Each 3x3 submatrix has exactly one hourglass.
- Find the sum of each hourglass in the matrix and return the largest of these values.

<br>

### Solution

```cpp
class Solution {
  public:
    int maxSum (vector <vector <int>>& grid) {
      int m = grid.size();
      int n = grid.front().size();
      int max = 0;
      
      for (int i = 0; i + 2 < m; ++i) {
        for (int j = 0; j + 2 < n; ++j) {
          int sum = 0;
          
          for (int k = 0; k < 3; ++k) {
            for (int l = 0; l < 3; ++l) {
              sum += grid[i + k][j + l];
            }
          }
          
          max = std::max(max, sum - grid[i + 1][j] - grid[i + 1][j + 2]);
        }
      }
      
      return max;
    }
};
```

<br>

### Statistics

- total accepted: 17799
- total submissions: 24261
- acceptance rate: 73.4%
- likes: 146
- dislikes: 16

<br>

### Similar Problems

- [Matrix Block Sum](https://leetcode.com/problems/matrix-block-sum) (Medium)
