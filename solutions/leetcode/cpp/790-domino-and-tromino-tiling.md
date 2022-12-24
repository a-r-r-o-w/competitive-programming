# [790] Domino and Tromino Tiling

**[dynamic-programming]**

### Statement

You have two types of tiles: a `2 x 1` domino shape and a tromino shape. You may rotate these shapes.
![](https://assets.leetcode.com/uploads/2021/07/15/lc-domino.jpg)
Given an integer n, return *the number of ways to tile an* `2 x n` *board*. Since the answer may be very large, return it **modulo** `109 + 7`.

In a tiling, every square must be covered by a tile. Two tilings are different if and only if there are two 4-directionally adjacent cells on the board such that exactly one of the tilings has both squares occupied by a tile.


**Example 1:**
![](https://assets.leetcode.com/uploads/2021/07/15/lc-domino1.jpg)

```

**Input:** n = 3
**Output:** 5
**Explanation:** The five different ways are show above.

```

**Example 2:**

```

**Input:** n = 1
**Output:** 1

```

**Constraints:**
* `1 <= n <= 1000`


<br>

### Hints

None

<br>

### Solution

```cpp
class Solution {
  public:
    int numTilings (int n) {
      constexpr int64_t mod = 1000000007;
      std::vector <int64_t> dp (n + 1);
      int64_t sum = 0;

      dp[0] = 1;

      for (int i = 1; i <= n; ++i) {
        dp[i] += dp[i - 1];
        
        if (i - 2 >= 0)
          dp[i] += dp[i - 2];
        
        if (i - 3 >= 0) {
          sum += dp[i - 3];
          sum %= mod;
        }
        
        dp[i] += 2 * sum;
        dp[i] %= mod;
      }

      return dp[n];
    }
};
```

<br>

### Statistics

- total accepted: 60436
- total submissions: 122423
- acceptance rate: 49.4%
- likes: 1906
- dislikes: 676

<br>

### Similar Problems

None
