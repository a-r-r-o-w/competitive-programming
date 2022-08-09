# [322] Coin Change

**[array, dynamic-programming, breadth-first-search]**

### Statement

You are given an integer array `coins` representing coins of different denominations and an integer `amount` representing a total amount of money.

Return *the fewest number of coins that you need to make up that amount*. If that amount of money cannot be made up by any combination of the coins, return `-1`.

You may assume that you have an infinite number of each kind of coin.


**Example 1:**

```

**Input:** coins = [1,2,5], amount = 11
**Output:** 3
**Explanation:** 11 = 5 + 5 + 1

```

**Example 2:**

```

**Input:** coins = [2], amount = 3
**Output:** -1

```

**Example 3:**

```

**Input:** coins = [1], amount = 0
**Output:** 0

```

**Constraints:**
* `1 <= coins.length <= 12`
* `1 <= coins[i] <= 231 - 1`
* `0 <= amount <= 104`


<br>

### Hints

None

<br>

### Solution

```cpp
class Solution {
  public:
    Solution () {
      std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);
    }
  
    int coinChange (vector <int>& coins, int amount) {
      const int inf32 = 1 << 30;
      std::vector <int> dp (amount + 1, inf32);
      dp[0] = 0;
      
      for (int i = 1; i <= amount; ++i) {
        for (int n: coins)
          if (i - n >= 0)
            dp[i] = std::min(dp[i], dp[i - n] + 1);
          else break;
      }
      
      return dp[amount] == inf32 ? -1 : dp[amount];
    }
};
```

<br>

### Statistics

- total accepted: 1122714
- total submissions: 2735329
- acceptance rate: 41.0%
- likes: 13130
- dislikes: 293

<br>

### Similar Problems

- [Minimum Cost For Tickets](https://leetcode.com/problems/minimum-cost-for-tickets) (Medium)
- [Maximum Value of K Coins From Piles](https://leetcode.com/problems/maximum-value-of-k-coins-from-piles) (Hard)
- [Minimum Number of Operations to Convert Time](https://leetcode.com/problems/minimum-number-of-operations-to-convert-time) (Easy)
