# [188] Best Time to Buy and Sell Stock IV

**[array, dynamic-programming]**

### Statement

You are given an integer array `prices` where `prices[i]` is the price of a given stock on the `ith` day, and an integer `k`.

Find the maximum profit you can achieve. You may complete at most `k` transactions.

**Note:** You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).


**Example 1:**

```

**Input:** k = 2, prices = [2,4,1]
**Output:** 2
**Explanation:** Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4-2 = 2.

```

**Example 2:**

```

**Input:** k = 2, prices = [3,2,6,5,0,3]
**Output:** 7
**Explanation:** Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit = 6-2 = 4. Then buy on day 5 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.

```

**Constraints:**
* `0 <= k <= 100`
* `0 <= prices.length <= 1000`
* `0 <= prices[i] <= 1000`


<br>

### Hints

None

<br>

### Solution

```cpp
template <typename T>
using v = std::vector <T>;

class Solution {
  public:
    int maxProfit (int k, vector <int>& prices) {
      int n = prices.size();
      v <v <v <int>>> dp (2, v <v <int>> (k + 1, v <int> (n + 1, -1)));
      
      auto dfs = [&] (auto self, int index, int transactions, bool can_buy) -> int {
        if (index >= n or transactions > k)
          return 0;
        if (dp[can_buy][transactions][index] != -1)
          return dp[can_buy][transactions][index];
        
        int profit;
        
        if (can_buy)
          profit = std::max(
            self(self, index + 1, transactions + 1, false) - prices[index],
            self(self, index + 1, transactions, true)
          );
        else
          profit = std::max(
            self(self, index + 1, transactions, true) + prices[index],
            self(self, index + 1, transactions, false)
          );
        
        dp[can_buy][transactions][index] = profit;
        return profit;
      };
      
      return dfs(dfs, 0, 0, true);
    }
};
```

<br>

### Statistics

- total accepted: 308334
- total submissions: 832651
- acceptance rate: 37.0%
- likes: 5451
- dislikes: 183

<br>

### Similar Problems

- [Best Time to Buy and Sell Stock](https://leetcode.com/problems/best-time-to-buy-and-sell-stock) (Easy)
- [Best Time to Buy and Sell Stock II](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii) (Medium)
- [Best Time to Buy and Sell Stock III](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii) (Hard)
- [Maximum Profit From Trading Stocks](https://leetcode.com/problems/maximum-profit-from-trading-stocks) (Medium)
