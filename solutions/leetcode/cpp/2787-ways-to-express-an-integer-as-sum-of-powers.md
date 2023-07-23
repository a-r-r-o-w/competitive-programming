# [2787] Ways to Express an Integer as Sum of Powers



### Statement

Given two **positive** integers `n` and `x`.

Return *the number of ways* `n` *can be expressed as the sum of the* `x^th` *power of **unique** positive integers, in other words, the number of sets of unique integers* `[n1, n2, ..., nk]` *where* `n = n1^x + n2^x + ... + nk^x`*.*

Since the result can be very large, return it modulo `10^9 + 7`.

For example, if `n = 160` and `x = 3`, one way to express `n` is `n = 2^3 + 3^3 + 5^3`.


**Example 1:**

```

**Input:** n = 10, x = 2
**Output:** 1
**Explanation:** We can express n as the following: n = 3^2 + 1^2 = 10.
It can be shown that it is the only way to express 10 as the sum of the 2^nd power of unique integers.

```

**Example 2:**

```

**Input:** n = 4, x = 1
**Output:** 2
**Explanation:** We can express n in the following ways:
- n = 4^1 = 4.
- n = 3^1 + 1^1 = 4.

```

**Constraints:**
* `1 <= n <= 300`
* `1 <= x <= 5`


<br />

### Hints

- You can use dynamic programming, where dp[k][j] represents the number of ways to express k as the sum of the x-th power of unique positive integers such that the biggest possible number we use is j.
- To calculate dp[k][j], you can iterate over the numbers smaller than j and try to use each one as a power of x to make our sum k.

<br />

### Solution

```cpp
class Solution {
  public:
    int numberOfWays (int n, int x) {
      const int mod = 1000000007, max = 300 + 1;
      std::vector dp (n + 1, std::vector(max, -1));
      
      auto dfs = [&] (auto self, int n, int i) -> int {
        if (n == 0)
          return 1;
        if (i >= max)
          return 0;
        if (dp[n][i] != -1)
          return dp[n][i];
        int64_t ways = 0, p = pow(i, x);
        if (n - p >= 0)
          ways += self(self, n - p, i + 1);
        ways += self(self, n, i + 1);
        return dp[n][i] = ways % mod;
      };
      
      return dfs(dfs, n, 1);
    }
};
```

<br />

### Statistics

- total accepted: 4920
- total submissions: 19253
- acceptance rate: 25.6%
- likes: 21
- dislikes: 2

<br />

### Similar Problems

- [Perfect Squares](https://leetcode.com/problems/perfect-squares) (Medium)
- [Combination Sum IV](https://leetcode.com/problems/combination-sum-iv) (Medium)
- [Target Sum](https://leetcode.com/problems/target-sum) (Medium)
