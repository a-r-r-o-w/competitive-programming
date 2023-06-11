# [2732] Find a Good Subset of the Matrix



### Statement

You are given a **0-indexed** `m x n` binary matrix `grid`.

Let us call a **non-empty** subset of rows **good** if the sum of each column of the subset is at most half of the length of the subset.

More formally, if the length of the chosen subset of rows is `k`, then the sum of each column should be at most `floor(k / 2)`.

Return *an integer array that contains row indices of a good subset sorted in **ascending** order.*

If there are multiple good subsets, you can return any of them. If there are no good subsets, return an empty array.

A **subset** of rows of the matrix `grid` is any matrix that can be obtained by deleting some (possibly none or all) rows from `grid`.


**Example 1:**

```

**Input:** grid = [[0,1,1,0],[0,0,0,1],[1,1,1,1]]
**Output:** [0,1]
**Explanation:** We can choose the 0^th and 1^st rows to create a good subset of rows.
The length of the chosen subset is 2.
- The sum of the 0^thcolumn is 0 + 0 = 0, which is at most half of the length of the subset.
- The sum of the 1^stcolumn is 1 + 0 = 1, which is at most half of the length of the subset.
- The sum of the 2^ndcolumn is 1 + 0 = 1, which is at most half of the length of the subset.
- The sum of the 3^rdcolumn is 0 + 1 = 1, which is at most half of the length of the subset.

```

**Example 2:**

```

**Input:** grid = [[0]]
**Output:** [0]
**Explanation:** We can choose the 0^th row to create a good subset of rows.
The length of the chosen subset is 1.
- The sum of the 0^thcolumn is 0, which is at most half of the length of the subset.

```

**Example 3:**

```

**Input:** grid = [[1,1,1],[1,1,1]]
**Output:** []
**Explanation:** It is impossible to choose any subset of rows to create a good subset.

```

**Constraints:**
* `m == grid.length`
* `n == grid[i].length`
* `1 <= m <= 10^4`
* `1 <= n <= 5`
* `grid[i][j]` is either `0` or `1`.


<br />

### Hints

- It can be proven, that if there exists a good subset of rows then there exists a good subset of rows with the size of either 1 or 2.
- To check if there exists a good subset of rows of size 1, we check if there exists a row containing only zeros, if it does, we return its index as a good subset.
- To check if there exists a good subset of rows of size 2, we iterate over two bit-masks, check if both are presented in the array and if they form a good subset, if they do, return their indices as a good subset.

<br />

### Solution

```cpp
class Solution {
  public:
    vector <int> goodSubsetofBinaryMatrix (vector <vector <int>>& grid) {
      int m = grid.size(), n = grid.front().size();
      std::vector <std::vector <int>> map (n + 1);
      std::vector <int> bitmap (m);
      
      for (int i = 0; i < m; ++i) {
        int count = 0;
        for (int j = 0; j < n; ++j) {
          count += grid[i][j];
          if (grid[i][j])
            bitmap[i] |= 1 << j;
        }
        map[count].push_back(i);
      }
      
      if (!map[0].empty())
        return {map[0].front()};
      
      for (int i = 1; i < n; ++i) {
        for (int j = i; j <= n - i; ++j) {
          for (int k: map[i]) {
            for (int l: map[j]) {
              if (k == l)
                continue;
              if (bitmap[k] & bitmap[l])
                continue;
              if (k < l)
                return {k, l};
              else
                return {l, k};
            }
          }
        }
      }
      
      return {};
    }
};
```

<br />

### Statistics

- total accepted: 2749
- total submissions: 7333
- acceptance rate: 37.5%
- likes: 79
- dislikes: 6

<br />

### Similar Problems

None
