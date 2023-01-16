# [2536] Increment Submatrices by One



### Statement

You are given a positive integer `n`, indicating that we initially have an `n x n`**0-indexed** integer matrix `mat` filled with zeroes.

You are also given a 2D integer array `query`. For each `query[i] = [row1i, col1i, row2i, col2i]`, you should do the following operation:

* Add `1` to **every element** in the submatrix with the **top left** corner `(row1i, col1i)` and the **bottom right** corner `(row2i, col2i)`. That is, add `1` to `mat[x][y]` for for all `row1i <= x <= row2i` and `col1i <= y <= col2i`.



Return *the matrix* `mat` *after performing every query.*
**Example 1:**
![](https://assets.leetcode.com/uploads/2022/11/24/p2example11.png)

```

**Input:** n = 3, queries = [[1,1,2,2],[0,0,1,1]]
**Output:** [[1,1,0],[1,2,1],[0,1,1]]
**Explanation:** The diagram above shows the initial matrix, the matrix after the first query, and the matrix after the second query.
- In the first query, we add 1 to every element in the submatrix with the top left corner (1, 1) and bottom right corner (2, 2).
- In the second query, we add 1 to every element in the submatrix with the top left corner (0, 0) and bottom right corner (1, 1).

```

**Example 2:**
![](https://assets.leetcode.com/uploads/2022/11/24/p2example22.png)

```

**Input:** n = 2, queries = [[0,0,1,1]]
**Output:** [[1,1],[1,1]]
**Explanation:** The diagram above shows the initial matrix and the matrix after the first query.
- In the first query we add 1 to every element in the matrix.

```

**Constraints:**
* `1 <= n <= 500`
* `1 <= queries.length <= 104`
* `0 <= row1i <= row2i < n`
* `0 <= col1i <= col2i < n`


<br>

### Hints

- Imagine each row as a separate array. Instead of updating the whole submatrix together, we can use prefix sum to update each row separately.
- For each query, iterate over the rows i in the range [row1, row2] and add 1 to prefix sum S[i][col1], and subtract 1 from S[i][col2 + 1].
- After doing this operation for all the queries, update each row separately with S[i][j] = S[i][j] + S[i][j - 1].

<br>

### Solution

```cpp
class Solution {
  public:
    vector< vector <int>> rangeAddQueries (int n, vector <vector <int>>& queries) {
      std::vector <std::vector <int>> grid (n, std::vector <int> (n));
      
      for (auto &v: queries) {
        for (int i = v[0]; i <= v[2]; ++i) {
          grid[i][v[1]] += 1;
          if (v[3] + 1 < n)
            grid[i][v[3] + 1] -= 1;
        }
      }
      
      for (int i = 0; i < n; ++i) {
        for (int j = 1; j < n; ++j)
          grid[i][j] += grid[i][j - 1];
      }
      
      return grid;
    }
};
```

<br>

### Statistics

- total accepted: 8456
- total submissions: 20642
- acceptance rate: 41.0%
- likes: 76
- dislikes: 45

<br>

### Similar Problems

- [Range Sum Query 2D - Mutable](https://leetcode.com/problems/range-sum-query-2d-mutable) (Hard)
- [Count Positions on Street With Required Brightness](https://leetcode.com/problems/count-positions-on-street-with-required-brightness) (Medium)
