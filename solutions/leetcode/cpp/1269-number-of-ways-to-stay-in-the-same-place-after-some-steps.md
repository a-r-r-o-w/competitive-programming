# [1269] Number of Ways to Stay in the Same Place After Some Steps

**[dynamic-programming]**

### Statement

You have a pointer at index `0` in an array of size `arrLen`. At each step, you can move 1 position to the left, 1 position to the right in the array, or stay in the same place (The pointer should not be placed outside the array at any time).

Given two integers `steps` and `arrLen`, return the number of ways such that your pointer is still at index `0` after **exactly** `steps` steps. Since the answer may be too large, return it **modulo** `10^9 + 7`.


**Example 1:**

```

**Input:** steps = 3, arrLen = 2
**Output:** 4
**Explanation:** There are 4 differents ways to stay at index 0 after 3 steps.
Right, Left, Stay
Stay, Right, Left
Right, Stay, Left
Stay, Stay, Stay

```

**Example 2:**

```

**Input:** steps = 2, arrLen = 4
**Output:** 2
**Explanation:** There are 2 differents ways to stay at index 0 after 2 steps
Right, Left
Stay, Stay

```

**Example 3:**

```

**Input:** steps = 4, arrLen = 2
**Output:** 8

```

**Constraints:**
* `1 <= steps <= 500`
* `1 <= arrLen <= 10^6`


<br />

### Hints

- Try with Dynamic programming, dp(pos,steps): number of ways to back pos = 0 using exactly "steps" moves.
- Notice that the computational complexity does not depend of "arrlen".

<br />

### Solution

```cpp
class Solution {
  public:
    int numWays(int steps, int arrLen) {
      const int mod = 1000000007;
      int m = std::min(steps, arrLen);
      std::vector dp(steps, std::vector<int64_t>(m, -1));

      auto dfs = [&] (auto &&self, int step, int location) -> int64_t {
        if (step >= steps)
          return location == 0;
        if (dp[step][location] != -1)
          return dp[step][location];
        int64_t ans = 0;
        if (location + 1 < arrLen)
          ans = (ans + self(self, step + 1, location + 1)) % mod;
        if (location - 1 >= 0)
          ans = (ans + self(self, step + 1, location - 1)) % mod;
        ans = (ans + self(self, step + 1, location)) % mod;
        return dp[step][location] = ans;
      };

      return dfs(dfs, 0, 0);
    }
};
```

<br />

### Statistics

- total accepted: 37383
- total submissions: 84019
- acceptance rate: 44.5%
- likes: 783
- dislikes: 42

<br />

### Similar Problems

- [Number of Ways to Reach a Position After Exactly k Steps](https://leetcode.com/problems/number-of-ways-to-reach-a-position-after-exactly-k-steps) (Medium)
