# [343] Integer Break

**[math, dynamic-programming]**

### Statement

Given an integer `n`, break it into the sum of `k` **positive integers**, where `k >= 2`, and maximize the product of those integers.

Return *the maximum product you can get*.


**Example 1:**

```

**Input:** n = 2
**Output:** 1
**Explanation:** 2 = 1 + 1, 1 × 1 = 1.

```

**Example 2:**

```

**Input:** n = 10
**Output:** 36
**Explanation:** 10 = 3 + 3 + 4, 3 × 3 × 4 = 36.

```

**Constraints:**
* `2 <= n <= 58`


<br>

### Hints

- There is a simple O(n) solution to this problem.
- You may check the breaking results of <i>n</i> ranging from 7 to 10 to discover the regularities.

<br>

### Solution

```cpp
class Solution {
  public:
    int integerBreak (int n) {
      // dp[i][j]: max product using i integers that sum to j
      // dp[i][j] = dp[i - 1][j - v] * v

      std::vector <std::vector <int>> dp (n + 1, std::vector <int> (n + 1));
      dp[0][0] = 1;

      for (int i = 1; i <= n; ++i) {
        for (int j = i; j <= n; ++j) {
          for (int v = 0; v <= j; ++v)
            dp[i][j] = std::max(dp[i][j], dp[i - 1][j - v] * v);
        }
      }

      int max = 0;
      for (int i = 2; i <= n; ++i)
        max = std::max(max, dp[i][n]);
      
      return max;
    }
};
```

<br>

### Statistics

- total accepted: 220438
- total submissions: 395716
- acceptance rate: 55.7%
- likes: 3440
- dislikes: 356

<br>

### Similar Problems

- [Maximize Number of Nice Divisors](https://leetcode.com/problems/maximize-number-of-nice-divisors) (Hard)
