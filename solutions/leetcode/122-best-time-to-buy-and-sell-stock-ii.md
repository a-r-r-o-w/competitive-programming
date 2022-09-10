# [122] Best Time to Buy and Sell Stock II

**[array, dynamic-programming, greedy]**

### Statement

You are given an integer array `prices` where `prices[i]` is the price of a given stock on the `ith` day.

On each day, you may decide to buy and/or sell the stock. You can only hold **at most one** share of the stock at any time. However, you can buy it then immediately sell it on the **same day**.

Find and return *the **maximum** profit you can achieve*.


**Example 1:**

```

**Input:** prices = [7,1,5,3,6,4]
**Output:** 7
**Explanation:** Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
Total profit is 4 + 3 = 7.

```

**Example 2:**

```

**Input:** prices = [1,2,3,4,5]
**Output:** 4
**Explanation:** Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
Total profit is 4.

```

**Example 3:**

```

**Input:** prices = [7,6,4,3,1]
**Output:** 0
**Explanation:** There is no way to make a positive profit, so we never buy the stock to achieve the maximum profit of 0.

```

**Constraints:**
* `1 <= prices.length <= 3 * 104`
* `0 <= prices[i] <= 104`


<br>

### Hints

None

<br>

### Solution

```cpp
class Solution {
  public:
    int maxProfit (vector <int>& prices) {
      const int inf32 = 1 << 30;
      int min = inf32, max = -inf32, profit = 0;
      int n = prices.size();
      
      for (int i = 0; i < n; ++i) {
        if (prices[i] < max) {
          if (max != -inf32)
            profit += max - min;
          max = prices[i];
          min = prices[i];
        }
        else {
          min = std::min(min, prices[i]);
          max = std::max(max, prices[i]);
        }
      }
      
      if (max != inf32)
        profit += max - min;
      
      return profit;
    }
};
```

<br>

### Statistics

- total accepted: 1258678
- total submissions: 1999840
- acceptance rate: 62.9%
- likes: 8985
- dislikes: 2457

<br>

### Similar Problems

- [Best Time to Buy and Sell Stock](https://leetcode.com/problems/best-time-to-buy-and-sell-stock) (Easy)
- [Best Time to Buy and Sell Stock III](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii) (Hard)
- [Best Time to Buy and Sell Stock IV](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv) (Hard)
- [Best Time to Buy and Sell Stock with Cooldown](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown) (Medium)
- [Best Time to Buy and Sell Stock with Transaction Fee](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee) (Medium)
- [Maximum Profit From Trading Stocks](https://leetcode.com/problems/maximum-profit-from-trading-stocks) (Medium)
