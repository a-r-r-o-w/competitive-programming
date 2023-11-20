# [1314] Matrix Block Sum

**[array, matrix, prefix-sum]**

### Statement

Given a `m x n` matrix `mat` and an integer `k`, return *a matrix* `answer` *where each* `answer[i][j]` *is the sum of all elements* `mat[r][c]` *for*:

* `i - k <= r <= i + k,`
* `j - k <= c <= j + k`, and
* `(r, c)` is a valid position in the matrix.


**Example 1:**

```

**Input:** mat = [[1,2,3],[4,5,6],[7,8,9]], k = 1
**Output:** [[12,21,16],[27,45,33],[24,39,28]]

```

**Example 2:**

```

**Input:** mat = [[1,2,3],[4,5,6],[7,8,9]], k = 2
**Output:** [[45,45,45],[45,45,45],[45,45,45]]

```

**Constraints:**
* `m ==mat.length`
* `n ==mat[i].length`
* `1 <= m, n, k <= 100`
* `1 <= mat[i][j] <= 100`


<br>

### Hints

- How to calculate the required sum for a cell (i,j) fast ?
- Use the concept of cumulative sum array.
- Create a cumulative sum matrix where dp[i][j] is the sum of all cells in the rectangle from (0,0) to (i,j), use inclusion-exclusion idea.

<br>

### Solution

```cpp
class Solution {
  public:
    vector <vector <int>> matrixBlockSum (vector <vector <int>>& mat, int k) {
      int m = mat.size(), n = mat.front().size();
      std::vector <std::vector <int>> sum (m + 1, std::vector <int> (n + 1));

      for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j)
          sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + mat[i - 1][j - 1];
      }

      for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
          int l = std::max(0, j - k), r = std::min(n - 1, j + k);
          int u = std::max(0, i - k), d = std::min(m - 1, i + k);
          mat[i][j] = sum[d + 1][r + 1] - sum[d + 1][l] - sum[u][r + 1] + sum[u][l];
        }
      }

      return mat;
    }
};
```

<br>

### Statistics

- total accepted: 73383
- total submissions: 97312
- acceptance rate: 75.4%
- likes: 2059
- dislikes: 321

<br>

### Similar Problems

- [Stamping the Grid](https://leetcode.com/problems/stamping-the-grid) (Hard)
- [Maximum Sum of an Hourglass](https://leetcode.com/problems/maximum-sum-of-an-hourglass) (Medium)
