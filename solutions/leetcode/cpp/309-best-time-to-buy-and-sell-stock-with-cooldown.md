# [309] Best Time to Buy and Sell Stock with Cooldown

**[array, dynamic-programming]**

### Statement

You are given an array `prices` where `prices[i]` is the price of a given stock on the `ith` day.

Find the maximum profit you can achieve. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times) with the following restrictions:

* After you sell your stock, you cannot buy stock on the next day (i.e., cooldown one day).


**Note:** You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).


**Example 1:**

```

**Input:** prices = [1,2,3,0,2]
**Output:** 3
**Explanation:** transactions = [buy, sell, cooldown, buy, sell]

```

**Example 2:**

```

**Input:** prices = [1]
**Output:** 0

```

**Constraints:**
* `1 <= prices.length <= 5000`
* `0 <= prices[i] <= 1000`


<br>

### Hints

None

<br>

### Solution

```cpp
class Solution {
  public:
    int maxProfit (vector <int>& prices) {
      int n = prices.size();
      std::vector <std::vector <int>> dp (2, std::vector <int> (n + 1, -1));
      
      auto dfs = [&] (auto self, int index, bool can_buy) -> int {
        if (index >= n)
          return 0;
        if (dp[can_buy][index] != -1)
          return dp[can_buy][index];
        
        int profit;
        
        if (can_buy)
          profit = std::max(
            self(self, index + 1, true),
            self(self, index + 1, false) - prices[index]
          );
        else
          profit = std::max(
            self(self, index + 1, false),
            self(self, index + 2, true) + prices[index]
          );
        
        dp[can_buy][index] = profit;
        return profit;
      };
      
      return dfs(dfs, 0, true);
    }
};
```

<br>

### Statistics

- total accepted: 318224
- total submissions: 588711
- acceptance rate: 54.1%
- likes: 6577
- dislikes: 226

<br>

### Similar Problems

- [Best Time to Buy and Sell Stock](https://leetcode.com/problems/best-time-to-buy-and-sell-stock) (Easy)
- [Best Time to Buy and Sell Stock II](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii) (Medium)
