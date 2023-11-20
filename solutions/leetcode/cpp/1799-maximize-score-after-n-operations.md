# [1799] Maximize Score After N Operations

**[array, math, dynamic-programming, backtracking, bit-manipulation, number-theory, bitmask]**

### Statement

You are given `nums`, an array of positive integers of size `2 * n`. You must perform `n` operations on this array.

In the `i^th` operation **(1-indexed)**, you will:

* Choose two elements, `x` and `y`.
* Receive a score of `i * gcd(x, y)`.
* Remove `x` and `y` from `nums`.



Return *the maximum score you can receive after performing* `n` *operations.*

The function `gcd(x, y)` is the greatest common divisor of `x` and `y`.


**Example 1:**

```

**Input:** nums = [1,2]
**Output:** 1
**Explanation:**The optimal choice of operations is:
(1 * gcd(1, 2)) = 1

```

**Example 2:**

```

**Input:** nums = [3,4,6,8]
**Output:** 11
**Explanation:**The optimal choice of operations is:
(1 * gcd(3, 6)) + (2 * gcd(4, 8)) = 3 + 8 = 11

```

**Example 3:**

```

**Input:** nums = [1,2,3,4,5,6]
**Output:** 14
**Explanation:**The optimal choice of operations is:
(1 * gcd(1, 5)) + (2 * gcd(2, 4)) + (3 * gcd(3, 6)) = 1 + 4 + 9 = 14

```

**Constraints:**
* `1 <= n <= 7`
* `nums.length == 2 * n`
* `1 <= nums[i] <= 10^6`


<br />

### Hints

- Find every way to split the array until n groups of 2. Brute force recursion is acceptable.
- Calculate the gcd of every pair and greedily multiply the largest gcds.

<br />

### Solution

```cpp
class Solution {
  public:
    int maxScore (vector <int>& nums) {
      const int mx = 14;
      int n = nums.size();
      std::vector <std::vector <int>> dp (7, std::vector <int> (1 << mx, -1));

      auto dfs = [&] (auto self, int operation, int mask) -> int {
        if (operation > n / 2)
          return 0;
        if (dp[operation - 1][mask] != -1)
          return dp[operation - 1][mask];
        int max = 0;
        for (int i = 0; i < n; ++i) {
          if (mask & (1 << i))
            continue;
          for (int j = i + 1; j < n; ++j) {
            if (mask & (1 << j))
              continue;
            max = std::max(max, self(self, operation + 1, mask | (1 << i) | (1 << j)) + operation * std::gcd(nums[i], nums[j]));
          }
        }
        return dp[operation - 1][mask] = max;
      };

      return dfs(dfs, 1, 0);
    }
};
```

<br />

### Statistics

- total accepted: 22845
- total submissions: 44954
- acceptance rate: 50.8%
- likes: 726
- dislikes: 63

<br />

### Similar Problems

None
