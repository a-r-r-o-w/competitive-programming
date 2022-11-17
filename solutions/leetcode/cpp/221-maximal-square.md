# [221] Maximal Square

**[array, dynamic-programming, matrix]**

### Statement

Given an `m x n` binary `matrix` filled with `0`'s and `1`'s, *find the largest square containing only* `1`'s *and return its area*.


**Example 1:**
![](https://assets.leetcode.com/uploads/2020/11/26/max1grid.jpg)

```

**Input:** matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
**Output:** 4

```

**Example 2:**
![](https://assets.leetcode.com/uploads/2020/11/26/max2grid.jpg)

```

**Input:** matrix = [["0","1"],["1","0"]]
**Output:** 1

```

**Example 3:**

```

**Input:** matrix = [["0"]]
**Output:** 0

```

**Constraints:**
* `m == matrix.length`
* `n == matrix[i].length`
* `1 <= m, n <= 300`
* `matrix[i][j]` is `'0'` or `'1'`.


<br>

### Hints

None

<br>

### Solution

**Time: O(n.m)**
**Space: O(n.m)**

```cpp
class Solution {
  public:
    Solution () {
      std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);
    }
  
    int maximalSquare (vector <vector <char>>& matrix) {
      int m = matrix.size();
      int n = matrix.front().size();
      std::vector <std::vector <int>> dp (m, std::vector <int> (n));
      int max = 0;
      
      for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
          if (matrix[i][j] == '0')
            dp[i][j] = 0;
          else {
            if (i and j)
              dp[i][j] = std::min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
            else
              dp[i][j] = 1;
          }
          max = std::max(max, dp[i][j]);
        }
      }
      
      return max * max;
    }
};
```

**Time: O(n.m)**
**Space: O(n)**

```cpp
class Solution {
  public:
    Solution () {
      std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);
    }
  
    int maximalSquare (vector <vector <char>>& matrix) {
      int m = matrix.size();
      int n = matrix.front().size();
      std::vector <std::vector <int>> dp (2, std::vector <int> (n));
      int max = 0;
      
      for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
          if (matrix[i][j] == '0')
            dp[i % 2][j] = 0;
          else {
            if (i and j)
              dp[i % 2][j] = std::min({dp[(i + 1) % 2][j], dp[i % 2][j - 1], dp[(i + 1) % 2][j - 1]}) + 1;
            else
              dp[i % 2][j] = 1;
          }
          max = std::max(max, dp[i % 2][j]);
        }
      }
      
      return max * max;
    }
};
```

<br>

### Statistics

- total accepted: 535424
- total submissions: 1208246
- acceptance rate: 44.3%
- likes: 8039
- dislikes: 174

<br>

### Similar Problems

- [Maximal Rectangle](https://leetcode.com/problems/maximal-rectangle) (Hard)
- [Largest Plus Sign](https://leetcode.com/problems/largest-plus-sign) (Medium)
- [Count Artifacts That Can Be Extracted](https://leetcode.com/problems/count-artifacts-that-can-be-extracted) (Medium)
- [Stamping the Grid](https://leetcode.com/problems/stamping-the-grid) (Hard)
