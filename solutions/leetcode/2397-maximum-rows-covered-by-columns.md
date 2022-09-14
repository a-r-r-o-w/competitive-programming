# [2397] Maximum Rows Covered by Columns



### Statement

You are given a **0-indexed** `m x n` binary matrix `mat` and an integer `cols`, which denotes the number of columns you must choose.

A row is **covered** by a set of columns if each cell in the row that has a value of `1` also lies in one of the columns of the chosen set.

Return *the **maximum** number of rows that can be **covered** by a set of* `cols` *columns.*
**Example 1:**
**![](https://assets.leetcode.com/uploads/2022/07/14/rowscovered.png)**

```

**Input:** mat = [[0,0,0],[1,0,1],[0,1,1],[0,0,1]], cols = 2
**Output:** 3
**Explanation:**
As shown in the diagram above, one possible way of covering 3 rows is by selecting the 0th and 2nd columns.
It can be shown that no more than 3 rows can be covered, so we return 3.

```

**Example 2:**
**![](https://assets.leetcode.com/uploads/2022/07/14/rowscovered2.png)**

```

**Input:** mat = [[1],[0]], cols = 1
**Output:** 2
**Explanation:**
Selecting the only column will result in both rows being covered, since the entire matrix is selected.
Therefore, we return 2.

```

**Constraints:**
* `m == mat.length`
* `n == mat[i].length`
* `1 <= m, n <= 12`
* `mat[i][j]` is either `0` or `1`.
* `1 <= cols <= n`


<br>

### Hints

- Try a brute-force approach.
- Iterate through all possible sets of exactly <code>cols</code> columns.
- For each valid set, check how many rows are covered, and return the maximum.

<br>

### Solution

```cpp
class Solution {
  public:
    int maximumRows (vector<vector <int>>& mat, int cols) {
      int m = mat.size();
      int n = mat.front().size();
      int ans = 0;
      
      for (int i = 0; i < 1 << n; ++i) {
        if (__builtin_popcount(i) > cols)
          continue;
        
        int count = 0;
        
        for (int j = 0; j < m; ++j) {
          bool good = true;
          
          for (int k = 0; k < n; ++k) {
            if (mat[j][k] == 0)
              continue;
            if (i & (1 << k))
              continue;
            good = false;
            break;
          }
          
          if (good)
            ++count;
        }
        
        ans = std::max(ans, count);
      }
      
      return ans;
    }
};
```

<br>

### Statistics

- total accepted: 6058
- total submissions: 13502
- acceptance rate: 44.9%
- likes: 62
- dislikes: 157

<br>

### Similar Problems

- [Matchsticks to Square](https://leetcode.com/problems/matchsticks-to-square) (Medium)
- [Partition to K Equal Sum Subsets](https://leetcode.com/problems/partition-to-k-equal-sum-subsets) (Medium)
- [Find the Shortest Superstring](https://leetcode.com/problems/find-the-shortest-superstring) (Hard)
- [Smallest Sufficient Team](https://leetcode.com/problems/smallest-sufficient-team) (Hard)
- [Fair Distribution of Cookies](https://leetcode.com/problems/fair-distribution-of-cookies) (Medium)
