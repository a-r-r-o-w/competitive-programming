# [1155] Number of Dice Rolls With Target Sum

**[dynamic-programming]**

### Statement

You have `n` dice and each die has `k` faces numbered from `1` to `k`.

Given three integers `n`, `k`, and `target`, return *the number of possible ways (out of the* `kn` *total ways)* *to roll the dice so the sum of the face-up numbers equals* `target`. Since the answer may be too large, return it **modulo** `109 + 7`.


**Example 1:**

```

**Input:** n = 1, k = 6, target = 3
**Output:** 1
**Explanation:** You throw one die with 6 faces.
There is only one way to get a sum of 3.

```

**Example 2:**

```

**Input:** n = 2, k = 6, target = 7
**Output:** 6
**Explanation:** You throw two dice, each with 6 faces.
There are 6 ways to get a sum of 7: 1+6, 2+5, 3+4, 4+3, 5+2, 6+1.

```

**Example 3:**

```

**Input:** n = 30, k = 30, target = 500
**Output:** 222616187
**Explanation:** The answer must be returned modulo 109 + 7.

```

**Constraints:**
* `1 <= n, k <= 30`
* `1 <= target <= 1000`


<br>

### Hints

- Use dynamic programming.  The states are how many dice are remaining, and what sum total you have rolled so far.

<br>

### Solution

**Time:** O(n.k.target)

**Space:** O(n.target)

```cpp
class Solution {
  public:
    int numRollsToTarget (int n, int k, int target) {
      // dp[i][j]: number of ways to use i dice to get sum as j
      // dp[i][j] += dp[i - 1][j - x] for x in range(1, k)
      
      const int mod = 1000000007;
      
      std::vector <std::vector <int>> dp (n, std::vector <int> (target + 1));
      
      for (int i = 1; i <= std::min(k, target); ++i)
        dp[0][i] = 1;
      
      for (int i = 1; i < n; ++i) {
        for (int j = 0; j <= target; ++j) {
          for (int x = 1; x <= std::min(j, k); ++x) {
            dp[i][j] += dp[i - 1][j - x];
            if (dp[i][j] >= mod)
              dp[i][j] -= mod;
          }
        }
      }
      
      return dp[n - 1][target];
    }
};
```

**Time:** O(n.k.target)

**Space:** O(target)

```cpp
class Solution {
  public:
    int numRollsToTarget (int n, int k, int target) {
      // dp[i][j]: number of ways to use i dice to get sum as j
      // dp[i][j] += dp[i - 1][j - x] for x in range(1, k)
      
      const int mod = 1000000007;
      
      std::vector <std::vector <int>> dp (2, std::vector <int> (target + 1));
      
      for (int i = 1; i <= std::min(k, target); ++i)
        dp[0][i] = 1;
      
      for (int i = 1; i < n; ++i) {
        int p = i % 2;
        int q = (i + 1) % 2;
        
        for (int j = 0; j <= target; ++j) {
          dp[p][j] = 0;
          
          for (int x = 1; x <= std::min(j, k); ++x) {
            dp[p][j] += dp[q][j - x];
            
            if (dp[p][j] >= mod)
              dp[p][j] -= mod;
          }
        }
      }
      
      return dp[(n + 1) % 2][target];
    }
};
```

<br>

### Statistics

- total accepted: 139920
- total submissions: 274087
- acceptance rate: 51.0%
- likes: 2990
- dislikes: 105

<br>

### Similar Problems

- [Equal Sum Arrays With Minimum Number of Operations](https://leetcode.com/problems/equal-sum-arrays-with-minimum-number-of-operations) (Medium)
- [Find Missing Observations](https://leetcode.com/problems/find-missing-observations) (Medium)
