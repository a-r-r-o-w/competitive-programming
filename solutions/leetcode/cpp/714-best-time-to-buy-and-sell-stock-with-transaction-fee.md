# [714] Best Time to Buy and Sell Stock with Transaction Fee

**[array, dynamic-programming, greedy]**

### Statement

You are given an array `prices` where `prices[i]` is the price of a given stock on the `ith` day, and an integer `fee` representing a transaction fee.

Find the maximum profit you can achieve. You may complete as many transactions as you like, but you need to pay the transaction fee for each transaction.

**Note:** You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).


**Example 1:**

```

**Input:** prices = [1,3,2,8,4,9], fee = 2
**Output:** 8
**Explanation:** The maximum profit can be achieved by:
- Buying at prices[0] = 1
- Selling at prices[3] = 8
- Buying at prices[4] = 4
- Selling at prices[5] = 9
The total profit is ((8 - 1) - 2) + ((9 - 4) - 2) = 8.

```

**Example 2:**

```

**Input:** prices = [1,3,7,5,10,3], fee = 3
**Output:** 6

```

**Constraints:**
* `1 <= prices.length <= 5 * 104`
* `1 <= prices[i] < 5 * 104`
* `0 <= fee < 5 * 104`


<br>

### Hints

- Consider the first K stock prices.  At the end, the only legal states are that you don't own a share of stock, or that you do.  Calculate the most profit you could have under each of these two cases.

<br>

### Solution

```cpp
template <typename T>
using v = std::vector <T>;

class Solution {
  public:
    int maxProfit (vector <int>& prices, int fee) {
      int n = prices.size();
      v <v <int>> dp (2, v <int> (n + 1, -1));
      
      auto dfs = [&] (auto self, int index, bool can_buy) -> int {
        if (index >= n)
          return 0;
        if (dp[can_buy][index] != -1)
          return dp[can_buy][index];
        
        int profit;
        
        if (can_buy)
          profit = std::max(
            self(self, index + 1, true),
            self(self, index + 1, false) - prices[index] - fee
          );
        else
          profit = std::max(
            self(self, index + 1, false),
            self(self, index + 1, true) + prices[index]
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

- total accepted: 192451
- total submissions: 301234
- acceptance rate: 63.9%
- likes: 4571
- dislikes: 113

<br>

### Similar Problems

- [Best Time to Buy and Sell Stock II](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii) (Medium)
